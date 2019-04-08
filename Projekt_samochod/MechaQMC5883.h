#ifndef Mecha_QMC5883
#define Mecha_QMC5883

#include "Arduino.h"
#include "Wire.h"

#define QMC5883_ADDR 0x0D


//REG CONTROL

//0x09

#define Mode_Standby    0b00000000
#define Mode_Continuous 0b00000001

#define ODR_10Hz        0b00000000
#define ODR_50Hz        0b00000100
#define ODR_100Hz       0b00001000
#define ODR_200Hz       0b00001100

#define RNG_2G          0b00000000
#define RNG_8G          0b00010000

#define OSR_512         0b00000000
#define OSR_256         0b01000000
#define OSR_128         0b10000000
#define OSR_64          0b11000000


class MechaQMC5883{
public:


void setAddress(int addr);

void init(); //init qmc5883

void setMode(int mode,int odr,int rng,int osr); // setting
void softReset(); //soft RESET
int getX(void) const { return this->x; }
int getY(void) const { return this->y; }
int getZ(void) const { return this->z; }
void read();
void read(int* x,int* y,int* z); //reading
void read(int* x,int* y,int* z,int* a);
void read(int* x,int* y,int* z,float* a);
float azimuth(int* a,int* b);
float azimuth(){return azimuth(&y,&x);}
private:
int x,y,z;
void WriteReg(int Reg,int val);
int address = QMC5883_ADDR;

};



#endif
