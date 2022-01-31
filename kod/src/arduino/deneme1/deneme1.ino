#include <ros.h>
#include <std_msgs/Float32.h>

/******************************/
const int trigPin = 9;
const int echoPin = 10;

long duration;
double distanceCm;
/*****************************/
ros::NodeHandle nh;
std_msgs::Float32 mesafe;
ros::Publisher pub("message",&mesafe);


void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  nh.initNode();
  nh.advertise(pub);
}

void loop() {
  
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
  
  mesafe.data = distanceCm;
  pub.publish(&mesafe);
  nh.spinOnce();
  delay(500);
}
