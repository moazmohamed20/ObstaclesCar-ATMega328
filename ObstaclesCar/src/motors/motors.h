#ifndef MOTORS_H_
#define MOTORS_H_

#include <util/delay.h>
#include "gpio/gpio.h"

void initMotors(char port, char in1, char in2, char in3, char in4);
void movForward();
void movBackward();
void rotLeft();
void rotRight();
void stop();

#endif