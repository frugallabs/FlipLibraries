/*------------------------------------------------------------
This is the .cpp file for FLIP SMART HEALTH Library
This is the property of Frugal Labs Tech Solutions Pvt. Ltd.
Please refer lisence.txt for complete details.
-------------------------------------------------------------*/
#include "FlipSmartHealth.h"

volatile int BPM;                   // int that holds raw Analog in 0. updated every 2mS
volatile int Signal;                // holds the incoming raw data
volatile int IBI = 600;             // int that holds the time interval between beats! Must be seeded!
volatile boolean Pulse = false;     // "True" when User's live heartbeat is detected. "False" when not a "live beat".
volatile boolean QS = false;        // becomes true when Arduoino finds a beat.

volatile int rate[10];                    // array to hold last ten IBI values
volatile unsigned long sampleCounter = 0;          // used to determine pulse timing
volatile unsigned long lastBeatTime = 0;           // used to find IBI
volatile int P = 512;                     // used to find peak in pulse wave, seeded
volatile int T = 512;                     // used to find trough in pulse wave, seeded
volatile int thresh = 525;                // used to find instant moment of heart beat, seeded
volatile int amp = 100;                   // used to hold amplitude of pulse waveform, seeded
volatile boolean firstBeat = true;        // used to seed rate array so we startup with reasonable BPM
volatile boolean secondBeat = false;      // used to seed rate array so we startup with reasonable BPM
#define avgVal 10
int samples[avgVal];

int xavg;
int yavg;
int zavg;
int xval[5]={0};
int yval[5]={0};
int zval[5]={0};

FlipSmartHealth::FlipSmartHealth()
{   
  pinMode(pulsePin, INPUT);
  pinMode(xpin, INPUT);
  pinMode(ypin, INPUT);
  pinMode(zpin, INPUT);
  interruptSetup();  
}

void FlipSmartHealth::interruptSetup()
{
  // Initializes Timer2 to throw an interrupt every 2mS.
  TCCR0A = 0x02;     // DISABLE PWM ON DIGITAL PINS 3 AND 11, AND GO INTO CTC MODE
  TCCR0B = 0x04;     // DON'T FORCE COMPARE, 256 PRESCALER
  OCR0A = 0X7C;      // SET THE TOP OF THE COUNT TO 124 FOR 500Hz SAMPLE RATE
  TIMSK0 = 0x02;     // ENABLE INTERRUPT ON MATCH BETWEEN TIMER2 AND OCR2A
  sei();             // MAKE SURE GLOBAL INTERRUPTS ARE ENABLED
}
// THIS IS THE TIMER 0 INTERRUPT SERVICE ROUTINE.
// Timer 0 makes sure that we take a reading every 2 miliseconds
ISR(TIMER0_COMPA_vect)
{ // triggered when Timer2 counts to 124
  cli();                                      // disable interrupts while we do this
  Signal = analogRead(pulsePin);              // read the Pulse Sensor
  sampleCounter += 2;                         // keep track of the time in mS with this variable
  int N = sampleCounter - lastBeatTime;       // monitor the time since the last beat to avoid noise

  //  find the peak and trough of the pulse wave
  if (Signal < thresh && N > (IBI / 5) * 3)
  { // avoid dichrotic noise by waiting 3/5 of last IBI
    if (Signal < T)
    { // T is the trough
      T = Signal;                         // keep track of lowest point in pulse wave
    }
  }

  if (Signal > thresh && Signal > P)
  { // thresh condition helps avoid noise
    P = Signal;                             // P is the peak
  }                                        // keep track of highest point in pulse wave

  //  NOW IT'S TIME TO LOOK FOR THE HEART BEAT
  // signal surges up in value every time there is a pulse
  if (N > 250)
  { // avoid high frequency noise
    if ( (Signal > thresh) && (Pulse == false) && (N > (IBI / 5) * 3) )
    {
      Pulse = true;                               // set the Pulse flag when we think there is a pulse
      IBI = sampleCounter - lastBeatTime;         // measure time between beats in mS
      lastBeatTime = sampleCounter;               // keep track of time for next pulse

      if (secondBeat)
      { // if this is the second beat, if secondBeat == TRUE
        secondBeat = false;                  // clear secondBeat flag
        for (int i = 0; i <= 9; i++)
        { // seed the running total to get a realisitic BPM at startup
          rate[i] = IBI;
        }
      }

      if (firstBeat)
      { // if it's the first time we found a beat, if firstBeat == TRUE
        firstBeat = false;                   // clear firstBeat flag
        secondBeat = true;                   // set the second beat flag
        sei();                               // enable interrupts again
        return;                              // IBI value is unreliable so discard it
      }


      // keep a running total of the last 10 IBI values
      word runningTotal = 0;                  // clear the runningTotal variable

      for (int i = 0; i <= 8; i++)
      { // shift data in the rate array
        rate[i] = rate[i + 1];                // and drop the oldest IBI value
        runningTotal += rate[i];              // add up the 9 oldest IBI values
      }

      rate[9] = IBI;                          // add the latest IBI to the rate array
      runningTotal += rate[9];                // add the latest IBI to runningTotal
      runningTotal /= 10;                     // average the last 10 IBI values
      BPM = 60000 / runningTotal;             // how many beats can fit into a minute? that's BPM!
      QS = true;                              // set Quantified Self flag
      // QS FLAG IS NOT CLEARED INSIDE THIS ISR
    }
  }

  if (Signal < thresh && Pulse == true)
  { // when the values are going down, the beat is over
    Pulse = false;                         // reset the Pulse flag so we can do it again
    amp = P - T;                           // get amplitude of the pulse wave
    thresh = amp / 2 + T;                  // set thresh at 50% of the amplitude
    P = thresh;                            // reset these for next time
    T = thresh;
  }

  if (N > 2500)
  { // if 2.5 seconds go by without a beat
    thresh = 512;                          // set thresh default
    P = 512;                               // set P default
    T = 512;                               // set T default
    lastBeatTime = sampleCounter;          // bring the lastBeatTime up to date
    firstBeat = true;                      // set these to avoid noise
    secondBeat = false;  
	//BPM = 0;// when we get the heartbeat back
  }

  sei();                                   // enable interrupts when youre done!
}// end isr

