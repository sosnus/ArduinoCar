#define DBG_STA 1

#include "Car.h"

#if DBG_STA
#include "Arduino.h"
#include "Dbg.h"
Dbg dbg;
#endif

#define A_ENABLE 2 //PWM
#define A_PHASE 46 //0 - przod, 1 - tyl DIGITAL

#define B_ENABLE 3 //PWM
#define B_PHASE 48 //0 - przod, 1 - tyl DIGITAL

Car car;

// #include <ISADefinitions.h>
#include <DueTimer.h>

bool state = false;
void dioda(){
state = !state;
digitalWrite(LED_BUILTIN,state);
}

//in setup:


void setup()
{
  Serial.begin(9600);
#if DBG_STA
  dbg.initialisation();
#endif
pinMode(LED_BUILTIN,OUTPUT);
Timer4.attachInterrupt(dioda);
Timer4.start(1000000);
}

void loop()
{
  // put your main code here, to run repeatedly:
#if DBG_STA
  dbg.checkCmd();
#endif

  /*
  if(car.getDistanceF() > 40)
    setEngines(150);
  else if(car.getDistanceF() < 40)
    setEngines(0);
  */
  Serial.print("Distance: ");
  Serial.print(car.getDistanceF());
  Serial.println(" cm");
  delay(500);
}
/*
void setEngines(int power)
{
    car.setPowerLevel("left", power);
    car.setPowerLevel("right", power);
}
*/