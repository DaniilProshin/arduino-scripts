#include <SoftwareSerial.h>
#include <SPI.h>

void setup() 
{
  Serial.begin(115200);
  SPI.begin();
}

void loop() 
{
  if(Serial.available())
    SPI.transfer(Serial.read());
}





/*
bool writeLin(uint8_t *data, uint8_t data_size)
{}
bool readLin(uint8_t *data, uint8_t data_size)
{}
bool writeRequestLin()
{}
bool writeResponceLin()
{}
*/
