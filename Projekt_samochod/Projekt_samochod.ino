/*
  Multiple Serial test

  Receives from the main serial port, sends to the others.
  Receives from serial port 1, sends to the main serial (Serial 0).

  This example works only with boards with more than one serial like Arduino Mega, Due, Zero etc.

  The circuit:
  - any serial device attached to Serial port 1
  - Serial Monitor open on Serial port 0

  created 30 Dec 2008
  modified 20 May 2012
  by Tom Igoe & Jed Roach
  modified 27 Nov 2015
  by Arturo Guadalupi

  This example code is in the public domain.
*/


void setup() {
  // initialize both serial ports:
  // Serial.begin(9600);
  // Serial1.begin(9600);
  Serial.begin(57600);
  Serial1.begin(57600);
}

void loop() {
  // read from port 1, send to port 0:
  if (Serial1.available()) {
    int inByte = Serial1.read();
    Serial.write(inByte);
  }

  // read from port 0, send to port 1:
  if (Serial.available()) {
    int inByte = Serial.read();
    Serial1.write(inByte);
  }
}

// #include "Car.h"

// #define A_ENABLE    2 //PWM
// #define A_PHASE     46  //0 - przod, 1 - tyl DIGITAL
  
// #define B_ENABLE    3 //PWM
// #define B_PHASE     48  //0 - przod, 1 - tyl DIGITAL

// Car car;

// void setup() 
// {
//   // put your setup code here, to run once:
//   car.Init();
//   Serial.begin(9600);
// }

// void loop() 
// {
//   // put your main code here, to run repeatedly:
  
//   if(car.GetDistanceF() > 40)
//     setEngines(150);
//   else if(car.GetDistanceF() < 40)
//     setEngines(0);
  
//   /*
//   Serial.print("Distance: "); 
//   Serial.print(car.GetDistanceF()); 
//   Serial.println(" cm");
//   delay(500);
//   */
// }

// void setEngines(int power)
// {
//     car.SetPowerLevel("left", power);
//     car.SetPowerLevel("right", power);
// }
