#include "System.h"
#include "Clock.h"
#include "SerialDriver.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "LedDriver.h"
#include "TimerDriver.h"
#include "TimingTest.h"
#include "PwmOperation.h"
#include "A2D.h"

int main () {
	systemClockInit(9);
	openUSART2(36,9600);
	A2D_INIT();
	
	uint16_t temp;
	float voltage;
	while(1)
	{
		char str[1024] = "";
		temp = readADC1(10);
		voltage = temp * 0.000806;
		sprintf(str,"%f",voltage);
		stringSendToUSART2(str);
	  printNewLine();
		for(int i=0;i<=1000000;i++);
	}
} 

