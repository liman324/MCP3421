#include <Arduino.h>
#include <Wire.h>
#include "MCP3421.h"

MCP3421::MCP3421(){
	Wire.begin();
}

void MCP3421::setConfig(int bit, int gain){
     switch (bit){
        case 0:bit = 0b00000000;break;
        case 1:bit = 0b00000100;break;
        case 2:bit = 0b00001000;break;
        case 3:bit = 0b00001100;break;
  }
 switch (gain){
        case 0:gain = 0b00000000;break;
        case 1:gain = 0b00000001;break;
        case 2:gain = 0b00000010;break;
        case 3:gain = 0b00000011;break;
  }
        int conf = 0b00010000 + bit + gain;
     writeWire(conf);
}


void MCP3421::writeWire(char a){
     Wire.beginTransmission(MCP3421_address);
     Wire.write (a);
     Wire.endTransmission();
}

int32_t MCP3421::readWire(){
        Wire.requestFrom(MCP3421_address,3); //запросить 3 байта данных
   long value = ((Wire.read()<<8) | Wire.read());//упаковка в одну переменную.
        value = ((value<<8)| Wire.read());
   return (int32_t)value;
}



