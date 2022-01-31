#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "opencv2/opencv.hpp"
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <math.h>

#define PI 3.14159265

using namespace std;
using namespace cv;

float x,y,z,mesafe;
float alfa;


int kbhit() {
    static const int STDIN = 0;
    static bool initialized = false;

    if (! initialized) {
        termios term;
        tcgetattr(STDIN, &term);
        term.c_lflag &= ~ICANON;
        tcsetattr(STDIN, TCSANOW, &term);
        setbuf(stdin, NULL);
        initialized = true;
    }

    int bytesWaiting;
    ioctl(STDIN, FIONREAD, &bytesWaiting);
    return bytesWaiting;
}


int main(int argc, char **argv){
	
	ros::init(argc,argv,"konum_msj");
	ros::NodeHandle nh;
	ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("konum_msj",1000);
	ros::Rate loop_rate(10);
	
	while(ros::ok()){

		geometry_msgs::Twist knm;
		
		
		if(kbhit()){
			int bos;
			cin >> bos;
			system("clear");
			cout << "X : ";
			cin  >> x;
			waitKey(100);
			cout << "Y : ";
			cin  >> y;
	
			alfa = 90 - fabs(atan(y/x))*(180/PI);
	
			knm.linear.x  = x;
			knm.linear.y  = y;
			knm.angular.z = alfa;

			pub.publish(knm);	
		}
		ros::spinOnce();
		loop_rate.sleep();
	}

	return 0;
}
