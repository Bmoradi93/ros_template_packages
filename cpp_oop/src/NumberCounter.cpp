/**
 * @file NumberCounter.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <ros/ros.h>
#include <std_msgs/Int64.h>
#include <std_srvs/SetBool.h>
#include <cpp_oop/NumberCounter.h>

namespace ns {
    NumberCounter::NumberCounter(ros::NodeHandle *nh) {
        counter = 0;

        pub = nh->advertise<std_msgs::Int64>("/number_count", 10);    
        number_subscriber = nh->subscribe("/number", 1000, &NumberCounter::callback_number, this);
        reset_service = nh->advertiseService("/reset_counter", &NumberCounter::callback_reset_counter, this);
    }

    void NumberCounter::callback_number(const std_msgs::Int64& msg) {
        counter += msg.data;
        std_msgs::Int64 new_msg;
        new_msg.data = counter;
        pub.publish(new_msg);
    }

    bool NumberCounter::callback_reset_counter(std_srvs::SetBool::Request &req, std_srvs::SetBool::Response &res)
    {
        if (req.data) {
            counter = 0;
            res.success = true;
            res.message = "Counter has been successfully reset";
        }
        else {
            res.success = false;
            res.message = "Counter has not been reset";
        }

        return true;
    }
}