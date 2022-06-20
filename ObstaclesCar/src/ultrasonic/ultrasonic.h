#ifndef SENSOR_H_
#define SENSOR_H_

#include <avr/interrupt.h>
#include <util/delay.h>
#include "gpio/gpio.h"

void initUltrasonic(char port, char trigger_pin, char echo_pin);
float getUltrasonicDistance();

#endif