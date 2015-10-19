#include "Clock.h"

void systemClock24Mhz() {
	RCC_CFGR = 0x00050002;
	RCC_CR = 0x01010081;
}

void systemClockInit(uint8_t PLL) {
	unsigned char temp=0;   
	
 	RCC_CR|=0x00010000;  //HSEON
	while(!(RCC_CR>>17));//wait HES 
	RCC_CFGR=0X00000400; //APB1=DIV2;APB2=DIV1;AHB=DIV1;
	PLL-=2;
	RCC_CFGR|=PLL<<18;   //PLL Number
	RCC_CFGR|=1<<16;	  //PLLSRC ON 

	RCC_CR|=0x01000000;  //PLLON
	while(!(RCC_CR>>25));//wait PLL locked
	RCC_CFGR|=0x00000002;//PLL as system CLK
	while(temp!=0x02)     //wait PLL set as system CLK
	{   
		temp=RCC_CFGR>>2;
		temp&=0x03;
	}    
}	
