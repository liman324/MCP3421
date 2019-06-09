#ifndef MCP3421_H
#define MCP3421_H

#define MCP3421_address 0x68 

#include <Arduino.h>

class MCP3421
{
  public:
    MCP3421();
        void setConfig(int bit, int gain); 
        int32_t readWire(void);
	
  private:
	void writeWire(char a);      
};
	
#endif //MCP3421_H
