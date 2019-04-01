#include "Car.h"

void Car::Init()
{
  pinMode(US_FRONT_TRIGGER_PIN, OUTPUT);
  pinMode(US_FRONT_ECHO_PIN, INPUT);
  pinMode(US_BACK_TRIGGER_PIN, OUTPUT);
  pinMode(US_BACK_ECHO_PIN, INPUT);
  pinMode(US_LEFT_TRIGGER_PIN, OUTPUT);
  pinMode(US_LEFT_ECHO_PIN, INPUT);
  pinMode(US_RIGHT_TRIGGER_PIN, OUTPUT);
  pinMode(US_RIGHT_ECHO_PIN, INPUT);

  pinMode(A_PHASE, OUTPUT);
  pinMode(A_ENABLE, OUTPUT);
  pinMode(B_PHASE, OUTPUT);
  pinMode(B_ENABLE, OUTPUT);

  pinMode(ENCODER_LEFT, INPUT);
  pinMode(ENCODER_RIGHT, INPUT);

  SetPowerLevel("left", 0);
  SetPowerLevel("right", 0);
}


double Car::GetDistanceF()
{
  digitalWrite(US_FRONT_TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(US_FRONT_TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(US_FRONT_TRIGGER_PIN, LOW);
  int duration = pulseIn(US_FRONT_ECHO_PIN, HIGH);

  return duration*0.034/2;
}

double Car::GetDistanceB()
{
  digitalWrite(US_BACK_TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(US_BACK_TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(US_BACK_TRIGGER_PIN, LOW);
  int duration = pulseIn(US_BACK_ECHO_PIN, HIGH);

  return duration*0.034/2;
}

double Car::GetDistanceL()
{
  digitalWrite(US_LEFT_TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(US_LEFT_TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(US_LEFT_TRIGGER_PIN, LOW);
  int duration = pulseIn(US_LEFT_ECHO_PIN, HIGH);

  return duration*0.034/2;
}

double Car::GetDistanceR()
{
  digitalWrite(US_RIGHT_TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(US_RIGHT_TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(US_RIGHT_TRIGGER_PIN, LOW);
  int duration = pulseIn(US_RIGHT_ECHO_PIN, HIGH);

  return duration*0.034/2;
}

void Car::SetPowerLevel(String side, int level)
{
  level = constrain(level, -255, 255);
  
  if (side == "right") {
    if (level > 0) {
      // do przodu
      digitalWrite(A_PHASE, 1);
      analogWrite(A_ENABLE, level);
    } else if (level < 0) {
      // do tyłu
      digitalWrite(A_PHASE, 0);
      analogWrite(A_ENABLE, -level);
    } else {
      // stop
      digitalWrite(A_PHASE, 0);
      analogWrite(A_ENABLE, 0);
    }
  }
  
  if (side == "left") {
    if (level > 0) {
      // do przodu
      digitalWrite(B_PHASE, 1);
      analogWrite(B_ENABLE, level);
    } else if (level < 0) {
      // do tyłu
      digitalWrite(B_PHASE, 0);
      analogWrite(B_ENABLE, -level);
    } else {
      // stop
      digitalWrite(B_PHASE, 0);
      analogWrite(B_ENABLE, 0);
    }
  } 
}
