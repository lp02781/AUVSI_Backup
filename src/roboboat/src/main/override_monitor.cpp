#include "../../include/roboboat/haha.hpp"
#include "ros/ros.h"
#include "mavros_msgs/RCIn.h"
#include "std_msgs/Bool.h"
#include <string>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

int rc_in_data_channel[8];
bool override_status = false;
void rcinReceiver(const mavros_msgs::RCIn& rc_in_data);
roboboat::node_status override_pub;
using namespace std;

int main(int argc, char **argv){

	ros::init(argc, argv, "remote_monitor");
	ros::NodeHandle ovrd_mon;
	ros::Subscriber rc_in_sub 	= ovrd_mon.subscribe("/mavros/rc/in", 1, rcinReceiver);
	ros::Publisher pub_override_rc = ovrd_mon.advertise<roboboat::node_status>("/auvsi/node/status", 1);
	
	ROS_WARN("NC : remote_monitor.cpp active");
	
	while(ros::ok()){
		ros::spinOnce();
		
		if(rc_in_data_channel[OVERRIDE] > PWM_UP ){
			override_status ==	true;
		}
		else{
			override_status ==	false;	
		}
		override_pub.override_status = override_status;
		pub_override_rc.publish(override_pub);
	}
}

void rcinReceiver(const mavros_msgs::RCIn& rc_in_data){
	int x;
	for (x = 0; x<8;x++){
		rc_in_data_channel[x] = rc_in_data.channels[x];
	}
}
