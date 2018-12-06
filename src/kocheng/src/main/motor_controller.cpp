#include "../../include/kocheng/hehe.hpp"
#include "ros/ros.h"
#include "mavros_msgs/OverrideRCIn.h"
#include "kocheng/override_motor.h"
#include "kocheng/rc_number.h"
#include <iostream>

bool override_status = false;

int steering;
int throttle;
int cam_servo=CAM_INIT_PWM;
int drone_servo=DRONE_INIT_PWM;

ros::Publisher pub_override_rc;
ros::Subscriber sub_override_motor;
ros::Subscriber sub_override_status;

mavros_msgs::OverrideRCIn override_out;

void override_input_cb(const kocheng::override_motor& override_recv);
void override_status_cb(const kocheng::rc_number& override_status_recv);

int main(int argc, char **argv)
{
  ros::init(argc, argv, "motor_controller");
  ros::NodeHandle n;

  pub_override_rc = n.advertise<mavros_msgs::OverrideRCIn>("/mavros/rc/override", 10);
  
  sub_override_motor = n.subscribe("/auvsi/override/motor", 8, override_input_cb);
  sub_override_status = n.subscribe("/auvsi/rc/number", 8, override_status_cb);
  
  ROS_WARN("NC : motor_controller.cpp active");
  
  override_out.channels[DRONE_SERVO] = cam_servo;
  override_out.channels[CAMERA_SERVO] = drone_servo;
  pub_override_rc.publish(override_out);
	
	while(ros::ok()){
		sleep(0.2);
		ros::spinOnce();
		while(override_status == true){
			for(int i=0; i < 8; i++) override_out.channels[i] = 0;
			//ROS_ERROR("1");
			if (throttle > MAX_THROTTLE){
				override_out.channels[THROTTLE] = MAX_THROTTLE;
			}
			else if (throttle < MIN_THROTTLE){
				override_out.channels[THROTTLE] = MIN_THROTTLE;
			}
			else {
				override_out.channels[THROTTLE]=throttle;
			}

			if (steering > MAX_STEERING){
				override_out.channels[STEERING] = MAX_STEERING;
			}
			else if (steering < MIN_STEERING){
				override_out.channels[STEERING] = MIN_STEERING;
			}
			else {
				override_out.channels[STEERING] = steering;
			}
			override_out.channels[DRONE_SERVO] = drone_servo;
			override_out.channels[CAMERA_SERVO] = cam_servo;
			pub_override_rc.publish(override_out);
		}
	}
}

void override_status_cb(const kocheng::rc_number& override_status_recv){
	override_status = override_status_recv.override_status;
}

void override_input_cb(const kocheng::override_motor& override_recv){
	throttle=override_recv.throttle;
	steering=override_recv.steering;
	cam_servo=override_recv.camera_servo;
	drone_servo=override_recv.drone_servo;
}
