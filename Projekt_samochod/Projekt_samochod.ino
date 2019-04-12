#include "Car.h"

#define A_ENABLE 2 //PWM
#define A_PHASE 46 //0 - przod, 1 - tyl DIGITAL

#define B_ENABLE 3 //PWM
#define B_PHASE 48 //0 - przod, 1 - tyl DIGITAL

Car car;

void setup()
{
  // // // // // // car.Init();
  Serial.begin(57600);
  Serial1.begin(57600);
}

void loop()
{
  if (Serial1.available())
  {
    int inByte = Serial1.read();
    Serial.write(inByte);
  }

  if (Serial.available())
  {
    int inByte = Serial.read();
    Serial1.write(inByte);
  }

  // put your main code here, to run repeatedly:

  /*
  if(car.GetDistanceF() > 40)
    setEngines(150);
  else if(car.GetDistanceF() < 40)
    setEngines(0);
    */

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
