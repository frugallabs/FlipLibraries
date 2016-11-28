/*------------------------------------------------------------
This is the .cpp file for FLIP SMART HOME Library
This is the property of Frugal Labs Tech Solutions Pvt. Ltd.
Please refer lisence.txt for complete details.
-------------------------------------------------------------*/
#include "Arduino.h"
#include "FlipSmartHome.h"
#include "DHT.h"

DHT dht(DHTPIN,DHTTYPE);

FlipSmartHome::FlipSmartHome()
{   
    	pinMode(IR,INPUT);
		pinMode(LDR,INPUT);
    	pinMode(RELAY,OUTPUT);
		pinMode(XS1,INPUT);
		pinMode(XS2,INPUT);
    	dht.begin();
}


int FlipSmartHome::readHum()
{
  int h = dht.readHumidity();
  return (h);
}

int FlipSmartHome::readTempC()
{
  int t = dht.readTemperature();
  return (t);
}

int FlipSmartHome::readTempF()
{
  int t = dht.readTemperature(true);
  return (t);
}


int FlipSmartHome::readIr()
{
  int i=digitalRead(IR);
  return (i);
}

int FlipSmartHome::readLdr()
{
  int l=analogRead(LDR);
  return (l);
}

void FlipSmartHome::relayOn()
{
  digitalWrite(RELAY, HIGH);
}

void FlipSmartHome::relayOff()
{
  digitalWrite(RELAY, LOW);
}

int FlipSmartHome::readX1A()
{
	int aa=analogRead(XS1);
	int x1a = map (aa,0,1023,100,0);
	return(x1a);
}

int FlipSmartHome::readX1D()
{
	int x1d=digitalRead(XS1);
	return(x1d);
}

int FlipSmartHome::readX2A()
{
	int bb=analogRead(XS2);
	int x2a = map (bb,0,1023,0,100);
	return(x2a);
}

int FlipSmartHome::readX2D()
{
	int x2d=digitalRead(XS2);
	return(x2d);
}

int FlipSmartHome::readX3D()
{
	int x3d=digitalRead(XS3);
	return(x3d);
}

int FlipSmartHome::writeX3D(int aa)
{
	digitalWrite(XS3, aa);
}