#include <Wire.h>
#include <Adafruit_ADS1015.h>
#include <Adafruit_MCP4725.h>
#include <Arduino.h>

Adafruit_MCP4725 dac; // constructor
Adafruit_ADS1115 ads1(0x49);
Adafruit_ADS1115 ads2(0x48);

uint32_t dac_value;
float Out = 0;
float rawOut = 0;
float applied = 0;
float rawApplied = 0;
float dacOut;

int16_t val1, val2, val3, val4;


void setup(void)
{
  Serial.begin(9600);
  Wire.begin();
  delay(100);
  
  TCA9548A(0x74, 4);    // select I2C bus 6
  ads1.begin();
  delay(100);
 // Serial.println("setup ADS1");
  ads1.setGain(GAIN_SIXTEEN);
  

  TCA9548A(0x71, 7);    // select I2C bus 7
  ads2.begin();
  delay(100);
 // Serial.println("setup ADS2");
  ads2.setGain(GAIN_SIXTEEN);

  TCA9548A(0x71, 2);    // select I2C bus 2
  dac.begin(0x62);
  delay(100);

  float  dacOut = 0.256;
  float dac_value = (4096 / 3.3) * dacOut;
  dac.setVoltage(dac_value, false);

}

void loop(void)
{

  TCA9548A(0x74, 4);
  val1 = ads1.readADC_SingleEnded(0);
  Serial.println(val1);
 // Serial.print(" ");
  delay(30);
   val2 = ads1.readADC_SingleEnded(1);
  Serial.println(val2);
  //Serial.print(" ");
  delay(30);



  TCA9548A(0x71, 7);
  val3 = ads2.readADC_SingleEnded(0);
  Serial.println(val3);
 // Serial.print(" ");
  delay(30);
  val4 = ads2.readADC_SingleEnded(1);
  Serial.println(val4);
  delay(30);
}


void TCA9548A(byte address, uint8_t bus)
{
  Wire.beginTransmission(address);  // TCA9548A address is 0x70
  Wire.write(1 << bus);          // send byte to select bus
  Wire.endTransmission();
}
