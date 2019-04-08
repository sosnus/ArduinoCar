#include "Car.h"
#include "MechaQMC5883.h"

#define A_ENABLE    2 //PWM
#define A_PHASE     46  //0 - przod, 1 - tyl DIGITAL
  
#define B_ENABLE    3 //PWM
#define B_PHASE     48  //0 - przod, 1 - tyl DIGITAL

Car car;
MechaQMC5883 qmc;
void setup() 
{
  // put your setup code here, to run once:
  car.Init();
  qmc.init();
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

void QMC_test(){
  qmc.read();
  float a = qmc.azimuth();// Y X jak 0 to oś Y wskazuje na północ
  Serial.print("x: ");
  Serial.print(qmc.getX());
  Serial.print("  y: ");
  Serial.print(qmc.getY());
  Serial.print("  z: ");
  Serial.print(qmc.getZ());
  Serial.print("  a: ");
  Serial.println(a);
  delay(100);
}

void QMC_testAllAzim(){
  int x,y,z;
  qmc.read(&x,&y,&z);
  Serial.print("aXY: ");
  Serial.print(qmc.azimuth(&x,&y));
  Serial.print(" aXZ: ");
  Serial.print(qmc.azimuth(&x,&z));
  Serial.print(" aYX: ");
  Serial.print(qmc.azimuth(&y,&x));
  Serial.print(" aYZ: ");
  Serial.print(qmc.azimuth(&y,&z));
  Serial.print("aZX: ");
  Serial.print(qmc.azimuth(&z,&x));
  Serial.print(" aZY: ");
  Serial.println(qmc.azimuth(&z,&y));
  delay(100);
}