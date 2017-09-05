#include "ros/ros.h"
#include "std_msgs/String.h"

#include "message/ball.h"
#include "message/ballArray.h"

message::ball ball;
message::ballArray ballArray;
uint64_t count=0;
int main(int argc, char **argv)
{
  ros::init(argc, argv, "message");
  ros::NodeHandle nh;
  ros::Time now=ros::Time::now();
  ros::Publisher chatter1_pub = nh.advertise<message::ball>("ball", 1000);
  ros::Publisher chatter2_pub = nh.advertise<message::ballArray>("ballArray", 1000);

  ros::Rate loop_rate(10);
  while (ros::ok())
  {
    message::ball msg;

    //ball stamp
    msg.header.frame_id="world";
    msg.header.seq=count;
    now=ros::Time::now();
    msg.header.stamp=now;

    //for ball 1
    msg.name="ball1";
    msg.score=10;
    msg.radius=1.0;
    msg.pose.position.x=1;
    msg.pose.position.y=1;
    msg.pose.position.z=0;

    chatter1_pub.publish(msg);
    ballArray.data.push_back(msg);

    //for ball 2
    msg.name="ball2";
    msg.score=20;
    msg.radius=2.0;
    msg.pose.position.x=1;
    msg.pose.position.y=0;
    msg.pose.position.z=0;

    ballArray.data.push_back(msg);
    chatter2_pub.publish(ballArray);

    ros::spinOnce();
    loop_rate.sleep();
    count++;
  }

  return 0;
}
