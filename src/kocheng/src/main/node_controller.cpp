#include "../../include/kocheng/hehe.hpp"
#include <ros/ros.h>

#include "mavros_msgs/SetMode.h"
#include "mavros_msgs/State.h"

#include "kocheng/rc_number.h"
#include "kocheng/mission_status.h"
#include "kocheng/com_auvsi.h"

#include <std_msgs/Int32.h>

using namespace std;

int rc_flag_in;
string receive_mission;

ros::ServiceClient client_set_flightmode;
kocheng::mission_status	mission;
kocheng::com_auvsi com;
std_msgs::Int32	mode;

void rc_number_cb			(const kocheng::rc_number& number);
void rc_mission_cb			(const kocheng::mission_status& data);
void waypoint_running		(string waypoint);
void mission_running		(string mission_name);
void mission_waypoint_running(string waypoint);
bool changeFlightMode		(const char* flight_mode);
bool changeFlightModeDebug	(string fm);

ros::Subscriber sub_mission_rc;
ros::Publisher pub_mission_rc;
ros::Publisher pub_com_rc;

int main(int argc, char **argv)
{
	ros::init(argc, argv, "node_controller");
	ros::NodeHandle nh;
	
	pub_mission_rc 					= nh.advertise<kocheng::mission_status>("/auvsi/rc/mission", 1);
	pub_com_rc 						= nh.advertise<kocheng::com_auvsi>("/auvsi/rc/com", 1);
	ros::Publisher pub_mode_rc 		= nh.advertise<std_msgs::Int32>("/auvsi/ardu/status", 1);
	sub_mission_rc	 				= nh.subscribe("/auvsi/rc/mission", 1, rc_mission_cb);
	ros::Subscriber sub_rc_number 	= nh.subscribe("/auvsi/rc/number", 8, rc_number_cb);
	client_set_flightmode 			= nh.serviceClient<mavros_msgs::SetMode>("/mavros/set_mode");
	
	ROS_WARN("NC : node_controller.cpp active");
	
	while(ros::ok()){
		ros::spinOnce();
		sleep(0.2);
		if(rc_flag_in == first_simple ){
			
			ROS_ERROR("2");
			mode.data=2;
			pub_mode_rc.publish(mode);
			
			mission.mission_makara = "start_run";
			pub_mission_rc.publish(mission);
			
			waypoint_running("navigation_gate");
			//mission_waypoint_running("navigation");
			
			//waypoint_running("speed_gate");
			//mission_waypoint_running("speed");
			
			//waypoint_running("path_gate");
			//mission_waypoint_running("path");
			
			
			
			
			
			
			//waypoint_running("follow_gate");
			//mission_running("follow");
			
			/*
			waypoint_running("docking_gate");
			mission_waypoint_running("docking");
			
			waypoint_running("push_gate");
			mission_running("push");
			*/
			
			//waypoint_running("return");
						
			mission.mission_makara = "end_run";
			pub_mission_rc.publish(mission);
			
			ros::spinOnce();
			
			/*
			ROS_ERROR("1");
			mode.data=1;
			pub_mode_rc.publish(mode);
			
			mission.mission_makara = "start_run";
			pub_mission_rc.publish(mission);
			
			//waypoint_running("navigation_gate");
			//mission_running("navigation");
			
			//waypoint_running("speed_gate");
			mission_running("speed");
			
			waypoint_running("path_gate");
			mission_running("path");
			
			//waypoint_running("follow_gate");
			//mission_running("follow");
			
			waypoint_running("docking_gate");
			mission_running("docking");
			
			waypoint_running("push_gate");
			mission_running("push");
			
			waypoint_running("return");
						
			mission.mission_makara = "end_run";
			pub_mission_rc.publish(mission);
			*/
		}
		
		else if(rc_flag_in == second_simple){
			ROS_ERROR("2");
			mode.data=2;
			pub_mode_rc.publish(mode);
			
			mission.mission_makara = "start_run";
			pub_mission_rc.publish(mission);
			
			waypoint_running("navigation_gate");
			mission_waypoint_running("navigation");
			
			waypoint_running("speed_gate");
			mission_waypoint_running("speed");
			
			waypoint_running("path_gate");
			mission_waypoint_running("path");
			
			//waypoint_running("follow_gate");
			//mission_running("follow");
			
			/*
			waypoint_running("docking_gate");
			mission_waypoint_running("docking");
			
			waypoint_running("push_gate");
			mission_running("push");
			*/
			waypoint_running("return");
						
			mission.mission_makara = "end_run";
			pub_mission_rc.publish(mission);
			
			ros::spinOnce();
		}
		
		else if(rc_flag_in == zero_flag){
			mode.data=0;
			pub_mode_rc.publish(mode);
			
			changeFlightModeDebug("MANUAL");
			mission.mission_makara=mission_idle;
			pub_mission_rc.publish(mission);
			sleep(0.2);
		}
	}
}

