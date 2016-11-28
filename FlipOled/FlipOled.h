/*------------------------------------------------------------
This is the .h file for FLIP OLED Library
This is the property of Frugal Labs Tech Solutions Pvt. Ltd.
Please refer lisence.txt for complete details.
-------------------------------------------------------------*/
#ifndef FlipOLED_H
#define FlipOLED_H
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class FlipOled
{
  public:
		  FlipOled();
          void oledInit(String ii);
		  void oledDisp(String a, int aa);
		  void oledDisp(String a, int aa, String b, int bb);
		  void oledDisp(String a, int aa, String b, int bb, String c, int cc);
          
  private:

};

#endif
