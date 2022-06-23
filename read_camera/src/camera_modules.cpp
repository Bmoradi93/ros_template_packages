#include <iostream>
#include <vector>
#include <ros/ros.h>
#include <ros/console.h>
#include <std_msgs/Int64.h>
#include <std_srvs/SetBool.h>
#include <sensor_msgs/Image.h>
#include "../include/camera_modules.h"
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>

using namespace cv;
namespace cam
{
    camera_class::camera_class(ros::NodeHandle *nh)
    {
        sub_img = nh->subscribe("/zeda/zed_node_a/left/image_rect_color", 1000, &camera_class::camera_CB, this);
    }

    void camera_class::camera_CB(const sensor_msgs::ImageConstPtr& data)
    {
        // std::cout << "Image is recieved!";
        std_msgs::Header msg_header = data->header;
        std::string frame_id = msg_header.frame_id.c_str();
        ROS_INFO_STREAM("New Image from " << frame_id);

        cv_bridge::CvImagePtr cv_ptr;
        try
            {
                cv_ptr = cv_bridge::toCvCopy(data, sensor_msgs::image_encodings::BGR8);
            }
        catch (cv_bridge::Exception& e)
            {
                ROS_ERROR("cv_bridge exception: %s", e.what());
                return;
            }

        // Draw an example crosshair
        cv::drawMarker(cv_ptr->image, cv::Point(cv_ptr->image.cols/2, cv_ptr->image.rows/2),  cv::Scalar(0, 0, 255), cv::MARKER_CROSS, 10, 1);

        // Update GUI Window
        cv::imshow("window", cv_ptr->image);
        cv::waitKey(3);
    }
}

