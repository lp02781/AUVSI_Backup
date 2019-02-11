#include "../../include/kocheng/hehe.hpp"
#include <ros/ros.h>

#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>

#include "kocheng/drone_kocheng.h"
#include "kocheng/image_in.h"
#include "kocheng/image_out.h"

#include "mavros_msgs/SetMode.h"
#include "mavros_msgs/State.h"

#include "sensor_msgs/NavSatFix.h"

#include "geometry_msgs/TwistStamped.h"

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/opencv.hpp"
#include "opencv/cv.h"

#include "std_msgs/Float64.h"

#include "pid/plant_msg.h"
#include "pid/controller_msg.h"
#include "pid/pid_const_msg.h"

using namespace std;
using namespace cv;

void drone_status_cb	(const kocheng::drone_kocheng& data);
void altReceiver		(const std_msgs::Float64& alt_msg);

bool changeFlightMode		(const char* flight_mode);
bool changeFlightModeDebug	(string fm);

void pid_receiver_x_cb	(const pid::controller_msg& control);
void pid_receiver_y_cb	(const pid::controller_msg& control);

void image_out_cb(const kocheng::image_out& image);

kocheng::drone_kocheng drone;
kocheng::image_in image_in;

int state_x, state_y, throttle_pwm, steer_pwm, control_effort_x, control_effort_y;

pid::plant_msg  pid_in_x;
pid::pid_const_msg pid_const_x;
pid::plant_msg  pid_in_y;
pid::pid_const_msg pid_const_y;

ros::ServiceClient client_set_flightmode;

string drone_status;

string docking_picture;
string docking_home;
string docking_emergency;

Mat Original;

float alt_now;

geometry_msgs::TwistStamped quad_vel;

void imageCallback(const sensor_msgs::CompressedImageConstPtr& msg){
  try{
    Original = cv::imdecode(cv::Mat(msg->data),1);//convert compressed image data to cv::Mat
  }
  catch (cv_bridge::Exception& e){
    ROS_ERROR("Could not convert to image!");
  }
}

