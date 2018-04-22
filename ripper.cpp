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
	pinMode(D1, INPUT);
	pinMode(D2, INPUT);
	pinMode(D3, INPUT);
	pinMode(D4, INPUT);
	pinMode(D5, INPUT);
	pinMode(D6, INPUT);
	pinMode(D7, INPUT);

	digitalWrite(WRITE, 1);
	digitalWrite(READ, 0);
	for(unsigned short i=0x4000; i < 0xFFFF; i++){
	// Translate address to wires

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

		sleep(5);

		unsigned char data = 0;

		data += ((char)digitalRead(D0));
		data += ((char)digitalRead(D1)) << 1;
		data += ((char)digitalRead(D2)) << 2;
		data += ((char)digitalRead(D3)) << 3;
		data += ((char)digitalRead(D4)) << 4;
                data += ((char)digitalRead(D5)) << 5;
		data += ((char)digitalRead(D6)) << 6;
		data += ((char)digitalRead(D7)) << 7;

		cout << (int)data;


	}
}
