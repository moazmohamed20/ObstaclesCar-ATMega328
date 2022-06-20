#include "ultrasonic.h"

char sensorPort;
char sensorEchoPin;
char sensorTriggerPin;

void INT0_init()
{
	sei();
	bitSet(EIMSK, INT0);  // Enable INT0
	bitSet(EICRA, ISC00); // Any Logical Change on INT0 Generates An Interrupt Request
}

void initUltrasonic(char port, char triggerPin, char echoPin)
{
	setPinMode(port, triggerPin, OUTPUT); // Set Trigger Pin As Output
	setPinMode(port, echoPin, INPUT);	  // Set Echo Pin As Input
	INT0_init();						  // Enable INT0 To Sense Echo Rising & Falling Edges

	sensorTriggerPin = triggerPin;
	sensorEchoPin = echoPin;
	sensorPort = port;
}

void trigger()
{
	writePin(sensorPort, sensorTriggerPin, HIGH); // Set The Trigger Pin High
	_delay_us(10);								  // Keep The Trigger Pin High For 10 us
	writePin(sensorPort, sensorTriggerPin, LOW);  // Clear The Trigger Pin
}

short counts = 0;
float getUltrasonicDistance()
{
	// Fire The Trigger
	trigger();

	// Wait Until Echo Goes HIGH, Or Timeout Is Reached
	char wait = 0, timeout = 255;
	while (readPin(sensorPort, sensorEchoPin) == 0)
		if (wait++ == timeout)
			return 0;

	// Wait Until Echo Goes LOW
	while (readPin(sensorPort, sensorEchoPin) == 1)
		;

	// Wait 10 ms To Separate Between This Echo & The Next Trigger
	_delay_ms(10);

	return counts * 0.0340 * 0.5;
}

ISR(INT0_vect)
{
	// On Echo Rising Edge
	if (readPin(sensorPort, sensorEchoPin) == 1)
	{
		TCNT1 = 0;			  // Reset TIMER 1 To 0
		bitSet(TCCR1B, CS10); // Start TIMER 1,  Prescaler = 1 => (1 Count = 1 us)
	}
	// On Echo Falling Edge
	else
	{
		bitClear(TCCR1B, CS10); // Stop TIMER 1
		counts = TCNT1;			// Store The Number Of TIMER 1 Counts (Each Count = 1 us)
	}
}
