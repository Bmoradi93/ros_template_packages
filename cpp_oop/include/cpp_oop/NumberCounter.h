/**
 * @file NumberCounter.h
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

namespace ns {

    class NumberCounter {

        private:
        int counter;
        ros::Publisher pub;
        ros::Subscriber number_subscriber;
        ros::ServiceServer reset_service;

        public:
        NumberCounter(ros::NodeHandle *nh);

        void callback_number(const std_msgs::Int64& msg);

        bool callback_reset_counter(std_srvs::SetBool::Request &req, std_srvs::SetBool::Response &res);
    };

}