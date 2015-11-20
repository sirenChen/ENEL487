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
#include "math.h"


int main () {
	char myChar;
	int height;
	char move[50] = "";
	char command[50] = "";
	systemClockInit(9);
	timer4Init();
	openUSART2(36,9600);
	A2D_INIT();
	
	uint16_t temp;
	setDutyCycleTim4Ch2(1500);
	for (int i = 0; i<10000000;i++) {}
	
	printNewLine();
		stringSendToUSART2("Input the height from 300 to 2400: ");
	printNewLine();
		//read the command from the input and store to command string
	for (int i=0;i<100;i++) {
		myChar = readCharFromUSART2();	
		if (myChar == 0x0d) {
				printNewLine();
				break;
		} else if (myChar == 0x08) {
				charSendToUSART2(0x08);
				i = i - 2;
		} else {
				charSendToUSART2(myChar);
			  command[i] = (char)myChar;		
		}
	}
	
	
	sscanf(command,"%d",&height);
	intSendToUSART2(height);

	while(1)
	{
		temp = readADC1(10);
		if(temp < height) {
			ballDown();
		}
		if(temp > height) {
			ballUp();
		}
	}
} 

