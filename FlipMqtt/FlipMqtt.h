/*------------------------------------------------------------
This is the .h file for FLIP MQTT Library
This is the property of Frugal Labs Tech Solutions Pvt. Ltd.
Please refer lisence.txt for complete details.
-------------------------------------------------------------*/

#ifndef FlipMqtt_H
#define FlipMqtt_H
#if ARDUINO >= 100
#include "Arduino.h"

#else
#include "WProgram.h"

#endif
#define RX 11
#define TX 10

class FlipMqtt 
{
	public:
			FlipMqtt();
			void wifiCb(void* );
			void mqttConnected(void* );
			void mqttDisconnected(void* );
			void mqttPublished(void* );
			void mqttData(void* );
			void mqttPub(char* ,int);
                       
                void mqttPub(char [] ,char [] );
                void mqttSetup();
			void wifiSetup();
			void mqttBegin(char* ,char* );
			char* GetSubValue(char* );
                void mqttSub(char* );

         		
	private:
			  
                        int _cmd=LOW; 
                        int _baud_wifi=19200; 
                        
                        char *_ssid;
                        char *_pwd;
};

#endif
