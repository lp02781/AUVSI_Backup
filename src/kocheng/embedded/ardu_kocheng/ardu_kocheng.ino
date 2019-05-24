#include <ros.h>
#include <std_msgs/Int32.h>
#include <std_msgs/Int32MultiArray.h>

ros::NodeHandle  nh;
std_msgs::Int32MultiArray srf_msg;

const int trigPin_1 = 3;
const int echoPin_1 = 2;
const int trigPin_2 = 5;
const int echoPin_2 = 4;
const int trigPin_3 = 6;
const int echoPin_3 = 7;
const int trigPin_4 = 9;
const int echoPin_4 = 8;
const int trigPin_5 = 11;
const int echoPin_5 = 12;

int pwm_remote;
int middle_pwm = 120;
int remote_pin = A3;

int led_red     = A0;
int led_yellow  = A1;
int led_green   = A2;

int kocheng_status;

long duration_1;
long duration_2;
long duration_3;
long duration_4;
long duration_5;

int distance_1;
int distance_2;
int distance_3;
int distance_4;
int distance_5;

ros::Publisher chatter("/auvsi/ardu/srf", &srf_msg);

void messageCb( const std_msgs::Int32& msg){
  kocheng_status=msg.data;
}

ros::Subscriber<std_msgs::Int32> sub("/auvsi/ardu/led", &messageCb );

void setup()
{ 
  nh.initNode();
  nh.advertise(chatter);
  nh.subscribe(sub);
  
  pinMode(led_red, OUTPUT);
  pinMode(led_green, OUTPUT);
  pinMode(led_yellow, OUTPUT);

  pinMode(remote_pin, INPUT);
  
  pinMode(trigPin_1, OUTPUT); 
  pinMode(echoPin_1, INPUT);
  pinMode(trigPin_2, OUTPUT); 
  pinMode(echoPin_2, INPUT);
  pinMode(trigPin_3, OUTPUT); 
  pinMode(echoPin_3, INPUT);
  pinMode(trigPin_4, OUTPUT); 
  pinMode(echoPin_4, INPUT);

}

void loop()
{  
  nh.spinOnce();

  pwm_remote = analogRead(remote_pin);
  
  digitalWrite(trigPin_1, LOW);
  digitalWrite(trigPin_2, LOW);
  digitalWrite(trigPin_3, LOW);
  digitalWrite(trigPin_4, LOW);
  digitalWrite(trigPin_5, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin_1, HIGH);
  digitalWrite(trigPin_2, HIGH);
  digitalWrite(trigPin_3, HIGH);
  digitalWrite(trigPin_4, HIGH);
  digitalWrite(trigPin_5, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigPin_1, LOW);
  digitalWrite(trigPin_2, LOW);
  digitalWrite(trigPin_3, LOW);
  digitalWrite(trigPin_4, LOW);
  digitalWrite(trigPin_5, HIGH);
  
  duration_1=pulseIn(echoPin_1, HIGH);
  duration_2=pulseIn(echoPin_2, HIGH);
  duration_3=pulseIn(echoPin_3, HIGH);
  duration_4=pulseIn(echoPin_4, HIGH);
  duration_5=pulseIn(echoPin_5, HIGH);

  distance_1= duration_1*0.034/2;
  distance_2= duration_2*0.034/2;
  distance_3= duration_3*0.034/2;
  distance_4= duration_4*0.034/2;
  distance_5= duration_5*0.034/2;
  
  srf_msg.data[0]= distance_1;
  srf_msg.data[1]= distance_2;
  srf_msg.data[2]= distance_3;
  srf_msg.data[3]= distance_4;
  srf_msg.data[4]= distance_5;
  
  chatter.publish( &srf_msg );
  
  if(kocheng_status==1 && pwm_remote<middle_pwm){//manual
    digitalWrite(led_red, LOW);
    digitalWrite(led_yellow, HIGH);
    digitalWrite(led_green, LOW);    
  }
  else if(kocheng_status==2 && pwm_remote<middle_pwm){//auto
    digitalWrite(led_red, LOW);
    digitalWrite(led_yellow, LOW);
    digitalWrite(led_green, HIGH);
  }
  else if(pwm_remote>middle_pwm && kocheng_status!=2 &&kocheng_status!=1){//motor
    digitalWrite(led_red, HIGH);
    digitalWrite(led_yellow, LOW);
    digitalWrite(led_green, LOW);      
  }
  else {
    digitalWrite(led_red, LOW);
    digitalWrite(led_yellow, LOW);
    digitalWrite(led_green, LOW); 
  }
  delay(1);
}
