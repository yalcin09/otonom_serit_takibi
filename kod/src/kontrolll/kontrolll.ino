#include <ros.h>
#include <std_msgs/Float32.h>

const int trigPin = 21;
const int echoPin = 20;
long duration;
double distanceCm;

const int wheel_inB   =  27;
const int wheel_inA   =  29;
const int wheel_inC   =  31;
const int wheel_inD   =  33;
const int wheel_left  =  9;
const int wheel_right =  8;

float Kp = 5;
float Ki = 0.003;
float Kd = 0;
float error, errorLast, errorInt;

  double now;
  double LastTime = 0;
  ros::NodeHandle  nh;

float calcPID(float angle){
  
  float errorDiff;
  float output;
  double dt=(double)(now-LastTime);
  
  error = 0 - angle;
  errorInt +=   error * dt;
  errorDiff = (error - errorLast)/dt;
  output    = Kp*error + Ki*errorInt + Kd*errorDiff;
  errorLast = error;
  LastTime=now;

  return output;
  }

void messageCb( const std_msgs::Float32 angle_msg){
  now=millis()*0.001;
  float ctrl = calcPID((float)(angle_msg.data));
  float ff = 70;
  motor_speed(ff-ctrl,ff+ctrl);
}
int pwm_max = 200;

void motor_speed(int spdL,int spdR){
  spdR = -spdR;
  ////////////////  
  /*
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm= duration*0.034/2;
  */
  ////////////////
  /*if(distanceCm < 20){
    analogWrite(wheel_left,0);
    analogWrite(wheel_right,0);
    }else{*/
       if(spdL < 0){
         analogWrite(wheel_left,constrain(-spdL, 0, pwm_max));
         digitalWrite(wheel_inA,0);
         digitalWrite(wheel_inB,1);
       }else{
         analogWrite(wheel_left,constrain(spdL, 0, pwm_max));
         digitalWrite(wheel_inA,1);
         digitalWrite(wheel_inB,0);
        }
        if(spdR < 0){
         analogWrite(wheel_right,constrain(-spdR, 0, pwm_max));
         digitalWrite(wheel_inC,0);
         digitalWrite(wheel_inD,1);
       }else{
         analogWrite(wheel_right,constrain(spdR, 0, pwm_max));
         digitalWrite(wheel_inC,1);
         digitalWrite(wheel_inD,0);
      }
    //}
}

ros::Subscriber<std_msgs::Float32> sub("angle", messageCb );

void setup() {

  pinMode(wheel_inA,OUTPUT);
  pinMode(wheel_inB,OUTPUT);
  pinMode(wheel_inC,OUTPUT);
  pinMode(wheel_inD,OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);


    nh.initNode();
    nh.subscribe(sub);

}

void loop() {
  
  nh.spinOnce();
  delay(10);

}
