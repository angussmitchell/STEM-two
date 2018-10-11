#include "Farmhand.h"

Farmhand::Farmhand(void){
    
    throttle_       = 0;       //[%]
    angRate_        = 0;       //[%]
    
    throttlePWM_    = 1500;    //[PWM]  
    angRatePWM_     = 1500;    //[PWM]

    latitude       = 0;
    longitude      = 0;

    AprilAngle     = 0;
    AprilID 	   = 0;
    AprilTime      = 0;

    GPSLatMessageHeader = ">FH,1,8,";
    GPSLonMessageHeader = ">FH,1,9,";
    CamAprilAngle = ">FH,1,4,";
    CamOdomHeader = ">FH,1,5,";
    CamColourHeader = ">FH,1,6,";
    CamAprilID = ">FH,1,7,";

}

void Farmhand::initialise(long baud){
    
    delay(1000);
    Serial.println("Initialising bluetooth connection to Farmhand Robot");
    serialport_ = 2;		// previously this was provided as argument, but its confusing for students
    serialbaud_ = baud;
    Serial2.begin(serialbaud_);
	return;
    
}

void Farmhand::moveArm(int height)
{
	Serial2.print( ">FH,1,3,");    
	Serial2.print(height);        
	Serial2.print(";"); 
	return;
}

void Farmhand::drive(int throttle, int angRate)
{
    
	// convert values from -100 : 100 to 1000 : 2000
	getThrottlePWM(throttle);
	getAngRatePWM(angRate);    
	Serial2.print( ">FH,1,2,"); //Modify this text to print your own message.    
	Serial2.print(throttle_);
	Serial2.print(","); 
	Serial2.print(angRate_);
	Serial2.print(";");
       
    
}
void Farmhand::getThrottlePWM(int throttle){

	unsigned int result = throttle * 5;
	result = result + 1500;
	throttle_ = result;
	return;
}

void Farmhand::getAngRatePWM(int angRate){
    
    unsigned int result = angRate * 5;
    result = result + 1500;
    angRate_ = result;
    return;

}  


void Farmhand::readData(void)
{
	
	char buffer[50];    
	String Buffer;
	int buffer_length;


	if (Serial2.available()){Buffer = Serial2.readStringUntil(';');}

	Buffer+=';';
	buffer_length = Buffer.length();
	if (buffer_length >= 4 )
	{
		ProcessDataStream(Buffer);
	}

	return;

}

int Farmhand::ProcessDataStream(String Buffer)
{	

    if (Buffer.startsWith(GPSLatMessageHeader.c_str()))
    {
        ProcessLatGPS(Buffer);
    }
    if (Buffer.startsWith(GPSLonMessageHeader.c_str()))
    {
        ProcessLonGPS(Buffer);
    }
    else if (Buffer.startsWith(CamAprilAngle.c_str()))
    {
        ProcessAprilAngle(Buffer);
    }
    else if (Buffer.startsWith(CamAprilID.c_str()))
    {
	ProcessAprilID(Buffer);
    }
    return 0;
}

int Farmhand::ProcessLatGPS(String Buffer)
{   
	
    int StartIndex = Buffer.indexOf(GPSLatMessageHeader.c_str()) + strlen(GPSLatMessageHeader.c_str());
    int EndIndex = Buffer.indexOf(";", StartIndex);
    String LatString = Buffer.substring(StartIndex, EndIndex);
    
    long tmp_lat = atol(LatString.c_str());
    latitude = tmp_lat/(double)1000000;
    
    return 0;
}

int Farmhand::ProcessLonGPS(String Buffer)
{   

    int StartIndex = Buffer.indexOf(GPSLonMessageHeader.c_str()) + strlen(GPSLonMessageHeader.c_str());
    int EndIndex = Buffer.indexOf(";", StartIndex);
    String LonString = Buffer.substring(StartIndex, EndIndex);
	
    
    long tmp_lon = atol(LonString.c_str());
   
    longitude = tmp_lon/(double)1000000;

    
    return 0;
}

int Farmhand::ProcessAprilAngle(String Buffer)
{   

    int StartIndex = Buffer.indexOf(CamAprilAngle.c_str()) + strlen(CamAprilAngle.c_str());
    int EndIndex = Buffer.indexOf(";", StartIndex);
    String AprilStr = Buffer.substring(StartIndex, EndIndex);

    AprilAngle = atoi(AprilStr.c_str());
    AprilTime  = millis();
    return 0;
}

int Farmhand::ProcessAprilID(String Buffer)
{   

    int StartIndex = Buffer.indexOf(CamAprilID.c_str()) + strlen(CamAprilID.c_str());
    int EndIndex = Buffer.indexOf(";", StartIndex);
    String AprilStr = Buffer.substring(StartIndex, EndIndex);

    AprilID = atoi(AprilStr.c_str());
    AprilTime  = millis();
    return 0;
}

bool Farmhand::tagAvailable()
{
	unsigned long current_time = millis();
	if ((current_time - AprilTime) > 100)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

double Farmhand::getLat()
{
	
	return latitude;
}
double Farmhand::getLon()
{
	
	return longitude;
}


Farmhand::~Farmhand(void){}


