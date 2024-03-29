#include "../../include/kocheng/hehe.hpp"
#include <ros/ros.h>

#include "pid/plant_msg.h"
#include "pid/controller_msg.h"
#include "pid/pid_const_msg.h"

#include "kocheng/override_value.h"
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
void image_out_cb		(const kocheng::image_out& image);

pid::plant_msg  pid_in;
pid::pid_const_msg pid_const;

kocheng::override_value controller;
kocheng::mission_status	mission;
kocheng::debug_mission	debug;
kocheng::image_in image_in;

int state_x, state_y, throttle_pwm, steer_pwm, control_effort;

int camera_pwm;

float latitude, longitude;

string receive_mission;

float longitude_nav_end;
float latitude_nav_end;


int main(int argc, char **argv){
	ros::init(argc, argv, "navigation");
	ros::NodeHandle nh;
	
	ROS_WARN("NC : navigation.cpp active");
	
	ros::Publisher pub_debug_rc 	= nh.advertise<kocheng::debug_mission>("/auvsi/debug/rc", 10);
	ros::Publisher pub_override_rc 	= nh.advertise<kocheng::override_value>("/auvsi/rc/value", 10);
	ros::Publisher pub_mission_rc 	= nh.advertise<kocheng::mission_status>("/auvsi/rc/mission", 1);
	
	ros::Publisher pub_pid_in 		= nh.advertise<pid::plant_msg>("/auvsi/pid/inX", 1);
	ros::Publisher pub_pid_const 	= nh.advertise<pid::pid_const_msg>("/auvsi/pid/constX", 1,true);
	
	ros::Publisher pub_image_in 	= nh.advertise<kocheng::image_in>("/auvsi/image/in", 1);
	
	ros::Subscriber sub_mission_rc 	= nh.subscribe("/auvsi/rc/mission", 1, rc_mission_cb);
	ros::Subscriber sub_pid_x_out 	= nh.subscribe("/auvsi/pid/outX", 10, pid_receiver_cb );
	
	ros::Subscriber sub_gps_cb		= nh.subscribe("/mavros/global_position/global", 1, gps_rc_cb);
	
	ros::Subscriber sub_image_out	= nh.subscribe("/auvsi/image/out", 8, image_out_cb);

	if(course_type.compare("courseA")==0){
		longitude_nav_end	= longitude_nav_end_A;
		latitude_nav_end	= latitude_nav_end_A;
	}
	else if(course_type.compare("courseB")==0){
		longitude_nav_end	= longitude_nav_end_B;
		latitude_nav_end	= latitude_nav_end_B;
	}
	else if(course_type.compare("courseC")==0){
		longitude_nav_end	= longitude_nav_end_C;
		latitude_nav_end	= latitude_nav_end_C;
	}
	else if(course_type.compare("courseUI")==0){
		longitude_nav_end	= longitude_nav_end_UI;
		latitude_nav_end	= latitude_nav_end_UI;
	}

	
	while (ros::ok()) {
		ros::spinOnce();
		while(receive_mission=="navigation.start"){
			//ROS_ERROR("2");
			image_in.x_init	= x_nav;
			image_in.y_init	= y_nav;
			image_in.width	= width_nav;
			image_in.height	= height_nav;
			image_in.LowH	= LowH_nav;
			image_in.HighH	= HighH_nav;
			image_in.LowS	= LowS_nav;
			image_in.HighS	= HighS_nav;
			image_in.LowV	= LowV_nav;
			image_in.HighV	= HighV_nav;
			image_in.Noise	= Noise_nav;
			pub_image_in.publish(image_in);
	
			pid_const.p = kp_nav;
			pid_const.i = ki_nav;
			pid_const.d = kd_nav;
			pub_pid_const.publish(pid_const);
			
			pid_in.x		= state_x;
			pid_in.t 		= pid_in.t+delta_t;
			pid_in.setpoint = setpoint_nav;
			pub_pid_in.publish(pid_in);
			
			ros::spinOnce();
			throttle_pwm 	= THROT_NAV;
			steer_pwm 		= MIDDLE_PWM - control_effort;
			
			camera_pwm		= CAM_INIT_PWM;
			
			if(state_x==0){
				steer_pwm=MIDDLE_PWM;
			}
			
			//cout<<steer_pwm<<"	"<<throttle_pwm<<endl;
			controller.camera_servo = camera_pwm;
			controller.steering 	= steer_pwm;
			controller.throttle 	= throttle_pwm;
			pub_override_rc.publish(controller);
		
			debug.longitude			= longitude_nav_end;
			debug.latitude			= latitude_nav_end;
			pub_debug_rc.publish(debug);

			if(longitude<longitude_nav_end+tolerance_nav && longitude>longitude_nav_end-tolerance_nav &&
			latitude<latitude_nav_end+tolerance_nav && latitude>latitude_nav_end-tolerance_nav){
				mission.mission_makara="navigation.end";
				pub_mission_rc.publish(mission);
			}
		}
	}
}

void image_out_cb(const kocheng::image_out& image){
	state_x = image.state_x;
	state_y = image.state_y;
}

void pid_receiver_cb(const pid::controller_msg& control){
	control_effort = control.u;
}

void rc_mission_cb	(const kocheng::mission_status& data){
	receive_mission = data.mission_makara;
}
void gps_rc_cb		(const sensor_msgs::NavSatFix& data){
	latitude	= data.latitude;
	longitude	= data.longitude;
}
