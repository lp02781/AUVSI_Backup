#include "../../include/kocheng/hehe.hpp"
#include <iostream>
#include <stdio.h>
#include <ros/ros.h>
#include "pid/controller_msg.h"
#include "mavros_msgs/State.h"
#include "mavros_msgs/OverrideRCIn.h"
#include "mavros_msgs/RCIn.h"
#include "mavros_msgs/GlobalPositionTarget.h"
#include "std_msgs/Float64.h"
#include "kocheng/override_motor.h"
#include "kocheng/rc_number.h"
#include "kocheng/mission_status.h"
#include "kocheng/debug_mission.h"

using namespace std;

string override_status;

string first_simple_status;
string second_simple_status; 

int rc_flag;
string flight_mode;

int steering;
int throttle;

int out_channel[8];
int in_channel[8];

string armed;
string mode;

string mission_name;

int setpoint;
int state;
int effort;
float longitude;
float latitude;

float latitude_now;
float longitude_now;

double compass_hdg;

void override_rc_cb	(const kocheng::override_motor& rc);
void rc_number_cb (const kocheng::rc_number& state);

void override_motor_cb (const mavros_msgs::OverrideRCIn& motor);
void rc_in_cb (const mavros_msgs::RCIn& input);
void rc_state_cb (const mavros_msgs::State& state);
void rc_debug_cb (const kocheng::debug_mission& debug);
void rc_mission_cb (const kocheng::mission_status& mission);
void gps_rc_cb	(const mavros_msgs::GlobalPositionTarget& data);
void compass_rc_cb(const std_msgs::Float64& msg);

int main(int argc, char **argv)
{
	ros::init(argc, argv, "debug_makara");
	ros::NodeHandle nh;
	
	ros::Subscriber sub_override_rc 	= nh.subscribe("/auvsi/override/motor", 8, override_rc_cb);
	ros::Subscriber sub_rc_number 		= nh.subscribe("/auvsi/rc/number", 8, rc_number_cb);
	ros::Subscriber sub_override_motor 	= nh.subscribe("/mavros/rc/override", 8, override_motor_cb);
	ros::Subscriber sub_rc_in 			= nh.subscribe("/mavros/rc/in", 8, rc_in_cb);
	ros::Subscriber sub_state_rc 		= nh.subscribe("/mavros/state", 8, rc_state_cb);
	ros::Subscriber sub_mission_rc 		= nh.subscribe("/auvsi/rc/mission", 8, rc_mission_cb);
	ros::Subscriber sub_debug_rc 		= nh.subscribe("/auvsi/debug/rc", 8, rc_debug_cb);
	ros::Subscriber sub_gps_cb			= nh.subscribe("/mavros/global_position/global", 8, gps_rc_cb);
	ros::Subscriber sub_compass_cb		= nh.subscribe("/mavros/global_position/compass_hdg", 8, compass_rc_cb);

	ROS_WARN("NC : debug_makara.cpp active");

	while( ros::ok() ){	
		ros::spinOnce();
		
		ROS_WARN("NC : topic master");
		ROS_INFO("mission:%s", mission_name.c_str());
		ROS_INFO("override:%s\t rc:%d", override_status.c_str(), rc_flag);
		ROS_INFO(" ");
		
		ROS_INFO("compass:%0.2f\t long:%0.2f\t lat:%0.2f", compass_hdg, longitude, latitude);
		ROS_INFO("setpoint:%d\t state:%d\t effort:%d\t long:%0.2f\t lat:%0.2f", setpoint, state, effort, longitude, latitude);
		ROS_INFO(" ");
		
		ROS_INFO("steering:%d\t throttle:%d", steering, throttle);
		ROS_INFO("armed:%s\t mode:%s", armed.c_str(), mode.c_str());		
		ROS_INFO(" ");
		
		ROS_WARN("NC : topic channel");
		ROS_INFO("1:%d\t 2:%d\t 3:%d\t 4:%d\t 5:%d\t 6:%d\t 7:%d\t 8:%d", in_channel[0], in_channel[1], in_channel[2], in_channel[3], in_channel[4], in_channel[5], in_channel[6], in_channel[7]);		
		ROS_INFO("1:%d\t 2:%d\t 3:%d\t 4:%d\t 5:%d\t 6:%d\t 7:%d\t 8:%d", out_channel[0], out_channel[1], out_channel[2], out_channel[3], out_channel[4], out_channel[5], out_channel[6], out_channel[7]);		
		ROS_INFO(" ");
		
		sleep(1);
		system("clear");
	}
}

void compass_rc_cb(const std_msgs::Float64& msg){
	compass_hdg = msg.data;
}

void gps_rc_cb	(const mavros_msgs::GlobalPositionTarget& data){
	latitude_now=data.latitude;
	longitude_now=data.longitude;
}

void rc_mission_cb (const kocheng::mission_status& mission){
	mission_name=mission.mission_makara;
}

void rc_debug_cb (const kocheng::debug_mission& debug){
	setpoint	=debug.setpoint;
	state		=debug.state;
	effort		=debug.effort;
	longitude	=debug.longitude;
	latitude	=debug.latitude;
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

void pid_receiver_cb(const pid::controller_msg& control){
	effort = control.u;
}
