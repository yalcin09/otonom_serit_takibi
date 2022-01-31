#include <ros/ros.h>
#include <std_msgs/Float32.h>

void messageCallback(const std_msgs::Float32::ConstPtr& msg){
	ROS_INFO("I heard: [%f]",msg->data);
}

int main(int argc,char **argv){
	ros::init(argc,argv,"arduino_code");
	ros::NodeHandle nh;
	ros::Subscriber sub = nh.subscribe("message",1000,messageCallback);
	ros::spin();
	return 0;
}
