/*------------------------------------------------------------
This is the .h file for FLIP GLCD Library
This is the property of Frugal Labs Tech Solutions Pvt. Ltd.
Please refer lisence.txt for complete details.
-------------------------------------------------------------*/
#ifndef FlipGlcd_H
#define FlipGlcd_H
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define XPOS 0
#define YPOS 1
#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16

class FlipGlcd
{
  public:
          FlipGlcd();
          void glcdInit();
          void glcdDisp(int a, int b, int c);
            
  private:

};

#endif
