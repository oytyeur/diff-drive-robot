#include "pid.h"

PID::PID() 
: Kp(0.0), Ki(0.0), Kd(0.0),
  errOld(0.0), errSum(0.0), errDot(0.0)
{}

PID::~PID(){}

float PID::computeControl(float err, float dt, int rfidFound)
{
    // if(rfidFound > 0)
    //     errSum = 0;

    errDot = err - errOld; // дельта соседних измерений
    errSum = errSum + err; // суммарная ошибка за всё время

    float u = Kp*err + Ki*errSum*dt + Kd*errDot/dt;
    errOld = err;
    return u;
}



float PID::computeAngleError(float thetaGoal, float theta)
{
    float err = thetaGoal - theta;
    if(err > 3.141593) return err - 2*3.141593;
    else if(err < -3.141593) return err + 2*3.141593;
    else return err;
}

void PID::setCoefficient(float Kp, float Ki, float Kd)
{
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
}