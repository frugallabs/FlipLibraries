/*------------------------------------------------------------
This is the .cpp file for FLIP OLED Library
This is the property of Frugal Labs Tech Solutions Pvt. Ltd.
Please refer lisence.txt for complete details.
-------------------------------------------------------------*/
#include "Arduino.h"
#include "FlipOled.h"
#include "U8x8lib.h"
#define SCL 7 //OLED's SCL pin connected to D7
#define SDA 8 //OLED's SDA pin connected to D8

// Please update the pin numbers according to your setup. Use U8X8_PIN_NONE if the reset pin is not connected
// Initilizing Software I2C for OLED
U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);   // OLEDs without Reset of the Display

FlipOled::FlipOled()
{
  
}

void FlipOled::oledInit(String ii)
{
  u8x8.begin();
  u8x8.setPowerSave(0);
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  u8x8.setCursor(0,2);
  u8x8.print(ii);
  u8x8.setCursor(0,3);
  u8x8.print(" initializing...");
  u8x8.setCursor(0,6);
  u8x8.print(" Powered by FLIP");
  delay(5000);
  u8x8.clearDisplay();
}

void FlipOled::oledDisp(String a, int aa)
{
  u8x8.setCursor(0,0);
  u8x8.print(a);
  u8x8.setCursor(10,0);
  u8x8.print(aa);
}

void FlipOled::oledDisp(String a, int aa, String b, int bb)
{
  u8x8.setCursor(0,0);
  u8x8.print(a);
  u8x8.setCursor(10,0);
  u8x8.print(aa);
  u8x8.setCursor(0,2);
  u8x8.print(b);
  u8x8.setCursor(10,2);
  u8x8.print(bb);
}

void FlipOled::oledDisp(String a, int aa, String b, int bb, String c, int cc)
{
  u8x8.setCursor(0,0);
  u8x8.print(a);
  u8x8.setCursor(10,0);
  u8x8.print(aa);
  u8x8.setCursor(0,2);
  u8x8.print(b);
  u8x8.setCursor(10,2);
  u8x8.print(bb);
  u8x8.setCursor(0,4);
  u8x8.print(c);
  u8x8.setCursor(10,4);
  u8x8.print(cc);
}