#include <ros.h>
#include <std_msgs/Int32.h>
#include <std_msgs/Int32MultiArray.h>

ros::NodeHandle  nh;
std_msgs::Int32MultiArray srf_msg;

const int trigPin_1 = 8;
const int echoPin_1 = 11;

const int trigPin_2 = 9;
const int echoPin_2 = 10;

const int trigPin_3 = 7;
const int echoPin_3 = 6;

const int trigPin_4 = 4;
const int echoPin_4 = 5;

int kocheng_status;

int led_1 = 13;
int led_2 = 12;

long duration_1;
long duration_2;
long duration_3;
long duration_4;

int distance_1;
int distance_2;
int distance_3;
int distance_4;

ros::Publisher chatter("/auvsi/ardu/srf", &srf_msg);

void messageCb( const std_msgs::Int32& msg){
  kocheng_status=msg.data;
}

ros::Subscriber<std_msgs::Int32> sub("/auvsi/ardu/status", &messageCb );

void setup()
{ 
  nh.initNode();
  nh.advertise(chatter);
  nh.subscribe(sub);
  
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);

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

  digitalWrite(trigPin_1, LOW);
  digitalWrite(trigPin_2, LOW);
  digitalWrite(trigPin_3, LOW);
  digitalWrite(trigPin_4, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin_1, HIGH);
  digitalWrite(trigPin_2, HIGH);
  digitalWrite(trigPin_3, HIGH);
  digitalWrite(trigPin_4, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigPin_1, LOW);
  digitalWrite(trigPin_2, LOW);
  digitalWrite(trigPin_3, LOW);
  digitalWrite(trigPin_4, LOW);

  duration_1=pulseIn(echoPin_1, HIGH);
  duration_2=pulseIn(echoPin_2, HIGH);
  duration_3=pulseIn(echoPin_3, HIGH);
  duration_4=pulseIn(echoPin_4, HIGH);

  distance_1= duration_1*0.034/2;
  distance_2= duration_2*0.034/2;
  distance_3= duration_3*0.034/2;
  distance_4= duration_4*0.034/2;
  
  srf_msg.data[0]= distance_1;
  srf_msg.data[1]= distance_2;
  srf_msg.data[2]= distance_3;
  srf_msg.data[3]= distance_4;

  chatter.publish( &srf_msg );
  
  if(kocheng_status==0){
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, LOW);    
  }
  else if(kocheng_status==1){
    digitalWrite(led_1, LOW);
    digitalWrite(led_2, HIGH);
  }
  else{
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, LOW);    
    
  }
  delay(1);
}
