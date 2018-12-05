#include <iostream>
#include <stdio.h>

#define STEERING 0
#define THROTTLE 2

#define SIMPLE_PIN 3

#define MAX_THROTTLE 1800//1750
#define MIN_THROTTLE 1400

#define MAX_STEERING 1900
#define MIN_STEERING 1100

#define PWM_UP 	1700
#define PWM_LOW 1300

#define MIDDLE_PWM 	1520

float update_time=0.01;
float delta_t = 0.01;
float initial_time = 0; 

int number_camera=0;

#define PWM_NAV 1400
float kp_nav = 1.65;//1.5
float ki_nav = 1;//1
float kd_nav = 0.5;//0.5
float longtitude_nav_end;
float latitude_nav_end;
float tolerance_nav;
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

int zero_flag 		= 0;
int first_simple 	= 1;
int second_simple 	= 2;
