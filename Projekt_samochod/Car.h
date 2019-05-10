#ifndef Car_h
#define Car_h
#include <avr/pgmspace.h>
#include <Arduino.h>

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

class Car;
extern Car car;

class Car
{
  public:
    int leftEncoderCounter, rightEncoderCounter;
    
    Car();
  
  	double getDistance(Direction dir);
  	void setPowerLevel(Direction dir, int level);
  	int getEncoderCount(Direction dir);
};


void encodersInterruptLeft();
void encodersInterruptRight();

#endif
