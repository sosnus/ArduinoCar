#define DBG_STA 1

// #include "Car.h"

#if DBG_STA
 #include "Arduino.h"
 #include "Dbg.h"
#endif

#define A_ENABLE    2 //PWM
#define A_PHASE     46  //0 - przod, 1 - tyl DIGITAL
  
#define B_ENABLE    3 //PWM
#define B_PHASE     48  //0 - przod, 1 - tyl DIGITAL

// Car car;
#if DBG_STA
 Dbg dbg;
#endif
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
#if DBG_STA
    dbg.initialisation();
#endif
}

void loop() 
{
  // put your main code here, to run repeatedly:
  
  if(car.getDistanceF() > 40)
    setEngines(150);
  else if(car.getDistanceF() < 40)
    setEngines(0);
  */
  /*
  Serial.print("Distance: "); 
  Serial.print(car.getDistanceF()); 
  Serial.println(" cm");
  delay(500);
  */
}
/*
void setEngines(int power)
{
    car.setPowerLevel("left", power);
    car.setPowerLevel("right", power);
}
*/