#include <ros/ros.h>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include <cmath>

using namespace cv;
using namespace std;

class SeritTakip{

	ros::NodeHandle nh_;
	image_transport::ImageTransport it_;
	image_transport::Subscriber sub_;

	vector<Vec4i> dogrular;

public:

	SeritTakip() : it_(nh_){
		sub_ = it_.subscribe("video_", 1, &SeritTakip::gelenResim,this);
	}
	~SeritTakip(){
		destroyWindow("class");
	}

	Mat serit_ciz(Mat resim){
		for(int i=0;i<dogrular.size();i++)
		line(resim,Point(dogrular[i][0],dogrular[i][1]),Point(dogrular[i][2],dogrular[i][3]),Scalar(0,255,0),2,8);
		return resim;
	}

	Mat cokgen_olustur(Mat resim){
		Mat mask = Mat::zeros(resim.rows,resim.cols,CV_8UC1);
		Point nokta[1][4];
		nokta[0][0]=Point(320,290);
		nokta[0][1]=Point(650,290);
		nokta[0][2]=Point(800,resim.rows);
		nokta[0][3]=Point(180,resim.rows);

		const Point* ppt[1] = { nokta[0] };
		int npt[] = {4};
		fillPoly(mask,ppt,npt,1,Scalar(255,255,255),8);
		bitwise_and(resim,mask,mask);
		
		return mask;
	}

	void serit_takib(Mat &resim){
		//*****Gelen görüntü önce tek kanallı yapılıyor;
		Mat griResim;
		cvtColor(resim,griResim,CV_BGR2GRAY);
		//*****Gürültüleri temizlemek için bulanıklaştırma yapılıyor;
		GaussianBlur(griResim,griResim,Size(11,11),3,3);
		//*****Kenar bulma
		Canny(griResim,griResim,10,100);
		//*****Şerit sınırını belirlemek için bir çokgen oluşturuluyor;
		Mat mask;
		mask = cokgen_olustur(griResim);
		//*****Şeritleri bulma
		HoughLinesP(mask,dogrular,2,CV_PI/180,30,15,90);
		//*****Şeritleri çizme
		Mat s_resim;
		s_resim = serit_ciz(resim);

			//****imshow*****
			imshow("Belirlenen Aralık",mask);
			imshow("Tek kanallı",griResim);
			imshow("Sonuc",resim);
			waitKey(3);
	}

	void gelenResim(const sensor_msgs::ImageConstPtr& msg){
		Mat image;
		cv_bridge::CvImagePtr ros_resim;

		try{
			ros_resim =  cv_bridge::toCvCopy(msg,sensor_msgs::image_encodings::BGR8);
			image = ros_resim -> image;
		}
		catch(cv_bridge::Exception& ex){
			ROS_ERROR("--------HATA-------");
		}
		
		SeritTakip::serit_takib(image);	
	}
};


int main(int argc, char **argv){
	ros::init(argc,argv,"Serit_Takip");
	SeritTakip serit_Takip;
	ros::spin();
}
