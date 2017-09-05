#include "ros/ros.h"
#include "std_msgs/String.h"
#include "subscribe.h"
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard chatter1 : [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "sub");
  subscribe sub2;
  ros::NodeHandle nh;
  ros::Rate loop_rate(10);
  ros::Subscriber sub1 = nh.subscribe("chatter1", 10, chatterCallback);
  while(ros::ok())
  {
    ROS_INFO("I heard chatter2 : [%s]", sub2.info.data.c_str());
    loop_rate.sleep();
    ros::spinOnce();
  }
  return 0;
}
