#include <ros/ros.h>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>

#include <opencv2/highgui/highgui.hpp>

using namespace cv;

int main(int argc, char **argv){
	
	ros::init(argc,argv,"video");
	ros::NodeHandle nh;
	image_transport::ImageTransport it(nh);
	image_transport::Publisher pub;
	pub = it.advertise("video_",1);

	sensor_msgs::ImagePtr msg;

	Mat image;

	//VideoCapture video;
	//video.open("/home/yalcin/Effective_Robotics/src/goruntu_isleme/src/yol_video.mp4");
	
	ros::Rate loop_rate(20);

	while(nh.ok()){
		//video >> image;
		image = imread("/home/yalcin/Effective_Robotics/src/goruntu_isleme/src/yol.jpg");
		resize(image, image, Size(), 0.5, 0.5, INTER_LINEAR);
		msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8",image).toImageMsg();
		pub.publish(msg);
		ros::spinOnce();
		loop_rate.sleep();
	}

}

