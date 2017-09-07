#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "publisher");
  ros::NodeHandle nh;

  ros::Publisher chatter1_pub = nh.advertise<std_msgs::String>("chatter1", 1000);
  ros::Publisher chatter2_pub = nh.advertise<std_msgs::String>("chatter2", 1000);
  ros::Publisher chatter3_pub = nh.advertise<std_msgs::String>("chatter3", 1000);
  ros::Publisher chatter4_pub = nh.advertise<std_msgs::String>("chatter4", 1000);
  ros::Publisher chatter5_pub = nh.advertise<std_msgs::String>("chatter5", 1000);

  ros::Rate loop_rate(10);
  while (ros::ok())
  {
    std_msgs::String msg;

    msg.data = " chatter1";
    chatter1_pub.publish(msg);

    msg.data = " chatter2";
    chatter2_pub.publish(msg);
    msg.data = " chatter3";
    chatter3_pub.publish(msg);
    msg.data = " chatter4";
    chatter4_pub.publish(msg);
    msg.data = " chatter5";
    chatter5_pub.publish(msg);
    loop_rate.sleep();
  }

  return 0;
}
