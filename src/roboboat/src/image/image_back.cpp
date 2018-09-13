#include "../../include/roboboat/haha.hpp"
#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <iostream>

using namespace cv;
bool image_back_status = false;
void node_status_cb(const roboboat::node_status& msg);
Mat image;

int main(int argc, char** argv)
{
	ros::init(argc, argv, "image_back");
	ros::NodeHandle nh;
	image_transport::ImageTransport it(nh);
	image_transport::Publisher pub = it.advertise("/camera/image", 1, true);
	ros::Subscriber sub_node_status = nh.subscribe("/auvsi/node/status", 1, node_status_cb);
	ROS_WARN("NC : image_back.cpp active");
	
	VideoCapture cap(back_camera); 
	if(!cap.isOpened()){
		ROS_ERROR ("Error opening camera.");	  
		return 1;
	}
	while (nh.ok()) {
		cap.read(image);		
		if(!image.empty() && image_back_status == true){	
			sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();
			pub.publish(msg);
		}
		ros::spinOnce();
	}
}
void node_status_cb(const roboboat::node_status& msg){
	image_back_status=msg.image_back_status;
}
