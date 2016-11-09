#include <Wire.h>
#include "IO_ADS1118.h"

IO_ADS1118 ads(10);

void setup()
{
  Serial.begin(115200);
  Serial.println("IoTech ADS1118 Arduino Test");
  
  ads.begin();
  ads.setGain(G2_048);
}

void loop()
{
  int16_t adc_in0 = ads.adsRead(ads.AIN0);
  int16_t adc_in1 = ads.adsRead(ads.AIN1);
  int16_t adc_in2 = ads.adsRead(ads.AIN2);
  int16_t adc_in3 = ads.adsRead(ads.AIN3);
 
  Serial.println(adc_in0);
  Serial.println(adc_in1);
  Serial.println(adc_in2);
  Serial.println(adc_in3);
  Serial.println();
  delay(100);
}
