#include "ros/ros.h"
#include "std_msgs/String.h"
#include"listener.h"
#include <iostream>
//#include "string.h"
ros::master::V_TopicInfo topic_list;

std::vector<std::string> team_list;
std::vector<listener* > teamVector;

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
  ros::init(argc, argv, "subscriber");
  ros::NodeHandle nh;
  ros::Rate loop_rate(5);

  ros::Duration(0.5).sleep();
  getRosTopics(topic_list);
  team_list.clear();
  teamVector.clear();

  for(ros::master::V_TopicInfo::iterator it=topic_list.begin();it!=topic_list.end();it++)
  {
    ros::master::TopicInfo& info=*it;
    if(info.name.compare(0,13,"/team/chatter")==0)
    {
      team_list.push_back(info.name);
    }
  }

  for(int i=0;i<team_list.size();i++)
  {
    for(int j=i;j<team_list.size();j++)
    {
      if(team_list[i].at(team_list[i].size()-1) >
         team_list[j].at(team_list[j].size()-1)
        )
      {
        std::swap(team_list[j],team_list[i]);
      }
    }
  }

  for(int i=0;i<team_list.size();i++)
  {
    teamVector.push_back(new listener(team_list[i]));
    std::cout<<team_list[i]<<std::endl;
  }

  while(ros::ok())
  {
      std::cout<<"we have :"<<teamVector[0]->info.data
                            <<teamVector[1]->info.data
                            <<teamVector[2]->info.data
                            <<teamVector[3]->info.data
                            <<teamVector[4]->info.data
                            <<std::endl;

     loop_rate.sleep();
     ros::spinOnce();
  }

  return 0;
}
