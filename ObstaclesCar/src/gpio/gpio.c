#include "gpio.h"

void setPinMode(char port, char pin, char mode)
{
	switch (port)
	{
	case PORT_B:
		if (mode == INPUT)
			bitClear(DDRB, pin);
		else if (mode == OUTPUT)
			bitSet(DDRB, pin);
		break;

	case PORT_C:
		if (mode == INPUT)
			bitClear(DDRC, pin);
		else if (mode == OUTPUT)
			bitSet(DDRC, pin);
		break;

	case PORT_D:
		if (mode == INPUT)
			bitClear(DDRD, pin);
		else if (mode == OUTPUT)
			bitSet(DDRD, pin);
		break;
	default:
		break;
	}
}

void writePin(char port, char pin, char data)
{
	switch (port)
	{
	case PORT_B:
		if (data == LOW)
			bitClear(PORTB, pin);
		else if (data == HIGH)
			bitSet(PORTB, pin);
		break;

	case PORT_C:
		if (data == LOW)
			bitClear(PORTC, pin);
		else if (data == HIGH)
			bitSet(PORTC, pin);
		break;

	case PORT_D:
		if (data == LOW)
			bitClear(PORTD, pin);
		else if (data == HIGH)
			bitSet(PORTD, pin);
		break;

	default:
		break;
	}
}

char readPin(char port, char pin)
{
	switch (port)
	{
	case PORT_B:
		return bitRead(PINB, pin);
		break;

	case PORT_C:
		return bitRead(PINC, pin);
		break;

	case PORT_D:
		return bitRead(PIND, pin);
		break;

	default:
		return -1;
		break;
	}
}