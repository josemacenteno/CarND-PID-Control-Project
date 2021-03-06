#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  Kp_ = Kp;
  Ki_ = Ki;
  Kd_ = Kd;

  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;

  d_error_init = false;
}

void PID::UpdateError(double cte) {
  i_error += cte;

  // d_error could be mislead by p_error initialzation
  if(!d_error_init){
    d_error_init = 0.0;
    d_error_init = true;
  }
  else{
    d_error  = cte - p_error;
  }
  p_error  = cte;
}

double PID::TotalError() {
  double steer;

  //steer = -1.0*(Kp_ * p_error) - (Ki_ * i_error) - (Kd_ *d_error);
  steer = -1.0*(Kp_ * p_error) - (Ki_ * i_error) - (Kd_ *d_error);

  return steer;
}

