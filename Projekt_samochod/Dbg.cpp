#include "Arduino.h"
#include "Dbg.h"

Dbg::Dbg()
{

}


void Dbg::initialisation()
{
    Serial.begin(57600);
    Serial1.begin(57600);
    Serial.println("Dbg init USB");
    Serial1.println("Dbg init BT");
}



int Dbg::getY()
{
        Serial.println("Dbg getY USB");
    Serial1.println("Dbg getY BT");
    return 5;
}