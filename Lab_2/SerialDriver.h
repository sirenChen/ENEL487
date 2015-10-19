#include "System.h"

char readCharFromUSART1 (void);
void charSendToUSART1 (char myChar);
void stringSendToUSART1 (char str[]);

char readCharFromUSART2 (void);
void charSendToUSART2 (char myChar);
void stringSendToUSART2 (char str[]);

void printNewLine (void);


void openUSART1 (uint16_t frequencyOfUSART, uint16_t bitRates);
void openUSART2 (uint16_t frequencyOfUSART, uint16_t bitRates);
uint16_t determineMantissa(uint16_t frequencyOfUSART, uint16_t bitRates);
