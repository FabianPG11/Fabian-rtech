#include "ros/ros.h"
    #include "final_exam/mover2d2.h"
    #include <cstdlib>
    
    int main(int argc, char **argv)
    {
      ros::init(argc, argv, "move_client");
     if (argc != 3)
     {
       ROS_INFO("usage: move_client X Y");
       return 1;
     }
   
     ros::NodeHandle n;
     ros::ServiceClient client = n.serviceClient<final_exam::mover2d2>("move_server");
     final_exam::mover2d2 srv;
     srv.request.a = atoll(argv[1]);
     srv.request.b = atoll(argv[2]);
     if (client.call(srv))
    {
       ROS_INFO("Response: %ld", (long int)srv.response.c);
     }
     else
     {
       ROS_ERROR("Failed to call service move_client");
       return 1;
     }
   
     return 0;
   }

