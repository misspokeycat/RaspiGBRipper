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

	for (int i=0; i<27; i++){
		pullUpDnControl(i, PUD_DOWN);
	}

	for(;;){
	// Translate address to wires
	if (digitalRead(WRITE)) cout << "0 WRITE" << endl;
	if (digitalRead(READ)) cout << "1 READ" << endl;
        if (digitalRead(SRAM)) cout << "2 SRAM" << endl;
        if (digitalRead(A0)) cout << "3 A0" << endl;
        if (digitalRead(A1)) cout << "4 A1" << endl;
        if (digitalRead(A2)) cout << "5 A2" << endl;
        if (digitalRead(A3)) cout << "6 A3" << endl;
        if (digitalRead(A4)) cout << "7 A4" << endl;
        if (digitalRead(A5)) cout << "8 A5" << endl;
        if (digitalRead(A6)) cout << "9 A6" << endl;
        if (digitalRead(A7)) cout << "10 A7" << endl;
        if (digitalRead(A8)) cout << "11 A8" << endl;
        if (digitalRead(A9)) cout << "12 A9" << endl;
        if (digitalRead(A10)) cout << "13 A10" << endl;
        if (digitalRead(A11)) cout << "14 A11" << endl;
        if (digitalRead(A12)) cout << "15 A12" << endl;
        if (digitalRead(A13)) cout << "16 A13" << endl;
        if (digitalRead(A14)) cout << "17 A14" << endl;
        if (digitalRead(A15)) cout << "18 A15" << endl;
        if (digitalRead(D0)) cout << "19 D0" << endl;
        if (digitalRead(D1)) cout << "20 D1" << endl;
        if (digitalRead(D2)) cout << "21 D2" << endl;
        if (digitalRead(D3)) cout << "22 D3" << endl;
        if (digitalRead(D4)) cout << "23 D4" << endl;
        if (digitalRead(D5)) cout << "24 D5" << endl;
        if (digitalRead(D6)) cout << "25 D6" << endl;
        if (digitalRead(D7)) cout << "26 D7" << endl;
	cout << "##################" << endl;
	delay(500);
	}
}
