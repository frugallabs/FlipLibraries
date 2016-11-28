/*
*This is a Source coede for the FLIP SMART HOME SHIELD with ESP8266/01 wifi module.
*The code is written by Anirban Chowdhury & Abhay S Bharadwaj
*for Frugal Labs Tech Solutions Pvt. Ltd. Bengaluru,India.
*CC license, check license.txt for more information.
*All text above must be included in any redistribution.
 */

#include <FlipSmartAgriculture.h>
#include <FlipMqtt.h>
FlipSmartAgriculture fsa; //create an instance called fsa for the class FlipSmartAgriculture.
FlipMqtt m; //create an instance called m for the class FlipMqtt.
//-----------    User Inputs    -----------//
 char* temp_topic ="abhay/agri/temp"; //enter desired hierarchical topic for mqtt to publish the temp values
 char* hum_topic ="abhay/agri/hum";//enter desired hierarchical topic for mqtt to publish the hum values
 char* mois_topic ="abhay/agri/mois";//enter desired hierarchical topic for mqtt to publish the IR values
 char* ldr_topic ="abhay/agri/ldr";//enter desired hierarchical topic for mqtt to publish the LDR values
 char* switch_topic="abhay/agri/switch";//enter desired hierarchical topic for mqtt to subscribe to the switch values
 char* ssid="flip"; //enter your wifi router's SSID. ex: FLIP
 char* pwd="frugal2016";//enter your wifi router's password. ex: frugal2015
//-----------------------------------------//
//-----------   Variables -------------------//
int temp,hum,mois,ldr; // variables to store sensor data
char* s=NULL; // variable to store switch data


//--------------------------------------------//
void setup()
{ 
  m.mqttSub(switch_topic); //Subscribe to switch topic
  m.mqttBegin(ssid,pwd);//start mqtt
  fsa.relayOff();
}

void loop()
{
  s=m.GetSubValue(switch_topic);
  if (strcmp(s,"1")==0){
    fsa.relayOn();}
  else{
    fsa.relayOff();} 
  
  temp = fsa.readTempC(); //read temperature value
  m.mqttPub(temp_topic,temp); //publish temperature value to the topic mentioned above

  hum = fsa.readHum();//read Humidity value
  m.mqttPub(hum_topic,hum);//publish humidity value to the topic mentioned above

  mois = fsa.readMois();//read soil moisture value
  m.mqttPub(mois_topic,mois);//publish mois value to the topic mentioned above

  ldr = fsa.readLdr();//read LDR value
  m.mqttPub(ldr_topic,ldr);//publish LDR value to the topic mentioned above
}