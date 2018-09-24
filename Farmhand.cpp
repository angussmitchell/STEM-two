#include "Farmhand.h"

Farmhand::Farmhand(void){
    
    throttle_       = 0;       //[%]
    angRate_        = 0;       //[%]
    
    throttlePWM_    = 1500;    //[PWM]  
    angRatePWM_     = 1500;    //[PWM]

    latitude       = 0;
    longitude      = 0;

    AprilAngle     = 0;



    GPSMessageHeader =  ">FH,1,2,";
    CamAprilAngle = ">FH,1,4,";
    CamOdomHeader = ">FH,1,5,";
    CamColourHeader = ">FH,1,6,";
    CamAprilID = ">FH,1,7,";

}

void Farmhand::initFarmhand(int port = 2 , long baud = 115200){
    
    delay(1000);
    Serial.println("Initialising bluetooth connection to Farmhand Robot");
    serialport_ = port;
    serialbaud_ = baud;
    
    switch (port)
    {
    	case 0: Serial.begin(serialbaud_);
    		break;
    	case 1: Serial1.begin(serialbaud_);
    		break;
    	case 2: Serial2.begin(serialbaud_);
    		 break;
    	case 3: Serial3.begin(serialbaud_);
    		break;
    	default: 
    			Serial.begin(serialbaud_);		
    }
}

void Farmhand::sprayOn(void)
{

    switch (serialport_)
    {
        case 0: 
        {
            Serial.print( ">FH,1,1,");     
            Serial.print(1600);        //this value has to be anything > 1500. I chose 1600 for safety (rather than 2000)
            Serial.print(";"); 
        }
            break;
        case 1: 
        {       
            Serial1.print( ">FH,1,1,");     
            Serial1.print(1600);        //this value has to be anything > 1500. I chose 1600 for safety (rather than 2000)
            Serial1.print(";"); 
        }
            break;
        case 2: 
        {       
          
            Serial2.print( ">FH,1,1,");    
            Serial2.print(1600);        //this value has to be anything > 1500. I chose 1600 for safety (rather than 2000)
            Serial2.print(";"); 
        }
             break;
        case 3: 
        {   
            Serial3.print( ">FH,1,1,");   
            Serial3.print(1600);        //this value has to be anything > 1500. I chose 1600 for safety (rather than 2000)
            Serial3.print(";"); 
        }
            break;

        default: 
        {
            Serial.print( ">FH,1,1,");     
            Serial.print(1600);        //this value has to be anything > 1500. I chose 1600 for safety (rather than 2000)
            Serial.print(";"); 
        }   
    }

    return;
}
void Farmhand::sprayOff(void)
{

    switch (serialport_)
    {
        case 0: 
        {
            Serial.print( ">FH,1,1,");     
            Serial.print(1400);        //this value has to be anything > 1500. I chose 1400 for safety (rather than 1000)
            Serial.print(";"); 
        }
            break;
        case 1: 
        {       
            Serial1.print( ">FH,1,1,");     
            Serial1.print(1400);        //this value has to be anything > 1500. I chose 1400 for safety (rather than 1000)
            Serial1.print(";"); 
        }
            break;
        case 2: 
        {       
          
            Serial2.print( ">FH,1,1,");    
            Serial2.print(1400);        //this value has to be anything > 1500. I chose 1400 for safety (rather than 1000)
            Serial2.print(";"); 
        }
             break;
        case 3: 
        {   
            Serial3.print( ">FH,1,1,");   
            Serial3.print(1400);        //this value has to be anything > 1500. I chose 1400 for safety (rather than 1000)
            Serial3.print(";"); 
        }
            break;

        default: 
        {
            Serial.print( ">FH,1,1,");     
            Serial.print(1400);        //this value has to be anything > 1500. I chose 1400 for safety (rather than 1000)
            Serial.print(";"); 
        }   
    }
    return;
}


