#undef F_CPU
#define F_CPU 1000000UL

#include "motors/motors.h"
#include "ultrasonic/ultrasonic.h"

int main()
{
  initUltrasonic(PORT_D, PD1, PD2);
  initMotors(PORT_C, PC0, PC1, PC2, PC3);

  while (1)
  {
    if (getUltrasonicDistance() > 30)
    {
      movForward();
    }
    else
    {
      // Mov A Little Backward
      movBackward();
      _delay_ms(500);
      stop();

      // Measure Distance At Right
      rotRight();
      _delay_ms(250);
      stop();
      float rDistance = getUltrasonicDistance();

      // Measure Distance At Left
      rotLeft();
      _delay_ms(500);
      stop();
      float lDistance = getUltrasonicDistance();

      _delay_ms(500);
      if (rDistance > lDistance)
      {
        rotRight();
        _delay_ms(500);
      }
    }
  }
}