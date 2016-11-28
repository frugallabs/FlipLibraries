/*
This is a Test code for the FLIP SMART HOME SHIELD.
The code is written by Anirban Chowdhury & Abhay S Bharadwaj
for Frugal Labs Tech Solutions Pvt. Ltd. Bengaluru,India.
CC license, check license.txt for more information.
All text above must be included in any redistribution.
*/
#include <FlipSmartHome.h>
FlipSmartHome fsh; // create an instance called fsh for the class FlipSmartHome.

void setup()
{
  Serial.begin(19200);
  Serial.println("Starting...");
  delay(5000);
}

void loop()
{
  int i = fsh.readIr();//read IR sensor value
  int l = fsh.readLdr();//read ldr value
  int t = fsh.readTempC();//ead temperature sensor value
  int h = fsh.readHum();//read humidity sensor value
  Serial.print("IR  : "); Serial.println(i);
  Serial.print("Ldr : "); Serial.println(l);
  Serial.print("Temp: "); Serial.println(t);
  Serial.print("Humd: "); Serial.println(h);
  Serial.print("-----------------"); Serial.println("");
  delay(1000);
}