void Farmhand::moveArm(int height)
{
    switch (serialport_)
    {
        case 0: 
        {
            Serial.print( ">FH,1,3,");     
            Serial.print(height);        //this value has to be anything > 1500. I chose 1400 for safety (rather than 1000)
            Serial.print(";"); 
        }
            break;
        case 1: 
        {       
            Serial1.print( ">FH,1,3,");     
            Serial1.print(height);        //this value has to be anything > 1500. I chose 1400 for safety (rather than 1000)
            Serial1.print(";"); 
        }
            break;
        case 2: 
        {       
          
            Serial2.print( ">FH,1,3,");    
            Serial2.print(height);        //this value has to be anything > 1500. I chose 1400 for safety (rather than 1000)
            Serial2.print(";"); 
        }
             break;
        case 3: 
        {   
            Serial3.print( ">FH,1,3,");   
            Serial3.print(height);        //this value has to be anything > 1500. I chose 1400 for safety (rather than 1000)
            Serial3.print(";"); 
        }
            break;

        default: 
        {
            Serial.print( ">FH,1,3,");     
            Serial.print(height);        //this value has to be anything > 1500. I chose 1400 for safety (rather than 1000)
            Serial.print(";"); 
        }   
    }
    return;
}
void Farmhand::drive(int throttle, int angRate)
{
    
    // convert values from -100 : 100 to 1000 : 2000
    getThrottlePWM(throttle);
    getAngRatePWM(angRate);
    
    switch (serialport_)
    {
        case 0: 
        {
            Serial.print( ">FH,1,2,"); //Modify this text to print your own message.    
            Serial.print(throttle_);
            Serial.print(","); 
            Serial.print(angRate_);
            Serial.print(";");
        }
            break;
        case 1: 
        {       
            Serial1.print( ">FH,1,2,"); //Modify this text to print your own message.    
            Serial1.print(throttle_);
            Serial1.print(","); 
            Serial1.print(angRate_);
            Serial1.print(";");
        }
            break;
        case 2: 
        {       
          
          
           Serial2.print( ">FH,1,2,"); //Modify this text to print your own message.    
           Serial2.print(throttle_);
           Serial2.print(","); 
           Serial2.print(angRate_);
           Serial2.print(";");
        }
             break;
        case 3: 
        {   
            Serial3.print( ">FH,1,2,"); //Modify this text to print your own message.    
            Serial3.print(throttle_);
            Serial3.print(","); 
            Serial3.print(angRate_);
            Serial3.print(";");
        }
            break;

        default: 
        {
            Serial.print( ">FH,1,2,"); //Modify this text to print your own message.    
            Serial.print(throttle_);
            Serial.print(","); 
            Serial.print(angRate_);
            Serial.print(";");
        }   
    }
    
}
void Farmhand::getThrottlePWM(int throttle){

    unsigned int result = throttle * 5;
    result = result + 1500;
    throttle_ = result;
    return;
}

void Farmhand::getAngRatePWM(int angRate){
    
    unsigned int result = angRate *5;
    result = result + 1500;
    angRate_ = result;
    return;

}  


int Farmhand::readData(void)
{
	
    char buffer[50];    
    String Buffer;
    int buffer_length;

    switch (serialport_)
    {
        case 0:
        if (Serial.available()){Buffer = Serial.readStringUntil(';');}
        break;
        case 1:
        if (Serial1.available()){Buffer = Serial1.readStringUntil(';');}
        break;
        case 2:
        if (Serial2.available()){Buffer = Serial2.readStringUntil(';');}
        
	break;
        case 3:
        if (Serial3.available()){Buffer = Serial3.readStringUntil(';');}
        break;
        default:
        if (Serial2.available()){Buffer = Serial2.readStringUntil(';');}
        break;
    }

    Buffer+=';';
    buffer_length = Buffer.length();
    if (buffer_length >= 4 )
          {
            ProcessDataStream(Buffer);
          }

    return 0;

}

int Farmhand::ProcessDataStream(String Buffer)
{	

    if (Buffer.startsWith(GPSMessageHeader.c_str()))
    {
        ProcessGPS(Buffer);
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

int Farmhand::ProcessGPS(String Buffer)
{   

    int StartLatIndex = Buffer.indexOf(">FH,1,2,") + strlen(GPSMessageHeader.c_str());
    int EndLatIndex = Buffer.indexOf(",", StartLatIndex);
    String LatString = Buffer.substring(StartLatIndex, EndLatIndex);

    int StartLonIndex = EndLatIndex + 1;
    int EndLonIndex = Buffer.indexOf(";", StartLonIndex);
    String LonString = Buffer.substring(StartLonIndex, EndLonIndex);

    latitude = atof(LatString.c_str());
    longitude = atof(LonString.c_str());
    return 0;
}

int Farmhand::ProcessAprilAngle(String Buffer)
{   

    int StartIndex = Buffer.indexOf(CamAprilAngle.c_str()) + strlen(CamAprilAngle.c_str());
    int EndIndex = Buffer.indexOf(";", StartIndex);
    String AprilStr = Buffer.substring(StartIndex, EndIndex);

    AprilAngle = atoi(AprilStr.c_str());
    return 0;
}

int Farmhand::ProcessAprilID(String Buffer)
{   

    int StartIndex = Buffer.indexOf(CamAprilID.c_str()) + strlen(CamAprilID.c_str());
    int EndIndex = Buffer.indexOf(";", StartIndex);
    String AprilStr = Buffer.substring(StartIndex, EndIndex);

    AprilID = atoi(AprilStr.c_str());
    return 0;
}

Farmhand::~Farmhand(void){}
