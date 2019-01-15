#include "../../include/kocheng/hehe.hpp"
#include <iostream>
#include <stdio.h>
#include <ros/ros.h>
#include "std_msgs/Float64.h"

#include "mavros_msgs/State.h"
#include "mavros_msgs/OverrideRCIn.h"
#include "mavros_msgs/RCIn.h"
#include "mavros_msgs/GlobalPositionTarget.h"

#include "sensor_msgs/NavSatFix.h"

#include "kocheng/override_motor.h"
#include "kocheng/rc_number.h"
#include "kocheng/mission_status.h"
#include "kocheng/debug_mission.h"
#include "kocheng/communication.h"
#include "kocheng/decode_status.h"
#include "kocheng/image_in.h"
#include "kocheng/image_out.h"

#include "pid/plant_msg.h"
#include "pid/controller_msg.h"
#include "pid/pid_const_msg.h"

using namespace std;

string override_status;

string first_simple_status, second_simple_status; 

int rc_flag;
string flight_mode;

int steering, throttle;

int out_channel[8], in_channel[8];

string armed, mode;

string mission_name;

float longitude, latitude;
float latitude_now, longitude_now;

double compass_hdg;

int setpoint_x, setpoint_y, state_x, state_y,effort_x, effort_y;
float kp_x, kp_y, ki_x, ki_y,  kd_x, kd_y;

int state_x_image, state_y_image;

int run_course_status, heartbeat_status, follow_status, docking_status;
string heartbeat_payload, run_course_payload, follow_payload, docking_payload;

int x_init=5;
int y_init=5;
int width=5; //width 400 for simple
int height=5;
int LowH=5; 		//0  
int HighH=5;		//184 
int LowS=5;      //130  65
int HighS=5;      //248  246
int LowV=5;		//49   242
int HighV=5;		//230  255
int Noise=15;

void override_rc_cb		(const kocheng::override_motor& rc);
void rc_number_cb 		(const kocheng::rc_number& state);
void override_motor_cb 	(const mavros_msgs::OverrideRCIn& motor);
void rc_in_cb 			(const mavros_msgs::RCIn& input);
void rc_state_cb 		(const mavros_msgs::State& state);
void rc_debug_cb 		(const kocheng::debug_mission& debug);
void rc_mission_cb 		(const kocheng::mission_status& mission);
void gps_rc_cb			(const sensor_msgs::NavSatFix& data);
void compass_rc_cb		(const std_msgs::Float64& msg);
void pid_effort_x_cb	(const pid::controller_msg& data);
void pid_const_x_cb		(const pid::pid_const_msg& data);
void pid_plant_x_cb		(const pid::plant_msg& data);
void pid_effort_y_cb	(const pid::controller_msg& data);
void pid_const_y_cb		(const pid::pid_const_msg& data);
void pid_plant_y_cb		(const pid::plant_msg& data);
void image_in_cb		(const kocheng::image_in& in);
void image_out_cb		(const kocheng::image_out& image);
void decode_status_cb	(const kocheng::decode_status& data);
void string_payload_cb	(const kocheng::communication& data);

