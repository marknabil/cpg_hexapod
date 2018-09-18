

//// just for testing to be removed
//template<
//    class Container ,
//    class Time = double ,
//    class Traits = container_traits< Container >
//    >
//class ode_step
//{
//    // provide basic typedefs
//    //
// public:

//    typedef unsigned short order_type;
//    typedef Time time_type;
//    typedef Traits traits_type;
//    typedef typename traits_type::container_type container_type;
//    typedef typename traits_type::value_type value_type;

//    // public interface
// public:

//    // return the order of the stepper
//    order_type order_step() const;

//    // standard constructor
//    ode_step( void );

//    // adjust the size of the internal arrays
//    void adjust_size( const container_type &x );

//    // performs one step
//    template< class DynamicalSystem >
//    void do_step( DynamicalSystem &system ,
//                  container_type &x ,
//                  const container_type &dxdt ,
//                  time_type t ,
//                  time_type dt );

//    // performs one step
//    template< class DynamicalSystem >
//    void do_step( DynamicalSystem &system ,
//                  container_type &x ,
//                  time_type t ,
//                  time_type dt );
//};

////Eulers Method to solve a differential equation
//#include<iostream>
//#include<iomanip>
//#include<cmath>


//using namespace std;
//double df(double x, double y)            //function for defining dy/dx
//{
//    double a=x+y;                //dy/dx=x+y
//    return a;
//}
//int main()
//{
//    int n;
//    double x0,y0,x,y,h;            //for initial values, width, etc.
//    cout.precision(5);            //for precision
//    cout.setf(ios::fixed);
//    cout<<"\nEnter the initial values of x and y respectively:\n";        //Initial values
//    cin>>x0>>y0;
//    cout<<"\nFor what value of x do you want to find the value of y\n";
//    cin>>x;
//    cout<<"\nEnter the width of the sub-interval:\n";            //input width
//    cin>>h;
//    cout<<"x"<<setw(19)<<"y"<<setw(19)<<"dy/dx"<<setw(16)<<"y_new\n";
//    cout<<"----------------------------------------------------------\n";
//    while(fabs(x-x0)>0.0000001)        //I couldn't just write "while(x0<x)" as they both are floating point nos. It is dangerous to compare two floating point nos. as they are not the same in binary as they are in decimal. For instance, a computer cannot exactly represent 0.1 or 0.7 in binary just like decimal can't represent 1/3 exactly without recurring digits.
//    {
//        y=y0+(h*df(x0,y0));            //calculate new y, which is y0+h*dy/dx
//        cout<<x0<<setw(16)<<y0<<setw(16)<<df(x0,y0)<<setw(16)<<y<<endl;
//        y0=y;                    //pass this new y as y0 in the next iteration.
//        x0=x0+h;                //calculate new x.
//    }
//    cout<<x0<<setw(16)<<y<<endl;
//    cout<<"The approximate value of y at x=0 is "<<y<<endl;        //print the solution.
//    return 0;
//}


////////////////////////////////////////////////////////////

//#include <iostream>
//#include <boost/numeric/odeint.hpp>
//#include "tp.h"
//#define tab "\t"

//using namespace std;
//using namespace boost::numeric::odeint;

//typedef vector< double > state_type;

//const double sigma = 10.0;
//const double R = 28.0;
//const double b = 8.0 / 3.0;

//void lorenz( state_type &x , state_type &dxdt , double t )
//{
//    dxdt[0] = sigma * ( x[1] - x[0] );
//    dxdt[1] = R * x[0] - x[1] - x[0] * x[2];
//    dxdt[2] = x[0]*x[1] - b * x[2];
//}

//int main( int argc , char **argv )
//{
//    const double dt = 0.01;

//    state_type x(3);
//    x[0] = 1.0 ;
//    x[1] = 0.0 ;
//    x[2] = 0.0;
//    stepper_euler< state_type > stepper;
//    stepper.adjust_size( x );

//    double t = 0.0;
//    for( size_t oi=0 ; oi<10000 ; ++oi,t+=dt )
//    {
//        stepper.do_step( lorenz , x , t , dt );
//        cout << x[0] << tab << x[1] << tab << x[2] << endl;
//    }
//}
