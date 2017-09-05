#include "subscribe.h"
#include "stdio.h"
subscribe::subscribe() :
  nh(new ros::NodeHandle)
{
   sub=nh->subscribe<std_msgs::String>("chatter2",10,&subscribe::callback,this);
}


void subscribe::callback(const std_msgs::String::ConstPtr& msg)
{
 //data=msg->data;
 // ROS_INFO("I heard chatter1 : [%s]", msg->data.c_str());
  this->info.data = msg->data;
}


