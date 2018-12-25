
#define heartratePin A1
#include "Heartrate.h"
Heartrate heartrate(DIGITAL_MODE); ///< ANALOG_MODE or DIGITAL_MODE

void setup() {
  Serial.begin(9600);
}

void loop() {
  uint8_t rateValue;
  heartrate.getValue(heartratePin);
  rateValue = heartrate.getRate(); ///< Get heart rate value 
  if(rateValue)  {
  Serial.println(rateValue);
  }
  delay(20);
}
