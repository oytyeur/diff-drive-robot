#ifndef TWO_WHEELED_ROBOT_H
#define TWO_WHEELED_ROBOT_H


#include "motorBlock.h"
#include "pid.h"
#include "velocity.h"
#include "position.h"
#include "math.h"

#include "RFIDReader.h"
//#include <MFRC522.h>


class TwoWheeledRobot
{
private:
    //MFRC522* rfidReader;
    RFIDReader* rfidReader;

    MotorBlock* motorBlockL;
    MotorBlock* motorBlockR;
    PID* pidL;
    PID* pidR;
    PID* pid;
    Velocity vel;
    Position pos;

    float baseLength;
    byte PIN_CURRENT_SENSOR;

    bool reachedGoal;
    bool globalStop;
    int newMinRange; // Для функции map в setVelocity
    byte inByte;

public:
    TwoWheeledRobot();
    ~TwoWheeledRobot();

    void createWheels(float wheelRadius, float baseLength, float maxVel);
    //void createRFIDReader();

    // SET
    void setEncoderPins(byte encPinL, byte encPinR);
    void setDriverPins(byte driverPinPWM_R, byte driverPin_R2, byte driverPin_R1, byte driverPin_L1, byte driverPin_L2, byte driverPinPWM_L);
    // GET
    float getRadiusWheels();
    byte getSerialData();
    
    void tuneWhlPID(float KpL, float KiL, float KdL, float KpR, float KiR, float KdR);
    void tunePID(float Kp, float Ki, float Kd);
    
// ========= behavior ===========
    void serialControl(bool deb);
    void goCircle(float radius, int ptsNum, bool deb, int circles);
    int goToGoal(float x_d, float y_d, bool isFinish, int del, bool deb, bool followRFID, int idRFID);
    void manualControl(int dt);

    void rfidTest(int del);
    void rot_test(int whl_vel_des, byte del, bool deb, float xGoal, float yGoal); // ####################################

    void goForward(int velL, int velR);
    void turnLeft(int velL, int velR);
    void turnRight(int velL, int velR);
    void stopMoving();
    int checkCurrent(byte PIN_CURRENT_SENSOR);
};

#endif // TWO_WHEELED_ROBOT_H
