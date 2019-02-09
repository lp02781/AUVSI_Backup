#include "../../include/kocheng/hehe.hpp"
#include <ros/ros.h>

#include "std_msgs/Float64.h"

#include "pid/plant_msg.h"
#include "pid/controller_msg.h"
#include "pid/pid_const_msg.h"

#include "kocheng/override_motor.h"
#include "kocheng/mission_status.h"
#include "kocheng/debug_mission.h"
#include "kocheng/image_in.h"
#include "kocheng/image_out.h"
#include "kocheng/decode_status.h"
#include "kocheng/communication.h"

#include "mavros_msgs/GlobalPositionTarget.h"
#include "sensor_msgs/NavSatFix.h"

using namespace std;

void pid_receiver_x_cb	(const pid::controller_msg& control);
void pid_receiver_y_cb	(const pid::controller_msg& control);
void rc_mission_cb		(const kocheng::mission_status& data);
void gps_rc_cb			(const sensor_msgs::NavSatFix& data);
void image_out_cb		(const kocheng::image_out& image);
void compass_rc_cb		(const std_msgs::Float64& msg);

pid::plant_msg  pid_in_x;
pid::pid_const_msg pid_const_x;
pid::plant_msg  pid_in_y;
pid::pid_const_msg pid_const_y;

kocheng::override_motor controller;
kocheng::mission_status	mission;
kocheng::debug_mission	debug;
kocheng::image_in image_in;
kocheng::decode_status follow_status_decode;
kocheng::communication follow_payload_string;

int state_x, state_y, throttle_pwm, steer_pwm, control_effort_x, control_effort_y;

int drone_pwm, camera_pwm;

float latitude, longitude;

string receive_mission;

double compass_hdg, compass_init, compass_end;

float longitude_follow_end;
float latitude_follow_end;

MissionMessage follow_communication(server_ip, server_port, course_type, team_code);

