//
//  ENEL 487 assignment 1
//  Siren Chen
//  200315360
//
//  ComplexNumber.cpp
//
//  Copyright (c) 2015 Siren Chen. All rights reserved.
//

#ifndef __CommandLine__ComplexNumber__
#define __CommandLine__ComplexNumber__

#include <stdio.h>
#include <iostream>
#include <math.h>

//Define the complex data type
struct complex {
    double real;
    double imag;
};

complex creatComplexNumber(double real, double imag);

void add(complex a, complex b);
void sub(complex a, complex b);
void mul(complex a, complex b);
void div(complex a, complex b);

void printComplexNumber(complex complexNumber);

bool useExponentialnotation(double number);

#endif /* defined(__CommandLine__ComplexNumber__) */
