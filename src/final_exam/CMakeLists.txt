cmake_minimum_required(VERSION 2.8.3)
project(final_exam)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  genmsg
)

## Declare ROS messages and services
add_service_files(FILES mover2d2.srv)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(move_client src/move_client.cpp)
target_link_libraries(move_client ${catkin_LIBRARIES})
add_dependencies(move_client final_exam_generate_messages_cpp)

add_executable(move_server src/move_server.cpp)
target_link_libraries(move_server ${catkin_LIBRARIES})
add_dependencies(move_server final_exam_generate_messages_cpp)