void mission_waypoint_running(string waypoint){
	if(receive_mission != mission_idle){
		sleep(1);
		com.mission_makara = waypoint;
		pub_com_rc.publish(com);
		
		sleep(1);
		changeFlightModeDebug("HOLD");
		sleep(1);
		string waypoint_start = waypoint+".start";
		mission.mission_makara = waypoint_start;
		pub_mission_rc.publish(mission);
		sleep(1);
		system("rosrun mavros mavwp clear"); //clear wp
		string command = "rosrun mavros mavwp load ~/waypoints/"+course_type+"_"+waypoint+".waypoints";
		system(command.c_str());
		sleep(1);
		//changeFlightModeDebug("AUTO");
		system("rosrun mavros mavsys mode -c AUTO");
		sleep(10);
		changeFlightModeDebug("HOLD");
		
		string waypoint_end		= waypoint+course_type+".end";
		mission.mission_makara	= waypoint_end;
		pub_mission_rc.publish(mission);
	}
}
	
	
void waypoint_running(string waypoint){
	if(receive_mission != mission_idle){
		sleep(1);
		changeFlightModeDebug("HOLD");
		sleep(1);
		string waypoint_start = waypoint+".start";
		mission.mission_makara = waypoint_start;
		pub_mission_rc.publish(mission);
		sleep(1);
		system("rosrun mavros mavwp clear"); //clear wp
		string command = "rosrun mavros mavwp load ~/waypoints/"+course_type+"_"+waypoint+".waypoints";
		system(command.c_str());
		sleep(1);
		//changeFlightModeDebug("AUTO");
		system("rosrun mavros mavsys mode -c AUTO");
		sleep(10);
		changeFlightModeDebug("HOLD");
		sleep(1);
		
		string waypoint_end		= waypoint+course_type+"_gate.end";
		mission.mission_makara	= waypoint_end;
		pub_mission_rc.publish(mission);
	}
	sleep(1);
}
	
void mission_running(string mission_name){
	if(receive_mission != mission_idle){
		sleep(1);
		com.mission_makara = mission_name;
		pub_com_rc.publish(com);
		sleep(1);
		changeFlightModeDebug("MANUAL");
		sleep(1);
		string mission_start = mission_name+".start";
		mission.mission_makara = mission_start;
		pub_mission_rc.publish(mission);
		sleep(1);
		string mission_end = mission_name+".end";

		while(ros::ok() && receive_mission != mission_end ) ros::spinOnce();
	}
}

void rc_number_cb (const kocheng::rc_number& number){
	rc_flag_in = number.rc_number;
}

bool changeFlightMode(const char* flight_mode){
	mavros_msgs::SetMode flightmode;
	flightmode.request.base_mode 	= 0;				
	flightmode.request.custom_mode 	= flight_mode;		
	bool success = client_set_flightmode.call(flightmode);

	if(success){
		return true;
	}
	else {
		return  false;
	}
}

bool changeFlightModeDebug(string fm){
	changeFlightMode(fm.c_str());
}
void rc_mission_cb	(const kocheng::mission_status& data){
	receive_mission = data.mission_makara;
}
