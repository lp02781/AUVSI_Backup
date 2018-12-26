#include "../../include/kocheng/hehe.hpp"
#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include "std_msgs/Float64.h"

#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"

#include "pid/plant_msg.h"
#include "pid/controller_msg.h"
#include "pid/pid_const_msg.h"

#include "kocheng/override_motor.h"
#include "kocheng/mission_status.h"
#include "kocheng/debug_mission.h"

#include "mavros_msgs/GlobalPositionTarget.h"

#include "sensor_msgs/NavSatFix.h"

using namespace std;
using namespace cv;

void imageProcessing	(Mat input_image);
void pid_receiver_cb	(const pid::controller_msg& control);
void rc_mission_cb		(const kocheng::mission_status& data);
void gps_rc_cb			(const sensor_msgs::NavSatFix& data);
void compass_rc_cb		(const std_msgs::Float64& msg);
void change_value_image_processing();

Mat receive_image;

pid::plant_msg  pid_in;
pid::pid_const_msg pid_const;

kocheng::override_motor controller;
kocheng::mission_status	mission;
kocheng::debug_mission	debug;

int state, throttle_pwm, steer_pwm, control_effort;

int drone_pwm, camera_pwm;

float latitude, longitude;

double compass_hdg, compass_init, compass_end;

string receive_mission;


float longitude_speed_end;
float latitude_speed_end;

void imageCallback		(const sensor_msgs::CompressedImageConstPtr& msg){
  try{
    receive_image = cv::imdecode(cv::Mat(msg->data),1);//convert compressed image data to cv::Mat
    waitKey(10);
  }
  catch (cv_bridge::Exception& e){
    ROS_ERROR("Could not convert to image!");
  }
}

