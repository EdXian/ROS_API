#include "listener.h"
#include"ros/ros.h"

listener::listener(std::string name)
{
  sub=nh.subscribe<std_msgs::String>(name,10,&listener::callback,this);
}
void listener::callback(const std_msgs::String::ConstPtr& msg)
{

    info.data=msg->data;
}

void listener::print()
{
  printf("test\n");
}