int main(int argc, char **argv)
{
	ros::init(argc, argv, "debug_makara");
	ros::NodeHandle nh;
	
	ros::Subscriber sub_override_rc 	= nh.subscribe("/auvsi/override/motor", 8, override_rc_cb);
	ros::Subscriber sub_rc_number 		= nh.subscribe("/auvsi/rc/number", 8, rc_number_cb);
	ros::Subscriber sub_mission_rc 		= nh.subscribe("/auvsi/rc/mission", 8, rc_mission_cb);
	ros::Subscriber sub_debug_rc 		= nh.subscribe("/auvsi/debug/rc", 8, rc_debug_cb);
	ros::Subscriber sub_image_in		= nh.subscribe("/auvsi/image/in", 1, image_in_cb);
	ros::Subscriber sub_image_out		= nh.subscribe("/auvsi/image/out", 8, image_out_cb);
	ros::Subscriber sub_run_status		= nh.subscribe("/auvsi/run_course/status", 8, decode_status_cb);
	//ros::Subscriber sub_string_payload	= nh.subscribe("/auvsi/run_course/status", 8, string_payload_cb);
	
	ros::Subscriber sub_override_motor 	= nh.subscribe("/mavros/rc/override", 8, override_motor_cb);
	ros::Subscriber sub_rc_in 			= nh.subscribe("/mavros/rc/in", 8, rc_in_cb);
	ros::Subscriber sub_state_rc 		= nh.subscribe("/mavros/state", 8, rc_state_cb);
	ros::Subscriber sub_gps_cb			= nh.subscribe("/mavros/global_position/global", 8, gps_rc_cb);
	ros::Subscriber sub_compass_cb		= nh.subscribe("/mavros/global_position/compass_hdg", 8, compass_rc_cb);
	
	ros::Subscriber sub_pid_x_in 	= nh.subscribe("/auvsi/pid/inX", 10, pid_plant_x_cb );
	ros::Subscriber sub_pid_x_out 	= nh.subscribe("/auvsi/pid/outX", 10, pid_effort_x_cb );
	ros::Subscriber sub_pid_x_const = nh.subscribe("/auvsi/pid/constX", 10, pid_const_x_cb );
	ros::Subscriber sub_pid_y_in 	= nh.subscribe("/auvsi/pid/inY", 10, pid_plant_y_cb);
	ros::Subscriber sub_pid_y_out 	= nh.subscribe("/auvsi/pid/outY", 10, pid_effort_y_cb );
	ros::Subscriber sub_pid_y_const = nh.subscribe("/auvsi/pid/constX", 10, pid_const_y_cb );
	
	ROS_WARN("NC : debug_makara.cpp active");

	while( ros::ok() ){	
		ros::spinOnce();
		
		ROS_WARN("NC : topic master");
		ROS_INFO("mission:%s", mission_name.c_str());
		ROS_INFO("override:%s\t rc:%d", override_status.c_str(), rc_flag);
		ROS_INFO(" ");
		
		ROS_INFO("compass:%0.2f\t long:%0.2f\t lat:%0.2f", compass_hdg, longitude, latitude);
		ROS_INFO("long:%0.2f\t lat:%0.2f", longitude, latitude);
		ROS_INFO(" ");
		
		ROS_WARN("NC : topic PID");
		ROS_INFO("X: kp:%0.2f\t ki:%0.2f\t kd:%0.2f\t setpoint:%d\t state:%d\t effort:%d\t", kp_x, ki_x, kd_x, setpoint_x, state_x, effort_x);
		ROS_INFO("Y: kp:%0.2f\t ki:%0.2f\t kd:%0.2f\t setpoint:%d\t state:%d\t effort:%d\t", kp_y, ki_y, kd_y, setpoint_y, state_y, effort_y);
		ROS_INFO(" ");
		
		ROS_INFO("steering:%d\t throttle:%d", steering, throttle);
		ROS_INFO("armed:%s\t mode:%s", armed.c_str(), mode.c_str());		
		ROS_INFO(" ");
		
		ROS_WARN("NC : topic channel");
		ROS_INFO("1:%d\t 2:%d\t 3:%d\t 4:%d\t 5:%d\t 6:%d\t 7:%d\t 8:%d", in_channel[0], in_channel[1], in_channel[2], in_channel[3], in_channel[4], in_channel[5], in_channel[6], in_channel[7]);		
		ROS_INFO("1:%d\t 2:%d\t 3:%d\t 4:%d\t 5:%d\t 6:%d\t 7:%d\t 8:%d", out_channel[0], out_channel[1], out_channel[2], out_channel[3], out_channel[4], out_channel[5], out_channel[6], out_channel[7]);		
		ROS_INFO(" ");
		
		ROS_WARN("NC: topic image");
		ROS_INFO("x:%d\t y:%d\t w:%d\t h:%d\t Lh:%d\t Hh:%d\t Ls:%d\t Hs:%d\t Lv:%d\t Hv:%d\t N:%d", x_init, y_init, width, height, LowH, HighH, LowS, HighS, LowV, HighV, Noise);
		ROS_INFO("state_x:%d\t state_y:%d", state_x_image, state_y_image);
		ROS_INFO(" ");
		
		ROS_WARN("NC: Communication");
		ROS_INFO("run:%d\t heartbeat:%d\t follow:%d\t docking:%d\t", run_course_status, heartbeat_status, follow_status, docking_status);
		/*
		ROS_INFO("run_course:%s", run_course_payload.c_str());
		ROS_INFO("heartbeat:%s", heartbeat_payload.c_str());
		ROS_INFO("follow:%s", follow_payload.c_str());
		ROS_INFO("docking:%s", docking_payload.c_str());
		ROS_INFO(" ");
		*/
		sleep(1);
		system("clear");
	}
}

