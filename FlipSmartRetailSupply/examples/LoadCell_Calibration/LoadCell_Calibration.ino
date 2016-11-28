/*
 Example using the HX711 breakout board with a Load Cell (or Scale)
 By: Nathan Seidle
 
 This is the calibration sketch. Use it to determine the calibration_factor that the FLIP Smart Retail & Supply Chain library uses.
 It also outputs the zero_factor useful for projects that have a permanent mass on the scale in between power cycles.
 
 Setup your scale and start the sketch WITHOUT a weight on the scale
 Once readings are displayed place the weight on the scale
 Press +/- or a/z to adjust the calibration_factor until the output readings match the known weight
 Use this calibration_factor on the FLIP Smart Retail & Supply Chain library.
 
 This example assumes pounds (lbs). If you prefer kilograms, change the Serial.print(" lbs"); line to kg. The
 calibration factor will be significantly different but it will be linearly related to lbs (1 lbs = 0.453592 kg).
 
 Your calibration factor may be very positive or very negative. It all depends on the setup of your scale system
 and the direction the sensors deflect from zero state

 FLIP Base Board -> HX711 
      A3      -> CLK
      A5      -> DOUT
      5V     -> VCC
      GND    -> GND
 
*/

#include "HX711.h"

#define DOUT  A5
#define CLK  A3

HX711 scale1(DOUT, CLK);

float calibration_factor = -186000; //-7050 worked for my 440lb max scale setup

void setup() 
{
  Serial.begin(19200);
  Serial.println("HX711 calibration sketch");
  Serial.println("Remove all weight from scale");
  Serial.println("After readings begin, place known weight on scale");
  Serial.println("Press + or a to increase calibration factor");
  Serial.println("Press - or z to decrease calibration factor");

  scale1.set_scale();
  scale1.tare();	//Reset the scale to 0

  long zero_factor = scale1.read_average(); //Get a baseline reading
  Serial.print("Zero factor: "); //This can be used to remove the need to tare the scale1. Useful in permanent scale projects.
  Serial.println(zero_factor);
}

void loop() 
{

  scale1.set_scale(calibration_factor); //Adjust to this calibration factor for Kg scale1.

  Serial.print("Reading: ");
  Serial.print(scale1.get_units(), 1);
  Serial.print(" lbs"); 
  Serial.print(" calibration_factor: ");
  Serial.print(calibration_factor);
  Serial.println();

  if(Serial.available())
  {
    char temp = Serial.read();
    if(temp == '+' || temp == 'a')
      calibration_factor += 50;
    else if(temp == '-' || temp == 'z')
      calibration_factor -= 50;
  }
}