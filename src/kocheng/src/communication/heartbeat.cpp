#include "ros/ros.h"
#include <string>
#include "kocheng/mission_status.h"
#include "kocheng/decode_status.h"
#include "kocheng/communication.h"
#include "sensor_msgs/NavSatFix.h"
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "../../include/kocheng/hehe.hpp"

using namespace std;

void rc_mission_cb	(const kocheng::mission_status& data);
void globalPositionCB(const sensor_msgs::NavSatFix& msg);

sensor_msgs::NavSatFix	global_position;
kocheng::decode_status heartbeat_status_decode;
kocheng::communication heartbeat_payload_string;

ros::Publisher pub_run_status;
ros::Publisher pub_payload_status;

int main(int argc, char **argv){
	
	getTime time_lord;
	
	ros::init(argc, argv, "heartbeat");
	ros::NodeHandle heartbeat_nh;

	pub_run_status		= heartbeat_nh.advertise<kocheng::decode_status>("/auvsi/run_course/status", 16);
	pub_payload_status	= heartbeat_nh.advertise<kocheng::communication>("/auvsi/communication/status", 16);
	
	ros::Subscriber sub_mission_rc	 	= heartbeat_nh.subscribe("/auvsi/rc/mission", 16, rc_mission_cb);
	ros::Subscriber sub_global_position = heartbeat_nh.subscribe("/mavros/global_position/global", 1, globalPositionCB);
	
	HeartbeatMessage auvsi_protocol(server_ip, server_port, course_type, team_code);
	
	ros::Rate loop_rate(1);

	/*	Do not wait for data, always sent data no matter what the data is.
	while(ros::ok() && (challenge_status.compare("idle") == 0 || global_position.latitude == 0 || global_position.longitude == 0)){
		ros::spinOnce();
	}
	*/

	ROS_INFO("Starting Heartbeat.");

	while(ros::ok()){
		auvsi_protocol.setPayloadCommunication(time_lord.getYMDHS(), challenge_status, global_position.latitude,global_position.longitude);
		auvsi_protocol.sendTCP();
		heartbeat_payload_string.heartbeat_payload=auvsi_protocol.getPayload();
		//cout << auvsi_protocol.getRespone();
		heartbeat_status_decode.heartbeat_status = auvsi_protocol.decodeResponeStatus();
		//ROS_INFO_STREAM("Response code : "<<heartbeat_status.data);
		pub_run_status.publish(heartbeat_status_decode);
		pub_payload_status.publish(heartbeat_payload_string);
		ros::spinOnce();
		loop_rate.sleep();
	}

	return 0;
}

void rc_mission_cb	(const kocheng::mission_status& data){
	challenge_status = data.mission_makara;
}

void globalPositionCB(const sensor_msgs::NavSatFix& msg){
	global_position.latitude 	= msg.latitude;
	global_position.longitude 	= msg.longitude;
	global_position.altitude 	= msg.altitude;
}
