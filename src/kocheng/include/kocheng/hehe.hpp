#include <iostream>
#include <stdio.h>
#include <string.h>

//#################  MAIN VARIABLE  ###############
#define STEERING 0
#define THROTTLE 2
#define SIMPLE_PIN 3
#define CAMERA_SERVO 4
#define DRONE_SERVO 5

#define MAX_THROTTLE 1900//1750
#define MIN_THROTTLE 1100
#define MAX_STEERING 1900
#define MIN_STEERING 1100

#define PWM_UP 	1700
#define PWM_LOW 1300
#define MIDDLE_PWM 	1520

#define CAM_INIT_PWM 1500
#define DRONE_INIT_PWM 1300

char mission_idle[] = "no_mission";

float update_time=0.01;
float delta_t = 0.01;
float initial_time = 0; 

int number_camera=0;

int zero_flag 		= 0;
int first_simple 	= 1;
int second_simple 	= 2;

//#################  NAVIGATION VARIABLE  ###############
#define THROT_NAV 1650
float longitude_nav_end;
float latitude_nav_end;
float tolerance_nav;
float kp_nav = 1.65;//1.5
float ki_nav = 1;//1
float kd_nav = 0.5;//0.5
int setpoint_nav=160;
int x_nav=0;
int y_nav=180;
int width_nav=280; //width 400 for simple
int height_nav=180;
int LowH_nav	= 0; 		//0  
int HighH_nav 	= 184;		//184 
int LowS_nav 	= 130;      //130  65
int HighS_nav 	= 248;      //248  246
int LowV_nav 	= 49;		//49   242
int HighV_nav 	= 230;		//230  255
int Noise_nav 	= 15;

//#################  SPEED VARIABLE  ###############
#define THROT_SPEED 1650
float longitude_speed_end;
float latitude_speed_end;
float tolerance_speed;
int Noise_speed = 15;
double compass_point=60;
double compass_tolerance = 5;

//blue buoy
float kp_speed= 1.65;//1.5
float ki_speed = 1;//1
float kd_speed = 0.5;//0.5
int setpoint_speed=50;
int x_speed=0;
int y_speed=180;
int width_speed	=280; //width 400 for simple
int height_speed=180;
int LowH_speed	= 0; 		//0  
int HighH_speed = 184;		//184 
int LowS_speed 	= 130;      //130  65
int HighS_speed = 248;      //248  246
int LowV_speed 	= 49;		//49   242
int HighV_speed = 230;		//230  255

//red buoy
float kp_speed_new= 1.65;//1.5
float ki_speed_new = 1;//1
float kd_speed_new = 0.5;//0.5
int setpoint_speed_new=160;
int x_speed_new=0;
int y_speed_new=180;
int width_speed_new	=280; //width 400 for simple
int height_speed_new=180;
int LowH_speed_new	= 0; 		//0  
int HighH_speed_new = 184;		//184 
int LowS_speed_new 	= 130;      //130  65
int HighS_speed_new = 248;      //248  246
int LowV_speed_new 	= 49;		//49   242
int HighV_speed_new = 230;		//230  255

