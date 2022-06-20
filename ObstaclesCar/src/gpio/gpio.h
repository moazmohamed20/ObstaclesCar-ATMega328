#ifndef GPIO_H_
#define GPIO_H_

#include <avr/io.h>
#include "macros.h"

// Ports
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'
// Pin Modes
#define INPUT 0
#define OUTPUT 1
// Pin Data
#define LOW 0
#define HIGH 1

void setPinMode(char port, char pin, char mode);
void writePin(char port, char pin, char data);
char readPin(char port, char pin);

#endif