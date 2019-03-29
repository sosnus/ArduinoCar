
#define US_FRONT        0
#define US_FRONT_TRIGGER_PIN  8
#define US_FRONT_ECHO_PIN   9

#define US_BACK         1
#define US_BACK_TRIGGER_PIN   10
#define US_BACK_ECHO_PIN    11

#define US_LEFT         2
#define US_LEFT_TRIGGER_PIN   6
#define US_LEFT_ECHO_PIN    7

#define US_RIGHT        3
#define US_RIGHT_TRIGGER_PIN  4
#define US_RIGHT_ECHO_PIN   5

#define A_ENABLE    2 //PWM
#define A_PHASE     46  //0 - przod, 1 - tyl DIGITAL
  
#define B_ENABLE    3 //PWM
#define B_PHASE     48  //0 - przod, 1 - tyl DIGITAL

double getDistanceF();

void setup() 
{
  // put your setup code here, to run once:
  pinMode(US_FRONT_TRIGGER_PIN, OUTPUT);
  pinMode(US_FRONT_ECHO_PIN, INPUT);

    // Silniki
  pinMode(A_PHASE, OUTPUT);
  pinMode(A_ENABLE, OUTPUT);
  pinMode(B_PHASE, OUTPUT);
  pinMode(B_ENABLE, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  
  Serial.print("Distance: "); 
  Serial.print(getDistanceF()); 
  Serial.println(" cm");
  delay(500);
}


double getDistanceF()
{
  digitalWrite(US_FRONT_TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(US_FRONT_TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(US_FRONT_TRIGGER_PIN, LOW);
  int duration = pulseIn(US_FRONT_ECHO_PIN, HIGH);
  double distanceCm = duration*0.034/2;

  return distanceCm;
}

