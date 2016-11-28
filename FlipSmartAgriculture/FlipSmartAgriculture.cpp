/*------------------------------------------------------------
This is the .cpp file for FLIP SMART AGRICULTURE Library
This is the property of Frugal Labs Tech Solutions Pvt. Ltd.
Please refer lisence.txt for complete details.
-------------------------------------------------------------*/
#include "Arduino.h"
#include "FlipSmartAgriculture.h"
#include "DHT.h"
#include "espduino.h"
#include "mqtt.h"
#include "FP.h"


DHT dht(DHTPIN,DHTTYPE);

FlipSmartAgriculture::FlipSmartAgriculture()
{   
    	pinMode(MOIS,INPUT);
		pinMode(LDR,INPUT);
    	pinMode(RELAY,OUTPUT);
		pinMode(XS1,INPUT);
		pinMode(XS2,INPUT);
    	dht.begin();
}


int FlipSmartAgriculture::readHum()
{
  int h = dht.readHumidity();
  return (h);
}

int FlipSmartAgriculture::readTempC()
{
  int t = dht.readTemperature();
  return (t);
}

int FlipSmartAgriculture::readTempF()
{
  int t = dht.readTemperature(true);
  return (t);
}


int FlipSmartAgriculture::readMois()
{
  int mo=analogRead(MOIS);
  int m = map(mo, 0, 1023, 100, 0);
  return (m);
}

int FlipSmartAgriculture::readLdr()
{
  int l=analogRead(LDR);
  return (l);
}

void FlipSmartAgriculture::relayOn()
{
  digitalWrite(RELAY, HIGH);
}

void FlipSmartAgriculture::relayOff()
{
  digitalWrite(RELAY, LOW);
}

int FlipSmartAgriculture::readX1A()
{
	int aa=analogRead(XS1);
	int x1a = map (aa,0,1023,100,0);
	return(x1a);
}

int FlipSmartAgriculture::readX1D()
{
	int x1d=digitalRead(XS1);
	return(x1d);
}

int FlipSmartAgriculture::readX2A()
{
	int bb=analogRead(XS2);
	int x2a = map (bb,0,1023,0,100);
	return(x2a);
}

int FlipSmartAgriculture::readX2D()
{
	int x2d=digitalRead(XS2);
	return(x2d);
}

int FlipSmartAgriculture::readX3D()
{
	int x3d=digitalRead(XS3);
	return(x3d);
}

int FlipSmartAgriculture::writeX3D(int aa)
{
	analogWrite(XS3, aa); 
}