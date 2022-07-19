#include <SPI.h>

uint8_t protectID(uint8_t id);

void setup() {
  Serial.begin(115200);
}

void loop() {
  uint8_t checksum;
  uint8_t id = protectID(1); 
  Serial.write(0x55);
  Serial.write(id);
  Serial.write("11111111");
  Serial.write(checksum);
  Serial.flush();
}

uint8_t protectID(uint8_t id)
{
  uint8_t  pid;       // result = protected ID
  uint8_t  tmp;       // temporary variable for calculating parity bits
  // copy (unprotected) ID
  pid = id;
  // protect ID  with parity bits
  pid  = (uint8_t) (pid & 0x3F);                                          // clear upper bit 6&7
  tmp  = (uint8_t) ((pid ^ (pid>>1) ^ (pid>>2) ^ (pid>>4)) & 0x01);       // -> pid[6] = PI0 = ID0^ID1^ID2^ID4
  pid |= (uint8_t) (tmp << 6);
  tmp  = (uint8_t) (~((pid>>1) ^ (pid>>3) ^ (pid>>4) ^ (pid>>5)) & 0x01); // -> pid[6] = PI1 = ~(ID1^ID3^ID4^ID5)
  pid |= (uint8_t) (tmp << 7);
  // return protected identifier
  return pid;
} // lin_bus::protectID()
