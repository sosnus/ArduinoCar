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

  //włączenie detekcji przerwań przez encoder 
  attachInterrupt(digitalPinToInterrupt(ENCODER_LEFT), &encodersInterruptLeft, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCODER_RIGHT), &encodersInterruptRight, CHANGE);
}

void loop()
{
#if DBG_STA
  dbg.checkCmd();
#endif

 if(car.getDistance(FRONT) > 40)
    setEngines(150);
  else if(car.getDistance(FRONT) < 40)
    setEngines(0);

  Serial.print("Distance: "); 
  Serial.print(car.getDistance(FRONT)); 
  Serial.println(" cm");
  delay(500);  
}

void setEngines(int power)
{
  car.setPowerLevel(Direction::LEFT, power);
  car.setPowerLevel(Direction::RIGHT, power);
}
