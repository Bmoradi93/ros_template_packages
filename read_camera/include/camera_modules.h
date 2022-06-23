/**
 * @file camera_modules.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#include <iostream>
#include <vector>
#include <ros/ros.h>
#include <std_msgs/Int64.h>
#include <std_srvs/SetBool.h>
#include <sensor_msgs/Image.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>

namespace cam
{
    class camera_class
    {
    private:
        // ros::Publisher pub_img;
        ros::Subscriber sub_img;
        // ros::ServiceServer cam_srvs;
    public:
        camera_class(ros::NodeHandle *nh);
        void camera_CB(const sensor_msgs::ImageConstPtr& data);
    }; 
}