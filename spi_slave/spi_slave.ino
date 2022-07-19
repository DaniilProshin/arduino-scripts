#include <SPI.h>

void setup() {
  Serial.begin(115200);
  SPCR |= _BV(SPE);   
  SPI.attachInterrupt();
}

static byte c=0;
  
ISR(SPI_STC_vect) {

    c = SPDR; 
    Serial.println(c);
    SPDR=0x0A;
    }


void loop() {
  // put your main code here, to run repeatedly:

}
