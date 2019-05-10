#include "Car.h"

Car car;
int torque = 150;

void setup()
{
  Serial.begin(9600);

  car.init();

  //włączenie detekcji przerwań przez encoder 
  //attachInterrupt(digitalPinToInterrupt(ENCODER_LEFT), &encodersInterruptLeft, CHANGE);
  //attachInterrupt(digitalPinToInterrupt(ENCODER_RIGHT), &encodersInterruptRight, CHANGE);
  Serial.print("Distance: "); 
}



void loop()
{
  if(car.getDistance(FRONT) > 40)
    setEngines(150);
  else if(car.getDistance(FRONT) < 40)
  {
    //setEngines(0);
    car.setSide(torque,torque,LEFT);
  }

  car.qmc.measure();
  Serial.print("Distance: "); 
  Serial.print(car.getDistance(FRONT)); 
  Serial.print(" cm \t Angle: ");
  Serial.println(car.qmc.getAngle());
  delay(500);  
}

void setEngines(int power)
{
  car.setPowerLevel(Direction::LEFT, power);
  car.setPowerLevel(Direction::RIGHT, power);
}


