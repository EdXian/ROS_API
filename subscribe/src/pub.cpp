#include "ros/ros.h"
#include "std_msgs/String.h"
#include"subscribe.h"
int main(int argc, char **argv)
{
  ros::init(argc, argv, "pub");
  ros::NodeHandle nh;
  ros::Publisher chatter1_pub = nh.advertise<std_msgs::String>("chatter1", 1000);
  ros::Publisher chatter2_pub = nh.advertise<std_msgs::String>("chatter2", 1000);

  ros::Rate loop_rate(10);
  while (ros::ok())
  {
    std_msgs::String msg1;
    std_msgs::String msg2;
    msg1.data = "1234567";
    msg2.data = "abcdefg";
    chatter1_pub.publish(msg1);
    chatter2_pub.publish(msg2);
    ros::spinOnce();

    loop_rate.sleep();
  }

  return 0;
}
