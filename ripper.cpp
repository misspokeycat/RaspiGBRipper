#include<wiringPi.h>
#include<iostream>
#include<time.h>
using namespace std;

/* cart pinouts are as follows
3 	/WR 	Write
4 	/RD 	Read
5 	/CS 	SRAM select
6 	A0 	Address 0
7 	A1 	Address 1
8 	A2 	Address 2
9 	A3 	Address 3
10 	A4 	Address 4
11 	A5 	Address 5
12 	A6 	Address 6
13 	A7 	Address 7
14 	A8 	Address 8
15 	A9 	Address 9
16 	A10 	Address 10
17 	A11 	Address 11
18 	A12 	Address 12
19 	A13 	Address 13
20 	A14 	Address 14
21 	A15 	Address 15
22 	D0 	Data 0
23 	D1 	Data 1
24 	D2 	Data 2
25 	D3 	Data 3
26 	D4 	Data 4
27 	D5 	Data 5
28 	D6 	Data 6
29 	D7 	Data 7*/

enum pins {
	WRITE,
	READ,
	SRAM,
	A0,
	A1,
	A2,
	A3,
	A4,
	A5,
	A6,
	A7,
	A8,
	A9,
	A10,
	A11,
	A12,
	A13,
	A14,
	A15,
	D0,
	D1,
	D2,
	D3,
	D4,
	D5,
	D6,
	D7
};

void readEnable(){
        digitalWrite(WRITE, 1);
        digitalWrite(READ, 0);

	delay(50);

	pinMode(D0, INPUT);
	pullUpDnControl (D0, PUD_DOWN);
	pinMode(D1, INPUT);
	pullUpDnControl (D1, PUD_DOWN);
	pinMode(D2, INPUT);
	pullUpDnControl (D2, PUD_DOWN);
	pinMode(D3, INPUT);
	pullUpDnControl (D3, PUD_DOWN);
	pinMode(D4, INPUT);
	pullUpDnControl (D4, PUD_DOWN);
	pinMode(D5, INPUT);
	pullUpDnControl (D5, PUD_DOWN);
	pinMode(D6, INPUT);
	pullUpDnControl (D6, PUD_DOWN);
	pinMode(D7, INPUT);
	pullUpDnControl (D7, PUD_DOWN);
}

void writeEnable(){

        digitalWrite(WRITE, 0);
        digitalWrite(READ, 1);

	delay(50);

	pinMode(D0, OUTPUT);
	pullUpDnControl (D0, PUD_OFF);
	pinMode(D1, OUTPUT);
	pullUpDnControl (D1, PUD_OFF);
	pinMode(D2, OUTPUT);
	pullUpDnControl (D2, PUD_OFF);
	pinMode(D3, OUTPUT);
	pullUpDnControl (D3, PUD_OFF);
	pinMode(D4, OUTPUT);
	pullUpDnControl (D4, PUD_OFF);
	pinMode(D5, OUTPUT);
	pullUpDnControl (D5, PUD_OFF);
	pinMode(D6, OUTPUT);
	pullUpDnControl (D6, PUD_OFF);
	pinMode(D7, OUTPUT);
	pullUpDnControl (D7, PUD_OFF);

	delay(50);

}


	unsigned char readAddress(unsigned short i){

		digitalWrite(A0, i & 0x01);
        digitalWrite(A1, i & 0x02);
        digitalWrite(A2, i & 0x04);
        digitalWrite(A3, i & 0x08);
        digitalWrite(A4, i & 0x10);
        digitalWrite(A5, i & 0x20);
        digitalWrite(A6, i & 0x40);
        digitalWrite(A7, i & 0x80);
        digitalWrite(A8, i & 0x100);
        digitalWrite(A9, i & 0x200);
        digitalWrite(A10, i & 0x400);
        digitalWrite(A11, i & 0x800);
        digitalWrite(A12, i & 0x1000);
        digitalWrite(A13, i & 0x2000);
        digitalWrite(A14, i & 0x4000);
        digitalWrite(A15, i & 0x8000);

		delayMicroseconds(50);

		unsigned char data = 0;

		data += ((char)digitalRead(D0));
		data += ((char)digitalRead(D1)) << 1;
		data += ((char)digitalRead(D2)) << 2;
		data += ((char)digitalRead(D3)) << 3;
		data += ((char)digitalRead(D4)) << 4;
        data += ((char)digitalRead(D5)) << 5;
		data += ((char)digitalRead(D6)) << 6;
		data += ((char)digitalRead(D7)) << 7;
 
		return data;
	}


	void writeAddress(unsigned short i, unsigned char j){
//	cerr << "writing" << (int)j << endl;

	digitalWrite(A0, i & 0x01);
        digitalWrite(A1, i & 0x02);
        digitalWrite(A2, i & 0x04);
        digitalWrite(A3, i & 0x08);
        digitalWrite(A4, i & 0x10);
        digitalWrite(A5, i & 0x20);
        digitalWrite(A6, i & 0x40);
        digitalWrite(A7, i & 0x80);
        digitalWrite(A8, i & 0x100);
        digitalWrite(A9, i & 0x200);
        digitalWrite(A10, i & 0x400);
        digitalWrite(A11, i & 0x800);
        digitalWrite(A12, i & 0x1000);
        digitalWrite(A13, i & 0x2000);
        digitalWrite(A14, i & 0x4000);
        digitalWrite(A15, i & 0x8000);

		delay(5);
//		cerr << "1&j" << (int)(j & 0x01) << endl;

		digitalWrite(D0, j & 0x01);
		digitalWrite(D1, j & 0x02);
		digitalWrite(D2, j & 0x04);
		digitalWrite(D3, j & 0x08);
		digitalWrite(D4, j & 0x10);
        	digitalWrite(D5, j & 0x20);
		digitalWrite(D6, j & 0x40);
		digitalWrite(D7, j & 0x80);
		delay(5);


	}



