#include "ros/ros.h"
#include "std_msgs/String.h"
#include "service/service_client.h"
 #include <cstdlib>
bool multiple(service::service_client::Request &req,
              service::service_client::Response &res
              )
{
    res.result=req.a*req.b;

    return true;
}



int main(int argc, char **argv)
{
  ros::init(argc, argv, "service_call");
  ros::NodeHandle nh;
  service::service_client srv;

  ros::ServiceServer service = nh.advertiseService("/multiple", multiple);

  ros::Rate loop_rate(10);
  while (ros::ok())
  {
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}

