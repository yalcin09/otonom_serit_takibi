#include <ros/ros.h>
#include <std_msgs/Float32.h>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <algorithm>
#include <iostream>
#include <string>
#include <ctime>
#include <cmath>


using namespace cv;
using namespace std;



class Strip{

	//ROS ile ilgili değişken tanımlaması yapıldı.
	ros::NodeHandle nh_;
	ros::Publisher pub_;
	image_transport::ImageTransport it_;
	image_transport::Subscriber sub_;

public:

	//Kurucu fonksiyon ile bir dinleyici ve yayıncı oluşturuluyor.
	Strip() : it_(nh_){
		sub_ = it_.subscribe("image_raw", 1, &Strip::imageCallback, this);
		pub_ = nh_.advertise<std_msgs::Float32>("angle", 1000);
	}
	
	//Yıkcı fonksiyon ile tüm açılan pencereler kapatıldı.
	~Strip(){
		destroyAllWindows();
	}
	
	//Dinleyici fonksiyon oluştururuyor.
	void imageCallback(const sensor_msgs::ImageConstPtr& msg);
	//Şerit bulma işlemleri yapılıyor.
	void strip_find(Mat image);
	//Bir çokgen oluşturulurdu.
	Mat polygon_create(Mat image);
	//Bulunan şeritler çiziliyor.
	void line_draw(Mat image);
	//İki şerit arasındaki orta noktayı bulma.
	void midpoint(Mat image,Mat clnImage,Mat orjImage);
	//Açı hesaplansı yapılıyor.
	void calculate_angle();
	
	//void deneme(Mat image);///////Deneme Fonksiyon Pasif
public:
	std_msgs::Float32 angle; //Yayıncının göderdiği açı değeri
	vector<Vec4i> lines;     //Şerit bilgilerinin tuturduğu değişken
	Point center;		 //İki şerit arasındaki mesafenin orta noktası
	double thita;		 //Aracın dönme açısı
};

void Strip::imageCallback(const sensor_msgs::ImageConstPtr& msg){
	Mat image;
	cv_bridge::CvImagePtr bridge_image;

	try{
		//Kameradan gelen görüntü OpenCV'de işlenmesi için kopyalanıyor.
		bridge_image = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
		//cv_bridge türündeki görsel Mat türüne dönüştülürdü.
		image = bridge_image->image;
		//Görsel içindeki şerit bulma fonksiyonu
		Strip::strip_find(image);

	}catch(cv_bridge::Exception& ex){ //Resim okuma sırasında hata olur ise consola uyarı mesajı geliyor.
		cout<<"Okuma Hatasi...."<<endl;
	}
	
}

void Strip::strip_find(Mat image){
	Mat grayImg;
	Mat maskImg;
	Mat orjImg;
	Mat clnImg = image.clone();

	//Renkli resim önce gri tona dönüştürürüyor.
	cvtColor(image,grayImg,CV_BGR2GRAY);
	//Gürültülerden kurturmak için resim bulanıklaştırıyoruz.
	GaussianBlur(grayImg,grayImg,Size(11,11),3,3);
	//Daha sonra resim üzerindeki çizgiler bulunuyor.
	Canny(grayImg,grayImg,10,100);
	//Resimin belirli bir bölümü kırpılıyor. Daha sonra AND ile maskelenme yapılıyor.
	maskImg = polygon_create(grayImg);
	//Maske işleminden sonra çizgi çizme işlemi için 
	//Canny metodu ile bulunan çizgilerin konum bilgileri alınıyor.
	HoughLinesP(maskImg,lines,2,CV_PI/180,10,3,3);
	//Alınan bilgiler ile çizgi çizme işlemi gerçekleşiyor.
	line_draw(image);
	//Daha sonra çizgiler arasındaki orta nokta bulunuyor.
	midpoint(maskImg,clnImg,image);
	//Sonuç resmi gösteriliyor.
	imshow("deneme",image);
	waitKey(30);
}

Mat Strip::polygon_create(Mat image){
	Mat mask = Mat::zeros(image.rows,image.cols,CV_8UC1);
	
	//Çokgen noktaları belirleniyor.
	Point point[1][4]; //Oluşacak çokgenin köşelerini tutan matris
	point[0][0]=Point(145,90); //Sol üst köşe
	point[0][1]=Point(image.cols-145,90); //Sağ üst köşe
	point[0][2]=Point(image.cols-50,image.rows-50); // Sağ alt köşe
	point[0][3]=Point(50,image.rows-50); // Sol alt köşe

	const Point* ppt[1] = { point[0] }; //Köşe noktaları çokgen oluşturma(fillPoly) fonksiyonu için işaretçi(Point) olarak ayarlanıyor.
	int npt[] = {4};//Köşe sayısı belirleniyor.
	//Çokgen çiziliyor.
	fillPoly(mask,ppt,npt,1,Scalar(255,255,255),8);
	//Çizilen çokgen ile gri tona dönüşen resim And işlemine tabi tuturuyor.
	bitwise_and(image,mask,mask);
	return mask;
}

