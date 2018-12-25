#include <SoftwareSerial.h> 
#define heartratePin A1
#include "Heartrate.h"

Heartrate heartrate(DIGITAL_MODE); ///< ANALOG_MODE or DIGITAL_MODE
SoftwareSerial BT(1, 0);
void setup() {
  Serial.begin(9600);
  BT.begin(115200);
  BT.println("Hello from Arduino");
}

void loop() {
  uint8_t rateValue;
  heartrate.getValue(heartratePin);
  rateValue = heartrate.getRate(); ///< Get heart rate value 
  if(rateValue)  {
    BT.println("heartrate:"+ rateValue);
    Serial.println(rateValue);
  }
  delay(20);
}
