#include "Car.h"

Car::Car()
{
  
}

void Car::init()
{
  Serial.begin(9600);
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
    pinMode(ENCODER_LEFT, INPUT);
    pinMode(ENCODER_RIGHT, INPUT);

    //======== KOMPASS
    Wire.begin();
    qmc.init();
}

Car::~Car()
{
    Serial.println("car destructor");
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

void Car::setSide(int torqueLeft, int torqueRight, Direction dir)
{
  switch(dir)
  {
    case LEFT:
      turnCar(-torqueLeft,torqueRight);
    break;
    case RIGHT:
      turnCar(torqueLeft,-torqueRight);
    break;
  }
}

void Car::turnCar(int leftTorque, int rightTorque)
{
  int x,y,z;
  bool check = true;
  
    //qmc.reset();
    qmc.measure();
    x = qmc.getX();
    y = qmc.getY();
    z = qmc.getZ();
    startAngle = qmc.getAngle();
    Serial.print("x=");
    Serial.print(x);
    Serial.print("\ty=");
    Serial.print(y);
    Serial.print("\tz=");
    Serial.print(z);
    Serial.print("\tStart=");
    Serial.println(startAngle);


  while(check)
  {
    setPowerLevel(LEFT, leftTorque);
    setPowerLevel(RIGHT, rightTorque);

    //qmc.reset();
    qmc.measure();
    x = qmc.getX();
    y = qmc.getY();
    z = qmc.getZ();
    actualAngle = qmc.getAngle();
    Serial.print("x=");
    Serial.print(x);
    Serial.print("\ty=");
    Serial.print(y);
    Serial.print("\tz=");
    Serial.print(z);
    Serial.print("\tActual=");
    Serial.println(actualAngle);
    check = checkRightAngle();
  }

  setPowerLevel(LEFT, 0);
  setPowerLevel(RIGHT, 0);
}

bool Car::checkRightAngle()
{ 
  int checkAng = actualAngle;

  if(startAngle > 269 && actualAngle >= 0)
    checkAng += 360; 
  
  if(abs(checkAng - startAngle) > 88)
    return false;
  else 
    return true;
}


void Car::squaredDrive(int torque, int &leftEncoder, int &rightEncoder) // jazda po prostokącie 
{ 
  straightAndTurn(torque, 40, leftEncoder, rightEncoder); 
  straightAndTurn(torque, 20, leftEncoder, rightEncoder); 
  straightAndTurn(torque, 40, leftEncoder, rightEncoder); 
  straightAndTurn(torque, 20, leftEncoder, rightEncoder); 
} 
 
void Car::straightAndTurn(int torque, int amountEncoder, int &leftEncoder, int &rightEncoder) //jedz prosto przez ilość sygnałów z enkodera i skręć 
{    
  leftEncoder=0;
  rightEncoder=0;
  
  while(leftEncoder < amountEncoder) 
  {
  Serial.print("L=");
  Serial.print(leftEncoder);
  Serial.print("\tR=");
  Serial.println(rightEncoder);
    setPowerLevel(LEFT, torque); 
    setPowerLevel(RIGHT, torque); 
 
    //tu później wstawić sprawdzanie przeszkód 
  } 
  setSide(torque,torque,LEFT);
}
 
void Car::straightDrive(int torque, Direction dir) // zabezpieczyć lepiej  
{ 
  Direction newDir; 
   
  newDir = changeDir(dir); 
 
  while(getDistance(newDir) < 60 && getDistance(FRONT) > 40) 
  { 
    setPowerLevel(LEFT, torque); 
    setPowerLevel(RIGHT, torque); 
    //Zliczanie sygnałów enkodera 
  } 
} 
 
Direction changeDir(Direction dir) 
{ 
  if(dir == LEFT) 
    return RIGHT; 
  else 
    return LEFT;  
} 