int main(int argc, char **argv){
	ros::init(argc, argv, "speed");
	ros::NodeHandle nh;
	cv::startWindowThread();
	
	ROS_WARN("NC : speed.cpp active");
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
	ros::Subscriber sub_compass_cb		= nh.subscribe("/mavros/global_position/compass_hdg", 8, compass_rc_cb);
	 
	namedWindow("panel_speed", CV_WINDOW_AUTOSIZE);
	
	createTrackbar("LowH_speed", "panel_speed", &LowH_speed, 255);
	createTrackbar("HighH_speed", "panel_speed", &HighH_speed, 255);
	createTrackbar("LowS_speed", "panel_speed", &LowS_speed, 255); 
	createTrackbar("HighS_speed", "panel_speed", &HighS_speed, 255);
	createTrackbar("LowV_speed", "panel_speed", &LowV_speed, 255);
	createTrackbar("HighV_speed", "panel_speed", &HighV_speed, 255);
	createTrackbar("x_speed", "panel_speed", &x_speed, 700); //Hue (0 - 255)
	createTrackbar("y_speed", "panel_speed", &y_speed, 700);
	createTrackbar("width_speed", "panel_speed", &width_speed, 700); //Saturation (0 - 255)
	createTrackbar("hight_speed", "panel_speed", &height_speed, 700);
	createTrackbar("noise_speed", "panel_speed", &Noise_speed, 255);
	
	if(course_type.compare("courseA")==0){
		longitude_speed_end=longitude_speed_end_A;
		latitude_speed_end=latitude_speed_end_A;
	}
	else if(course_type.compare("courseB")==0){
		longitude_speed_end=longitude_speed_end_B;
		latitude_speed_end=latitude_speed_end_B;
	}
	else if(course_type.compare("courseC")==0){
		longitude_speed_end=longitude_speed_end_C;
		latitude_speed_end=latitude_speed_end_C;
	}
	else if(course_type.compare("courseUI")==0){
		longitude_speed_end=longitude_speed_end_UI;
		latitude_speed_end=latitude_speed_end_UI;
	}
	
	while (ros::ok()) {
		ros::spinOnce();
		while(receive_mission=="speed.start"){
		
			pid_const.p = kp_speed;
			pid_const.i = ki_speed;
			pid_const.d = kd_speed;
			pub_pid_const.publish(pid_const);
			
			mission.mission_makara="speed.step_1";
			pub_mission_rc.publish(mission);
			ros::spinOnce();
			
			compass_init	= compass_hdg;
			compass_end		= compass_init+compass_point;
			
			while(receive_mission=="speed.step_1"){
				ros::spinOnce();
				imageProcessing(receive_image);
				
				pid_in.x 		= state;
				pid_in.t 		= pid_in.t+delta_t;
				pid_in.setpoint = setpoint_speed;
				pub_pid_in.publish(pid_in);
			
				ros::spinOnce();
				throttle_pwm 	= THROT_SPEED;
				steer_pwm 		= MIDDLE_PWM - control_effort;
			
				camera_pwm=CAM_INIT_PWM;
				drone_pwm=DRONE_INIT_PWM;
			
				if(state==0){
					steer_pwm=MIDDLE_PWM;
				}
			
				controller.drone_servo 	= drone_pwm;
				controller.camera_servo = camera_pwm;
				controller.steering = steer_pwm;
				controller.throttle = throttle_pwm;
				pub_override_rc.publish(controller);
		
				debug.longitude	= longitude_speed_end;
				debug.latitude	= latitude_speed_end;
				pub_debug_rc.publish(debug);

				if(compass_hdg < compass_end-compass_tolerance && compass_hdg > compass_end+compass_tolerance){
					mission.mission_makara="speed.step_2";
					pub_mission_rc.publish(mission);
					ros::spinOnce();
				}
			}
			ros::spinOnce();
			change_value_image_processing();
			
			pid_const.p = kp_speed;
			pid_const.i = ki_speed;
			pid_const.d = kd_speed;
			pub_pid_const.publish(pid_const);
			ros::spinOnce();
			while(receive_mission=="speed.step_2"){
				ros::spinOnce();
				imageProcessing(receive_image);
				pid_in.x 		= state;
				pid_in.t 		= pid_in.t+delta_t;
				pid_in.setpoint = setpoint_speed;
				pub_pid_in.publish(pid_in);
			
				ros::spinOnce();
				throttle_pwm 	= THROT_SPEED;
				steer_pwm 		= MIDDLE_PWM - control_effort;
			
				camera_pwm	= CAM_INIT_PWM;
				drone_pwm	= DRONE_INIT_PWM;
			
				if(state==0){
					steer_pwm=MIDDLE_PWM;
				}
			
				controller.drone_servo 	= drone_pwm;
				controller.camera_servo = camera_pwm;
				controller.steering 	= steer_pwm;
				controller.throttle 	= throttle_pwm;
				pub_override_rc.publish(controller);
		
				debug.longitude	= longitude_speed_end;
				debug.latitude	= latitude_speed_end;
				pub_debug_rc.publish(debug);

				if(longitude<longitude_speed_end+tolerance_speed && longitude>longitude_speed_end-tolerance_speed &&
				latitude<latitude_speed_end+tolerance_speed && latitude>latitude_speed_end-tolerance_speed){
					mission.mission_makara="speed.end";
					pub_mission_rc.publish(mission);
					ros::spinOnce();
				}
			}
		}
	}
}

