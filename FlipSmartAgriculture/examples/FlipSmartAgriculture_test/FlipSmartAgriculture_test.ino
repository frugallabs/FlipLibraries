/*
This is a Test code for the FLIP SMART AGRICULTURE SHIELD.
The code is written by Anirban Chowdhury & Abhay S Bharadwaj
for Frugal Labs Tech Solutions Pvt. Ltd. Bengaluru,India.
CC license, check license.txt for more information.
All text above must be included in any redistribution.
*/
#include <FlipSmartAgriculture.h>
FlipSmartAgriculture fsa; // create an instance called fsa for the class FlipSmartAgriculture.

void setup()
{
  Serial.begin(19200);
  Serial.println("Starting...");
  delay(5000);
}

void loop()
{
  int m = fsa.readMois();//read SoilMoisture sensor value
  int l = fsa.readLdr();//read ldr value
  int t = fsa.readTempC();//ead temperature sensor value
  int h = fsa.readHum();//read humidity sensor value
  Serial.print("Mois: "); Serial.println(m);
  Serial.print("Ldr : "); Serial.println(l);
  Serial.print("Temp: "); Serial.println(t);
  Serial.print("Humd: "); Serial.println(h);
  Serial.print("-----------------"); Serial.println("");
  delay(1000);
}
