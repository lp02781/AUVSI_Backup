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

int zero_flag 		= 0;
int first_simple 	= 1;
int second_simple 	= 2;
