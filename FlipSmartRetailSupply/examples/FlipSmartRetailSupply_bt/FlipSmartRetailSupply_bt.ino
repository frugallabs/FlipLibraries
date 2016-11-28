/*
 * This is a Source coede for the FLIP SMART Reatil & Supply chain SHIELD with Bluetooth.
 * The code is written by Anirban Chowdhury & Abhay S Bharadwaj
 * for Frugal Labs Tech Solutions Pvt. Ltd. Bengaluru,India.
 * CC license, check license.txt for more information.
 * All text above must be included in any redistribution.
 * this code is for bluetooth module use.
 */
#include <FlipSmartRetailSupply.h>
#include <FlipJson.h>

FlipSmartRetailSupply fsrs; // create an instance called asb for the class FlipSmartRetailSupply.
FlipJson fbt; // create an instance called fbt for the class FlipJson.

String* rfidnum;
int hum,temp,lght,pir,wt;

void setup()
{
//nothing else to do in setup() as everything is done in FlipSmartRetailSupply.h
}

void loop()
{
  rfidnum=fsrs.getRfid();
  temp=fsrs.readTempC();//ead temperature sensor value
  hum=fsrs.readHum();//read humidity sensor value
  lght=fsrs.readLdr();
  pir=fsrs.readPir();
  wt=fsrs.getWeight();
  fbt.jsonPrint(hum,temp,lght,pir,wt,rfidnum);// send sensor values serially in json format; RFID must always be sent last.
  delay(200);
}