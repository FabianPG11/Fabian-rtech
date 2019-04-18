#include "ros/ros.h"
//#include "ros/random_numbers.h"

// %EndTag(ROS_HEADER)%
// %Tag(MSG_HEADER)%
#include "sensor_msgs/Range.h"




int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "sensor_ultrasonic");
// %EndTag(INIT)%

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
// %Tag(NODEHANDLE)%
  ros::NodeHandle n;
// %EndTag(NODEHANDLE)%

  /**
   * The advertise() function is how you tell ROS that you want to
   * publish on a given topic name. This invokes a call to the ROS
   * master node, which keeps a registry of who is publishing and who
   * is subscribing. After this advertise() call is made, the master
   * node will notify anyone who is trying to subscribe to this topic name,
   * and they will in turn negotiate a peer-to-peer connection with this
   * node.  advertise() returns a Publisher object which allows you to
   * publish messages on that topic through a call to publish().  Once
   * all copies of the returned Publisher object are destroyed, the topic
   * will be automatically unadvertised.
   *
   * The second parameter to advertise() is the size of the message queue
   * used for publishing messages.  If messages are published more quickly
   * than we can send them, the number here specifies how many messages to
   * buffer up before throwing some away.
   */
// %Tag(PUBLISHER)%
  ros::Publisher chatter_pub = n.advertise<sensor_msgs::Range>("sensor_range", 1000);
// %EndTag(PUBLISHER)%


  ros::Rate loop_rate(10);
  sensor_msgs::Range msg;

  msg.min_range = 0.02;
  msg.max_range = 4;
  msg.field_of_view = 3.1415/4;

  msg.header.frame_id = "sensor_range";

  int random_numbers=0;

	srand(time(0));
  while (ros::ok())
  {


msg.range=(3.98)*float(rand())/float(RAND_MAX)+0.02;
    
    /**
     * The publish() function is how you send messages. The parameter
     * is the message object. The type of this object must agree with the type
     * given as a template parameter to the advertise<>() call, as was done
     * in the constructor above.
     */
// %Tag(PUBLISH)%
    chatter_pub.publish(msg);
// %EndTag(PUBLISH)%

// %Tag(SPINONCE)%
    ros::spinOnce();
// %EndTag(SPINONCE)%

// %Tag(RATE_SLEEP)%
    loop_rate.sleep();
// %EndTag(RATE_SLEEP)%

  }


  return 0;
}

