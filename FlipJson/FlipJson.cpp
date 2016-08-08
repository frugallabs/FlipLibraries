#include "Arduino.h"
#include "SoftwareSerial.h"
#include "ArduinoJson.h"
#include "FlipJson.h"

SoftwareSerial myflipSerial(RX, TX);

FlipJson::FlipJson()
{     
  myflipSerial.begin(_baud_bt);
}

/******** json print for int *************/

void FlipJson::jsonPrint(int a)
{
  StaticJsonBuffer<100> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["data1"] = a;
  root.printTo(myflipSerial);
  myflipSerial.println();
  delay(500);
}

void FlipJson::jsonPrint(int a,int b)
{
  StaticJsonBuffer<100> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["data1"] = a;
  root["data2"] = b;
  root.printTo(myflipSerial);
  myflipSerial.println();
  delay(500);
}


void FlipJson::jsonPrint(int a,int b, int c)
{
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["data1"] = a;
  root["data2"] = b;
  root["data3"] = c;
  root.printTo(myflipSerial);
  myflipSerial.println();
  delay(500);
}


void FlipJson::jsonPrint(int a,int b, int c, int d)
{
  StaticJsonBuffer<300> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["data1"] = a;
  root["data2"] = b;
  root["data3"] = c;
  root["data4"] = d;
  root.printTo(myflipSerial);
  myflipSerial.println();
  delay(500);
}

void FlipJson::jsonPrint(int a, int b, int c, int d, int e)
{
  StaticJsonBuffer<500> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["data1"] = a;
  root["data2"] = b;
  root["data3"] = c;
  root["data4"] = d;
  root["data5"] = e;
  root.printTo(myflipSerial);
  myflipSerial.println();
  delay(500);
}

/************  json with string **********/

void FlipJson::jsonPrint(String* x)
{
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["data1"] = *x;
  root.printTo(myflipSerial);
  myflipSerial.println();
  delay(500);
}

void FlipJson::jsonPrint(int a, String* x)
{
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["data1"] = a;
  root["data2"] = *x;
  root.printTo(myflipSerial);
  myflipSerial.println();
  delay(500);
}


void FlipJson::jsonPrint(int a,int b, String* x)
{
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["data1"] = a;
  root["data2"] = b;
  root["data3"] = *x;
  root.printTo(myflipSerial);
  myflipSerial.println();
  delay(500);
}


void FlipJson::jsonPrint(int a,int b, int c, String* x)
{
  StaticJsonBuffer<300> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["data1"] = a;
  root["data2"] = b;
  root["data3"] = c;
  root["data4"] = *x;
  root.printTo(myflipSerial);
  myflipSerial.println();
  delay(500);
}

void FlipJson::jsonPrint(int a, int b, int c, int d, String* x)
{
  StaticJsonBuffer<600> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["data1"] = a;
  root["data2"] = b;
  root["data3"] = c;
  root["data4"] = d;
  root["data5"] = *x;
  root.printTo(myflipSerial);
  myflipSerial.println();
  delay(500);
}

void FlipJson::jsonPrint(int a, int b, int c, int d, int e, String* x)
{
  StaticJsonBuffer<700> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["data1"] = a;
  root["data2"] = b;
  root["data3"] = c;
  root["data4"] = d;
  root["data5"] = e;
  root["data6"] = *x;
  root.printTo(myflipSerial);
  myflipSerial.println();
  delay(500);
}

/**********************************************************/

int FlipJson::relayState()
{
  
  int serial_in='0';
  if (myflipSerial.available() > 0)
  {
    serial_in = myflipSerial.read();
    if (serial_in == '1')
    _cmd = HIGH;
    
    else if (serial_in == '0')
    _cmd = LOW;
  }
  return (_cmd);
}