#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "opencv2/opencv.hpp"
#include <iostream>


using namespace std;
using namespace cv;


void gelen_mesaj(const geometry_msgs::Twist::ConstPtr& msg){

	cout << "Motor Sol: " << msg->angular.x << endl;
	cout << "Motor Sag: " << msg->angular.y << endl;
}


int main(int argc, char **argv){

	ros::init(argc,argv,"arduino_o");
	ros::NodeHandle nh;
	ros::Subscriber sub = nh.subscribe("motor",1000,gelen_mesaj);
	ros::spin();

	return 0;
}
