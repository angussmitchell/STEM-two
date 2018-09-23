#ifndef PUMP
#define PUMP

#define PWM1 11
#define MOTOR1_1 49
#define MOTOR1_2 48
#define PWM2 10
#define MOTOR2_1 47
#define MOTOR2_2 46


#include <Arduino.h>



class pump
{

    public:
	
	pump(void);
	~pump(void);
	
	void setSpeed(int speed);

	int _port;

};

#endif
