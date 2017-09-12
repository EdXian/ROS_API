#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "param");
  ros::NodeHandle nh;
  float f;
  std::string str;
  int x;
  std::vector<std::string> param_list;

  std::string param_key("string");
  std::string param_result;
  std::string param_value;
  bool _bool;
  nh.getParam("float",f);
  nh.getParam("string",str);
  nh.getParam("int",x);
  nh.getParam("bool",_bool);

  ros::param::getParamNames(param_list);
  std::cout<<"-----------parameter list-----------"<<std::endl;
  for(std::vector<std::string>::iterator it=param_list.begin() ;it!=param_list.end() ;it++)
  {
    std::cout<<*(it)<<std::endl;
  }

  std::cout<<"-----------parameter search-----------"<<std::endl;
  ros::param::search(param_key,param_result);
  std::cout<<param_result<<std::endl;

  std::cout<<"-----------parameter value-----------"<<std::endl;
  ros::param::get(param_result,param_value);
  std::cout<<param_value<<std::endl;
  return 0;
}
