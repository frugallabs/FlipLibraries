/*
This is a Source code for the FLIP SMART HEALTH SHIELD with Bluetooth.
The code is written by Anirban Chowdhury & Abhay S Bharadwaj
for Frugal Labs Tech Solutions Pvt. Ltd. Bengaluru,India.
CC license, check license.txt for more information.
All text above must be included in any redistribution.

this code is for bluetooth module use.
 */
#include <FlipSmartHealth.h>
#include <FlipJson.h>

FlipSmartHealth fsh; // create an instance called fsh for the class FlipSmartHealth.
FlipJson fbt; // create an instance called fbt for the class FlipJson.

int pedoin,tempin,bpmin;// variables to store sensor data

void setup()
{
//nothing else to do in setup() as everything is done in FlipSmartHealth.h
}

void loop()
{
  pedoin = fsh.getPedo();
  tempin = fsh.readTemp();
  bpmin = fsh.getBpm();
  fbt.jsonPrint(pedoin,tempin,bpmin);//send the sensor values via BT in Json format.
  delay(200);
}
