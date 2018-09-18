// walking.cpp
// ros publisher to publish joint commands that should be given by CPG

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Float64.h"

#include <sstream>

#include <string>
using namespace std;


int
main (int argc, char **argv)
{
  //int count = 0;

  int hz = 100;
  ros::init (argc, argv, "walking_ctrl");
  ros::NodeHandle n;

  int n_legs = 6;
  int n_joints = 3;
  int total_DOF = n_legs * n_joints;	// 18

  // create the joints publishers 
  array < ros::Publisher, 18 > pub;
  int i = 0;
  while (i < n_legs)
    {

      string topic_name;
      for (int j = 0; j < n_joints; j++)
        {
          topic_name =
            "/snake_monster/" + string ("L") + to_string (i + 1) +
            string ("_") + to_string (j + 1) + string ("_") +
            string ("eff_pos_controller") + string ("/command");
          cout << topic_name << endl;
          pub[i] = n.advertise < std_msgs::Float64 > (topic_name, 1000);
        }
      i++;
    }
  // end of joint publisher creation


  while (ros::ok ())
    {
      std_msgs::Float64 msg;
      ros::Rate loop_rate (hz);
      msg.data = +1.0;

      pub[0].publish (msg);

      /////////////////////////////////////////////////////////////
      // Alternating tripod gait should go here 
      /////////////////////////////////////////////////////////////

      ros::spinOnce ();
      loop_rate.sleep ();
      //++count;
    }


  return 0;
}