/**************************************************************/
int FlipSmartHealth::getBpm()
{
  int BeatsPerMinute;
  if (QS == true)
  { // A Heartbeat Was Found
    // BPM and IBI have been Determined
    // Quantified Self "QS" true when arduino finds a heartbeat
    if (BPM>0)
	{
		BeatsPerMinute = BPM-100;
	}
	else
	{
		BeatsPerMinute = BPM;
	}
	QS = false;                      // reset the Quantified Self flag for next time
  }
  else
  {
	  BeatsPerMinute = 0;
  }
  delay(20);  //  take a break
  //Serial.print("BPM: ");   Serial.println(BeatsPerMinute);   // A Beat Happened, Output that to serial.
  return (BeatsPerMinute);
}
/**************************************************************/


void FlipSmartHealth::Init()
{
	calibrate();
}

int FlipSmartHealth::getAccX()
{
	int ax = analogRead(xpin);
	return ax;
}

int FlipSmartHealth::getAccY()
{
	int ay = analogRead(ypin);
	return ay;
}

int FlipSmartHealth::getAccZ()
{
	int az = analogRead(zpin);
	return az;
}

/*************************************************************/
float FlipSmartHealth::readTempC()
{
  for(int i=0; i<avgVal; i++)
  {
	  samples[i]=((5.0 * analogRead(temppin) * 100.0) / 1024);
	  delay(10);
  }
  float Tavg=0;
  for(int i=0; i<avgVal; i++)
  {
	  Tavg+=samples[i];
  }
  Tavg/=avgVal;
  float TempC = Tavg;
  return(TempC);
}
/*************************************************************/
float FlipSmartHealth::readTempF()
{
  for(int i=0; i<avgVal; i++)
  {
	  samples[i]=((5.0 * analogRead(temppin) * 100.0) / 1024);
	  delay(10);
  }
  float Tavg=0;
  for(int i=0; i<avgVal; i++)
  {
	  Tavg+=samples[i];
  }
  Tavg/=avgVal;
  float TempC = Tavg;
  float TempF = ((TempC*9)/5+32)+5;
  return(TempF);
}
/*************************************************************/
int FlipSmartHealth::getPedo()
{
	// External variables

int xaccl[5]={0};
int yaccl[5]={0};
int zaccl[5]={0};
  int totvect[5]={0};
  int totave[5]={0};


  for (int i=0;i<5;i++)
  {
    xaccl[i]=float(analogRead(xpin));
    delay(1);
    yaccl[i]=float(analogRead(ypin));
    delay(1);
    zaccl[i]=float(analogRead(zpin));
    delay(1);
    totvect[i] = sqrt(((xaccl[i]-xavg)* (xaccl[i]-xavg))+ ((yaccl[i] - yavg)*(yaccl[i] - yavg)) + ((zval[i] - zavg)*(zval[i] - zavg)));
    totave[i] = (totvect[i] + totvect[i-1]) / 2 ;
    delay(60);

    //cal steps 
    if (totave[i]>threshhold && flag==0)
    {
       steps=steps+1;
       flag=1;
    }
    else if (totave[i] > threshhold && flag==1)
    {
        //do nothing 
    }
    if (totave[i] <threshhold  && flag==1)
    {
      flag=0;
    }
   // Serial.print("steps=");
   // Serial.println(steps);
   return(steps);
  }
  delay(60);
}
/**************************************************************/

void FlipSmartHealth::calibrate()
{
  Serial.begin(19200);
  digitalWrite(13,HIGH);
  Serial.println("Calibrating......");
  float sum=0;
  float sum1=0;
  float sum2=0;
  for (int i=0;i<5;i++)
  {
    xval[i]=float(analogRead(xpin));
    sum=xval[i]+sum;
  }
  delay(60);
  xavg=sum/5.0;
  Serial.println(xavg);
  for (int j=0;j<5;j++)
  {
    xval[j]=float(analogRead(xpin));
    sum1=xval[j]+sum1;
  }
  yavg=sum1/5.0;
  Serial.println(yavg);
  delay(60);
  for (int i=0;i<5;i++)
  {
    zval[i]=float(analogRead(zpin));
    sum2=zval[i]+sum2;
  }
  zavg=sum2/5.0;
  delay(60);
  Serial.println(zavg);
  digitalWrite(13,LOW);
  Serial.println("Calibration Successful!");
  //delay(900);
}
/**************************************************************/
