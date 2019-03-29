#include <avr/pgmspace.h>

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif


#define US_FRONT_TRIGGER_PIN  8
#define US_FRONT_ECHO_PIN   9
#define US_BACK_TRIGGER_PIN   10
#define US_BACK_ECHO_PIN    11
#define US_LEFT_TRIGGER_PIN   6
#define US_LEFT_ECHO_PIN    7
#define US_RIGHT_TRIGGER_PIN  4
#define US_RIGHT_ECHO_PIN   5


class Car
{


  public:
    void Init();

    double GetDistanceF();
    double GetDistanceB();
    double GetDistanceL();
    double GetDistanceR();
  
};

