#include "A2D.h"

uint16_t A2D = 0;

void ADC1_2_IRQHandler(void) {
	A2D = ADC1_DR;
	ADC1_SR &= ~(1 << 1);
}

uint16_t readADC1(uint8_t ch) {
	A2D=0XFFFF;  		 
	ADC1_SQR3&=0XFFFFFFE0;
	ADC1_SQR3|=ch;	

	ADC1_CR2 |= (1<<22);
	ADC1_CR2 |= 1;
	for (int i=0;i<=100;i++) {}
	while(A2D==0XFFFF);	  	 	   
	return A2D;		
}

void A2D_INIT(){
	RCC_APB2ENR|=1<<4;   //GPIOC
	GPIOC_CRL&=0XFFFFFFF0;
			 
	RCC_APB2ENR|=1<<9;    
	RCC_APB2RSTR|=1<<9; 
	RCC_APB2RSTR&=~(1<<9);    
	RCC_CFGR&=~(3<<14);  

	RCC_CFGR|=2<<14;      	 
	ADC1_CR1&=0XF0FFFF;   
	ADC1_CR1|=0<<16;
	ADC1_CR1&=~(1<<8);    	  
	ADC1_CR1|=1<<5;       
	ADC1_CR2&=~(1<<1);    
	ADC1_CR2&=~(7<<17);	   
	ADC1_CR2|=7<<17;	   
	ADC1_CR2|=1<<20;      
	ADC1_CR2&=~(1<<11);   
	ADC1_SQR1&=~(0XF<<20);
	ADC1_SQR1|=0<<20;    		   
	
	ADC1_SMPR1&=~(7<<0); //set 55.5 cycle on    
 	ADC1_SMPR1|=5<<0;      
	
	ADC1_CR2|=1<<0;	    
	ADC1_CR2|=1<<3;         
	
	while(ADC1_CR2&1<<3); 			 
	
	ADC1_CR2|=1<<2;          
	while(ADC1_CR2&1<<2){}; 
	NVIC_ISER0 |= 1<<18;
}

