#ifndef SRV_H
#define SRV_H
#include "ros/ros.h"
#include "std_srvs/Empty.h"
class srv
{
public:
  srv();
   bool initialize();
private:
  ros::NodeHandle nh;
  ros::ServiceServer __srv;

  bool empty_cb(std_srvs::Empty::Request& req,
                std_srvs::Empty::Response& res
                );
};

#endif // SRV_H
