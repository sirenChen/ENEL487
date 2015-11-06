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

int firstCommandToInt(char firstCommand[]);
void commandProcess(char firstCommand[], char secondCommand[], char thirdCommand[]);
int case1SecondCommandToInt(char secondCommand[]);
int case4SecondCommandToInt(char secondCommand[]);
int case5SecondCommandToInt(char secondCommand[]);



int main () {
  systemClockInit(9);
	openUSART2(36,9600);
	openLed();
	
	while(1){ 
		char myChar = ' ';
		char command[100] = "";
		char firstCommand[50] = "";
		char secondCommand[50] = "";
		char thirdCommand[50] = "";
		
		printNewLine();
		charSendToUSART2('$');
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
		
		
		//split the command to 3 parts
		sscanf(command,"%s %s %s", firstCommand, secondCommand, thirdCommand);
		
		commandProcess(firstCommand,secondCommand,thirdCommand);

  }
}


// Determine which command should be processed
// @pre 
// @post
void commandProcess(char firstCommand[], char secondCommand[], char thirdCommand[]) {
	int firstCommandNumber = -2;
	int case1SecondNumber = -2;
	int case4SecondNumber = -2;
	int case5SecondNumber = -2;
	firstCommandNumber = firstCommandToInt(firstCommand);
	
	//**switch the first command**//
	switch(firstCommandNumber) {
		//CASE_1 -- LED COMMAND
		case 1:
			stringSendToUSART2("LED ");
		  case1SecondNumber = case1SecondCommandToInt(secondCommand);
		//*LED -- switch the second command*/
		  switch(case1SecondNumber) {
				//LED :: CASE_1 -- LED ON
				case 1:
					stringSendToUSART2("ON ");
				  if(atoi(thirdCommand) == -1) {
						ledOnA();
						stringSendToUSART2("ALL");
					} else if(atoi(thirdCommand)) {
						ledOn(atoi(thirdCommand));
						stringSendToUSART2(thirdCommand);
					}
					printNewLine();
				  break;
				
				//LED :: CASE_2 -- LED OFF
				case 2:
					stringSendToUSART2("OFF ");
				  if(atoi(thirdCommand) == -1) {
						ledOffA();
						stringSendToUSART2("ALL");
					}else if(atoi(thirdCommand)) {
						ledOff(atoi(thirdCommand));
						stringSendToUSART2(thirdCommand);
					}
					printNewLine();
				  break;
					
				//LED :: CASE_3 -- LED CHECK
				case 3:
					if(atoi(thirdCommand)) {
						if(ledCheck(atoi(thirdCommand)) == 1) {
							stringSendToUSART2("This LED is ON ");
						} else {
						  stringSendToUSART2("This LED is OFF ");
						}
					}
					printNewLine();
					break;
				
				
				//LED :: DEFAULT -- WRONG
				default:
					stringSendToUSART2("LED COMMAND WRONG");
				  printNewLine();
				  break;
			}
			break;
		
		//CASE2 -- HELP
		case 2:
			stringSendToUSART2("ASK SIREN FOR HELPING!!!");
		  printNewLine();
		  break;
		
		case 3:
			stringSendToUSART2(__DATE__ );
		  stringSendToUSART2(" ");
		  stringSendToUSART2(__TIME__);
		  printNewLine();
		  break;
		
		//CASE4 -- TIMER
		case 4:
			case4SecondNumber = case4SecondCommandToInt(secondCommand);
		switch (case4SecondNumber) {
			case 1:
				timeTest();
			  break;
			
			case 2:
				timer2InterruptOpen();
				break;
			
			case 3:
				timer2Shutdown();
			  break;
			
			default:
				stringSendToUSART2("TIMER COMMAND WRONG");
		    printNewLine();
				break;
		}
		break;
		
		//CASE5 -- MOTOR
		case 5:
			case5SecondNumber = case5SecondCommandToInt(secondCommand);
			switch (case5SecondNumber) {
				case 1:
					timer4Init();
				  stringSendToUSART2("Motor is on now");
				  printNewLine();
				  break;
				
				case 2:
					setDutyCycleTim4Ch2(
						setMotor((atoi(thirdCommand)) * 0.01));
					stringSendToUSART2("Motor turn ");
					intSendToUSART2(atoi(thirdCommand));
					printNewLine();
					break;
			}
			break;
		
		//DEFAULT CASE
		default:
			stringSendToUSART2("COMMAND WRONG; PLEASE SEE HELP");
		  printNewLine();
		  break;
	}
}

// map the first command to an integer number
// @pre
// @post
int firstCommandToInt(char firstCommand[]) {
	int firstCommandNumber;
	if (!strcmp(firstCommand,"led")) {
		firstCommandNumber = 1;
	} else if (!strcmp(firstCommand,"help")) {
		firstCommandNumber = 2;
	} else if (!strcmp(firstCommand,"time")) {
		firstCommandNumber = 3;
	} else if (!strcmp(firstCommand,"timer")) {
		firstCommandNumber = 4;
	} else if (!strcmp(firstCommand,"motor")) {
		firstCommandNumber = 5;
	}
	else {
		firstCommandNumber = 0;
	}
	return firstCommandNumber;
}

// map the LED command to an integer number
int case1SecondCommandToInt(char secondCommand[]) {
	int secondCommandNumber;
	if (!strcmp(secondCommand,"on")) {
		secondCommandNumber = 1;
	} else if (!strcmp(secondCommand,"off")) {
		secondCommandNumber = 2;
	} else if (!strcmp(secondCommand,"check")) {
		secondCommandNumber = 3;
	} else {
		secondCommandNumber = 0;
	}
	return secondCommandNumber;
}

int case4SecondCommandToInt(char secondCommand[]) {
	int secondCommandNumber;
	if (!strcmp(secondCommand,"measure")) {
		secondCommandNumber = 1;
	} else if (!strcmp(secondCommand,"interrupt")) {
		secondCommandNumber = 2;
	} else if (!strcmp(secondCommand,"shutdown")) {
		secondCommandNumber = 3;
	}
	else {
		secondCommandNumber = 0;
	}
	return secondCommandNumber;
}

int case5SecondCommandToInt(char secondCommand[]) {
	int secondCommandNumber;
	if (!strcmp(secondCommand,"on")) {
		secondCommandNumber = 1;
	} else if (!strcmp(secondCommand,"turn")) {
		secondCommandNumber = 2;
	} 
	else {
		secondCommandNumber = 0;
	}
	return secondCommandNumber;
}
