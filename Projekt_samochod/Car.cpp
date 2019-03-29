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

