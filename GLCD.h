#ifndef GLCD_H
#define GLCD_H

#include <Arduino.h>
#include <string.h>

class LCD
{
public:
	void begin(HardwareSerial *serial);
	void clear();
	void print(int row, int col, String data);
};

#endif
