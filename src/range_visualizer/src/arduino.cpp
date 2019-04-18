#include "ros/ros.h"
#include "sensor_msgs/Range.h"
#include "std_msgs/String.h"
//#include "std_msgs/Float32.h"

float prev1=3;
float prev2=4;
float filtered=0;
float a=0.1;
float b=0.2;

sensor_msgs::Range ultras_dist;

void chatterCallback(const sensor_msgs::Range msg)
{
  //ROS_INFO("I heard: [%s]", msg);
	ROS_INFO("I heard: [%f]", msg.range);

 ultras_dist.range = msg.range;

filtered= ultras_dist.range+a*prev1+b*prev2;
prev1=filtered;
prev2=prev1;	
	ROS_INFO("filtered: [%f]", filtered);

}


int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "arduino");  //name of node
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("/ultrasound/raw", 1000, chatterCallback);
  ros::Publisher chatter_pub = n.advertise<sensor_msgs::Range>("/ultrasound/filtered", 1000);

//ros::Publisher chatter_pub = n.advertise<std_msgs::Float32>("ultrasound/filtered", 1000);

  ros::Rate loop_rate(10);
  sensor_msgs::Range msg;

  msg.min_range = 0.02;
  msg.max_range = 4;
  msg.field_of_view = 3.1415/4;
  msg.header.frame_id = "ultrasound";

ultras_dist.min_range = 0.02;
  ultras_dist.max_range = 4;
  ultras_dist.field_of_view = 3.1415/4;
  ultras_dist.header.frame_id = "ultrasound";

  //int random_numbers=0;
  //srand(time(0));

  while (ros::ok())
  {

//    msg.range=(3.98)*float(rand())/float(RAND_MAX)+0.02;
msg.range=a*prev1+b*prev2;	
    chatter_pub.publish(ultras_dist);
    ros::spinOnce();
    loop_rate.sleep();

  }

  return 0;
}

