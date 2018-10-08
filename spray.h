#ifndef PulseRelay_h
#define PulseRelay_h

#include<Servo.h>
#include <Arduino.h>


#define PULSE_RELAY_ON_PWM  160
#define PULSE_RELAY_OFF_PWM  40

class spray
{    
    private:    
        int RelayPin_;
        Servo picoswitch;   // Relay take in as input a PWM pulse like a servo - 
        					// The switch is called picoswitch made by 
        					// Dimensions Engineering    
    
    public:    
        spray(void);
        ~spray(void);
        
        void turnOn (void);
	void turnOff (void);
        void intialise(int relay_pin = 8);
             
    protected:    	

};

#endif



