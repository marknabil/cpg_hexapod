
#include "cpg.hpp" 
// that will include the change_param request and response automatically generated headers
#include <snake_monster_control/change_param.h>

//#include <ros/xmlrpc_manager.h>

using namespace std;
using namespace snake_monster_control;

typedef struct State_ {
  double proximal; // proximal joint angle
  double intermediate; // intermediate joint angle
  double distal; // distal joint angle
} State;

State current_state;

//ros::Publisher pub_joint_commands_;

const int number_legs = 6;

// Intial Values for CPG parameters as defined in the paper
// equations 17 and 18
int w = 5; // control forward velocity not oscillation
int n = 4; // can be 2 if circular limit cycle is desired
double a = M_PI/180 , b = M_PI/6;
double alpha = 0.25; 
int epsi=40;

// CPG constant offset of limit cycle
double C_x0 [number_legs] = {M_PI/4, M_PI/4, 0, 0, -M_PI/4, -M_PI/4}; // will be constant 

//C_y0 will be constant too since it only gets updated for the purpose of inertial feedback
double C_y0 [number_legs] = {M_PI/16, M_PI/16, M_PI/16, M_PI/16, M_PI/16, M_PI/16};

// Coupling matrix intially
// eq 16
int K[number_legs][number_legs] = {{0, -1, -1, 1, 1, -1},
			   {-1, 0, 1, -1, -1, 1},
			   {-1, 1, 0, -1, -1, 1},
			   {1, -1, -1, 0, 1, -1},
			   {1, -1, -1, 1, 0, -1},
			   {-1, 1, 1, -1, -1, 0}};

int x=0, y=0;
double H_c[number_legs];
double H_c_y[number_legs];
double H_c_x[number_legs];
double X_dot[number_legs];
double Y_dot[number_legs];


bool change_cpg_param(change_param::Request &req, change_param::Response &res)
{

  ROS_INFO("request: w=%ld, n=%ld a=%ld", (int)req.w, (int)req.n,(double)req.a);
  w=req.w;
  n=req.n;
  a=req.a;
  bool flag = true;

  while (ros::ok)
  {

    /////////////////////////////////////////////////
    for (int i=0; i<number_legs; i++)
      {
        
        H_c[i] = pow( (x-C_x0[i])/a, n) + pow( (y-C_y0[i])/b, n);
        H_c_y[i] = ((double)(n/b) * ( pow ( (y - (C_y0[i])/b) , n-1))); // H_c_y
        H_c_x[i] = ((double)(n/a) * (pow ( ( (double)y - C_x0[i])/a , (double)n-1))); // H_c_x

        // equations 15 of the paper 
        X_dot[i] = (-w * H_c_y[i]) + (epsi*(1 - H_c[i])* H_c_x[i]); 
        
        //for (int i=1 , i<) loop over the every K column -> multi -> sum all
        // the o/p should be multiplied to the alpha in the derivative of Y equation
        int K_sigma = 0;
        for (int j=0;j<number_legs;j++)
        {
          K_sigma += K[j][i];
          //cout << K_sigma <<endl;
        }
        //cout << K_sigma <<endl;

        Y_dot[i] = (-w * H_c_x[i]) + (epsi*(1 - H_c[i])* H_c_y[i]) + alpha*K_sigma; 
        // the previous equation should hold the summation of vector K "j" for every leg "i"

        //cout << X_dot[i] << endl;

      }
    /////////////////////////////////////////////////
  }
    return flag;
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "cpg_2");
  ros::NodeHandle nh;

  ros::Time begin = ros::Time::now();
  //double dt = (current_time - last_integrate).toSec();
  double dt = 0.001;
  
  
  // int i =1; 
  ros::ServiceServer service = nh.advertiseService("cpg_change_param", change_cpg_param);
  //ROS_INFO("request ", cpg_change_param.flag);
  cout <<"Start the Service by running rosservice call" << endl;


  ros::Time last_integrate = ros::Time::now();

  ///////////////////////////////////////////////////////////////////////
  // Integration eq should be done here ! 
  ///////////////////////////////////////////////////////////////////////

  // update time to be used in the next integration step
  ros::Time current_time = ros::Time::now();


  //cout<<"x"<<setw(19)<<"y"<<setw(19)<<"dy/dx"<<setw(16)<<"y_new\n";
  ros::spin();
  //ros::Publisher L5_3_pub = nh.advertise<std_msgs::Float64> ("/snake_monster/L5_3_eff_pos_controller/command", 100);
  return 0;
}
