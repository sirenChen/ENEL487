//
// ENEL 487 Assignment 2
// Siren Chen
//
// ComplexNumber.h
//

#ifndef ComplexNumber_h
#define ComplexNumber_h

#define PI 3.141592653

#include <stdio.h>
#include <math.h>

struct complexNumber {
    double real;
    double imag;
};

struct complexNumber creatComplexNumber(double real, double imag);

void addComplex(struct complexNumber a, struct complexNumber b);
void subComplex(struct complexNumber a, struct complexNumber b);
void mulComplex(struct complexNumber a, struct complexNumber b);
void divComplex(struct complexNumber a, struct complexNumber b);

void absComplex(struct complexNumber a);
void argComplex(struct complexNumber a);
void argDegComplex(struct complexNumber a);
void expComplex(struct complexNumber a);
void invComplex(struct complexNumber a);

void printComplex(struct complexNumber);


#endif /* ComplexNumber_h */
