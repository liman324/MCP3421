// liman324@yandex.ru | Alexander Liman | rcl-radio.ru
#include <Wire.h>
#include <MCP3421.h>
  MCP3421 mcp;
  
  long dig;
  float u;
  
void setup(){ 
  Serial.begin(9600);Wire.begin();
  mcp.setConfig(3,0); // 12 14 16 18 bit - 0-3 // 1x 2x 4x 8x gain - 0-3
}

void loop(){
 dig = mcp.readWire();
 u = dig * 2.048 /131071;
 Serial.println(u,6);
}
 /* 1x = 2.048V; 2x = 1.024V; 4x = 0.512V; 8x = 0.256V
 
 18 bit = 17 bit (dec 131071)  + 1 bit (полярность напряжения) */
