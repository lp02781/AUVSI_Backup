#include "../../include/roboboat/haha.hpp"
#include "ros/ros.h"
#include "mavros_msgs/OverrideRCIn.h"
#include "roboboat/override_motor.h"
#include "roboboat/node_master.h"
#include "roboboat/image_process.h"
#include "roboboat/setpoint.h"
#include <iostream>
#include "pid/plant_msg.h"
#include "pid/controller_msg.h"
#include "pid/pid_const_msg.h"

bool simple_status = false;
int state;
int red_x;
int green_x;
int count_red;
int count_green;
int steer_pwm;
int throttle_pwm;
int control_effort;

void pid_status_cb(const roboboat::node_master& pid_status_recv);
void image_process_cb(const roboboat::image_process& image);
void pid_receiver_cb(const pid::controller_msg& control);
void get_state();

roboboat::override_motor controller;
roboboat::setpoint point;
ros::Publisher pub_override_rc;

pid::plant_msg  pid_in;
pid::pid_const_msg pid_const;

int main(int argc, char **argv)
{
	ros::init(argc, argv, "pid_controller");
	ros::NodeHandle n;

	pub_override_rc 				= n.advertise<roboboat::override_motor>("/auvsi/override/motor", 10);
	ros::Publisher pub_pid_in 		= n.advertise<pid::plant_msg>("/auvsi/pid/in", 1);
	ros::Publisher pub_pid_const 	= n.advertise<pid::pid_const_msg>("/auvsi/pid/const", 1,true);
	ros::Publisher pub_setpoint 	= n.advertise<roboboat::setpoint>("/auvsi/image/setpoint", 1,true);

	ros::Subscriber sub_pid_x_out 		= n.subscribe("/auvsi/pid/out", 10, pid_receiver_cb );
	ros::Subscriber sub_image_process 	= n.subscribe("/auvsi/image/process", 1, image_process_cb);
	ros::Subscriber sub_pid_status 		= n.subscribe("/auvsi/node/master", 1, pid_status_cb);
	
	ROS_WARN("NC : pid_controller.cpp active");
	
	pid_const.p = kp;
	pid_const.i = ki;
	pid_const.d = kd;
	pub_pid_const.publish(pid_const);
	
	pid_in.t = initial_time;
	
	while(ros::ok()){
		sleep(0.5);
		ros::spinOnce();
	
		get_state();
	
		if(simple_status == true){
			point.setpoint = red_setpoint;
			pub_setpoint.publish(point);
		
			pid_in.x = state;
			pid_in.t = pid_in.t+delta_t;
			pid_in.setpoint = red_setpoint;
			pub_pid_in.publish(pid_in);
			
			ros::spinOnce();
			
			//ROS_ERROR("%d", state);
			
			if(state < red_setpoint && state >= noise_state){ //turn left
				controller.header = left_header;
				throttle_pwm = MIDDLE_PWM + CHANGE_THROTTLE;
				steer_pwm = MIDDLE_PWM + control_effort;
				//ROS_ERROR("1");
			}
			else if(state > red_setpoint && state >= noise_state){ //turn right
				controller.header = right_header;
				throttle_pwm = MIDDLE_PWM + CHANGE_THROTTLE;
				steer_pwm = MIDDLE_PWM + control_effort;
				//ROS_ERROR("2");
			}
			
			else if(red_x == 0 && green_x !=0){
				controller.header = left_header;
				throttle_pwm = MIDDLE_PWM + CHANGE_THROTTLE;
				steer_pwm = MIDDLE_PWM - CHANGE_STEER;
			}
			
			else if(red_x != 0 && green_x ==0){
				controller.header = right_header;
				throttle_pwm = MIDDLE_PWM + CHANGE_THROTTLE;
				steer_pwm = MIDDLE_PWM + CHANGE_STEER;
			}
			
			else {											//just go away
				controller.header = center_header;
				throttle_pwm = MIDDLE_PWM + CHANGE_THROTTLE;
				steer_pwm = MIDDLE_PWM;
				//ROS_ERROR("3");
			}
		}
		controller.steering = steer_pwm;
		controller.throttle = throttle_pwm;
		pub_override_rc.publish(controller);	
	}
}

void get_state(){
	state = red_x;
}
void image_process_cb(const roboboat::image_process& image){
	red_x 		= image.state_red;
	green_x 	= image.state_green;
	count_red 	= image.count_red;
	count_green	= image.count_green;
}

void pid_status_cb(const roboboat::node_master& pid_status_recv){
	simple_status = pid_status_recv.simple_manuver;
}

void pid_receiver_cb(const pid::controller_msg& control){
	control_effort = control.u;
}
