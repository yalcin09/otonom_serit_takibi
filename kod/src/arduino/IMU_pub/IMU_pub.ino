#include <ros.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Empty.h>
#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);
ros::NodeHandle  nh;


std_msgs::Float32 alfa;
ros::Publisher chatter("IMU", &alfa);

void setup()
{
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.advertise(chatter);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

void loop()
{
  mpu6050.update();
  alfa.data = mpu6050.getAngleZ();
  chatter.publish( &alfa );
  nh.spinOnce();
  delay(500);
}
