#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "sub");
  ros::NodeHandle nh;
  ros::Rate loop_rate(10);
  ros::Subscriber sub = nh.subscribe("chatter1", 1000, chatterCallback);
 while(ros::ok())
 {
   loop_rate.sleep();
   ros::spinOnce();
 }

 std::cout<<"exit sub"<<std::endl;
  return 0;
}
