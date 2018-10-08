#include "PulseRelay.h"

spray::spray(void){
    //RelayPin_ = pin ; //[Default Digital PWM Pin 8 ]
    //picoswitch.attach(RelayPin_);
    
}

void spray::initialise(int relay_pin = 8){

	RelayPin_ = relay_pin;
	picoswitch.attach(RelayPin_);
        
}


void spray::turnOn (bool isRelayOn){
  
  if(isRelayOn)
  	picoswitch.write(PULSE_RELAY_ON_PWM); 
  else
  	picoswitch.write(PULSE_RELAY_OFF_PWM); 
    
}



spray::~spray(void)
{
  picoswitch.detach();
  
}
