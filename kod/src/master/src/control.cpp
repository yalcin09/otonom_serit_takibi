#include "ros/ros.h"
#include "std_msgs/UInt16.h"
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;

int getch(void)
{
	struct termios oldt, newt;
	int ch;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

	return ch;
}

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


int main(int argc, char** argv)
{ 
	ros::init(argc, argv, "control");
  	ros::NodeHandle n;
  	ros::Publisher pub = n.advertise<std_msgs::UInt16>("yon", 1);
	ros::Rate loop_rate(20);

	std_msgs::UInt16 msg;

	while(ros::ok()){
 
		if(kbhit()){
			switch(getch()){
			case 65 :
				msg.data = 65;
				pub.publish(msg);
				cout<<"Yukari"<<endl;
				break;
			case 66 :
				msg.data = 66;
				pub.publish(msg);
				cout<<"Asagi"<<endl;
				break;
			case 67 :
				msg.data = 67;
				pub.publish(msg);
				cout<<"sag"<<endl;
				break;
			case 68 :
				msg.data = 68;
				pub.publish(msg);
				cout<<"sol"<<endl;
				break;
			default :
				msg.data = 0;
				pub.publish(msg);
				break;
			}
		}
	 ros::spinOnce();
   	 loop_rate.sleep();
	}
}
