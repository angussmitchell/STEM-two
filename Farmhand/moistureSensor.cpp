#include "moistureSensor.h"

moistureSensor::moistureSensor(int port)
{
	
	_port =portMapping[port];
		
}

int moistureSensor::measure()
{
    int val;
    val = analogRead(_port);				
    return val;
}

