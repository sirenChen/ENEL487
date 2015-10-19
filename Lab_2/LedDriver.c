#include "LedDriver.h"

void openLed () {
	 RCC_APB2ENR |= 0x08; // Enable Port B clock
	 GPIOB_ODR  &= ~0x0000FF00;          /* switch off LEDs                    */
	 GPIOB_CRH  = 0x33333333; //50MHz  General Purpose output push-pull
}

void ledOn (int ledNumber) {
	GPIOB_ODR |= 0x01<<ledNumber;
}

void ledOff (int ledNumber) {
	GPIOB_ODR &= ~(0x01<<ledNumber);
}

void ledOnA() {
	GPIOB_ODR |= 0x0000ff00;
}

void ledOffA() {
	GPIOB_ODR &= ~0x0000ff00;
}

int ledCheck(int ledNumber) {
	return (GPIOB_ODR >> ledNumber) & 0x1 ;
}
