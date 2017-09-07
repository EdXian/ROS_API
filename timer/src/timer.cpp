#include <ros/ros.h>
/*
 *
 *http://wiki.ros.org/roscpp/Overview/Timers
 *
*/
using namespace std;

int i=0;
void timer_cb(const ros::TimerEvent& event)
{
  ROS_INFO(" %dth time callback ",i);
  i++;
  //cout<<"%dth callback"<<count<<endl;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "timer");
  ros::NodeHandle nh;
  ros::Timer timer = nh.createTimer(ros::Duration(2), timer_cb);
  ROS_INFO("timer");
  ros::spin();  //cannot use spinOnce
}
