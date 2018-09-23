#ifndef FARMHAND
#define FARMHAND

//#include <StandardCplusplus.h>
#include <Arduino.h>

#define FH_STRING ">FH"
#define FH_STRING_LEN 3

class Farmhand
{
    
    private:
    
        int FH_number;   //number of which farmhand unit the message is being sent to

        int throttle_;
        int angRate_;
        int throttlePWM_;
        int angRatePWM_;
        
        int serialport_;
        long serialbaud_;
	       
        
    public:
	
        Farmhand(void);
        ~Farmhand(void);
	
        double latitude, longitude;
        float AprilAngle;
        String GPSMessageHeader;
        String CamAprilHeader;
        String CamOdomHeader;
        String CamColourHeader;

        void drive(int,int);
        void sprayOn(void);
        void sprayOff(void);
        void moveArm(int height);
        void getThrottlePWM(int throttle);
        void getAngRatePWM(int angRate);
        void initFarmhand(int port , long baud);
        int readData(void);
        int ProcessDataStream(String Buffer);
        int ProcessGPS(String Buffer);
        int ProcessApril(String Buffer);
	

};

#endif

