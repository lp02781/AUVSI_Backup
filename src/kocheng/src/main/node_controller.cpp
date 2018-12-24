#include "../../include/kocheng/hehe.hpp"
#include <ros/ros.h>

#include "mavros_msgs/SetMode.h"
#include "mavros_msgs/State.h"

#include "kocheng/rc_number.h"
#include "kocheng/mission_status.h"

using namespace std;

int rc_flag_in;
string receive_mission;

ros::ServiceClient client_set_flightmode;
kocheng::mission_status	mission;

void rc_number_cb		(const kocheng::rc_number& number);
void rc_mission_cb		(const kocheng::mission_status& data);
void waypoint_running	(string waypoint);
void mission_running	(string mission_name);
bool changeFlightMode	(const char* flight_mode);
bool changeFlightModeDebug(string fm);

ros::Subscriber sub_mission_rc;
ros::Publisher pub_mission_rc;

int main(int argc, char **argv)
{
	ros::init(argc, argv, "node_controller");
	ros::NodeHandle nh;
	
	pub_mission_rc 					= nh.advertise<kocheng::mission_status>("/auvsi/rc/mission", 1);
	sub_mission_rc	 				= nh.subscribe("/auvsi/rc/mission", 1, rc_mission_cb);
	ros::Subscriber sub_rc_number 	= nh.subscribe("/auvsi/rc/number", 8, rc_number_cb);
	client_set_flightmode 			= nh.serviceClient<mavros_msgs::SetMode>("/mavros/set_mode");
	
	ROS_WARN("NC : node_controller.cpp active");
	
	while(ros::ok()){
		ros::spinOnce();
		sleep(0.2);
		if(rc_flag_in == first_simple ){
			waypoint_running("navigation_gate");
			mission_running("navigation");
			waypoint_running("speed_gate");
			mission_running("speed");
		}
		else if(rc_flag_in == second_simple){
			ros::spinOnce();
		}
		else if(rc_flag_in == zero_flag){
			mission.mission_makara=mission_idle;
			pub_mission_rc.publish(mission);
			sleep(0.2);
		}
	}
}

void waypoint_running(string waypoint){
	if(receive_mission != mission_idle){
		string waypoint_start = waypoint+course_type+"_gate.start";
		changeFlightModeDebug("HOLD");
		mission.mission_makara = waypoint_start;
		pub_mission_rc.publish(mission);
		system("rosrun mavros mavwp clear"); //clear wp
		string command = "rosrun mavros mavwp load ~/"+waypoint+".waypoints";
		system(command.c_str());
		changeFlightModeDebug("AUTO");
		changeFlightModeDebug("HOLD");
		string waypoint_end		= waypoint+course_type+"_gate.end";
		mission.mission_makara	= waypoint_end;
		pub_mission_rc.publish(mission);
	}
}
	
void mission_running(string mission_name){
	if(receive_mission != mission_idle){
		string mission_start = mission_name+".start";
		changeFlightModeDebug("MANUAL");
		mission.mission_makara = mission_start;
		pub_mission_rc.publish(mission);
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
