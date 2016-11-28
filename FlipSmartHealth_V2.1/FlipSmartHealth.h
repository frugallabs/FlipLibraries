/*------------------------------------------------------------
This is the .h file for FLIP SMART Health Library
This is the property of Frugal Labs Tech Solutions Pvt. Ltd.
Please refer lisence.txt for complete details.
-------------------------------------------------------------*/

#ifndef FlipSmartHealth_H
#define FlipSmartHealth_H
#if ARDUINO >= 100
#include "Arduino.h"

#else
#include "WProgram.h"

#endif

#define pulsePin A1
#define temppin A0
#define xpin A5
#define ypin A6
#define zpin A7

class FlipSmartHealth
{
	public:
			FlipSmartHealth();
			int getPedo();
			float readTempC();
			float readTempF();
			int getBpm();
			int getAccX();
			int getAccY();
			int getAccZ();
			void calibrate();
			void Init();
			
			

  
int threshhold=80;
int steps,flag=0;
  

	private:

                        int _baud_wifi=19200;
                        int _baud_bt=9600;
                        String _ssid;
                        String _pwd;
						void interruptSetup();
};

#endif
