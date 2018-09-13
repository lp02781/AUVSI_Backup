#include "roboboat/image_process.h"
#include "roboboat/node_status.h"
#include "roboboat/override_motor.h"
#include "roboboat/node_status.h"

#define STEERING 0
#define THROTTLE 2
#define OVERRIDE 3

#define PWM_UP 	1700
#define PWM_LOW 1300

#define MAX_PWM 1920
#define MIN_PWM 1120

#define MIDDLE_PWM 	1520

int left_setpoint 	= 213; //camera 640/3
int center_setpoint = 320;
int right_setpoint 	= 426;

int front_camera = 0;
int back_camera = 1;

int noise_state = 5;

float kp = 1;
float ki = 0;
float kd = 0;

float delta_t = 0.01;
float initial_time = 0; 

int left_header 	= 1;
int right_header 	= 2;
int center_header 	= 0;
							//nuc  pc
int LowH_red 	= 3; 		//170  3
int HighH_red 	= 51;		//179  51
int LowS_red 	= 65;      //150  65
int HighS_red 	= 246;      //255  246
int LowV_red 	= 242;		//60   242
int HighV_red 	= 255;		//255  255
int max_radius_red 	= 1000; 
int min_radius_red 	= 1;
int Noise_red 	= 5;

int LowH_green	= 14;
int HighH_green = 81;
int LowS_green 	= 121; 
int HighS_green = 210;
int LowV_green 	= 105;
int HighV_green = 164;
int max_radius_green = 1000;
int min_radius_green = 1;
int Noise_green = 5;

int LowH_blue	= 14;
int HighH_blue = 81;
int LowS_blue 	= 121; 
int HighS_blue = 210;
int LowV_blue 	= 105;
int HighV_blue = 164;
int max_radius_blue = 1000;
int min_radius_blue = 1;
int Noise_blue = 5;