int main(int argc, char **argv){
	ros::init(argc, argv, "follow");
	ros::NodeHandle nh;
	
	ROS_WARN("NC : folow.cpp active");
	
	ros::Publisher pub_debug_rc 	= nh.advertise<kocheng::debug_mission>("/auvsi/debug/rc", 10);
	ros::Publisher pub_override_rc 	= nh.advertise<kocheng::override_motor>("/auvsi/override/motor", 10);
	ros::Publisher pub_mission_rc 	= nh.advertise<kocheng::mission_status>("/auvsi/rc/mission", 1);
	
	ros::Publisher pub_pid_in_x 	= nh.advertise<pid::plant_msg>("/auvsi/pid/inX", 1);
	ros::Publisher pub_pid_const_x 	= nh.advertise<pid::pid_const_msg>("/auvsi/pid/constX", 1,true);
	ros::Publisher pub_pid_in_y 	= nh.advertise<pid::plant_msg>("/auvsi/pid/inY", 1);
	ros::Publisher pub_pid_const_y 	= nh.advertise<pid::pid_const_msg>("/auvsi/pid/constY", 1,true);
	
	ros::Publisher pub_image_in 	= nh.advertise<kocheng::image_in>("/auvsi/image/in", 1);
	
	ros::Publisher pub_run_status		= nh.advertise<kocheng::decode_status>("/auvsi/run_course/status", 16);
	ros::Publisher pub_payload_status	= nh.advertise<kocheng::communication>("/auvsi/communication/status", 16);
	
	ros::Subscriber sub_compass_cb		= nh.subscribe("/mavros/global_position/compass_hdg", 8, compass_rc_cb);
	ros::Subscriber sub_mission_rc 	= nh.subscribe("/auvsi/rc/mission", 1, rc_mission_cb);
	
	ros::Subscriber sub_pid_x_out 	= nh.subscribe("/auvsi/pid/outX", 10, pid_receiver_x_cb );
	ros::Subscriber sub_pid_y_out 	= nh.subscribe("/auvsi/pid/outy", 10, pid_receiver_y_cb );
	
	ros::Subscriber sub_gps_cb		= nh.subscribe("/mavros/global_position/global", 1, gps_rc_cb);
	
	ros::Subscriber sub_image_out	= nh.subscribe("/auvsi/image/out", 8, image_out_cb);

	if(course_type.compare("courseA")==0){
		longitude_follow_end	= longitude_follow_end_A;
		latitude_follow_end		= latitude_follow_end_A;
	}
	else if(course_type.compare("courseB")==0){
		longitude_follow_end	= longitude_follow_end_B;
		latitude_follow_end		= latitude_follow_end_B;
	}
	else if(course_type.compare("courseC")==0){
		longitude_follow_end	= longitude_follow_end_C;
		latitude_follow_end		= latitude_follow_end_C;
	}
	else if(course_type.compare("courseUI")==0){
		longitude_follow_end	= longitude_follow_end_UI;
		latitude_follow_end		= latitude_follow_end_UI;
	}
	
	while (ros::ok()) {
		ros::spinOnce();
		while(receive_mission=="follow.start"){
			compass_init	= compass_hdg;
			compass_end		= compass_init+compass_point_follow;
			
			follow_communication.setPayloadCommunication(follow);
			follow_communication.sendTCP();
			//follow_communication.getPayload();
			ros::spinOnce();
			follow_payload_string.follow_payload	= follow_communication.getPayload();
			follow_status_decode.follow_status	= follow_communication.decodeResponeStatus();
			
			pub_run_status.publish(follow_status_decode);
			pub_payload_status.publish(follow_payload_string);
			
			image_in.x_init	= x_follow;
			image_in.y_init	= y_follow;
			image_in.width	= width_follow;
			image_in.height	= height_follow;
			image_in.LowH	= LowH_follow;
			image_in.HighH	= HighH_follow;
			image_in.LowS	= LowS_follow;
			image_in.HighS	= HighS_follow;
			image_in.LowV	= LowV_follow;
			image_in.HighV	= HighV_follow;
			image_in.Noise	= Noise_follow;
			pub_image_in.publish(image_in);
			
			pid_const_x.p = kp_follow_x;
			pid_const_x.i = ki_follow_x;
			pid_const_x.d = kd_follow_x;
			pub_pid_const_x.publish(pid_const_x);
			pid_const_y.p = kp_follow_y;
			pid_const_y.i = ki_follow_y;
			pid_const_y.d = kd_follow_y;
			pub_pid_const_y.publish(pid_const_y);
			
			mission.mission_makara="follow.step_1";
			pub_mission_rc.publish(mission);
			ros::spinOnce();
			
			while(receive_mission=="follow.step_1"){
				pid_in_x.x		= state_x;
				pid_in_x.t 		= pid_in_x.t+delta_t;
				pid_in_x.setpoint = setpoint_follow_x;
				
				pid_in_y.x		= state_y;
				pid_in_y.t 		= pid_in_y.t+delta_t;
				pid_in_y.setpoint = setpoint_follow_y;
			
				pub_pid_in_x.publish(pid_in_x);
				pub_pid_in_y.publish(pid_in_y);
			
				ros::spinOnce();
			
				throttle_pwm 	= THROT_NAV - control_effort_y;
				steer_pwm 		= MIDDLE_PWM - control_effort_x;
			
				camera_pwm		= CAM_FOLLOW_PWM;
				drone_pwm		= DRONE_INIT_PWM;
			
				if(state_x==0){
					steer_pwm=MIDDLE_PWM;
				}
				if(state_y==0){
					throttle_pwm=THROT_FOLLOW;
				}
			
				controller.drone_servo 	= drone_pwm;
				controller.camera_servo = camera_pwm;
				controller.steering 	= steer_pwm;
				controller.throttle 	= throttle_pwm;
				pub_override_rc.publish(controller);
		
				if(compass_hdg < compass_end-compass_tolerance && compass_hdg > compass_end+compass_tolerance){
					mission.mission_makara="follow.end";
					pub_mission_rc.publish(mission);
				}
			}
		}
	}
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

void rc_mission_cb	(const kocheng::mission_status& data){
	receive_mission = data.mission_makara;
}
void gps_rc_cb		(const sensor_msgs::NavSatFix& data){
	latitude	= data.latitude;
	longitude	= data.longitude;
}

void compass_rc_cb(const std_msgs::Float64& msg){
	compass_hdg = msg.data;
}
