#include <Adafruit_MCP3008.h>
#include <Wire.h>
#include <SoftwareSerial.h>

int temp;
int val1 = 0;
int val2 = 0;

Adafruit_MCP3008 mcp1;

void setup() {
  mcp1.begin(10);
  Serial.begin(9600);
  while(!Serial){};
}

void loop() 
{
  
  val1 = mcp1.readADC(2);
  val2 = mcp1.readADC(0);
 // Serial.println(val1);
  Serial.println(val2);
 // Serial.println(99);
  delay(10);
}
