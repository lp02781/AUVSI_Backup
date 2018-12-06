#include "../../include/kocheng/hehe.hpp"
#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <cv_bridge/cv_bridge.h>
#include <iostream>
#include <stdio.h>
#include "pid/plant_msg.h"
#include "pid/controller_msg.h"
#include "pid/pid_const_msg.h"
#include "kocheng/override_motor.h"
#include "kocheng/mission_status.h"
#include "kocheng/debug_mission.h"
#include "mavros_msgs/GlobalPositionTarget.h"

using namespace std;
using namespace cv;

void imageProcessing(Mat input_image);
void pid_receiver_cb(const pid::controller_msg& control);
void rc_mission_cb	(const kocheng::mission_status& data);
void gps_rc_cb	(const mavros_msgs::GlobalPositionTarget& data);

Mat receive_image;
pid::plant_msg  pid_in;
pid::pid_const_msg pid_const;
kocheng::override_motor controller;
kocheng::mission_status	mission;
kocheng::debug_mission	debug;

int state;
int throttle_pwm;
int steer_pwm;
int control_effort;

int drone_pwm;
int camera_pwm;

float latitude;
float longitude;

string receive_mission;

void imageCallback(const sensor_msgs::CompressedImageConstPtr& msg)
{
  try
  {
    receive_image = cv::imdecode(cv::Mat(msg->data),1);//convert compressed image data to cv::Mat
    waitKey(10);
  }
  catch (cv_bridge::Exception& e)
  {
    ROS_ERROR("Could not convert to image!");
  }
}

int main(int argc, char **argv){
	ros::init(argc, argv, "navigation");
	ros::NodeHandle nh;
	cv::startWindowThread();
	
	ROS_WARN("NC : navigation.cpp active");
	image_transport::ImageTransport it(nh);
	
	ros::Publisher pub_debug_rc 	= nh.advertise<kocheng::debug_mission>("/auvsi/debug/rc", 10);
	ros::Publisher pub_override_rc 	= nh.advertise<kocheng::override_motor>("/auvsi/override/motor", 10);
	ros::Publisher pub_pid_in 		= nh.advertise<pid::plant_msg>("/auvsi/pid/inX", 1);
	ros::Publisher pub_pid_const 	= nh.advertise<pid::pid_const_msg>("/auvsi/pid/constX", 1,true);
	ros::Publisher pub_mission_rc 	= nh.advertise<kocheng::mission_status>("/auvsi/rc/mission", 1);
	
	ros::Subscriber sub_mission_rc 	= nh.subscribe("/auvsi/rc/mission", 1, rc_mission_cb);
	ros::Subscriber sub_pid_x_out 	= nh.subscribe("/auvsi/pid/outX", 10, pid_receiver_cb );
	ros::Subscriber sub_image_cb	= nh.subscribe("camera/image/compressed", 1, imageCallback);
	ros::Subscriber sub_gps_cb		= nh.subscribe("/mavros/global_position/global", 1, gps_rc_cb);
	 
	namedWindow("panel_nav", CV_WINDOW_AUTOSIZE);
	
	createTrackbar("LowH_Nav", "panel_nav", &LowH_nav, 255);
	createTrackbar("HighH_Nav", "panel_nav", &HighH_nav, 255);
	createTrackbar("LowS_Nav", "panel_nav", &LowS_nav, 255); 
	createTrackbar("HighS_Nav", "panel_nav", &HighS_nav, 255);
	createTrackbar("LowV_Nav", "panel_nav", &LowV_nav, 255);
	createTrackbar("HighV_Nav", "panel_nav", &HighV_nav, 255);
	createTrackbar("x_Nav", "panel_nav", &x_nav, 700); //Hue (0 - 255)
	createTrackbar("y_Nav", "panel_nav", &y_nav, 700);
	createTrackbar("width_Nav", "panel_nav", &width_nav, 700); //Saturation (0 - 255)
	createTrackbar("hight_Nav", "panel_nav", &height_nav, 700);
	createTrackbar("noise_Nav", "panel_nav", &Noise_nav, 255);
	
	while (ros::ok()) {
		ros::spinOnce();
		while(receive_mission=="navigation.start"){
			imageProcessing(receive_image);
		
			pid_const.p = kp_nav;
			pid_const.i = ki_nav;
			pid_const.d = kd_nav;
			pub_pid_const.publish(pid_const);
		
			pid_in.x = state;
			pid_in.t = pid_in.t+delta_t;
			pid_in.setpoint = setpoint_nav;
			pub_pid_in.publish(pid_in);
			
			ros::spinOnce();
			throttle_pwm = THROT_NAV;
			steer_pwm = MIDDLE_PWM - control_effort;
			
			camera_pwm=CAM_INIT_PWM;
			drone_pwm=DRONE_INIT_PWM;
			
			controller.drone_servo = drone_pwm;
			controller.camera_servo = camera_pwm;
			controller.steering = steer_pwm;
			controller.throttle = throttle_pwm;
			pub_override_rc.publish(controller);
		
			debug.setpoint=setpoint_nav;
			debug.state=state;
			debug.effort=control_effort;
			debug.longitude=longitude_nav_end;
			debug.latitude=latitude_nav_end;
			pub_debug_rc.publish(debug);

			if(longitude<longitude_nav_end+tolerance_nav && longitude>longitude_nav_end-tolerance_nav &&
			latitude<latitude_nav_end+tolerance_nav && latitude>latitude_nav_end-tolerance_nav){
				mission.mission_makara="navigation.end";
				pub_mission_rc.publish(mission);
				ros::shutdown();
			}
		}
	}
}

