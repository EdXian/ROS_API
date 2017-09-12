#include"ros/ros.h"
#include"service/service_client.h"
#include"srv.h"
#include"std_srvs/Empty.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "call_service");
  ros::NodeHandle nh;
  std_srvs::Empty empty;
  service::service_client srv1;
  srv ss;
  ss.initialize();
  ros::ServiceClient client1 = nh.serviceClient<service::service_client>("/multiple");
  ros::ServiceClient client2 = nh.serviceClient<std_srvs::Empty>("/empty");

  ros::Rate loop_rate(10);
  while (ros::ok())
  {

    srv1.request.a=3;
    srv1.request.b=5;
    client1.call(srv1);
   client2.call(empty);
    printf("the response of multiple service is %ld\n",srv1.response.result);
    //printf("the response of service_class is %ld\n",srv2.response.result);
    loop_rate.sleep();
  }

  return 0;
}