void decode_status_cb	(const kocheng::decode_status& data){
	run_course_status	= data.run_course_status;
	heartbeat_status	= data.heartbeat_status;
	follow_status		= data.follow_status;
	docking_status		= data.docking_status;
}
/*
void string_payload_cb	(const kocheng::communication& data){
	heartbeat_payload	= data.heartbeat_payload;
	run_course_payload	= data.run_course_payload;
	follow_payload		= data.follow_payload;
	docking_payload		= data.docking_payload;
}
*/
void image_in_cb(const kocheng::image_in& in){
	x_init	= in.x_init;
	y_init	= in.y_init;
	width	= in.width; //width 400 for simple
	height	= in.height;
	LowH	= in.LowH; 		//0  
	HighH	= in.HighH;		//184 
	LowS	= in.LowS;      //130  65
	HighS	= in.HighS;      //248  246
	LowV	= in.LowV;		//49   242
	HighV	= in.HighV;		//230  255
	Noise	= in.Noise;
}

void image_out_cb(const kocheng::image_out& image){
	state_x_image = image.state_x;
	state_y_image = image.state_y;
}

void compass_rc_cb(const std_msgs::Float64& msg){
	compass_hdg = msg.data;
}

void gps_rc_cb	(const sensor_msgs::NavSatFix& data){
	latitude_now	= data.latitude;
	longitude_now	= data.longitude;
}

void rc_mission_cb (const kocheng::mission_status& mission){
	mission_name = mission.mission_makara;
}

void rc_debug_cb (const kocheng::debug_mission& debug){
	longitude	= debug.longitude;
	latitude	= debug.latitude;
}

void rc_number_cb (const kocheng::rc_number& number){
	rc_flag = number.rc_number;
	if(number.override_status == true){override_status = "true";}
	else{override_status = "false";}
}

void override_rc_cb	(const kocheng::override_motor& rc){
	steering	= rc.steering;
	throttle 	= rc.throttle;
}

void override_motor_cb (const mavros_msgs::OverrideRCIn& motor){
	int x;
	for(x=0;x<8;x++){ 
		out_channel[x] = motor.channels[x]; 
	}
}

void rc_in_cb (const mavros_msgs::RCIn& input){
	int y;
	for(y=0;y<8;y++){ 
		in_channel[y] = input.channels[y]; 
	}
}

void rc_state_cb (const mavros_msgs::State& state){
	if(state.armed == true){
		armed = "true";
	}
	else{armed = "false";}
	mode = state.mode;	
}

void pid_effort_x_cb(const pid::controller_msg& data){
	effort_x=data.u;
}
void pid_const_x_cb(const pid::pid_const_msg& data){
	kp_x = data.p;
	ki_x = data.i;
	kd_x = data.d;
}
void pid_plant_x_cb(const pid::plant_msg& data){
	state_x		= data.x;
	setpoint_x	= data.setpoint;
}
void pid_effort_y_cb(const pid::controller_msg& data){
	effort_y=data.u;
}
void pid_const_y_cb(const pid::pid_const_msg& data){
	kp_y = data.p;
	ki_y = data.i;
	kd_y = data.d;
}
void pid_plant_y_cb(const pid::plant_msg& data){
	state_y		= data.x;
	setpoint_y	= data.setpoint;
}
