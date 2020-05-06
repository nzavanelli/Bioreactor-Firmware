#include <Wire.h>
#include <Adafruit_ADS1015.h>
#include <Adafruit_MCP4725.h>

Adafruit_MCP4725 dac; // constructor
Adafruit_ADS1115 ads1115;

void setup(void)
{
  Serial.begin(9600);
  ads1115.begin();
  dac.begin(0x62); // The I2C Address: Run the I2C Scanner if you're not sure 

  ads1115.setGain(GAIN_EIGHT);
}

void loop(void)
{

  uint32_t dac_value;
  float Out = 0;
  float rawOut = 0;
  float applied = 0;
  float rawApplied = 0;
  float dacOut;
    
  int16_t adc0, adc1, adc2, adc3;
  dacOut = 0.256;
  dac_value = (4096/3.3) * dacOut;
  dac.setVoltage(dac_value, false);

   adc0 = ads1115.readADC_Differential_0_1();
Serial.println(adc0);
  
  
  delay(30);
}
