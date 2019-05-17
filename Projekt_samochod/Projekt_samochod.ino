#include "Car.h"

Car car;
int torque = 255;

int leftEncoderCounter=0;
int rightEncoderCounter=0;

void setup()
{
  Serial.begin(9600);

  car.init();

  //włączenie detekcji przerwań przez encoder 
  attachInterrupt(digitalPinToInterrupt(ENCODER_LEFT), &encodersInterruptLeft, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCODER_RIGHT), &encodersInterruptRight, CHANGE);
  Serial.print("Distance: "); 
}



void loop()
{
  /*
  if(car.getDistance(FRONT) > 60)
    setEngines(150);
  else
  {
    setEngines(0);
    car.setSide(torque,torque,LEFT);
  }

  car.qmc.measure();
  Serial.print("Distance: "); 
  Serial.print(car.getDistance(FRONT)); 
  Serial.print(" cm \t Angle: ");
  Serial.println(car.qmc.getAngle());
  delay(500);  

  */

  car.squaredDrive(torque, leftEncoderCounter, rightEncoderCounter);
  
}

void setEngines(int power)
{
  car.setPowerLevel(Direction::LEFT, power);
  car.setPowerLevel(Direction::RIGHT, power);
}


void encodersInterruptRight()
{
  rightEncoderCounter++;
}

void encodersInterruptLeft()
{
  leftEncoderCounter++;
}

