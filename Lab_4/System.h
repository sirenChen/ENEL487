//#include "stdint.h"
#include "stdlib.h"

#ifndef System_h
#define System_h

typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;
typedef   signed       __int64 int64_t;

/* exact-width unsigned integer types */
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;
typedef unsigned       __int64 uint64_t;

#define GPIOA_BASE ((uint32_t) 0x40010800)
#define GPIOA_CRL (*(uint32_t volatile *) (GPIOA_BASE + 0x00))
#define GPIOA_CRH (*(uint32_t volatile *) (GPIOA_BASE + 0x04))
	
#define GPIOB_BASE ((uint32_t) 0x40010C00)
#define GPIOB_CRL (*(uint32_t volatile *) (GPIOB_BASE + 0x00))
#define GPIOB_CRH (*(uint32_t volatile *) (GPIOB_BASE + 0x04))
#define GPIOB_ODR (*(uint32_t volatile *) (GPIOB_BASE + 0x0C))	
#define GPIOB_BSRR (*(uint32_t volatile *) (GPIOB_BASE + 0x10))
#define GPIOB_BRR (*(uint32_t volatile *) (GPIOB_BASE + 0x14))

#define RCC_BASE ((uint32_t) 0x40021000)
#define RCC_CR (*(uint32_t volatile *) (RCC_BASE + 0x00))
#define RCC_CFGR (*(uint32_t volatile *) (RCC_BASE + 0x04))
#define RCC_APB2ENR (*(uint32_t volatile *) (RCC_BASE + 0x18))
#define RCC_APB1ENR (*(uint32_t volatile *) (RCC_BASE + 0x1C))

#define  RCC_APB2ENR_IOPAEN    ((uint32_t)0x00000004) 
#define  RCC_APB2ENR_USART1EN  ((uint32_t)0x00004000)

#define USART1_BASE ((uint32_t) 0x40013800)
#define USART1_SR (*(uint32_t volatile *) (USART1_BASE + 0x00))
#define USART1_DR (*(uint32_t volatile *) (USART1_BASE + 0x04))
#define USART1_BRR (*(uint32_t volatile *) (USART1_BASE + 0x08))
#define USART1_CR1 (*(uint32_t volatile *) (USART1_BASE + 0x0c))

#define USART2_BASE ((uint32_t) 0x40004400)
#define USART2_SR (*(uint32_t volatile *) (USART2_BASE + 0x00))
#define USART2_DR (*(uint32_t volatile *) (USART2_BASE + 0x04))
#define USART2_BRR (*(uint32_t volatile *) (USART2_BASE + 0x08))
#define USART2_CR1 (*(uint32_t volatile *) (USART2_BASE + 0x0c))

#define USART_SR_TXE 0x00000080
#define USART_SR_RXNE 0x00000020

//#define TIM3_IRQn 29
#define TIM2_BASE ((uint32_t) 0x40000000)
#define TIM2_CR1 (*(uint32_t volatile *) (TIM2_BASE + 0x00))
#define TIM2_CR2 (*(uint32_t volatile *) (TIM2_BASE + 0x04))
#define TIM2_DIER (*(uint32_t volatile *) (TIM2_BASE + 0x0C))
#define TIM2_SR (*(uint32_t volatile *) (TIM2_BASE + 0x10))
#define TIM2_CNT (*(uint16_t volatile *) (TIM2_BASE + 0x24))
#define TIM2_PSC (*(uint16_t volatile *) (TIM2_BASE + 0x28))
#define TIM2_ARR (*(uint16_t volatile *) (TIM2_BASE + 0x2c))

#define NVIC_ISER0 (*(uint32_t volatile *) (0xE000E100))
	
#define TIM4_BASE ((uint32_t) 0x40000800)
#define TIM4_CR1 (*(uint32_t volatile *) (TIM4_BASE + 0x00))
#define TIM4_CR2 (*(uint32_t volatile *) (TIM4_BASE + 0x04))
#define TIM4_DIER (*(uint32_t volatile *) (TIM4_BASE + 0x0C))
#define TIM4_SR (*(uint32_t volatile *) (TIM4_BASE + 0x10))
#define TIM4_EGR (*(uint32_t volatile *) (TIM4_BASE + 0x14))
#define TIM4_CCMR1 (*(uint32_t volatile *) (TIM4_BASE + 0x18))
#define TIM4_CCMR2 (*(uint32_t volatile *) (TIM4_BASE + 0x1C))
#define TIM4_CCER (*(uint32_t volatile *) (TIM4_BASE + 0x20))
#define TIM4_CNT (*(uint32_t volatile *) (TIM4_BASE + 0x24))
#define TIM4_PSC (*(uint32_t volatile *) (TIM4_BASE + 0x28))
#define TIM4_ARR (*(uint32_t volatile *) (TIM4_BASE + 0x2c))
#define TIM4_CCR1 (*(uint32_t volatile *) (TIM4_BASE + 0x34))
#define TIM4_CCR2 (*(uint32_t volatile *) (TIM4_BASE + 0x38))
#define TIM4_CCR3 (*(uint32_t volatile *) (TIM4_BASE + 0x3C))
#define TIM4_CCR4 (*(uint32_t volatile *) (TIM4_BASE + 0x40))

#endif
