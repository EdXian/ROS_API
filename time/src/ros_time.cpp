#include "ros/ros.h"
#include "std_msgs/String.h"
/*
 * http://wiki.ros.org/roscpp/Overview/Time
 *
*/
int main(int argc, char **argv)
{
  ros::init(argc, argv, "ros_time");
  ros::NodeHandle nh;
  ros::Time current_time = ros::Time::now();
  ros::Time last_time;
  ros::Duration interval(5,0);

    ROS_INFO("going to sleep");
    ros::Duration(0.5).sleep();
    ROS_INFO("wakeup");

    last_time=ros::Time::now();
    current_time= ros::Time::now();
    std::cout<<current_time.toNSec()<<std::endl;
    while((current_time.toNSec()-last_time.toNSec())<interval.toNSec())
    {
      current_time= ros::Time::now();
      //std::cout<<"wait"<<std::endl;
    }
    std::cout<<current_time.toNSec()<<std::endl;
  return 0;
}