void imageProcessing(Mat input_image){
	Mat imgOriginal, imgHSV, imgThresholded, imgErode, imgDilate, imgDebug;
	
	imgDebug = input_image.clone();
	medianBlur(imgDebug, imgDebug, 5);
	cvtColor(imgDebug, imgDebug, COLOR_BGR2HSV);
	inRange(imgDebug, Scalar(LowH_nav, LowS_nav, LowV_nav), Scalar(HighH_nav, HighS_nav, HighV_nav), imgDebug);//range threshold
	erode(imgDebug, imgDebug, getStructuringElement(MORPH_ELLIPSE, Size(Noise_nav, Noise_nav)) );
	dilate( imgDebug, imgDebug, getStructuringElement(MORPH_ELLIPSE, Size(Noise_nav, Noise_nav)) ); 
	dilate(imgDebug, imgDebug, getStructuringElement(MORPH_ELLIPSE, Size(Noise_nav, Noise_nav)) ); 
	erode(imgDebug, imgDebug, getStructuringElement(MORPH_ELLIPSE, Size(Noise_nav, Noise_nav)) ); 
	
	Rect region_of_interest = Rect(x_nav, y_nav, width_nav, height_nav);
	Mat Original = input_image(region_of_interest);
	
	Size sz = Original.size();
	int original_height = sz.height; 
	int original_width	= sz.width;
	
	Size sx = input_image.size();
	int input_height = sx.height;
	int input_width = sx.width; 
	
	imgOriginal = Original.clone();
	
	medianBlur(imgOriginal, imgOriginal, 5);
		
	cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV);
	inRange(imgHSV, Scalar(LowH_nav, LowS_nav, LowV_nav), Scalar(HighH_nav, HighS_nav, HighV_nav), imgThresholded);//range threshold
		
	erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(Noise_nav, Noise_nav)) );
	dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(Noise_nav, Noise_nav)) ); 
		
	dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(Noise_nav, Noise_nav)) ); 
	erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(Noise_nav, Noise_nav)) ); 
	
	Moments mu=moments(imgThresholded);
	int area = mu.m00; // sum of zero'th moment is area
	int posX = mu.m10/area; // center of mass = w*x/weight
	area /= 255; // scale from bytes to pixels	
	
	state = posX;
	
	line( Original, Point( setpoint_nav, 0 ), Point( setpoint_nav, original_height), Scalar( 50, 50, 50 ), 2, 8 );
	line( Original, Point( state, 0 ), Point( state, original_height), Scalar( 150, 150, 150 ), 2, 8 );
	line( input_image, Point( setpoint_nav, 0 ), Point( setpoint_nav, input_height), Scalar( 50, 50, 50 ), 2, 8 );
	line( input_image, Point( state, 0 ), Point( state, input_height), Scalar( 150, 150, 150 ), 2, 8 );
	
	line( input_image, Point( x_nav, y_nav ), Point( x_nav+original_width, y_nav), Scalar( 100, 100, 100 ), 2, 8 );
	line( input_image, Point( x_nav, y_nav+original_height ), Point( x_nav+original_width, y_nav+original_height), Scalar( 100, 100, 100 ), 2, 8 );	
	line( input_image, Point( x_nav, y_nav ), Point( x_nav, y_nav+original_height), Scalar( 100, 100, 100 ), 2, 8 );
	line( input_image, Point( x_nav+original_width, y_nav ), Point( x_nav+original_width, y_nav+original_height), Scalar( 100, 100, 100 ), 2, 8 );
	
	imshow("Threshold_nav", imgThresholded);
	imshow("Input_nav", input_image);
	imshow("All_nav", imgDebug);
}

void pid_receiver_cb(const pid::controller_msg& control){
	control_effort = control.u;
}

void rc_mission_cb	(const kocheng::mission_status& data){
	receive_mission = data.mission_makara;
}
void gps_rc_cb	(const mavros_msgs::GlobalPositionTarget& data){
	latitude=data.latitude;
	longitude=data.longitude;
}
