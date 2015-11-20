#include "TimingTest.h"
#include "TimerDriver.h"
#include "SerialDriver.h"

void timeTest () {
	stringSendToUSART2("Add two random 32 bit integers: ");
	printNewLine();
	doubleSendToUSART2(add32BitsInt());
	stringSendToUSART2("ms");
	printNewLine();
	
	stringSendToUSART2("Multiply two random 32 bit integers: ");
	printNewLine();
	doubleSendToUSART2(mul32BitsInt());
	stringSendToUSART2("ms");
	printNewLine();
	
	stringSendToUSART2("Divide two random 32 bit integers: ");
	printNewLine();
	doubleSendToUSART2(div32BitsInt());
	stringSendToUSART2("ms");
	printNewLine();
	
	stringSendToUSART2("Copy an 8 byte struct: ");
	printNewLine();
	doubleSendToUSART2(copy8ByteStruct());
	stringSendToUSART2("ms");
	printNewLine();
	
	stringSendToUSART2("Copy a 128 byte struct: ");
	printNewLine();
	doubleSendToUSART2(copy128ByteStruct());
	stringSendToUSART2("ms");
	printNewLine();
	
	stringSendToUSART2("Add two random 64 bit integers: ");
	printNewLine();
	doubleSendToUSART2(add64BitsInt());
	stringSendToUSART2("ms");
	printNewLine();
	
	stringSendToUSART2("multiply two random 64 bit integers: ");
	printNewLine();
	doubleSendToUSART2(mul64BitsInt());
	stringSendToUSART2("ms");
	printNewLine();
	
	stringSendToUSART2("divide two random 64 bit integers: ");
	printNewLine();
	doubleSendToUSART2(div64BitsInt());
	stringSendToUSART2("ms");
	printNewLine();
}

// 32 bits measurement
double add32BitsInt () {
	timer2Init();
	int16_t start, stop, result = 0;
	int a, b, c, tempResult;
	
	for (int i=1;i<=100;i++) {
		a = rand();
		b = rand();
		start = timer2Start();
		c = a + b;
		stop  = timer2Stop();
		c++;
		tempResult = start - stop;
		result = result + tempResult;
	}
	
	result = result / 100;
	
	timer2Shutdown();
	return result * 0.0001388;
}

double mul32BitsInt () {
	timer2Init();
	int16_t start, stop, result = 0;
	int a, b, c, tempResult;
	
	for (int i=1;i<=100;i++) {
		a = rand();
		b = rand();
		start = timer2Start();
		c = a * b;
		stop  = timer2Stop();
		c++;
		tempResult = start - stop;
		result = result + tempResult;
	}
	
	result = result / 100;
	
	timer2Shutdown();
	return (int)(result) * 0.0001388;
}

double div32BitsInt () {
	timer2Init();
	int16_t start, stop, result = 0;
	int a, b, c, tempResult;
	
	for (int i=1;i<=100;i++) {
		a = rand();
		b = rand();
		start = timer2Start();
		c = a / b;
		stop  = timer2Stop();
		c++;
		tempResult = start - stop;
		result = result + tempResult;
	}
	
	result = result / 100;
	
	timer2Shutdown();
	return (int)(result) * 0.0001388;
}

double copy8ByteStruct () {
	timer2Init();
	int16_t start, stop, result = 0, tempResult;
	struct byte8Test a,b;
	
	for (int i=1;i<=100;i++) {
		a.test[0] = 1;
		a.test[1] = 2;
		
		start = timer2Start();
		b = a;
		stop  = timer2Stop();
		tempResult = start - stop;
		result = result + tempResult;
		b.test[0]++;
	}
	
	result = result / 100;
	
	timer2Shutdown();
	return (int)(result) * 0.0001388;
}

double copy128ByteStruct () {
	timer2Init();
	int16_t start, stop, result = 0, tempResult;
	struct byte128Test a,b;
	
	for (int i=1;i<=100;i++) {
		for (int i = 0; i<32;i++) {
			a.test[i] = i;
		}
		
		start = timer2Start();
		b = a;
		stop  = timer2Stop();
		tempResult = start - stop;
		result = result + tempResult;
		b.test[0]++;
	}
	
	result = result / 100;
	
	timer2Shutdown();
	return (int)(result) * 0.0001388;
}

double add64BitsInt() {
	timer2Init();
	int16_t start, stop, result;
	long long a, b, c, tempResult;
	
	for (int i=1;i<=100;i++) {
		a = ((long long)rand()<<32) + (long long)rand();
		b = ((long long)rand()<<32) + (long long)rand();
		start = timer2Start();
		c = a + b;
		stop  = timer2Stop();
		c++;
		tempResult = start - stop;
		result = result + tempResult;
	}
	
	result = result/100;
	
	timer2Shutdown();
	return (int)(result) * 0.0001388;
}

double mul64BitsInt() {
	timer2Init();
	int16_t start, stop, result;
	long long a, b, c, tempResult;
	
	for (int i=1;i<=100;i++) {
		a = ((long long)rand()<<32) + (long long)rand();
		b = ((long long)rand()<<32) + (long long)rand();
		start = timer2Start();
		c = a * b;
		stop  = timer2Stop();
		c++;
		tempResult = start - stop;
		result = result + tempResult;
	}
	
	result = result/100;
	
	timer2Shutdown();
	return (int)(result) * 0.0001388;
}

double div64BitsInt() {
	timer2Init();
	int16_t start, stop, result;
	long long a, b, c, tempResult;
	
	for (int i=1;i<=100;i++) {
		a = ((long long)rand()<<32) + (long long)rand();
		b = ((long long)rand()<<32) + (long long)rand();
		start = timer2Start();
		c = a + b;
		stop  = timer2Stop();
		c++;
		tempResult = start - stop;
		result = result + tempResult;
	}
	
	result = result/100;

	timer2Shutdown();
	return (int)(result) * 0.0001388;
}