void imageProcessing(Mat input_image){
	Mat imgOriginal, imgHSV, imgThresholded, imgErode, imgDilate, imgDebug;
	
	imgDebug = input_image.clone();
	medianBlur(imgDebug, imgDebug, 5);
	cvtColor(imgDebug, imgDebug, COLOR_BGR2HSV);
	inRange(imgDebug, Scalar(LowH_speed, LowS_speed, LowV_speed), Scalar(HighH_speed, HighS_speed, HighV_speed), imgDebug);//range threshold
	erode(imgDebug, imgDebug, getStructuringElement(MORPH_ELLIPSE, Size(Noise_speed, Noise_speed)) );
	dilate( imgDebug, imgDebug, getStructuringElement(MORPH_ELLIPSE, Size(Noise_speed, Noise_speed)) ); 
	dilate(imgDebug, imgDebug, getStructuringElement(MORPH_ELLIPSE, Size(Noise_speed, Noise_speed)) ); 
	erode(imgDebug, imgDebug, getStructuringElement(MORPH_ELLIPSE, Size(Noise_speed, Noise_speed)) ); 
	
	Rect region_of_interest = Rect(x_speed, y_speed, width_speed, height_speed);
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
	inRange(imgHSV, Scalar(LowH_speed, LowS_speed, LowV_speed), Scalar(HighH_speed, HighS_speed, HighV_speed), imgThresholded);//range threshold
		
	erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(Noise_speed, Noise_speed)) );
	dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(Noise_speed, Noise_speed)) ); 
		
	dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(Noise_speed, Noise_speed)) ); 
	erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(Noise_speed, Noise_speed)) ); 
	
	Moments mu=moments(imgThresholded);
	int area = mu.m00; // sum of zero'th moment is area
	int posX = mu.m10/area; // center of mass = w*x/weight
	area 	/= 255; // scale from bytes to pixels	
	
	state = posX;
	
	line( Original, Point( setpoint_speed, 0 ), Point( setpoint_speed, original_height), Scalar( 50, 50, 50 ), 2, 8 );
	line( Original, Point( state, 0 ), Point( state, original_height), Scalar( 150, 150, 150 ), 2, 8 );
	line( input_image, Point( setpoint_speed, 0 ), Point( setpoint_speed, input_height), Scalar( 50, 50, 50 ), 2, 8 );
	line( input_image, Point( state, 0 ), Point( state, input_height), Scalar( 150, 150, 150 ), 2, 8 );
	
	line( input_image, Point( x_speed, y_speed ), Point( x_speed+original_width, y_speed), Scalar( 100, 100, 100 ), 2, 8 );
	line( input_image, Point( x_speed, y_speed+original_height ), Point( x_speed+original_width, y_speed+original_height), Scalar( 100, 100, 100 ), 2, 8 );	
	line( input_image, Point( x_speed, y_speed ), Point( x_speed, y_speed+original_height), Scalar( 100, 100, 100 ), 2, 8 );
	line( input_image, Point( x_speed+original_width, y_speed ), Point( x_speed+original_width, y_speed+original_height), Scalar( 100, 100, 100 ), 2, 8 );
	
	imshow("Threshold_speed", imgThresholded);
	imshow("Input_speed", input_image);
	imshow("All_speed", imgDebug);
}

void pid_receiver_cb(const pid::controller_msg& control){
	control_effort = control.u;
}

void rc_mission_cb	(const kocheng::mission_status& data){
	receive_mission = data.mission_makara;
}
void gps_rc_cb	(const sensor_msgs::NavSatFix& data){
	latitude	= data.latitude;
	longitude	= data.longitude;
}

void compass_rc_cb(const std_msgs::Float64& msg){
	compass_hdg = msg.data;
}

void change_value_image_processing(){
	kp_speed 	= kp_speed_new;//1.5
	ki_speed 	= ki_speed_new;//1
	kd_speed 	= kd_speed;//0.5
	setpoint_speed = setpoint_speed_new;
	x_speed		= x_speed_new;
	y_speed		= y_speed_new;
	width_speed	= width_speed_new; //width 400 for simple
	height_speed= height_speed_new;
	LowH_speed	= LowH_speed_new; 		//0  
	HighH_speed = HighH_speed_new;		//184 
	LowS_speed 	= LowS_speed_new;      //130  65
	HighS_speed = HighS_speed_new;      //248  246
	LowV_speed 	= LowV_speed_new;		//49   242
	HighV_speed = HighV_speed_new;		//230  255
}		
