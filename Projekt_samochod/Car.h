/*
#include <avr/pgmspace.h>

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#define US_FRONT_TRIGGER_PIN  	8
#define US_FRONT_ECHO_PIN   	9
#define US_BACK_TRIGGER_PIN   	10
#define US_BACK_ECHO_PIN    	11
#define US_LEFT_TRIGGER_PIN   	6
#define US_LEFT_ECHO_PIN    	7
#define US_RIGHT_TRIGGER_PIN  	4
#define US_RIGHT_ECHO_PIN   	5

// Silniki, sterowanie PWM

#define A_ENABLE    2 //PWM
#define A_PHASE     46  //0 - przod, 1 - tyl DIGITAL  
#define B_ENABLE    3 //PWM
#define B_PHASE     48  //0 - przod, 1 - tyl DIGITAL
#define MODE      	44

//Silniki, wejście enkoderowe

#define ENCODER_LEFT  50  // Enkoder lewej strony
#define ENCODER_RIGHT 51  // Enkoder prawej strony  

class Car;
extern Car car;

class Car
{
  public:
		Car();

		double GetDistanceF();
		double GetDistanceB();
		double GetDistanceL();
		double GetDistanceR(); 

		void SetPowerLevel(String side, int level);
		
		uint64_t GetLeftEncoderCount();
		uint64_t GetRightEncoderCount();
	
	private:
		uint64_t leftEncoderCounter, rightEncoderCounter;
	
		static void EncodersInterruptLeft();
		static void EncodersInterruptRight();
};
*/