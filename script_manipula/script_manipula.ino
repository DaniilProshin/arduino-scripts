

#include <lin_bus.h>


#define LIN_TX PD1;
#define LIN_WK PD3;
#define LIN_EN PD4;

unsigned long baute = 9600;
uint8_t dataSize = 8;
uint8_t readData[dataSize];

lin_bus lin1(Serial1,LIN_V1,KIN_EN,LIN_WK,LIN_TX);

void setup() 
{
  time_t timeout = millis();
  Serial.begin(115200);

  lin1.slave(baute,1);
}

void loop() 
{
 int incId = lin1.read(readData,dataSize);
 if(incId == 1)
 {
   Serial.println("Received package:");
 }
 else if(lin1.available() == 2)
 {
  Serial.println("Received request form Master:");
 }
}
