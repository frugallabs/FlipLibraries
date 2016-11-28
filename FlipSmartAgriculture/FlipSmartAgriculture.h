/*------------------------------------------------------------
This is the .h file for FLIP SMART AGRICULTURE Library
This is the property of Frugal Labs Tech Solutions Pvt. Ltd.
Please refer lisence.txt for complete details.
-------------------------------------------------------------*/

#ifndef FlipSmartAgriculture_H
#define FlipSmartAgriculture_H
#if ARDUINO >= 100
#include "Arduino.h"

#else
#include "WProgram.h"

#endif
#define MOIS A3
#define LDR A0
#define RELAY 3
#define DHTPIN 8
#define DHTTYPE DHT11
#define XS1 A1
#define XS2 A2
#define XS3 5

class FlipSmartAgriculture
{
	public:
			FlipSmartAgriculture();
			int readMois();
			int readLdr();
			int readHum();
			int readTempC();
			int readTempF();
			int readX1A();
			int readX1D();
			int readX2A();
			int readX2D();
			int readX3D();
			int writeX3D(int);
			void relayOn();
			void relayOff();

	private:

};

#endif
