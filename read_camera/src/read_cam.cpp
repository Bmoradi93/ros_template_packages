/**
 * @file read_cam.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// Tutorials
// https://www.programcreek.com/cpp/?CodeExample=image+const+ptr+msg
// https://dabit-industries.github.io/turtlebot2-tutorials/14c-OpenCV2_CPP.html

#include <iostream>
#include <vector>
#include <ros/ros.h>
#include <std_msgs/Int64.h>
#include <std_srvs/SetBool.h>
#include "../include/camera_modules.h"
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "read_cam");
    ros::NodeHandle nh;
    cam::camera_class cc = cam::camera_class(&nh);
    ros::spin();
}