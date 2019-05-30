#include "ros/ros.h"
#include "final_exam/mover2d2.h"
#include "geometry_msgs/Twist.h"



float x;
float ang;


bool movedir(final_exam::mover2d2::Request  &req,
          final_exam::mover2d2::Response &res)
 {
   	res.c = req.a + req.b;
	x=req.a;
	ang=req.b;
	if (ang<60 | ang>100){
	ang=0;
	}

   ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
   ROS_INFO("sending back response: [%ld]", (long int)res.c);
   return true;

 }
 
 int main(int argc, char **argv)
 {

   ros::init(argc, argv, "move_server");
   ros::NodeHandle n;
 
   ros::ServiceServer service = n.advertiseService("move_server", movedir);

   ROS_INFO("Ready to move r2d2");

ros::Publisher chatter_pub = n.advertise<geometry_msgs::Twist>("cmd_vel", 1000);

ros::Rate loop_rate(10);
  geometry_msgs::Twist msg;

double secs =ros::Time::now().toSec();
ros::Duration d(3 , 0);
secs = d.toSec();

while (ros::ok())
  {

secs = d.toSec();
//if (secs<10){
	msg.linear.x = x;
	msg.angular.z = ang;
    chatter_pub.publish(msg);
//}
/*else{
msg.linear.x = 0;
	msg.angular.z = 0;
    chatter_pub.publish(msg);
}*/

    ros::spinOnce();
    loop_rate.sleep();


} 
   return 0;
 }
