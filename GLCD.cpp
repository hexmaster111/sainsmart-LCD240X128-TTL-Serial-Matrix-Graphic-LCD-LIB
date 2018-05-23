#include "GLCD.h" 

const byte sta = 0x8A;
const byte stb = 0xA8;

void LCD::init(){
	Serial1.begin(9600);
}

//void LCD::~INIT(){}

void LCD::clear(){
	Serial1.write(sta);
	Serial1.write(stb);
	Serial1.write(0xff);
	Serial1.write(0xff);	
}

void LCD::print(int row, int col, String data){
	int length = data.length();
	int modRow = row * 13; //13 as thats the length of the chars
	delay(60); // delay as the screen cant handle the speed of the truth.
	Serial1.write(sta);
	Serial1.write(stb);  
	Serial1.write(modRow);//row
	Serial1.write(col);//col
	Serial1.write(length);//string length
	Serial1.print(data);
	Serial.println(length);
}
