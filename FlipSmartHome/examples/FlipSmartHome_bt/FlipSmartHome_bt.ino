/*
This is a Source code for the FLIP SMART HOME SHIELD with Bluetooth.
The code is written by Anirban Chowdhury & Abhay S Bharadwaj
for Frugal Labs Tech Solutions Pvt. Ltd. Bengaluru,India.
CC license, check license.txt for more information.
All text above must be included in any redistribution.

this code is for bluetooth module use.
 */
#include <FlipSmartHome.h>
#include <FlipJson.h>

FlipSmartHome fsh; // create an instance called fsh for the class FlipSmartHome.
FlipJson fbt; // create an instance called fbt for the class FlipJson.

int bt=0;
int hum,temp,lig,ir;// variables to store sensor data

void setup()
{
//nothing else to do in setup() as everything is done in FlipSmartAgriculture.h
}

void loop()
{
  bt = fbt.relayState();; //check the relay control (ON / OFF)
  if (bt==HIGH)
  {
    fsh.relayOn();
  }
  if (bt==LOW)
  {
    fsh.relayOff();
  }
  ir=fsh.readIr();//read IR sensor value
  lig=fsh.readLdr();//read ldr value
  temp=fsh.readTempC();//ead temperature sensor value
  hum=fsh.readHum();//read humidity sensor value
  fbt.jsonPrint(hum,temp,lig,ir);//send the sensor values via BT in Json format.
  delay(200);
  
}