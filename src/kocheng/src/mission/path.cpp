#include "../../include/kocheng/hehe.hpp"
#include <ros/ros.h>
#include "std_msgs/Int32MultiArray.h"
#include "kocheng/override_value.h"
#include "kocheng/mission_status.h"

using namespace std;

void rc_mission_cb		(const kocheng::mission_status& data);
void ardu_srf_cb		(const std_msgs::Int32MultiArray& data);

kocheng::override_value controller;
kocheng::mission_status	mission;

int throttle_pwm, steer_pwm;

int camera_pwm;

int srf_1, srf_2, srf_3, srf_4;

string receive_mission;

int main(int argc, char **argv){
	ros::init(argc, argv, "navigation");
	ros::NodeHandle nh;
	
	ROS_WARN("NC : navigation.cpp active");
	
	ros::Publisher pub_override_rc 	= nh.advertise<kocheng::override_value>("/auvsi/rc/value", 10);
	ros::Publisher pub_mission_rc 	= nh.advertise<kocheng::mission_status>("/auvsi/rc/mission", 1);
	
	ros::Subscriber sub_mission_rc 	= nh.subscribe("/auvsi/rc/mission", 1, rc_mission_cb);
	ros::Subscriber sub_ardu_srf = nh.subscribe("/auvsi/ardu/srf", 1, ardu_srf_cb);
	
	while (ros::ok()) {
		ros::spinOnce();
		while(receive_mission=="path.start"){
			ros::spinOnce();
			throttle_pwm 	= THROT_PATH;
			
			camera_pwm		= CAM_INIT_PWM;
			if(srf_1<30){
				throttle_pwm+=50;
			}		
			if(srf_1<30){
				throttle_pwm+=50;
			}
			if(srf_1<30){
				throttle_pwm-=50;
			}
			if(srf_1<30){
				throttle_pwm-=50;
			}
			
			controller.camera_servo = camera_pwm;
			controller.steering 	= steer_pwm;
			controller.throttle 	= throttle_pwm;
			pub_override_rc.publish(controller);

			if(srf_1 >30&&srf_2 >30&&srf_3 >30&&srf_4 >30){
				mission.mission_makara="path.end";
				pub_mission_rc.publish(mission);
			}
		}
	}
}

void rc_mission_cb	(const kocheng::mission_status& data){
	receive_mission = data.mission_makara;
}

void ardu_srf_cb	(const std_msgs::Int32MultiArray& data){
	srf_1=data.data[0];
	srf_2=data.data[1];
	srf_3=data.data[2];
	srf_4=data.data[3];
}
