cmake_minimum_required(VERSION 2.8.3)
project(motoman_sia5d_moveit_config)

find_package(catkin REQUIRED
moveit_visual_tools
  moveit_ros_planning_interface)

catkin_package()

install(DIRECTORY launch DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
  PATTERN "setup_assistant.launch" EXCLUDE)
install(DIRECTORY config DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})


