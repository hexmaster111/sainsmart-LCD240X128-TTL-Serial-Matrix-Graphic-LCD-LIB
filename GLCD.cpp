#include "GLCD.h"

const byte sta = 0x8A;
const byte stb = 0xA8;

HardwareSerial *_serial = nullptr;

void LCD::begin(HardwareSerial *serial)
{
	_serial = serial;
}

void LCD::clear()
{
	if (_serial == nullptr)
		return;
	_serial->write(sta);
	_serial->write(stb);
	_serial->write(0xff);
	_serial->write(0xff);
}

void LCD::print(int row, int col, String data)
{
	if (_serial == nullptr)
		return;
	int length = data.length();
	int modRow = row * 12; // 13 as thats the length of the chars
	_serial->write(sta);
	_serial->write(stb);
	_serial->write(modRow); // row
	_serial->write(col);	// col
	_serial->write(length); // string length
	_serial->print(data);
	_serial->print(length);
}
