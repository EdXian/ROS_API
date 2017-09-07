#include "srv.h"
#include "stdio.h"
srv::srv()
{

}

bool srv::initialize()
{
  __srv=nh.advertiseService("/empty",&srv::empty_cb,this);
}

bool srv::empty_cb(std_srvs::Empty::Request &req, std_srvs::Empty::Response &res)
{
  printf("this is empty\n");
  return true;
}
