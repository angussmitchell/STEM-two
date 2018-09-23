#include "pump.h"

pump::pump()
{
	pinMode(PWM1,OUTPUT);    //We have to set PWM pin as output
	pinMode(PWM2,OUTPUT);  //Logic pins are also set as output
	pinMode(MOTOR1_1,OUTPUT);
	pinMode(MOTOR1_2,OUTPUT);    //We have to set PWM pin as output
	pinMode(MOTOR2_1,OUTPUT);  //Logic pins are also set as output
	pinMode(MOTOR2_2,OUTPUT);
}

void pump::setSpeed(int speed)
{
	
	digitalWrite(MOTOR1_1, HIGH);
	digitalWrite(MOTOR1_2, LOW);
	analogWrite(PWM1,speed);
	digitalWrite(MOTOR2_1, LOW);
	digitalWrite(MOTOR2_2, HIGH);
	analogWrite(PWM2,speed);
	return;
	
}

pump::~pump(void)
{}
