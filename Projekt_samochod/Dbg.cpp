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

void Dbg::checkCmd()
{
    if (Serial1.available())
    {
        Serial1.write("EVENT: TYPE=");
        int inByte = Serial1.read();
        Serial1.write("<");
        Serial1.write(inByte);
        Serial1.write(">");
        delay(100);
        switch (inByte)
        {
        case 'L':
        {
            inByte = Serial1.read();
            Serial1.write(" CMD=<");
            Serial1.write(inByte);
            Serial1.write(">");
            if (inByte == '1')
            {
                Serial1.write("LED_ON");
                digitalWrite(LED_BUILTIN, 1);
            }
            else
            {
                Serial1.write("LED_OFF");
                digitalWrite(LED_BUILTIN, 0);
            }
        }
        break;
                case '\n':
        {
            Serial1.write("<");
            Serial1.write("CR");
            Serial1.write(">");
        }             
           case '\r':
        {
            Serial1.write("<");
            Serial1.write("LF");
            Serial1.write(">");
        }
        break;
        default:
        {
                Serial1.write("BAD_CMD");
            Serial1.write("<");
            Serial1.write(inByte);
            Serial1.write(">");
        }

            break;
        }

        // while (Serial1.available())
        // {
        //  int inByte = Serial1.read();
        //   Serial.write(inByte);
        //   Serial.print(" ");
        // }
        Serial.println(";");
        delay(100);
    }
}

int Dbg::getY()
{
    Serial.println("Dbg getY USB");
    Serial1.println("Dbg getY BT");
    return 5;
}