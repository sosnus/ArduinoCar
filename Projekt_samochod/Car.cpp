#include "Car.h"

Car::Car()
{
    //======== Sensor Odległości
    pinMode(US_FRONT_TRIGGER_PIN, OUTPUT);
    pinMode(US_FRONT_ECHO_PIN, INPUT);
    pinMode(US_BACK_TRIGGER_PIN, OUTPUT);
    pinMode(US_BACK_ECHO_PIN, INPUT);
    pinMode(US_LEFT_TRIGGER_PIN, OUTPUT);
    pinMode(US_LEFT_ECHO_PIN, INPUT);
    pinMode(US_RIGHT_TRIGGER_PIN, OUTPUT);
    pinMode(US_RIGHT_ECHO_PIN, INPUT);

    //======== Silnik
    pinMode(A_PHASE, OUTPUT);
    pinMode(A_ENABLE, OUTPUT);
    pinMode(B_PHASE, OUTPUT);
    pinMode(B_ENABLE, OUTPUT);

    //======== ENCODERS
    car.leftEncoderCounter = 0;
    car.rightEncoderCounter = 0;
    pinMode(ENCODER_LEFT, INPUT);
    pinMode(ENCODER_RIGHT, INPUT);
}

double Car::getDistance(Direction dir)
{
    int trigger_pin = 0;
    int echo_pin = 0;
    switch (dir)
    {
      case FRONT:
      {
          trigger_pin = US_FRONT_TRIGGER_PIN;
          echo_pin = US_FRONT_ECHO_PIN;
          break;
      }
      case BACK:
      {
          trigger_pin = US_BACK_TRIGGER_PIN;
          echo_pin = US_BACK_ECHO_PIN;
          break;
      }
      case LEFT:
      {
          trigger_pin = US_LEFT_TRIGGER_PIN;
          echo_pin = US_LEFT_ECHO_PIN;
      }
      case RIGHT:
      {
          trigger_pin = US_RIGHT_TRIGGER_PIN;
          echo_pin = US_RIGHT_ECHO_PIN;
          break;
      }
    }
    digitalWrite(trigger_pin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigger_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger_pin, LOW);
    int duration = pulseIn(echo_pin, HIGH);
    return duration * 0.034 / 2;
}

void Car::setPowerLevel(Direction dir, int level)
{
    level = constrain(level, -255, 255);
    switch (dir)
    {
        case LEFT:
            if (level > 0)
            {
                // do przodu
                digitalWrite(B_PHASE, 1);
                analogWrite(B_ENABLE, level);
            }
            else if (level < 0)
            {
                // do tyłu
                digitalWrite(B_PHASE, 0);
                analogWrite(B_ENABLE, -level);
            }
            else
            {
                // stop
                digitalWrite(B_PHASE, 0);
                analogWrite(B_ENABLE, 0);
            }
            break;
        case RIGHT:
            if (level > 0)
            {
                // do przodu
                digitalWrite(A_PHASE, 1);
                analogWrite(A_ENABLE, level);
            }
            else if (level < 0)
            {
                // do tyłu
                digitalWrite(A_PHASE, 0);
                analogWrite(A_ENABLE, -level);
            }
            else
            {
                // stop
                digitalWrite(A_PHASE, 0);
                analogWrite(A_ENABLE, 0);
            }
            break;
    }
}


//======== ENCODERS


int Car::getEncoderCount(Direction dir)
{
  switch (dir)
  {
    case LEFT:
      return leftEncoderCounter;
      break;
    case RIGHT:
      return rightEncoderCounter;
      break;
  }
}

void encodersInterruptRight()
{
  car.rightEncoderCounter++;
}

void encodersInterruptLeft()
{
  car.leftEncoderCounter++;
}