void Strip::line_draw(Mat image){


	for(int i=0;i<lines.size();i++){
		//line komutu ile çizgiler çiziliyor.
		line(image,Point(lines[i][0],lines[i][1]),Point(lines[i][2],lines[i][3]),Scalar(255,255,0),3);
	}
	//Kameranın orta noktası bulunuyor..
	circle(image,Point((320),center.y),10,Scalar(0,255,255),3);

}


void Strip::midpoint(Mat image,Mat clnImage,Mat orjImage){
//Burada şeritlerin bellirli bir kısmı alınıyor.
//Kameradan belirlenen bu iki parçanın konumuna göre 
//Orta nokta bulunuyor.
//Daha sonra çaı hesaplanıp PUBLISHER ile açı ROSSERIAL_PYTHON ile arduino kitine veri yollanıyor.
	Mat circle_mask = Mat::zeros(image.rows,image.cols,CV_8UC1);
	Mat line_mask = Mat::zeros(image.rows,image.cols,CV_8UC1);
	Mat poly_mask = Mat::zeros(image.rows,image.cols,CV_8UC1);

	for(int i=0;i<lines.size();i++){
		line(line_mask,Point(lines[i][0],lines[i][1]),Point(lines[i][2],lines[i][3]),Scalar(255,255,255),5);
	}

	Point point[1][4];
	point[0][0]=Point(0,340);
	point[0][1]=Point(image.cols,340);
	point[0][2]=Point(image.cols,370);
	point[0][3]=Point(0,370);

	const Point* ppt[1] = { point[0] };
	int npt[] = {4};
	fillPoly(poly_mask,ppt,npt,1,Scalar(255,255,255),8);
	bitwise_and(poly_mask,line_mask,poly_mask);
	
	vector<Vec4i> Lines;
	HoughLinesP(poly_mask,Lines,2,CV_PI/180,10,3,3);

	for(int i=0;i<Lines.size();i++){
		circle(circle_mask,Point(Lines[i][0],Lines[i][1]),20,Scalar(255,255,255),-1);
		circle(circle_mask,Point(Lines[i][2],Lines[i][3]),20,Scalar(255,255,255),-1);
		line(orjImage,Point(Lines[i][0],Lines[i][1]),Point(Lines[i][2],Lines[i][3]),Scalar(0,255,0),5);
	}

	vector<vector<Point>> count;
	vector<Vec4i> hier;
	findContours(circle_mask,count,hier,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_NONE); //Kenar bulma işlemi
	if(count.size() == 2){
		Point2f left_center,right_center;
		float left_radius,right_radius;

		minEnclosingCircle(count[0],left_center,left_radius); //Minimum çember bulma -> Merkez -> yarıçap
		minEnclosingCircle(count[1],right_center,right_radius);
	imshow("circle",circle_mask);///
		center.x = fabs((int)((left_center.x - right_center.x) / 2)); // iki çizgi arasındaki merkez nokta bulma
		center.y = fabs((int)((left_center.y - right_center.y) / 2));

		center.x = center.x + right_center.x;
		center.y = center.y + right_center.y;
		circle(orjImage,center,6,Scalar(0,255,0),3);
		cout << center << endl;
		line(orjImage,left_center,right_center,Scalar(0,255,0),5);

//////////
		double My=200;
		double Mx;
		double multiplier = 1;
	//Açı hesaplama kısmı
		if(320 > center.x){
			Mx = ((double)((320) - center.x))*multiplier;
			thita = ((atan(Mx/My))*(180/3.14159265359));
		}else if(320 < center.x){
			Mx = ((double)(center.x - (320)))*multiplier;
			thita = ((-1)*(atan(Mx/My))*(180/3.14159265359));
		}else{
			thita = 0;
		}
	}

		//Tek çizgi durumu
		double multiplier1 = 0.15;

	if(count.size() == 1){
		if(330 > center.x){

		Point2f line_center;
		float line_radius;
		
		double c = 200;
		double My = 200;

		minEnclosingCircle(count[0],line_center,line_radius);

		double b = (line_center.x - (320))*multiplier1;
		thita = ((atan(b/My))*(180/3.14159265359));

	circle(orjImage,Point(b,line_center.y),6,Scalar(100,255,0),3);
	cout << "320 > center.x :" << center << endl;
	imshow("circle",circle_mask);///

		}else if(310 < center.x){
		Point2f line_center;
		float line_radius;
		double c = 200;
		double My = 200;

		minEnclosingCircle(count[0],line_center,line_radius);

		double b = ((320) - line_center.x)*multiplier1;
		thita = (-1)*((atan(b/My))*(180/3.14159265359));

		minEnclosingCircle(count[0],line_center,line_radius);
	circle(orjImage,Point(b,line_center.y),6,Scalar(100,255,0),3);
	cout << "320 < center.x :" << center << endl;
	imshow("circle",circle_mask);///

		}else{

		}

	}

	cout << thita << endl;
	angle.data = thita;  
	pub_.publish(angle); //Arduino kitine veri yollama
}


int main(int argc, char **argv){
	ros::init(argc,argv,"strip_node");
	Strip strip;
	ros::spin();
}
