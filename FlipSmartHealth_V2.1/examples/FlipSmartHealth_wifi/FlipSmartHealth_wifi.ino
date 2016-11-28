/*
*This is a Source code for the FLIP SMART HEALTH SHIELD with ESP8266/01 wifi module.
*The code is written by Anirban Chowdhury & Abhay S Bharadwaj
*for Frugal Labs Tech Solutions Pvt. Ltd. Bengaluru,India.
*CC license, check license.txt for more information.
*All text above must be included in any redistribution.
 */

#include "FlipSmartHealth.h"
#include <FlipMqtt.h>
FlipSmartHealth fsh; //create an instance called fsh for the class FlipSmartHealth.
FlipMqtt m; //create an instance called m for the class FlipMqtt.
//-----------    User Inputs    -----------//
char* temp_topic ="flip/bed/temp"; //enter desired hierarchical topic for mqtt to publish the temp values
char* bpm_topic ="flip/bed/bpm";//enter desired hierarchical topic for mqtt to publish the HR values
char* pedo_topic ="flip/bed/pedo";//enter desired hierarchical topic for mqtt to publish the pedometer values
char* ssid="flip"; //enter your wifi router's SSID. ex: FLIP
char* pwd="frugal2016";//enter your wifi router's password. ex: frugal2015
//-----------------------------------------//

int tempin,bpmin,pedoin; // variables to store sensor data

void setup()
{ 
  m.mqttBegin(ssid,pwd);//start mqtt
  //fsh.Init();
}


void loop()
{
  tempin = fsh.readTempF(); //read temperature value
  m.mqttPub(temp_topic,tempin); //publish temperature value to the topic mentioned above

  bpmin = fsh.getBpm();//calculate HR
  m.mqttPub(bpm_topic,bpmin);//publish HR value to the topic mentioned above

  pedoin = fsh.getPedo();//calculate steps
  m.mqttPub(pedo_topic,pedoin);//publish steps value to the topic mentioned above
}