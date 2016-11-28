/*------------------------------------------------------------
This is the .cpp file for FLIP SMART RETAIL&SUPPLY CHAIN Library
This is the property of Frugal Labs Tech Solutions Pvt. Ltd.
Please refer lisence.txt for complete details.
-------------------------------------------------------------*/

#include "Arduino.h"
#include "FlipSmartRetailSupply.h"
#include "RFID.h"
#include "DHT.h"
#include "HX711.h"
#include "espduino.h"
#include "mqtt.h"
#include "FP.h"

DHT dht(DHTPIN,DHTTYPE);           
RFID rfid(SS_PIN, RST_PIN);
HX711 scale(DOUT, CLK);
String cardNum;


FlipSmartRetailSupply::FlipSmartRetailSupply()
{
		pinMode(PIR,INPUT);
    	pinMode(LDR,INPUT);
    	dht.begin();
		rfid.init();
		initWeight();
}

int FlipSmartRetailSupply::readHum()
{
  int h = dht.readHumidity();
  return (h);
}

int FlipSmartRetailSupply::readTempC()
{
  int t = dht.readTemperature();
  return (t);
}

int FlipSmartRetailSupply::readTempF()
{
  int t = dht.readTemperature(true);
  return (t);
}

int FlipSmartRetailSupply::readLdr()
{
  int l = analogRead(LDR);
  return (l);
}

int FlipSmartRetailSupply::readPir()
{
  int p = digitalRead(PIR);
  return (p);
}

void FlipSmartRetailSupply::initRfid()
{
  rfid.init();
}

String* FlipSmartRetailSupply::getRfid()
{ 
  cardNum = String('\0'); 
  readRfid();
  //String(xn)=String(cardNum);
  if (cardNum != '\0')//if string cardNum is not empty, print the value
 {
	int length_val=cardNum.length()+1;
	char char_val[length_val];
	cardNum.toCharArray(char_val,length_val);
	return(&cardNum);
 }
}


void FlipSmartRetailSupply::readRfid()
{ 
  unsigned long readID;
  if (rfid.isCard())
  {
    if (rfid.readCardSerial())
    {
      for (int i=0; i<=4; i++)//card value: "xyz xyz xyz xyz xyz" (15 digits maximum; 5 pairs of xyz)hence 0<=i<=4 //
      {
        readID = rfid.serNum[i];
        cardNum += readID; // store RFID value into string "cardNum" and concatinate it with each iteration
      }
      //String(xn)=String(cardNum);
      //Serial.println(xn);
    }
  }
  rfid.halt();
}

void FlipSmartRetailSupply::initWeight()
{
	scale.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
	scale.tare();	//Assuming there is no weight on the scale at start up, reset the scale to 0
}

int FlipSmartRetailSupply::getWeight()
{
	int rawWT = scale.get_units();
  	int xy = rawWT * 453.592;//convert from lbs to grams
  	return xy;
}
