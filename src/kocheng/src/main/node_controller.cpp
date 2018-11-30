#include "../../include/kocheng/hehe.hpp"
#include <ros/ros.h>
#include <iostream>
#include <stdio.h>
#include "mavros_msgs/SetMode.h"
#include "mavros_msgs/State.h"
#include "kocheng/node_master.h"
#include "kocheng/rc_number.h"

using namespace std;
int rc_flag_in;
bool override_flag 	= false;

ros::ServiceClient client_set_flightmode;

kocheng::node_master control;

void rc_number_cb	(const kocheng::rc_number& number);

bool changeFlightMode(const char* flight_mode);

int main(int argc, char **argv)
{
	ros::init(argc, argv, "node_controller");
	ros::NodeHandle nh;
	
	ros::Publisher pub_node_master = nh.advertise<kocheng::node_master>("/auvsi/node/master", 8, true);
	ros::Subscriber sub_rc_number = nh.subscribe("/auvsi/rc/number", 8, rc_number_cb);
	client_set_flightmode = nh.serviceClient<mavros_msgs::SetMode>("/mavros/set_mode");
	
	ROS_WARN("NC : node_controller.cpp active");
	
	while(ros::ok()){
		ros::spinOnce();
		sleep(0.5);
		if(rc_flag_in == first_simple ){
			override_flag 			= true;
		}
		else if(rc_flag_in == second_simple){
			override_flag 			= true;
		}
		else if(rc_flag_in == zero_flag){
			override_flag 			= false;
		}
		else {
			override_flag 			= false;
		}
		
		control.override_status = override_flag;
		pub_node_master.publish(control);
	}
}

void rc_number_cb	(const kocheng::rc_number& number){
		rc_flag_in = number.rc_number;
}

bool changeFlightMode(const char* flight_mode){
	mavros_msgs::SetMode flightmode;
	flightmode.request.base_mode = 0;				
	flightmode.request.custom_mode = flight_mode;		
	bool success = client_set_flightmode.call(flightmode);

	if(success){
		return true;
	}
	else {
		return  false;
	}
}

