#include "ros/ros.h"
#include "std_msgs/String.h"

ros::master::V_TopicInfo rostopic_list;
ros::V_string rosnode_list;



bool getRosTopics(ros::master::V_TopicInfo& topics){
    XmlRpc::XmlRpcValue args, result, payload;
    args[0] = ros::this_node::getName();
    std::string str;
    if (!ros::master::execute("getTopicTypes", args, result, payload, true)){
        std::cout << "Failed!" << std::endl;
        return false;
    }

    topics.clear();
    for (int i = 0; i < payload.size(); ++i)
        topics.push_back(ros::master::TopicInfo(std::string(payload[i][0]), std::string(payload[i][1])));
    return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "master");
  ros::NodeHandle nh;

  if(ros::ok())
  {
    while(!ros::master::check());
    if(ros::master::getTopics(rostopic_list))
    {
      ROS_INFO("master is established");


      //rostopic list

      const std::string host_info=ros::master::getHost();
      std::cout<<"---------ros host-------"<<std::endl;
      std::cout<<"host name : "<<host_info.c_str()<<std::endl;

      std::cout<<"---------port-------"<<std::endl;
      uint32_t port_info=ros::master::getPort();
      std::cout<<"port : "<<port_info<<std::endl;

      std::cout<<"---------URI-------"<<std::endl;
      std::string URI_info=ros::master::getURI();
      std::cout<<"URI : "<<URI_info.c_str()<<std::endl;
       ros::master::getNodes(rosnode_list);
      std::cout<<"----rosnode list---"<<std::endl;
      for(ros::V_string::iterator it = rosnode_list.begin() ; it !=rosnode_list.end() ; it++)
      {
        std::cout << "node" <<it-rosnode_list.begin()<<":"<<*(it) <<std::endl;
      }

      std::cout<<"----rostopic list---"<<std::endl;
      // ros::master::getTopics(rostopic_list);
       getRosTopics(rostopic_list);
      for (ros::master::V_TopicInfo::iterator it = rostopic_list.begin() ; it != rostopic_list.end(); it++)
      {
        const ros::master::TopicInfo& info = *it;
        std::cout << "topic \t" << it - rostopic_list.begin()
                  << ": \t" << info.name<<"  \t"
                  <<"  type: "<< info.datatype
                  << std::endl;
      }



    }else
    {
      ROS_ERROR("get topics error");
    }
  }else
  {
    ROS_ERROR("ros master is not exist");
  }
  return 0;
}
