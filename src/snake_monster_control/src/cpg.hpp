#include <math.h>
#include <ros/ros.h>
#include <ros/subscribe_options.h>
#include <boost/thread.hpp>
#include <boost/algorithm/string.hpp>
#include <sensor_msgs/JointState.h>
// #include <std_msgs/JointCommands.h>

#include "std_msgs/Float64.h"

#include <boost/numeric/odeint/stepper/euler.hpp>
#include <boost/numeric/odeint.hpp>

# define M_PI       3.14159265358979323846  /* pi */

