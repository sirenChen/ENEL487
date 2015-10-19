#include "SerialDriver.h"

//===========Send and Read Data through USART1===============//
//Read a char from USART1
char readCharFromUSART1 () {
	while(!(USART1_SR & USART_SR_RXNE));
	return USART1_DR & 0xff;
}

//Print string to USART1
void stringSendToUSART1 (char str[]) {
	int i;
	char a;
	
	for (i=0;str[i]!='\0';i++) {
		a= str[i];
		while (!(USART1_SR & USART_SR_TXE));
		USART1_DR = (uint8_t)((int)(a));
	}
}

//Print char to USART1
void charSendToUSART1 (char myChar) {
	while (!USART1_SR & USART_SR_TXE);
	USART1_DR = (char)myChar;
}

//===========Send and read Data through USART2==============//
//Read a char from USART2
char readCharFromUSART2 () {
	while(!(USART2_SR & USART_SR_RXNE));
	return USART2_DR & 0xff;
}

//Print string to USART2
void stringSendToUSART2 (char str[]) {
	int i;
	char a;
	
	for (i=0;str[i]!='\0';i++) {
		a= str[i];
		while (!(USART2_SR & USART_SR_TXE));
		USART2_DR = (uint8_t)((int)(a));
	}
}

//Print char to USART2
void charSendToUSART2 (char myChar) {
	while (!USART2_SR & USART_SR_TXE);
	USART2_DR = (char)myChar;
}

//print a new line
void printNewLine () {
	char temp[2];
	temp[0] = 0x0a;
	temp[1] = 0x0d;
	stringSendToUSART2(temp);
}

//Open USART ============================================================== Open USART//
void openUSART1 (uint16_t frequencyOfUSART, uint16_t bitRates) {
	uint16_t mantissa;
	
	mantissa = determineMantissa(frequencyOfUSART, bitRates);
	
	RCC_APB2ENR |= RCC_APB2ENR_IOPAEN;
	
	GPIOA_CRH &= 0xfffff00f;
	GPIOA_CRH |= 0x000008B0;
	
	//Enable the USART_1 Clock
	RCC_APB2ENR |= RCC_APB2ENR_USART1EN;
	
	USART1_BRR = mantissa;
	
	USART1_CR1 |= 0x0000000C;
	USART1_CR1 |= 0x00002000;
}

void openUSART2 (uint16_t frequencyOfUSART, uint16_t bitRates) {
	uint16_t mantissa;
	
	mantissa = determineMantissa(frequencyOfUSART, bitRates);
	
	//Enable GPIOA
	RCC_APB2ENR |= RCC_APB2ENR_IOPAEN;
	//Enable USART2
	RCC_APB1ENR |= 0x00020000;
	
	GPIOA_CRL &= 0xffff00ff;
	GPIOA_CRL |= 0x00000B00;
	GPIOA_CRL |= 0x00004000;
	
	USART2_BRR |= mantissa;
	
	USART2_CR1 &= ~0x00001000;
	USART2_CR1 |= 0x0000000C;
	USART2_CR1 |= 0x00002000;
}

uint16_t determineMantissa(uint16_t frequencyOfUSART, uint16_t bitRates) {
	float temp;
	uint16_t mantissa;
	uint16_t fraction;
	
	//Calculate the Bits per second
	temp=(float)(frequencyOfUSART*1000000)/(bitRates*16);//Determine the USARTDIV
	mantissa=temp;				 
	fraction=(temp-mantissa)*16; 
  mantissa<<=4;
	mantissa+=fraction;
	
	return mantissa;
}
