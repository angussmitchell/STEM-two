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
        int AprilAngle;
	int AprilID;
	unsigned long AprilTime;

        String GPSLatMessageHeader;
	String GPSLonMessageHeader;
        String CamAprilAngle;
        String CamOdomHeader;
        String CamColourHeader;
	String CamAprilID;

        void drive(int,int);
        void moveArm(int height);
        void getThrottlePWM(int throttle);
        void getAngRatePWM(int angRate);
        void initialise(long baud = 115200);
        void readData(void);
        int ProcessDataStream(String Buffer);
        int ProcessLatGPS(String Buffer);
	int ProcessLonGPS(String Buffer);
        int ProcessAprilAngle(String Buffer);
	int ProcessAprilID(String Buffer);
	bool TagAvailable(void);

	double getLat(void);
	double getLon(void);


	
		

};

#endif

