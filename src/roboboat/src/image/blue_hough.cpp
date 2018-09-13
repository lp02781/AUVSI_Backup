#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <cv_bridge/cv_bridge.h>
#include <iostream>
#include <stdio.h>
#include "../../include/roboboat/haha.hpp"

using namespace std;
using namespace cv;

namespace patch{
    template<typename T> std::string to_string(const T& n){
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

Mat Original;
Mat imgOriginal, imgHSV, imgThresholded, imgErode, imgDilate;

int sum_x;
int sum_y;
int count_circle;
int state;
bool blue_hough_status = false;

void imageProcessing();

roboboat::image_process image;
ros::Publisher pub_state_camera;
void node_status_cb(const roboboat::node_status& msg);
void imageCallback(const sensor_msgs::CompressedImageConstPtr& msg)
{
  try
  {
    Original = cv::imdecode(cv::Mat(msg->data),1);//convert compressed image data to cv::Mat
    waitKey(10);
    if(blue_hough_status == true){
		imageProcessing();
	}
  }
  catch (cv_bridge::Exception& e)
  {
    ROS_ERROR("Could not convert to image!");
  }
}

int main(int argc, char **argv){
	ros::init(argc, argv, "videoRec");
	ros::NodeHandle nh;
	cv::startWindowThread();
	
	image_transport::ImageTransport it(nh);
	
	pub_state_camera 	= nh.advertise<roboboat::image_process>("/roboboat/image/process", 1);
	ros::Subscriber sub = nh.subscribe("camera/image/compressed", 1, imageCallback);
	ros::Subscriber sub_node_status = nh.subscribe("/auvsi/node/status", 1, node_status_cb);
	ROS_WARN("NC : blue_hough.cpp active");
	namedWindow("panel_blue", CV_WINDOW_AUTOSIZE);
	
	createTrackbar("LowH", "panel_blue", &LowH_blue, 255);
	createTrackbar("HighH", "panel_blue", &HighH_blue, 255);
	createTrackbar("LowS", "panel_blue", &LowS_blue, 255); 
	createTrackbar("HighS", "panel_blue", &HighS_blue, 255);
	createTrackbar("LowV", "panel_blue", &LowV_blue, 255);
	createTrackbar("HighV", "panel_blue", &HighV_blue, 255);
	createTrackbar("MaxRadius", "panel_blue", &max_radius_blue, 1000);
	createTrackbar("MinRadius", "panel_blue", &min_radius_blue, 1000);
	createTrackbar("noise", "panel_blue", &Noise_blue, 255);
	
	while (ros::ok()) {
		ros::spinOnce();
	}
}

void imageProcessing(){
	sum_x = 0;
	sum_y = 0;
	count_circle = 0;
		
	imgOriginal = Original.clone();
	medianBlur(imgOriginal, imgOriginal, 5);
		
	cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV);
	inRange(imgHSV, Scalar(LowH_blue, LowS_blue, LowV_blue), Scalar(HighH_blue, HighS_blue, HighV_blue), imgThresholded);//range threshold
		
	erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(Noise_blue, Noise_blue)) );
	dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(Noise_blue, Noise_blue)) ); 
		
	dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(Noise_blue, Noise_blue)) ); 
	erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(Noise_blue, Noise_blue)) ); 
		
	GaussianBlur(imgThresholded, imgThresholded, Size(9, 9), 2, 2);
		
	vector<Vec3f> circles;
	HoughCircles(imgThresholded, circles, HOUGH_GRADIENT, 1,
		imgThresholded.rows/16, 
		100, 30, min_radius_blue, max_radius_blue);
		
	for (size_t i = 0; i < circles.size(); i++ ){
		int x = round(circles[i][0]);
		int y = round(circles[i][1]);
		Point center(x, y);
		int radius = round(circles[i][2]);
		circle(Original, center, radius, Scalar(255,0,255), 3, LINE_AA);
		string strX = patch::to_string(x);
		string strY = patch::to_string(y);
		putText(Original, strX + " , " + strY, Point(x-radius/2, y), 
				FONT_HERSHEY_SIMPLEX, 0.3, Scalar(50, 255, 100), 1);
		sum_x = sum_x + x;
		sum_y = sum_y + y;
		count_circle++;
	}
	//cout<<count_circle<<endl;
	if(count_circle > 0){
		state = sum_x/count_circle;
	}
	else{
		state = 0;
	}
	image.buoy_blue = state;
	pub_state_camera.publish(image);
	
	imshow("Threshold_blue", imgThresholded);
	imshow("Original_blue", Original); 
}
void node_status_cb(const roboboat::node_status& msg){
	blue_hough_status=msg.blue_hough_status;
}
