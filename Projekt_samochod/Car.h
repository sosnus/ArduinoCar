#ifndef Car_h
#define Car_h
#include <avr/pgmspace.h>
#include <Arduino.h>
#include <Math.h>
#include "QMC5883.h"

enum Direction
{
    FRONT = 0, 
    RIGHT = 1,
    LEFT = 2,
    BACK = 3
};

#define ENCODER_LEFT 50	// Enkoder lewej strony
#define ENCODER_RIGHT 51 // Enkoder prawej strony

// Sensory Odległości 
#define US_FRONT_TRIGGER_PIN 8
#define US_FRONT_ECHO_PIN 9
#define US_BACK_TRIGGER_PIN 10
#define US_BACK_ECHO_PIN 11
#define US_LEFT_TRIGGER_PIN 6
#define US_LEFT_ECHO_PIN 7
#define US_RIGHT_TRIGGER_PIN 4
#define US_RIGHT_ECHO_PIN 5

//Silniki
#define LEFT_PWM   3
#define LEFT_IN1    47  // in1 (l298n)
#define LEFT_IN2    46  // in2 (l298n)

#define RIGHT_PWM   2
#define RIGHT_IN1   45  // in3 (l298n)
#define RIGHT_IN2   44  // in4 (l298n)

class Car
{
  public:
    
    Car();
    ~Car();
    
    void init(); 
  	double getDistance(Direction dir);
  	void setPowerLevel(Direction dir, int level);
    void setSide(int torqueLeft, int torqueRight, Direction dir);
    void turnCar(int leftTorque, int rightTorque);
    bool checkRightAngle();
    void squaredDrive(int torque, int &leftEncoder, int &rightEncoder);
    void straightAndTurn(int torque, int amountEncoder, int &leftEncoder, int &rightEncoder);
    void straightDrive(int torque, Direction dir); 
    Direction changeDir(Direction dir); 

  public:
    float startAngle, actualAngle;
    QMC5883 qmc;
};



/*
void cmd_qmc(void)
{
  char buffer[64];

  qmc.reset();
  while (Serial.available() == 0)
  {
    qmc.measure();
    int16_t x = qmc.getX();
    int16_t y = qmc.getY();
    int16_t z = qmc.getZ();

    sprintf(buffer, "\n X=%5d Y=%5d Z=%5d", x, y, z);
    Serial.print(buffer);
  }
  
  while (Serial.available())
    Serial.read();  
}
*/
#endif

