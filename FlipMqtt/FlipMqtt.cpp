/*------------------------------------------------------------
This is the .cpp file for FLIP MQTT Library v0.9.2
This is the property of Frugal Labs Tech Solutions Pvt. Ltd.
Please refer lisence.txt for complete details.
-------------------------------------------------------------*/
#include "Arduino.h"
#include "FlipMqtt.h"
#include "SoftwareSerial.h"
#include "espduino.h"
#include "mqtt.h"
#include "FP.h"

SoftwareSerial flipSerial(RX, TX);

ESP esp(&flipSerial, &Serial, 4);
MQTT mqtt(&esp);
boolean wifiConnected = false;
char* top="null";
String val;

FlipMqtt::FlipMqtt()
{
   flipSerial.begin(_baud_wifi);
   Serial.begin(_baud_wifi);
}

void FlipMqtt::mqttBegin(char* ss,char* pw)
{
    _ssid = ss;
    _pwd = pw;

    esp.enable();
    delay(500);
    esp.reset();
    delay(500);

    Serial.println("ESP is starting...");
    while(!esp.ready());

    Serial.println("ARDUINO: setup mqtt client");
    if(!mqtt.begin("DVES_duino", "admin", "Isb_C4OGD4c3", 120, 1))
    {
      Serial.println("ARDUINO: fail to setup mqtt");
      while(1);
    }



    Serial.println("ARDUINO: settingup mqtt LWT");
    mqtt.lwt("flip/den/lwt", "offline", 0, 0);
    //or mqtt.lwt("/lwt", "offline");
    mqttSetup();
    //delay(2000);
    wifiSetup();
    //delay(2000);
    //Serial.print("ssid:");
    //Serial.println(*ssid);
}
void FlipMqtt::wifiCb(void* response)
{
  uint32_t status;
  RESPONSE res(response);

  if(res.getArgc() == 1) {
    
    res.popArgs((uint8_t*)&status, 4);
    
    if(status == STATION_GOT_IP)
    {
      Serial.println("CONNECTED TO WIFI NETWORK");
	 delay(10);
	 //mqtt.connect("iot.eclipse.org", 1883, false);
      //mqtt.connect("10.10.17.237", 1883, false);
	 mqtt.connect("52.204.21.160", 1883, false);
      wifiConnected = true;
      //or mqtt.connect("host", 1883); /*without security ssl*/
    }
    else
    {
      if(status == STATION_CONNECTING)
      {
         Serial.println("WiFi is connecting...");
      }
      if(status == STATION_WRONG_PASSWORD)
      {
         Serial.println("WiFi AP Wrong password");
      }
      if(status == STATION_NO_AP_FOUND)
      {
         Serial.println("No WiFi AP Found");
      }
      if(status == STATION_CONNECT_FAIL)
      {
         Serial.println("WiFi Connect fail");
      }
      if(status == STATION_IDLE)
      {
         Serial.println("WiFi Idle");
      }
      wifiConnected = false;
      mqtt.disconnect();
    }

  }
}
void FlipMqtt::mqttPublished(void* response)
{

}
void FlipMqtt::mqttSub(char* s)
{
  top= s;
}
void FlipMqtt::mqttConnected(void* response)
{
  //Serial.println(top);
  Serial.println("mqtt Connected Successfully");
  delay(10);
  mqtt.subscribe(top,1);
  if(top!="null")
  Serial.println(top);
}
void FlipMqtt::mqttDisconnected(void* response)
{
	Serial.println("Disconnected.");
}
void FlipMqtt::mqttData(void* response)
{
  RESPONSE res(response);
  Serial.print("Received: topic=");
  String topic = res.popString();
  Serial.println(topic);

  Serial.print("data=");
  String data= res.popString();
  Serial.println(data);
  Serial.println(topic);
  //sw=data.toInt();
  val=data;
/*
  int length_data=data.length()+1;
  char char_data[length_data];
  data.toCharArray(char_data,length_data);
  Serial.println(char_data);
  strcpy(val,&char_data[0]);*/
}

void FlipMqtt::mqttPub(char* s,int val)
{
  esp.process();
  String str_val= String(val);
  int length_val=str_val.length()+1;
  char char_val[length_val];
  str_val.toCharArray(char_val,length_val);

  
  if(wifiConnected)
  {
     mqtt.publish(s, char_val);
  }
  delay(500);
}

void FlipMqtt::mqttPub(char s[],char val[])
{
  esp.process();
  /*String str_val= String(val);
  int length_val=str_val.length()+1;
  char char_val[length_val];
  str_val.toCharArray(char_val,length_val);*/

  
  if(wifiConnected)
  {
     mqtt.publish(s, val);
  }
  delay(500);
}


/*setup mqtt events */
void FlipMqtt::mqttSetup()
{
    FlipMqtt fsh;
    mqtt.connectedCb.attach(&fsh,&FlipMqtt::mqttConnected);
    mqtt.disconnectedCb.attach(&fsh,&FlipMqtt::mqttDisconnected);
    mqtt.publishedCb.attach(&fsh,&FlipMqtt::mqttPublished);
    mqtt.dataCb.attach(&fsh,&FlipMqtt::mqttData);
}


void FlipMqtt::wifiSetup()
/*setup wifi*/
{
    FlipMqtt fsh;
    Serial.println("ARDUINO: setup wifi");
    esp.wifiCb.attach(&fsh,&FlipMqtt::wifiCb);
    esp.wifiConnect(_ssid,_pwd);
    Serial.println("ARDUINO: system started");
}


char* FlipMqtt::GetSubValue(char* s)
{
    char* str_top= s;
    int length_data=val.length()+1;
    char char_data[length_data];
    val.toCharArray(char_data,length_data);
    //Serial.println(char_data);
    return(&char_data[0]);	
}
