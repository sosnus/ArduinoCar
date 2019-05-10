#define DBG_STA 1

#include "Car.h"

#if DBG_STA
#include "Arduino.h"
#include "Dbg.h"
Dbg dbg;
#endif

Car car;

void setup()
{
  Serial.begin(9600);
#if DBG_STA
  dbg.initialisation();
#endif
}

void loop()
{
  // put your main code here, to run repeatedly:
#if DBG_STA
  dbg.checkCmd();
#endif

  Serial.print("Distance: ");
  Serial.print(car.getDistanceF());
  Serial.println(" cm");
  delay(500);
}