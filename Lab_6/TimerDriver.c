#include "TimerDriver.h"

void timer2Init() {
	RCC_APB1ENR |= 1;
	
	TIM2_ARR = 0xffff;
	TIM2_PSC = 0;
	
	TIM2_CR1 |= 1<<4;
	
	TIM2_DIER &= ~(0x01<<0);
	TIM2_DIER &= ~(0x01<<6);
	
	TIM2_CR1 |= 0x01;
}

int16_t timer2Start () {
	return TIM2_CNT;
}

int16_t timer2Stop () {
	return TIM2_CNT;
}

void timer2Shutdown () {
  TIM2_DIER &= ~(0x01<<0);
	TIM2_DIER &= ~(0x01<<6);
	
	TIM2_CR1 |= 0;
	
	RCC_APB1ENR &= ~(0x1);
}


void timer2InterruptOpen() {
	RCC_APB1ENR |= 1;
	
	TIM2_ARR = 10000;
	TIM2_PSC = 7199;
	
	TIM2_CR1 |= 1<<4;
	
	TIM2_DIER |= 0x01;
	
	TIM2_CR1 |= 0x01;
	NVIC_ISER0 = 1 << 28;
}

// initial the timer 4 and set channel 2 as the output
void timer4Init() {
	RCC_APB1ENR |= (1<<2);
	RCC_APB2ENR |= 1<<0 | 1<<3;
	
	GPIOB_CRL &= ~(0xf0000000);
	GPIOB_CRL |= 0xB0000000;
	
	TIM4_CCER |= 1<<4;
	
	TIM4_CCMR1 &= ~(0x7000);
	TIM4_CCMR1 |= 0x6000;
	
	TIM4_CCMR1 |= (1<<11);
	TIM4_CCMR1 |= (1<<10);
	
	TIM4_CR1 |= 1<<7;
	
	TIM4_ARR = 19999;
	TIM4_PSC = 72;
	TIM4_CCR2 = 600;
	
	TIM4_EGR |= 0x1;
	TIM4_CR1 |= 0x1;
	
}


void TIM2_IRQHandler() {
	if (TIM2_SR & 0x0001) {
		GPIOB_ODR ^= 0x01<<8;
	}
	
	TIM2_SR &= ~(1<<0);
}

