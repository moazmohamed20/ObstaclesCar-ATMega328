#include "motors.h"

char motorPort;
char rightMotorFwd;
char rightMotorRev;
char leftMotorFwd;
char leftMotorRev;

void initMotors(char port, char in1, char in2, char in3, char in4)
{
    setPinMode(port, in1, OUTPUT);
    setPinMode(port, in2, OUTPUT);
    setPinMode(port, in3, OUTPUT);
    setPinMode(port, in4, OUTPUT);

    motorPort = port;
    leftMotorFwd = in1;
    leftMotorRev = in2;
    rightMotorRev = in3;
    rightMotorFwd = in4;
}

void movForward()
{
    writePin(motorPort, rightMotorFwd, HIGH);
    writePin(motorPort, rightMotorRev, LOW);
    writePin(motorPort, leftMotorFwd, HIGH);
    writePin(motorPort, leftMotorRev, LOW);
}

void movBackward()
{
    writePin(motorPort, rightMotorFwd, LOW);
    writePin(motorPort, rightMotorRev, HIGH);
    writePin(motorPort, leftMotorFwd, LOW);
    writePin(motorPort, leftMotorRev, HIGH);
}

void rotLeft()
{
    writePin(motorPort, rightMotorFwd, HIGH);
    writePin(motorPort, rightMotorRev, LOW);
    writePin(motorPort, leftMotorFwd, LOW);
    writePin(motorPort, leftMotorRev, HIGH);
}

void rotRight()
{
    writePin(motorPort, rightMotorFwd, LOW);
    writePin(motorPort, rightMotorRev, HIGH);
    writePin(motorPort, leftMotorFwd, HIGH);
    writePin(motorPort, leftMotorRev, LOW);
}

void stop()
{
    writePin(motorPort, rightMotorFwd, LOW);
    writePin(motorPort, rightMotorRev, LOW);
    writePin(motorPort, leftMotorFwd, LOW);
    writePin(motorPort, leftMotorRev, LOW);
}