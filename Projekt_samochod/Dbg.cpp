#include "Arduino.h"
#include "Dbg.h"


enum frameErr
{
    ok = 0, //OK
    badFrame = 1, //Without '@'
    badCmd = 2,
    endMethodReached = 3,
    //...
    przykladktorystam = 40 //przy "wartości" ostatniej przecinka nie stosuje się
};



Dbg::Dbg()
{
}

// __attribute__ ((weak))
void Dbg::led(int state)
{
    Serial1.write("LED METHOD TO OVERRIDE");
    digitalWrite(LED_BUILTIN, state);
}

void Dbg::initialisation()
{
    pinMode(LED_BUILTIN, OUTPUT);
    // Serial.begin(57600);
    Serial1.begin(57600);
    // Serial.println("Dbg init USB");
    Serial1.println(" ");
    Serial1.println("======================================");
    Serial1.println("Dbg init BT");
}

int Dbg::checkCmd()
{
    if (Serial1.available())
    {
        int inByte = Serial1.read();
        if (inByte == '@')
        {
            Serial1.write("EVENT:");
            delay(50);
            inByte = Serial1.read();
            if (inByte == 'L')
            {
                Serial1.write(" TYPE=<LED>");
                inByte = Serial1.read();
                if (inByte == '1')
                {
                    Serial1.write("CMD=<LED_ON>");
                    digitalWrite(LED_BUILTIN, 1);
                    return frameErr.ok;
                }
                else
                {
                    Serial1.write("CMD=<LED_OFF>");
                    digitalWrite(LED_BUILTIN, 0);
                    return frameErr.ok;
                }
            }
            else if (inByte == 'M')
            {
                Serial1.write(" TYPE=<M>");
                    return frameErr.ok;
            }
            else
            {
                Serial1.write("BAD_CMD");
                Serial1.write("<");
                Serial1.write(inByte);
                Serial1.write(">");
                    return  frameErr.badCmd;
            }
        }    // end '@' EVENT
        else // not '@'
        {

            while (inByte != -1)
            {
                if (inByte == 13 || inByte == 10)
                {

                    Serial1.write(";"); //<CR or LF>
                }
                else
                {
                Serial1.write("ERR_CLEAN_BUFF  ");
                    Serial1.write("<");
                    Serial1.write(inByte);
                    Serial1.write(">");
                }
                inByte = Serial1.read();
            }
            return  frameErr.badFrame;
        } // end  // not '@'

    } // if (Serial1.available())
    return  frameErr.endMethodReached;

} //end  Dbg::checkCmd()

int Dbg::getY()
{
    Serial.println("Dbg getY USB");
    Serial1.println("Dbg getY BT");
    return 5;
}