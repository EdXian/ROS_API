cmake_minimum_required(VERSION 2.8.3)
project(message)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
    roscpp
     message_generation
    std_msgs
    geometry_msgs

)

## Generate messages in the 'msg' folder
 add_message_files(
   DIRECTORY msg
   FILES
   ball.msg
   ballArray.msg
 )


 generate_messages(
   DEPENDENCIES
   std_msgs
   geometry_msgs
   message
     # Or other packages containing msgs
 )

catkin_package(

  INCLUDE_DIRS include
 # LIBRARIES message
 #  CATKIN_
      CATKIN_DEPENDS roscpp
                 std_msgs
                 geometry_msgs
                 message_runtime
#  DEPENDS system_lib
)

include_directories(
 include
  ${catkin_INCLUDE_DIRS}
)

add_executable(Message src/message.cpp )

add_dependencies(Message ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

 target_link_libraries(Message
   ${catkin_LIBRARIES}
 )
