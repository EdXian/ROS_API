#ifndef __SUBSCRIBE_H
#define __SUBSCRIBE_H
#include "ros/ros.h"
#include "std_msgs/String.h"
class subscribe
{
public:
  subscribe();
  std_msgs::String info;
  ros::NodeHandlePtr nh;
  ros::Subscriber sub;

 private:

  void callback(const std_msgs::String::ConstPtr& msg);

};

#endif // SUBSCRIBE_H
