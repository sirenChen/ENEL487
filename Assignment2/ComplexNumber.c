//
//  ComplexNumber.c
//  Assignment2
//
//  Created by Siren Chen on 15/10/17.
//  Copyright © 2015年 Siren Chen. All rights reserved.
//

#include "ComplexNumber.h"

struct complexNumber creatComplexNumber(double real, double imag) {
    struct complexNumber temp;
    temp.real = real;
    temp.imag = imag;
    return temp;
}

void addComplex(struct complexNumber a, struct complexNumber b) {
    struct complexNumber result;
    
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    
    printComplex(result);
}

void subComplex(struct complexNumber a, struct complexNumber b) {
    struct complexNumber result;
    
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    
    printComplex(result);
}

void mulComplex(struct complexNumber a, struct complexNumber b) {
    struct complexNumber result;
    
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.imag * b.real + a.real * b.imag;
    
    printComplex(result);
}

void divComplex(struct complexNumber a, struct complexNumber b) {
    struct complexNumber result;
    
    result.real = (a.real * b.real + a.imag * b.imag)
                  / (b.real * b.real + b.imag * b.imag);
    result.imag = (a.imag * b.real - a.real * b.imag)
                  / (b.real * b.real + b.imag * b.imag);
    
    printComplex(result);
}

void absComplex(struct complexNumber a) {
    double result;
    
    result = a.real * a.real + a.imag * a.imag;
    result = sqrt(result);
    
    printf("%lg\n",result);
}

void argComplex(struct complexNumber a) {
    double result = fabs(atan(a.imag/a.real));
    
    if (a.real >= 0) {
        if (a.imag >= 0) {
            result = result;
        } else
            result = -result;
    } else
        if (a.imag >= 0) {
            result = PI - result;
        } else
            result = result - PI;
    
    printf("%lg\n", result);
}

void argDegComplex(struct complexNumber a) {
    double result = fabs(atan(a.imag/a.real));
    
    if (a.real >= 0) {
        if (a.imag >= 0) {
            result = result;
        } else
            result = -result;
    } else
        if (a.imag >= 0) {
            result = PI - result;
        } else
            result = result - PI;
    
    result = (result/(2*PI)) * 360;
    printf("%lg\n",result);
}

void expComplex(struct complexNumber a) {
    struct complexNumber result;
    
    result.real = exp(a.real)*cos(a.imag);
    result.imag = exp(a.real)*sin(a.imag);
    
    printComplex(result);
}

void invComplex(struct complexNumber a) {
    struct complexNumber result;
    
    result.real = a.real/(a.real*a.real+a.imag*a.imag);
    result.imag = (-a.imag)/(a.real*a.real+a.imag*a.imag);
    
    printComplex(result);
}

void printComplex(struct complexNumber result) {
    char sign = '+';
    if (result.imag < 0) {
        sign = '-';
    }
    printf("%lg %c j %lg\n",result.real, sign, fabs(result.imag));
}
