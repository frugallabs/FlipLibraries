/*
This is a Source code for the FLIP SMART HEALTH SHIELD with GLCD.
The code is written by Anirban Chowdhury & Abhay S Bharadwaj
for Frugal Labs Tech Solutions Pvt. Ltd. Bengaluru,India.
CC license, check license.txt for more information.
All text above must be included in any redistribution.

this code is for bluetooth module use.
 */
#include <FlipSmartHealth.h>
#include <FlipGlcd.h>

FlipSmartHealth fsh; // create an instance called fsh for the class FlipSmartHealth.
FlipGlcd fg; // create an instance called fg for the class FlipGlcd.

int pedoin,tempin,bpmin;// variables to store sensor data

void setup()
{
   fg.glcdInit(); // initilize the lcd
   //fsh.Init(); //initilize the sensors.
}

void loop()
{
  pedoin = fsh.getPedo();
  tempin = fsh.readTempF();
  bpmin = fsh.getBpm();
  fg.glcdDisp(pedoin,tempin,bpmin);//send the sensor values to GLCD to display.
  delay(200);
}