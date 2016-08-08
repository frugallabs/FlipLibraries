#ifndef FlipJson_H
#define FlipJson_H
#if ARDUINO >= 100
#include "Arduino.h"

#else
#include "WProgram.h"

#endif
#define RX 11
#define TX 10

class FlipJson 
{
public:
	FlipJson();	
	int relayState();
	void jsonPrint(int a);
	void jsonPrint(int a, int b);
	void jsonPrint(int a, int b, int c);
	void jsonPrint(int a, int b, int c, int d);
	void jsonPrint(int a, int b, int c, int d, int e);
	void jsonPrint(String* x);
	void jsonPrint(int a, String* x);
	void jsonPrint(int a, int b, String* x);
	void jsonPrint(int a, int b, int c, String* x);
	void jsonPrint(int a, int b, int c, int d, String* x);
	void jsonPrint(int a, int b, int c, int d, int e, String* x);

	               
private:
                int _baud_bt=9600;  
			int _cmd=LOW;           
};

#endif
