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

#include "mavros_msgs/GlobalPositionTarget.h"

#include "sensor_msgs/NavSatFix.h"

using namespace std;


void pid_receiver_cb	(const pid::controller_msg& control);
void rc_mission_cb		(const kocheng::mission_status& data);
void gps_rc_cb			(const sensor_msgs::NavSatFix& data);
void compass_rc_cb		(const std_msgs::Float64& msg);
void image_out_cb		(const kocheng::image_out& image);

pid::plant_msg  pid_in;
pid::pid_const_msg pid_const;

kocheng::override_motor controller;
kocheng::mission_status	mission;
kocheng::debug_mission	debug;
kocheng::image_in image_in;

int state_x, state_y, throttle_pwm, steer_pwm, control_effort;

int drone_pwm, camera_pwm;

float latitude, longitude;

double compass_hdg, compass_init, compass_end;

string receive_mission;


float longitude_speed_end;
float latitude_speed_end;
int main(int argc, char **argv){
	ros::init(argc, argv, "speed");
	ros::NodeHandle nh;
	
	ROS_WARN("NC : speed.cpp active");
	
	ros::Publisher pub_debug_rc 	= nh.advertise<kocheng::debug_mission>("/auvsi/debug/rc", 10);
	ros::Publisher pub_override_rc 	= nh.advertise<kocheng::override_motor>("/auvsi/override/motor", 10);
	ros::Publisher pub_pid_in 		= nh.advertise<pid::plant_msg>("/auvsi/pid/inX", 1);
	ros::Publisher pub_pid_const 	= nh.advertise<pid::pid_const_msg>("/auvsi/pid/constX", 1,true);
	ros::Publisher pub_mission_rc 	= nh.advertise<kocheng::mission_status>("/auvsi/rc/mission", 1);
	ros::Publisher pub_image_in 	= nh.advertise<kocheng::image_in>("/auvsi/image/in", 1);
	
	ros::Subscriber sub_mission_rc 	= nh.subscribe("/auvsi/rc/mission", 1, rc_mission_cb);
	ros::Subscriber sub_pid_x_out 	= nh.subscribe("/auvsi/pid/outX", 10, pid_receiver_cb );
	ros::Subscriber sub_gps_cb		= nh.subscribe("/mavros/global_position/global", 1, gps_rc_cb);
	ros::Subscriber sub_compass_cb		= nh.subscribe("/mavros/global_position/compass_hdg", 8, compass_rc_cb);
	ros::Subscriber sub_image_out	= nh.subscribe("/auvsi/image/out", 8, image_out_cb);
	
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
			
			image_in.x_init	= x_speed;
			image_in.y_init	= y_speed;
			image_in.width	= width_speed;
			image_in.height	= height_speed;
			image_in.LowH	= LowH_speed;
			image_in.HighH	= HighH_speed;
			image_in.LowS	= LowS_speed;
			image_in.HighS	= HighS_speed;
			image_in.LowV	= LowV_speed;
			image_in.HighV	= HighV_speed;
			image_in.Noise	= Noise_speed;
			pub_image_in.publish(image_in);
	
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
				
				pid_in.x 		= state_x;
				pid_in.t 		= pid_in.t+delta_t;
				pid_in.setpoint = setpoint_speed;
				pub_pid_in.publish(pid_in);
			
				ros::spinOnce();
				throttle_pwm 	= THROT_SPEED;
				steer_pwm 		= MIDDLE_PWM - control_effort;
			
				camera_pwm=CAM_INIT_PWM;
				drone_pwm=DRONE_INIT_PWM;
			
				if(state_x==0){
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
			
			image_in.x_init	= x_speed_new;
			image_in.y_init	= y_speed_new;
			image_in.width	= width_speed_new;
			image_in.height	= height_speed_new;
			image_in.LowH	= LowH_speed_new;
			image_in.HighH	= HighH_speed_new;
			image_in.LowS	= LowS_speed_new;
			image_in.HighS	= HighS_speed_new;
			image_in.LowV	= LowV_speed_new;
			image_in.HighV	= HighV_speed_new;
			image_in.Noise	= Noise_speed_new;
			pub_image_in.publish(image_in);
			ros::spinOnce();
			
			pid_const.p = kp_speed_new;
			pid_const.i = ki_speed_new;
			pid_const.d = kd_speed_new;
			pub_pid_const.publish(pid_const);
			ros::spinOnce();
			
			while(receive_mission=="speed.step_2"){
				ros::spinOnce();
				pid_in.x 		= state_x;
				pid_in.t 		= pid_in.t+delta_t;
				pid_in.setpoint = setpoint_speed_new;
				pub_pid_in.publish(pid_in);
			
				ros::spinOnce();
				throttle_pwm 	= THROT_SPEED;
				steer_pwm 		= MIDDLE_PWM - control_effort;
			
				camera_pwm	= CAM_INIT_PWM;
				drone_pwm	= DRONE_INIT_PWM;
			
				if(state_x==0){
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
void image_out_cb(const kocheng::image_out& image){
	state_x = image.state_x;
	state_y = image.state_y;
}
