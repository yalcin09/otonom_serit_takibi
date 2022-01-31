#include <ros.h>
#include <std_msgs/UInt16.h>

const int Motor1_pA   =  8;
const int Motor1_pB   =  9;
const int Motor1_pwm  =  5;
const int Motor2_pC   =  10;
const int Motor2_pD   =  11;
const int Motor2_pwm  =  6;

int gelen = 0;

ros::NodeHandle  nh;

void kntrl(){
  switch(gelen){
  case 65:
  
          digitalWrite(Motor1_pA,HIGH);
          digitalWrite(Motor1_pB,LOW);
          digitalWrite(Motor2_pC,HIGH);
          digitalWrite(Motor2_pD,LOW);
          
          break;
  case 66:
  
          digitalWrite(Motor1_pA,LOW);
          digitalWrite(Motor1_pB,HIGH);
          digitalWrite(Motor2_pC,LOW);
          digitalWrite(Motor2_pD,HIGH);
          
          break;
  case 67:
  
          digitalWrite(Motor1_pA,LOW);
          digitalWrite(Motor1_pB,LOW);
          digitalWrite(Motor2_pC,HIGH);
          digitalWrite(Motor2_pD,LOW);
 
          break;
  case 68:
  
          digitalWrite(Motor1_pA,HIGH);
          digitalWrite(Motor1_pB,LOW);
          digitalWrite(Motor2_pC,LOW);
          digitalWrite(Motor2_pD,LOW);
          
          break;
   default:

          digitalWrite(Motor1_pA,LOW);
          digitalWrite(Motor1_pB,LOW);
          digitalWrite(Motor2_pC,LOW);
          digitalWrite(Motor2_pD,LOW);

          break;
   }
  }

void kontrol(const std_msgs::UInt16& msg){
 gelen = (int)msg.data;
}

ros::Subscriber<std_msgs::UInt16> sub("yon", kontrol);

void setup() {

  nh.initNode();
  nh.subscribe(sub);

  pinMode(Motor1_pA,OUTPUT);
  pinMode(Motor1_pB,OUTPUT);
  pinMode(Motor2_pC,OUTPUT);
  pinMode(Motor2_pD,OUTPUT);

  
  digitalWrite(Motor1_pA,LOW);
  digitalWrite(Motor1_pB,LOW);
  digitalWrite(Motor2_pC,LOW);
  digitalWrite(Motor2_pD,LOW);
  analogWrite(Motor1_pwm,100);
  analogWrite(Motor2_pwm,100);

}

void loop() {

  kntrl();
  nh.spinOnce();
  delay(1);

}
