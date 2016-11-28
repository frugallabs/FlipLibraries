/*
*This is a Source code for the FLIP SMART HOME SHIELD with ESP8266/01 wifi module.
*The code is written by Anirban Chowdhury & Abhay S Bharadwaj
*for Frugal Labs Tech Solutions Pvt. Ltd. Bengaluru,India.
*CC license, check license.txt for more information.
*All text above must be included in any redistribution.
 */

#include <FlipSmartHome.h>
#include <FlipMqtt.h>
FlipSmartHome fsh; //create an instance called fsh for the class FlipSmartHome.
FlipMqtt m; //create an instance called m for the class FlipMqtt.
//-----------    User Inputs    -----------//
 char* temp_topic ="flip/den/temp"; //enter desired hierarchical topic for mqtt to publish the temp values
 char* hum_topic ="flip/den/hum";//enter desired hierarchical topic for mqtt to publish the hum values
 char* ir_topic ="flip/den/ir";//enter desired hierarchical topic for mqtt to publish the IR values
 char* ldr_topic ="flip/den/light";//enter desired hierarchical topic for mqtt to publish the LDR values
 char* switch_topic="flip/den/switch";//enter desired hierarchical topic for mqtt to subscribe to the switch values
 char* ssid="flip"; //enter your wifi router's SSID. ex: FLIP
 char* pwd="frugal2016";//enter your wifi router's password. ex: frugal2015
//-----------------------------------------//
//-----------   Variables -------------------//
int temp,hum,ir,ldr; // variables to store sensor data
char* s=NULL; // variable to store switch data


//--------------------------------------------//
void setup()
{ 
  m.mqttSub(switch_topic); //Subscribe to switch topic
  m.mqttBegin(ssid,pwd);//start mqtt
  fsh.relayOff();
}

void loop()
{
  s=m.GetSubValue(switch_topic);
  if (strcmp(s,"1")==0){
    fsh.relayOn();}
  else{
    fsh.relayOff();} 
  
  temp = fsh.readTempC(); //read temperature value
  m.mqttPub(temp_topic,temp); //publish temperature value to the topic mentioned above

  hum = fsh.readHum();//read Humidity value
  m.mqttPub(hum_topic,hum);//publish humidity value to the topic mentioned above

  ir = fsh.readIr();//read IR value
  m.mqttPub(ir_topic,ir);//publish IR value to the topic mentioned above

  ldr = fsh.readLdr();//read LDR value
  m.mqttPub(ldr_topic,ldr);//publish LDR value to the topic mentioned above
}