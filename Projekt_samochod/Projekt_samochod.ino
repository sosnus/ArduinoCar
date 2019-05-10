 /* TODO: Staszek */ // #include "Arduino.h"

#include "Car.h"

Car car;
 /* TODO: Staszek */ // Dbg dbg;

void setup()
{
  Serial.begin(9600);

  //włączenie detekcji przerwań przez encoder 
  attachInterrupt(digitalPinToInterrupt(ENCODER_LEFT), &encodersInterruptLeft, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCODER_RIGHT), &encodersInterruptRight, CHANGE);
    /* TODO: Staszek */ // dbg.initialisation();
}

void loop()
{

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