void sleep(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

int main(void){
	wiringPiSetupGpio();
	// GPIO pin setup code goes here
	pinMode(WRITE, OUTPUT);
	pinMode(READ, OUTPUT);
	pinMode(SRAM, OUTPUT);
	pinMode(A0, OUTPUT);
	pinMode(A1, OUTPUT);
	pinMode(A2, OUTPUT);
	pinMode(A3, OUTPUT);
	pinMode(A4, OUTPUT);
	pinMode(A5, OUTPUT);
	pinMode(A6, OUTPUT);
	pinMode(A7, OUTPUT);
	pinMode(A8, OUTPUT);
	pinMode(A9, OUTPUT);
	pinMode(A10, OUTPUT);
	pinMode(A11, OUTPUT);
	pinMode(A12, OUTPUT);
	pinMode(A13, OUTPUT);
	pinMode(A14, OUTPUT);
	pinMode(A15, OUTPUT);
	pinMode(D0, INPUT);
	pullUpDnControl (D0, PUD_DOWN);
	pinMode(D1, INPUT);
	pullUpDnControl (D1, PUD_DOWN);
	pinMode(D2, INPUT);
	pullUpDnControl (D2, PUD_DOWN);
	pinMode(D3, INPUT);
	pullUpDnControl (D3, PUD_DOWN);
	pinMode(D4, INPUT);
	pullUpDnControl (D4, PUD_DOWN);
	pinMode(D5, INPUT);
	pullUpDnControl (D5, PUD_DOWN);
	pinMode(D6, INPUT);
	pullUpDnControl (D6, PUD_DOWN);
	pinMode(D7, INPUT);
	pullUpDnControl (D7, PUD_DOWN);
	digitalWrite(WRITE, 1);
	digitalWrite(READ, 0);
// Cart size is at address 0x148
/*
 00h -  32KByte (no ROM banking)
 01h -  64KByte (4 banks)
 02h - 128KByte (8 banks)
 03h - 256KByte (16 banks)
 04h - 512KByte (32 banks)
 05h -   1MByte (64 banks)  - only 63 banks used by MBC1
 06h -   2MByte (128 banks) - only 125 banks used by MBC1
 07h -   4MByte (256 banks)
 08h -   8MByte (512 banks)
 52h - 1.1MByte (72 banks)
 53h - 1.2MByte (80 banks)
 54h - 1.5MByte (96 banks)
*/


unsigned char bankNum = readAddress(0x148);
unsigned char bank;
	switch(bankNum){
		case 0x00: bank = 0;
			break;
		case 0x01: bank = 4;
			break;
		case 0x02: bank = 8;
			break;
		case 0x03: bank = 16;
			break;
		case 0x04: bank = 32;
			break;
		case 0x05: bank = 64;
			break;
		case 0x06: bank = 128;
			break;
		case 0x07: bank = 256;
			break;
		case 0x08: bank = 512;
			break;
		case 0x52: bank = 72;
			break;
		case 0x53: bank = 80;
			break;
		case 0x54: bank = 96;
			break;
	}

		cerr << "number of banks " << (int)bank << endl;

		readEnable();

		for(unsigned short i=0x0000; i < 0x4000; i++){
			cout << readAddress(i);
		}

		for(unsigned char i = 1; i < bank; i++){
			cerr << "reading bank " << (int)i << endl;

			writeEnable();
			delay(50);
			//writeAddress(0x6000, 0);
			delay(20);
			writeAddress(0x2100, i);
			//digitalWrite(D0, 1);
			readEnable();
			cerr << " first bit is " << hex << +readAddress(0x4000) << endl;

			for(unsigned short j=0x4000; j < 0x8000; j++){
				cout << readAddress(j);
			}

		}
	}


