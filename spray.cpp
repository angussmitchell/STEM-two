#include "spray.h"

spray::spray(void){
    //RelayPin_ = pin ; //[Default Digital PWM Pin 8 ]
    //picoswitch.attach(RelayPin_);
    
}

void spray::intialise(int relay_pin = 8){

	RelayPin_ = relay_pin;
	picoswitch.attach(RelayPin_);
        
}


void spray::turnOn (void){
	picoswitch.write(PULSE_RELAY_ON_PWM); 	    
}

void spray::turnOff (void){
	picoswitch.write(PULSE_RELAY_OFF_PWM);
}



spray::~spray(void)
{
  picoswitch.detach();
  
}
