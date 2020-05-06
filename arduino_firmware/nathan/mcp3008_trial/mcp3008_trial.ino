#include <Adafruit_MCP3008.h>
#include <Wire.h>
#include <SoftwareSerial.h>

int temp;
const int RX_PIN = 0;
const int TX_PIN = 1;
float val1[] = {0,1,2,3,4,5,6,7};
float val2[] = {0,1,2,3,4,5,6,7}; 
SoftwareSerial bluetooth(RX_PIN, TX_PIN);
Adafruit_MCP3008 mcp1;
Adafruit_MCP3008 mcp2;

void setup() {
  bluetooth.begin(9600);
  mcp1.begin(9);
  mcp2.begin(8);
}

void loop() 
{
  gather(mcp1, val1);
  gather(mcp2, val2);
  printer(val1);
  printer(val2);
  temp--;
}

void gather(Adafruit_MCP3008 device, float in[])
{
  for(int i = 0; i<8; i++)
  {
    in[i] = device.readADC(i);
  }
}
void printer(float in[])
{
  for(int i = 0; i<8; i++)
  {
    bluetooth.println(in[i]);
  }
}
