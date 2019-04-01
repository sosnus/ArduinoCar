#include "Car.h"

#define A_ENABLE    2 //PWM
#define A_PHASE     46  //0 - przod, 1 - tyl DIGITAL
  
#define B_ENABLE    3 //PWM
#define B_PHASE     48  //0 - przod, 1 - tyl DIGITAL

Car car;

void setup() 
{
  // put your setup code here, to run once:
  car.Init();
  Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  
  if(car.GetDistanceF() > 40)
    setEngines(150);
  else if(car.GetDistanceF() < 40)
    setEngines(0);
  
  /*
  Serial.print("Distance: "); 
  Serial.print(car.GetDistanceF()); 
  Serial.println(" cm");
  delay(500);
  */
}

void setEngines(int power)
{
    car.SetPowerLevel("left", power);
    car.SetPowerLevel("right", power);
}
