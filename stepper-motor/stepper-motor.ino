#include<Stepper.h>

Stepper m(200, 8, 9, 10, 11);

void setup()
{
  m.setSpeed(60);
//  Serial.begin(9600);
}

void loop()
{
//  m.step(2);
  delay(10);
}
