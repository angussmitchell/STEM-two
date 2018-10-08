#ifndef spray_h
#define spray_h

#include <Arduino.h>
#include <Servo.h>

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
        
        void turnOn (bool state);
        void initialise(int relay_pin = 8);
             
    protected:    	

};

#endif



