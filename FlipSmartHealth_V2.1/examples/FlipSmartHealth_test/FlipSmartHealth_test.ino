/*
This is a Test code for the FLIP SMART HEALTH SHIELD with Bluetooth.
The code is written by Anirban Chowdhury & Abhay S Bharadwaj
for Frugal Labs Tech Solutions Pvt. Ltd. Bengaluru,India.
CC license, check license.txt for more information.
All text above must be included in any redistribution.
*/
#include <FlipSmartHealth.h>
FlipSmartHealth fsh; // create an instance called fsa for the class FlipSmartAgriculture.

void setup()
{
  Serial.begin(19200);
  Serial.println("Starting...");
  delay(5000);
}

void loop()
{
  int t = fsh.readTemp();;//read temp value
  int b = fsh.getBpm();//get BPM from pulse sensor
  int x = fsh.getAccX();// get accelerometer 'x' axis values
  int y = fsh.getAccY();// get accelerometer 'y' axis values
  int z = fsh.getAccZ();// get accelerometer 'z' axis values
  Serial.print("Temp : "); Serial.println(t);
  Serial.print("BPM  : "); Serial.println(b);
  Serial.print("Xaxis: "); Serial.println(x);
  Serial.print("Xaxis: "); Serial.println(y);
  Serial.print("Zaxis: "); Serial.println(z);
  Serial.print("-----------------"); Serial.println("");
  delay(1000);
}
