#ifndef LISTENER_H
#define LISTENER_H
#include"ros/ros.h"
#include"std_msgs/String.h"
#include "string.h"
#include"stdio.h"
using namespace std;


class listener
{
public:

  listener(std::string name);
   std_msgs::String info;
  void print();
private:
  void callback(const std_msgs::String::ConstPtr& msg);
  ros::NodeHandle nh;
  ros::Publisher pub;
  ros::Subscriber sub;
};



#endif // LISTENER_H
