#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "opencv2/opencv.hpp"
#include <iostream>
#include <math.h>

#define PI 3.14159265
#define r  150

using namespace std;
using namespace cv;

class konum_kontrol{

	ros::NodeHandle nh_;
	ros::Subscriber sub_;
	ros::Publisher pub_motor;

public:
	konum_kontrol(){
		sub_ = nh_.subscribe("konum_msj",1000,&konum_kontrol::gelen_konum,this);
		pub_motor = nh_.advertise<geometry_msgs::Twist>("motor",1000);
	}

	void gelen_konum(const geometry_msgs::Twist::ConstPtr& msg){
	cout << "X : "    <<   msg->linear.x   <<   endl;
	cout << "Y : "    <<   msg->linear.y   <<   endl;
	cout << "alfa : " <<   msg->angular.z  <<   endl;
	
	double donme  = (2*PI*r*msg->angular.z)/360;
	double mesafe = sqrt(pow(msg->linear.x,2)+pow(msg->linear.y,2));
	cout << "mesafe : " << mesafe << endl;
	knm.linear.z  = mesafe;	

	if(msg->linear.x > 0){
		//sol motor ileri....sağ motor geri
		
		knm.angular.x = donme;
		knm.angular.y = -1*donme;
		pub_motor.publish(knm);
		
	}else if(msg->linear.x < 0){
		//sol motor geri.....sağ motor ileri

		knm.angular.x = -1*donme;
		knm.angular.y = donme;
		pub_motor.publish(knm);

	}else{
		cout << "donme yok" << endl;
	}

	waitKey(1500);
	knm.angular.x = mesafe;
	knm.angular.y = mesafe;
	pub_motor.publish(knm);


	}
private:
	geometry_msgs::Twist knm;

};


int main(int argc, char **argv){

	ros::init(argc,argv,"gelen_konum_msj");
	konum_kontrol knm_kntrl;
	ros::spin();

	return 0;
}
