#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "pub");
  ros::NodeHandle nh;
  ros::NodeHandle nh2("ns2");
  ros::NodeHandle nh3(nh2,"nh3");
  ros::NodeHandle nh4("~");
  ros::NodeHandle nh5("~nh5");
  ros::NodeHandle nh6(nh3,"/nh6");

  ros::Publisher chatter1_pub = nh.advertise<std_msgs::String>("/publish1", 1000);
  ros::Publisher chatter2_pub = nh.advertise<std_msgs::String>("publish2", 1000);

  ros::Publisher chatter3_pub = nh2.advertise<std_msgs::String>("publish3", 1000);
  ros::Publisher chatter4_pub = nh2.advertise<std_msgs::String>("/publish4", 1000);


  ros::Publisher chatter5_pub = nh3.advertise<std_msgs::String>("publish5", 1000);
  ros::Publisher chatter6_pub = nh4.advertise<std_msgs::String>("publish6", 1000);
  ros::Publisher chatter7_pub = nh5.advertise<std_msgs::String>("publish7", 1000);
  ros::Publisher chatter8_pub = nh6.advertise<std_msgs::String>("publish8", 1000);


  ros::Rate loop_rate(10);
  while (ros::ok())
  {
    std_msgs::String msg;
    msg.data = "hello world";

    chatter1_pub.publish(msg);
    chatter2_pub.publish(msg);
    chatter3_pub.publish(msg);
    chatter4_pub.publish(msg);
    chatter5_pub.publish(msg);
    chatter6_pub.publish(msg);
    chatter7_pub.publish(msg);
    chatter8_pub.publish(msg);
    ros::spinOnce();

    loop_rate.sleep();
  }

  return 0;
}
