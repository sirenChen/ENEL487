#include "System.h"
#include <stdlib.h>
#include <stdio.h>

#define ADC1_2_IRQChannel            ((u8)0x12)  /* ADC1 et ADC2 global Interrupt */

void A2D_INIT(void);

uint16_t readADC1(uint8_t ch) ;
