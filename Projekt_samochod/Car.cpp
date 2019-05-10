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
  pinMode(LEFT_PWM, OUTPUT);
  pinMode(LEFT_IN1, OUTPUT);
  pinMode(LEFT_IN2, OUTPUT);
  
  pinMode(RIGHT_PWM, OUTPUT);
  pinMode(RIGHT_IN1, OUTPUT);
  pinMode(RIGHT_IN2, OUTPUT);

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

  if (dir == Direction::LEFT) {
    if (level > 0) {
      // do przodu
      digitalWrite(LEFT_IN1, false);
      digitalWrite(LEFT_IN2, true);
      analogWrite(LEFT_PWM, level);
    } else if (level < 0) {
      // do tyłu
      digitalWrite(LEFT_IN1, true);
      digitalWrite(LEFT_IN2, false);
      analogWrite(LEFT_PWM, -level);
    } else {
      // stop (soft)
      digitalWrite(LEFT_IN1, true);
      digitalWrite(LEFT_IN2, true);
      analogWrite(LEFT_PWM, 0);
    }
  }
  
  if (dir == Direction::RIGHT) {
    if (level > 0) {
      // do przodu
      digitalWrite(RIGHT_IN1, true);
      digitalWrite(RIGHT_IN2, false);
      analogWrite(RIGHT_PWM, level);
    } else if (level < 0) {
      // do tyłu
      digitalWrite(RIGHT_IN1, false);
      digitalWrite(RIGHT_IN2, true);
      analogWrite(RIGHT_PWM, -level);
    } else {
      // stop (soft)
      digitalWrite(RIGHT_IN1, true);
      digitalWrite(RIGHT_IN2, true);
      analogWrite(RIGHT_PWM, 0);
    }
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
