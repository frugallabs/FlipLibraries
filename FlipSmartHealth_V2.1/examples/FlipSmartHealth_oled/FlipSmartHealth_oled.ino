/*
This is a Source code for the FLIP SMART HEALTH SHIELD V2.0 with OLED display.
The code is written by Anirban Chowdhury & Abhay S Bharadwaj
for Frugal Labs Tech Solutions Pvt. Ltd. Bengaluru,India.
CC license, check license.txt for more information.
All text above must be included in any redistribution.
*/

#include "FlipSmartHealth.h"
#include "FlipOled.h"
FlipOled disp;
FlipSmartHealth fsh; // create an instance called fsh for the class FlipSmartHealth.

int pedoin,tempin,bpmin;// variables to store sensor data

void setup()
{
   disp.oledInit("  Smart Watch"); // enter your project name to be displayed on OLED screen
   //fsh.Init(); //initilize the sensors.
}

void loop()
{
  pedoin = fsh.getPedo();
  tempin = fsh.readTempF();
  bpmin = fsh.getBpm();
  // oledDisp(String, int); // String = Sentense to be displayed. int = sensor value
  disp.oledDisp("Steps : ", pedoin, "Temp F : ", tempin, "BPM : ", bpmin);//send the sensor values to OLED to display.
  delay(200);
}