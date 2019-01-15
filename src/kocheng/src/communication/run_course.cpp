#include "ros/ros.h"
#include <string>
#include "sensor_msgs/NavSatFix.h"
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "kocheng/mission_status.h"
#include "kocheng/decode_status.h"
#include "kocheng/communication.h"
#include "../../include/kocheng/hehe.hpp"

using namespace std;

void rc_mission_cb(const kocheng::mission_status& msg);

kocheng::communication run_course_payload_string;

ros::Publisher pub_run_status;
ros::Publisher pub_mission_rc;
ros::Publisher pub_payload_status;

StartEndRunMessage auvsi_protocol(server_ip, server_port, course_type, team_code);

int main(int argc, char **argv){

	ros::init(argc, argv, "run_course");
	ros::NodeHandle run_course_nh;

	auvsi_protocol.setRemoteTarget(server_ip, server_port);
	auvsi_protocol.setTeamCode(team_code);
	auvsi_protocol.setCourseType(course_type);

	pub_run_status		= run_course_nh.advertise<kocheng::decode_status>("/auvsi/run_course/status", 16);
	pub_mission_rc 		= run_course_nh.advertise<kocheng::mission_status>("/auvsi/rc/mission", 16);
	pub_payload_status	= run_course_nh.advertise<kocheng::communication>("/auvsi/communication/status", 16);
	
	ros::Subscriber sub_mission_rc	 	= run_course_nh.subscribe("/auvsi/rc/mission", 16, rc_mission_cb);

	ROS_INFO("Starting Run Course.");

	ros::spin();
	return 0;
}

void rc_mission_cb(const kocheng::mission_status& msg){

	//ROS_INFO_STREAM("[RC] Receive command : "<< msg.data);
	
	kocheng::decode_status response_status;
	kocheng::mission_status node_select;
	
	if (msg.mission_makara.compare("start_run") == 0){
		auvsi_protocol.setPayloadCommunication(communicationType::start_run);
		//cout << auvsi_protocol.getPayload();
		//ROS_INFO_STREAM("\n\n[RC] Sending\n\n" << auvsi_protocol.getPayload());
		
		auvsi_protocol.sendTCP();
		//ROS_INFO_STREAM("[RC] Receiving\n\n" << auvsi_protocol.getResponse());
		response_status.run_course_status = auvsi_protocol.decodeResponeStatus();
		pub_run_status.publish(response_status);

		if(response_status.run_course_status == 200){
			node_select.mission_makara = "nc:node_select.start_run.ok";
			pub_mission_rc.publish(node_select);
		}
		else{
			node_select.mission_makara = "nc:node_select.start_run.error";
			pub_mission_rc.publish(node_select);
		}
		
		run_course_payload_string.run_course_payload=auvsi_protocol.getPayload();
		pub_payload_status.publish(run_course_payload_string);

		//cout << auvsi_protocol.getRespone();

		//ROS_INFO_STREAM("[RC] Response code : "<< "start_run." << response_status.data);
	}

	else if (msg.mission_makara.compare("end_run") == 0){
		auvsi_protocol.setPayloadCommunication(communicationType::end_run);
		//cout << auvsi_protocol.getPayload();
		//ROS_INFO_STREAM("\n\n[RC] Sending\n\n" << auvsi_protocol.getPayload());
		
		auvsi_protocol.sendTCP();
		//ROS_INFO_STREAM("[RC] Receiving\n\n" << auvsi_protocol.getResponse());
		response_status.run_course_status = auvsi_protocol.decodeResponeStatus();
		pub_run_status.publish(response_status);
		
		if(response_status.run_course_status == 200){
			node_select.mission_makara = "nc:node_select.end_run.ok";
			pub_mission_rc.publish(node_select);
		}
		else{
			node_select.mission_makara = "nc:node_select.end_run.error";
			pub_mission_rc.publish(node_select);
		}
		
		run_course_payload_string.run_course_payload=auvsi_protocol.getPayload();
		pub_payload_status.publish(run_course_payload_string);

		//cout << auvsi_protocol.getRespone();

		//ROS_INFO_STREAM("[RC] Response code : "<< "end_run." << response_status.data);
	}
}
