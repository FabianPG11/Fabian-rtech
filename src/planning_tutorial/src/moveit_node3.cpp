#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>
#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>
#include <moveit_visual_tools/moveit_visual_tools.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "moveit_node3");
  ros::NodeHandle node_handle;
  ros::AsyncSpinner spinner(1);
  spinner.start();

  static const std::string PLANNING_GROUP = "sia5";
  moveit::planning_interface::MoveGroupInterface move_group(PLANNING_GROUP);
  
/*

moveit::planning_interface::PlanningSceneInterface planning_scene_interface;   //Collision objects
  const robot_state::JointModelGroup* joint_model_group =
  move_group.getCurrentState()->getJointModelGroup(PLANNING_GROUP);		//Raw pointer to refer to a planning group
	*/
  /*namespace rvt = rviz_visual_tools;
  moveit_visual_tools::MoveItVisualTools visual_tools("base_link");
  visual_tools.deleteAllMarkers();
  visual_tools.loadRemoteControl();
  Eigen::Affine3d text_pose = Eigen::Affine3d::Identity();*/
 

//move_group.setMaxVelocityScalingFactor(0.1);
//moveit_msgs::RobotTrajectory trajectory;


//visual_tools.prompt("SIA5D along a triangular path!");
std::vector<geometry_msgs::Pose> waypoints;




geometry_msgs::Pose target_pose = move_group.getCurrentPose().pose;

target_pose.position.z -= 0.3;
target_pose.position.y -= 0.2;
//waypoints.push_back(target_pose); 
move_group.setPoseTarget(target_pose);
move_group.move();

target_pose.position.y += 0.4;
//waypoints.push_back(target_pose); 
move_group.setPoseTarget(target_pose);
move_group.move();

target_pose.position.z += 0.3;
target_pose.position.y -= 0.2;
//waypoints.push_back(target_pose); 
move_group.setPoseTarget(target_pose);
move_group.move();

moveit_msgs::RobotTrajectory trajectory;
  const double jump_threshold = 0.0;
  const double eef_step = 0.01;
  double fraction = move_group.computeCartesianPath(waypoints, eef_step, jump_threshold, trajectory);



  ros::shutdown();
  return 0;
}

