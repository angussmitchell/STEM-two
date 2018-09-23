#ifndef MOISTURESENSOR_H_
#define MOISTURESENSOR_H_

#include <Arduino.h>
#include "MePort.h"

///@brief class of moistureSensor,it contains two pin.
class moistureSensor
{
public:

    
	moistureSensor(int port);
    
	int measure(void);

	int portMapping[11]= {0,0,0,0,0,0,69,68,67,66,65};	//this maps port 6-10 to slot 2, which is 69-65. dodgy I know but Makeblocks is horrible.
	int _port;
};
#endif
