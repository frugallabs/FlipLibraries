/*
This is a Test code for the FLIP SMART RETAIL & SUPPLY SHIELD.
The code is written by Anirban Chowdhury & Abhay S Bharadwaj
for Frugal Labs Tech Solutions Pvt. Ltd. Bengaluru,India.
CC license, check license.txt for more information.
All text above must be included in any redistribution.
*/
#include <FlipSmartRetailSupply.h>
FlipSmartRetailSupply fsrs; // create an instance called fsrs for the class FlipSmartRetailSupply.

void setup()
{
  Serial.begin(19200);
  Serial.println("Starting...");
  delay(5000);
}

void loop()
{
  int t = fsrs.readTempC();//read temperature sensor value
  int h = fsrs.readHum();//read humidity sensor value
  int l = fsrs.readLdr();//read LDR sensor value
  int p = fsrs.readPir();//read PIR sensor value
  int w = fsrs.getWeight();//get weight from load cell
  String* r = fsrs.getRfid();//get RDID number
  String sx =*r;//copy RFID value as a string
  Serial.print("RFID: "); Serial.println(sx);
  Serial.print("Ldr : "); Serial.println(l);
  Serial.print("Temp: "); Serial.println(t);
  Serial.print("Humd: "); Serial.println(h);
  Serial.print("PIR : "); Serial.println(p);
  Serial.print("Wght: "); Serial.println(w);
  Serial.print("-----------------"); Serial.println("");
  delay(1000);
}