int main(int argc, char **argv){
	ros::init(argc, argv, "docking drone");
	ros::NodeHandle nh;
	cv::startWindowThread();
	
	ROS_WARN("NC : docking_drone.cpp active");
	image_transport::ImageTransport it(nh);
	
	ros::Publisher pub_drone_status = nh.advertise<kocheng::drone_kocheng>("/auvsi/drone/status", 8);
	ros::Publisher pub_quad_vel 	= nh.advertise<geometry_msgs::TwistStamped>("mavros/setpoint_velocity/cmd_vel", 1000);
	
	ros::Publisher pub_pid_in_x 	= nh.advertise<pid::plant_msg>("/auvsi/pid/inX", 1);
	ros::Publisher pub_pid_const_x 	= nh.advertise<pid::pid_const_msg>("/auvsi/pid/constX", 1,true);
	ros::Publisher pub_pid_in_y 	= nh.advertise<pid::plant_msg>("/auvsi/pid/inY", 1);
	ros::Publisher pub_pid_const_y 	= nh.advertise<pid::pid_const_msg>("/auvsi/pid/constY", 1,true);
	ros::Publisher pub_image_in 	= nh.advertise<kocheng::image_in>("/auvsi/image/in", 1);
	
	ros::Subscriber sub_image_cb		= nh.subscribe("camera/drone/compressed", 1, imageCallback);
	ros::Subscriber sub_drone_status 	= nh.subscribe("/auvsi/drone/status", 8, drone_status_cb);	
	ros::Subscriber sub_rel_alt 		= nh.subscribe("mavros/global_position/rel_alt", 1, altReceiver );
	ros::Subscriber sub_pid_x_out 	= nh.subscribe("/auvsi/pid/outX", 10, pid_receiver_x_cb );
	ros::Subscriber sub_pid_y_out 	= nh.subscribe("/auvsi/pid/outy", 10, pid_receiver_y_cb );
	ros::Subscriber sub_image_out	= nh.subscribe("/auvsi/image/out", 8, image_out_cb);
	
	client_set_flightmode 				= nh.serviceClient<mavros_msgs::SetMode>("/mavros/set_mode");
	
	docking_picture 	= "rosrun mavros mavwp load ~/docking_pic_"+course_type+".waypoints";
	docking_home		= "rosrun mavros mavwp load ~/docking_gate_"+course_type+".waypoints";
	docking_emergency	= "rosrun mavros mavwp load ~/emergency_"+course_type+".waypoints";
	
	while (ros::ok()) {
		ros::spinOnce();
		while(drone_status=="docking_drone"){
			changeFlightModeDebug("LOITER");
			system("rosrun mavros mavwp clear"); //clear wp
			system(docking_picture.c_str());
			changeFlightModeDebug("AUTO");
			changeFlightModeDebug("LOITER");
			
			namedWindow("Original", CV_WINDOW_AUTOSIZE);
    
			vector<int> compression_params; 
			compression_params.push_back(CV_IMWRITE_JPEG_QUALITY);
			compression_params.push_back(98); 
			bool cSuccess = imwrite("../docking.jpg", Original, compression_params); 
			
			system("rosrun mavros mavwp clear"); 
			system(docking_home.c_str());
			changeFlightModeDebug("AUTO");
			changeFlightModeDebug("LOITER");
			sleep(1);
			
			//##############################################################  send picture to surface vehicle
			
			drone.drone_status=="docking_capture";
			pub_drone_status.publish(drone);
			ros::spinOnce();
		}
		while (drone_status=="docking_capture"){
			image_in.x_init	= x_drone;
			image_in.y_init	= y_drone;
			image_in.width	= width_drone;
			image_in.height	= height_drone;
			image_in.LowH	= LowH_drone;
			image_in.HighH	= HighH_drone;
			image_in.LowS	= LowS_drone;
			image_in.HighS	= HighS_drone;
			image_in.LowV	= LowV_drone;
			image_in.HighV	= HighV_drone;
			image_in.Noise	= Noise_drone;
			pub_image_in.publish(image_in);
			
			pid_const_x.p = kp_drone_x;
			pid_const_x.i = ki_drone_x;
			pid_const_x.d = kd_drone_x;
			pub_pid_const_x.publish(pid_const_x);
			pid_const_y.p = kp_drone_y;
			pid_const_y.i = ki_drone_y;
			pid_const_y.d = kd_drone_y;
			pub_pid_const_y.publish(pid_const_y);
			
			pid_in_x.x		= state_x;
			pid_in_x.t 		= pid_in_x.t+delta_t;
			pid_in_x.setpoint = setpoint_drone_x;
				
			pid_in_y.x		= state_y;
			pid_in_y.t 		= pid_in_y.t+delta_t;
			pid_in_y.setpoint = setpoint_drone_y;
			
			pub_pid_in_x.publish(pid_in_x);
			pub_pid_in_y.publish(pid_in_y);
			
			ros::spinOnce();
			
			quad_vel.header.stamp = ros::Time::now();
			quad_vel.header.frame_id = "1";
			quad_vel.twist.linear.x = control_effort_x;
			quad_vel.twist.linear.y = control_effort_y;
			pub_quad_vel.publish(quad_vel);
			
			if(alt_now <= alt_threshold){
				changeFlightModeDebug("LANDING");
				drone.drone_status=="docking_landing";
				pub_drone_status.publish(drone);
				ros::spinOnce();
			}
			else if(state_x == 0 && state_y == 0){
				changeFlightModeDebug("LOITER");
				drone.drone_status=="docking_landing";
				pub_drone_status.publish(drone);
				system(docking_emergency.c_str());
				changeFlightModeDebug("AUTO");
				ros::spinOnce();
			}
		}
	}
}

void drone_status_cb	(const kocheng::drone_kocheng& data){
	drone_status=data.drone_status;
}

bool changeFlightMode(const char* flight_mode){
	mavros_msgs::SetMode flightmode;
	flightmode.request.base_mode 	= 0;				
	flightmode.request.custom_mode 	= flight_mode;		
	bool success = client_set_flightmode.call(flightmode);

	if(success){
		return true;
	}
	else {
		return  false;
	}
}

bool changeFlightModeDebug(string fm){
	changeFlightMode(fm.c_str());
}

void altReceiver(const std_msgs::Float64& alt_msg){
	alt_now = alt_msg.data;
}

void image_out_cb(const kocheng::image_out& image){
	state_x = image.state_x;
	state_y = image.state_y;
}

void pid_receiver_x_cb(const pid::controller_msg& control){
	control_effort_y = control.u;
}

void pid_receiver_y_cb(const pid::controller_msg& control){
	control_effort_x = control.u;
}


