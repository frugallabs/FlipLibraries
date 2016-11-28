/*
This is a Source code for the FLIP SMART AGRICULTURE SHIELD with Bluetooth.
The code is written by Anirban Chowdhury & Abhay S Bharadwaj
for Frugal Labs Tech Solutions Pvt. Ltd. Bengaluru,India.
CC license, check license.txt for more information.
All text above must be included in any redistribution.

this code is for bluetooth module use.
 */
#include <FlipSmartAgriculture.h>
#include <FlipJson.h>

FlipSmartAgriculture fsa; // create an instance called fsh for the class FlipSmartHome.
FlipJson fbt; // create an instance called fbt for the class FlipJson.

int bt=0;
int hum,temp,lig,m;// variables to store sensor data

void setup()
{
//nothing else to do in setup() as everything is done in FlipSmartAgriculture.h
}

void loop()
{
  bt = fbt.relayState();; //check the relay control (ON / OFF)
  if (bt==HIGH)
  {
    fsa.relayOn();
  }
  if (bt==LOW)
  {
    fsa.relayOff();
  }
  m=fsa.readMois();//read SoilMoisture sensor value
  lig=fsa.readLdr();//read ldr value
  temp=fsa.readTempC();//ead temperature sensor value
  hum=fsa.readHum();//read humidity sensor value
  fbt.jsonPrint(hum,temp,lig,m);//send the sensor values via BT in Json format.
  delay(200);
}
