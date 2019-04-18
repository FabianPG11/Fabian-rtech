#include "ros/ros.h"
#include "sensor_msgs/Range.h"
#include "std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}


int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "sensor_ultrasonic_arduino");  //name of node
  ros::NodeHandle n;
  //ros::Subscriber sub = n.subscribe("sensor_range", 1000, chatterCallback);
  ros::Publisher chatter_pub = n.advertise<sensor_msgs::Range>("filtered", 1000);

  ros::Rate loop_rate(10);
  sensor_msgs::Range msg;

  msg.min_range = 0.02;
  msg.max_range = 4;
  msg.field_of_view = 3.1415/4;

  msg.header.frame_id = "filtered";

  //int random_numbers=0;
  //srand(time(0));

  while (ros::ok())
  {

    msg.range=(3.98)*float(rand())/float(RAND_MAX)+0.02;
    chatter_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();

  }

  return 0;
}

