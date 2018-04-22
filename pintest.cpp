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
	pinMode(WRITE, INPUT);
	pinMode(READ, INPUT);
	pinMode(SRAM, INPUT);
	pinMode(A0, INPUT);
	pinMode(A1, INPUT);
	pinMode(A2, INPUT);
	pinMode(A3, INPUT);
	pinMode(A4, INPUT);
	pinMode(A5, INPUT);
	pinMode(A6, INPUT);
	pinMode(A7, INPUT);
	pinMode(A8, INPUT);
	pinMode(A9, INPUT);
	pinMode(A10, INPUT);
	pinMode(A11, INPUT);
	pinMode(A12, INPUT);
	pinMode(A13, INPUT);
	pinMode(A14, INPUT);
	pinMode(A15, INPUT);
	pinMode(D0, INPUT);
	pinMode(D1, INPUT);
	pinMode(D2, INPUT);
	pinMode(D3, INPUT);
	pinMode(D4, INPUT);
	pinMode(D5, INPUT);
	pinMode(D6, INPUT);
	pinMode(D7, INPUT);

	for(;;){
	// Translate address to wires
	if (digitalRead(WRITE)) cout << "WRITE" << endl;
	if (digitalRead(READ)) cout << "READ" << endl;
        if (digitalRead(SRAM)) cout << "SRAM" << endl;
        if (digitalRead(A0)) cout << "A0" << endl;
        if (digitalRead(A1)) cout << "A1" << endl;
        if (digitalRead(A2)) cout << "A2" << endl;
        if (digitalRead(A3)) cout << "A3" << endl;
        if (digitalRead(A4)) cout << "A4" << endl;
        if (digitalRead(A5)) cout << "A5" << endl;
        if (digitalRead(A6)) cout << "A6" << endl;
        if (digitalRead(A7)) cout << "A7" << endl;
        if (digitalRead(A8)) cout << "A8" << endl;
        if (digitalRead(A9)) cout << "A9" << endl;
        if (digitalRead(A10)) cout << "A10" << endl;
        if (digitalRead(A11)) cout << "A11" << endl;
        if (digitalRead(A12)) cout << "A12" << endl;
        if (digitalRead(A13)) cout << "A13" << endl;
        if (digitalRead(A14)) cout << "A14" << endl;
        if (digitalRead(A15)) cout << "A15" << endl;
        if (digitalRead(D0)) cout << "D0" << endl;
        if (digitalRead(D1)) cout << "D1" << endl;
        if (digitalRead(D2)) cout << "D2" << endl;
        if (digitalRead(D3)) cout << "D3" << endl;
        if (digitalRead(D4)) cout << "D4" << endl;
        if (digitalRead(D5)) cout << "D5" << endl;
        if (digitalRead(D6)) cout << "D6" << endl;
        if (digitalRead(D7)) cout << "D7" << endl;
	cout << "##################" << endl;
	delay(500);
	}
}
