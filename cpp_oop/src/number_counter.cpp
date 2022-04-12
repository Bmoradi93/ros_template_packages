#include <ros/ros.h>
#include <std_msgs/Int64.h>
#include <std_srvs/SetBool.h>
#include <cpp_oop/NumberCounter.h>

int main (int argc, char **argv)
{
    ros::init(argc, argv, "number_counter");
    ros::NodeHandle nh;
    ns::NumberCounter nc = ns::NumberCounter(&nh);
    ros::spin();
}