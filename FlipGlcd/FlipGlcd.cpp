/*------------------------------------------------------------
This is the .cpp file for FLIP GLCD Library
This is the property of Frugal Labs Tech Solutions Pvt. Ltd.
Please refer lisence.txt for complete details.
-------------------------------------------------------------*/
#include "Arduino.h"
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_PCD8544.h"
#include "FlipGlcd.h"
Adafruit_PCD8544 display = Adafruit_PCD8544(4,5,6,7,8); //configure the GLCD pins
FlipGlcd::FlipGlcd()
{
  
}

void FlipGlcd::glcdInit()
{
  display.begin();
  static const unsigned char PROGMEM logo16_glcd_bmp[] =
  {
    0b11111111, 0b11111111, 0b11111111, 0b11111111, // ################################
    0b11111111, 0b11111111, 0b11111111, 0b11111111, // ################################
    0b11111111, 0b11111111, 0b11111111, 0b11111111, // ################################
    0b11111111, 0b11111111, 0b11111111, 0b11111111, // ################################
    0b11111111, 0b11111111, 0b11111111, 0b11111111, // ################################
    0b11111110, 0b00000000, 0b00000000, 0b00001111, // #######                     ####
    0b11111100, 0b00000000, 0b00000000, 0b00001111, // ######                      ####
    0b11111000, 0b00000000, 0b00000000, 0b00001111, // #####                       ####
    0b11110000, 0b00000000, 0b00000000, 0b00001111, // ####                        ####
    0b11100000, 0b00000000, 0b00000000, 0b00001111, // ###                         ####
    0b11100000, 0b00000000, 0b00000000, 0b00001111, // ###                         ####
    0b11111111, 0b11111111, 0b11111111, 0b11111111, // ################################
    0b11111111, 0b11111111, 0b11111111, 0b11111111, // ################################
    0b11111111, 0b11111111, 0b11111111, 0b11111111, // ################################
    0b11111111, 0b10000000, 0b00000000, 0b00001111, // #########                   ####
    0b11111111, 0b00000000, 0b00000000, 0b00001111, // ########                    ####
    0b11111100, 0b00000000, 0b00000000, 0b00001111, // ######                      ####
    0b11111000, 0b00000000, 0b00000000, 0b00001111, // #####                       ####
    0b11111000, 0b00000000, 0b00000000, 0b00001111, // #####                       ####
    0b11110000, 0b00000000, 0b00000000, 0b00001111, // ####                        ####
    0b11110000, 0b00001111, 0b11111111, 0b11111111, // ####       #####################
    0b11100000, 0b00111111, 0b11111111, 0b11111111, // ###       ######################
    0b11100000, 0b01111111, 0b11111111, 0b11111111, // ###      #######################
    0b11100000, 0b01111111, 0b11111111, 0b11111111, // ###      #######################
    0b11100000, 0b01111111, 0b11111111, 0b11111111, // ###      #######################
    0b11100000, 0b01111111, 0b11111111, 0b11111111, // ###      #######################
    0b11100000, 0b01111111, 0b11111111, 0b11111111, // ###      #######################
    0b11100000, 0b01111111, 0b11111111, 0b11111111, // ###      #######################
    0b11111111, 0b11111111, 0b11111111, 0b11111111, // ################################
    0b11111111, 0b11111111, 0b11111111, 0b11111111, // ################################
    0b11111111, 0b11111111, 0b11111111, 0b11111111, // ################################
    0b11111111, 0b11111111, 0b11111111, 0b11111111, // ################################
  };
  display.begin();
  // miniature bitmap display
  display.clearDisplay();
  display.drawBitmap(25, 5,  logo16_glcd_bmp, 32, 32, 1);
  display.display();
  display.setCursor(12,40);
  display.print("DREAM IoT");
  display.display();//------------------------------------------------------
  delay(5000);
  display.clearDisplay();
  display.setCursor(0,5);
  display.print("  FLIP WATCH");
  //display.display();
  display.setCursor(0,20);
  display.print("Initilizing...");
  //display.display();//-------------------------------------------------
  for (int i=0; i<80; i++)
  {
    display.setCursor(i,30);
    display.print(".");
    //display.display();
    display.setCursor(i,32);
    display.print(".");
    //display.display();
    display.setCursor(i,34);
    display.print(".");
    display.display();//-----------------------------------------------------
    delay(5);
  }
  display.clearDisplay();
}

void FlipGlcd::glcdDisp(int a, int b, int c)
{
  display.clearDisplay();
  display.setTextSize(1);
  
  display.setCursor(0,0);
  display.print("Steps: ");
  display.setCursor(40,0);
  display.print(a);
    
  display.setCursor(0,15);  
  display.print("Temp: ");
  display.setCursor(40,15);
  display.print(b);
  display.setCursor(60,15);
  display.print("F");  
    
  display.setCursor(0,30);
  display.print("Heart");
  display.setCursor(0,40);
  display.print("Rate");
  display.setCursor(30,35);
  display.print(":");    
  display.setCursor(40,35);
  display.print(c);  
  display.setCursor(60,35);
  display.print("BPM"); 
    
  display.display();
}
