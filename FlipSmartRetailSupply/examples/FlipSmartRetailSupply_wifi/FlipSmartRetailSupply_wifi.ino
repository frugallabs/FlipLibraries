/*
 * This is a Source code for the FLIP SMART RETAIL & SUPPLY SHIELD with wifi.
 * The code is written by Anirban Chowdhury & Abhay S Bharadwaj
 * for Frugal Labs Tech Solutions Pvt. Ltd. Bengaluru,India.
 * CC license, check license.txt for more information.
 * All text above must be included in any redistribution.
 * this code is to be used with FLIP WiFi module.
 */
#include <FlipSmartRetailSupply.h>
#include <FlipMqtt.h>
FlipSmartRetailSupply fsrs; //create an instance "fsrs" for the class "FlipSmartRetailSupply"
FlipMqtt m; //create an instance "m" for the class "FlipMqtt"

/*************** Variables ******************/
String* x;
int hum,temp,ldr,pir,wt;

/*************** User Inputs  ****************/

char* temp_topic ="flip/store/temp";
char* hum_topic ="flip/store/hum";
char* pir_topic ="flip/store/pir";
char* ldr_topic ="flip/store/ldr";
char* rfid_topic ="flip/store/rfid";
char* weight_topic ="flip/store/weight";
char* ssid="flip";
char* pwd="frugal2016";

void setup() 
{
  m.mqttBegin(ssid,pwd);
}

void loop() 
{
  wt = fsrs.getWeight();
  m.mqttPub(weight_topic, wt);
  
  temp = fsrs.readTempC();
  m.mqttPub(temp_topic,temp);
  
  hum = fsrs.readHum();
  m.mqttPub(hum_topic,hum);
  
  pir = fsrs.readPir();
  m.mqttPub(pir_topic,pir);
  
  ldr = fsrs.readLdr();
  m.mqttPub(ldr_topic,ldr);

  x=fsrs.getRfid();//get the RFID value
  String sx =*x;//convert it to string
  if(sx!=0)//if string is not '0', then publish.
  m.mqttPub(rfid_topic, &sx);
}