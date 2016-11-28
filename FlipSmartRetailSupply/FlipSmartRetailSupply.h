/*------------------------------------------------------------
This is the .h file for FLIP SMART RETAIL&SUPPLY CHAIN Library
This is the property of Frugal Labs Tech Solutions Pvt. Ltd.
Please refer lisence.txt for complete details.
-------------------------------------------------------------*/

#ifndef FlipSmartRetailSupplySupply_H
#define FlipSmartRetailSupply_H
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"

#endif

#define SS_PIN 8
#define RST_PIN 4
#define DHTPIN 2
#define DHTTYPE DHT11
#define LDR A0
#define PIR A1
#define DOUT  A5
#define CLK  A3

#define calibration_factor -186000 //This value is obtained using the HX711_Calibration sketch


class FlipSmartRetailSupply
{
    public:
         FlipSmartRetailSupply();
		 int readHum();
		 int readTempC();
		 int readTempF();
		 int readLdr();
		 int readPir();
         void readRfid();
		 String* getRfid();
         void initRfid();
		 void initWeight();
		 int getWeight();


    private:
                        int _cmd=LOW;
                        int _baud_wifi=19200;
                        int _baud_bt=9600;
                        int _con_wifi=1;
                        int _con_bt=2;
                        String _ssid;
                        String _pwd;
};

#endif
