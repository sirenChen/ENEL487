//
// ENEL 487 Assignment 2
// Siren Chen
//
// ComplexNumber.c
//

#include "ComplexNumber.h"

// Creat a complex number
struct complexNumber creatComplexNumber(double real, double imag) {
    struct complexNumber temp;
    temp.real = real;
    temp.imag = imag;
    return temp;
}

// Add two complex number
void addComplex(struct complexNumber a, struct complexNumber b) {
    struct complexNumber result;
    
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    
    printComplex(result);
}

// Subtraction two complex number
void subComplex(struct complexNumber a, struct complexNumber b) {
    struct complexNumber result;
    
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    
    printComplex(result);
}

// Multiple two complex number
void mulComplex(struct complexNumber a, struct complexNumber b) {
    struct complexNumber result;
    
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.imag * b.real + a.real * b.imag;
    
    printComplex(result);
}

// Devide complex a by complex b
void divComplex(struct complexNumber a, struct complexNumber b) {
    struct complexNumber result;
    
    result.real = (a.real * b.real + a.imag * b.imag)
                  / (b.real * b.real + b.imag * b.imag);
    result.imag = (a.imag * b.real - a.real * b.imag)
                  / (b.real * b.real + b.imag * b.imag);
    
    printComplex(result);
}

// Print the magnitude of the given complex number
void absComplex(struct complexNumber a) {
    double result;
    
    result = a.real * a.real + a.imag * a.imag;
    result = sqrt(result);
    
    printf("%lg\n",result);
}

// Print the angle part of the given complex number , in radians
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

// Print the argument of the given complex number, in degrees
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

// For the given complex number, calculate the exponential
// of that number, exp(z)
void expComplex(struct complexNumber a) {
    struct complexNumber result;
    
    result.real = exp(a.real)*cos(a.imag);
    result.imag = exp(a.real)*sin(a.imag);
    
    printComplex(result);
}

// print the reciprocal of the given complex number: 1/z
void invComplex(struct complexNumber a) {
    struct complexNumber result;
    
    result.real = a.real/(a.real*a.real+a.imag*a.imag);
    result.imag = (-a.imag)/(a.real*a.real+a.imag*a.imag);
    
    printComplex(result);
}

// Print the complex number
void printComplex(struct complexNumber result) {
    char sign = '+';
    if (result.imag < 0) {
        sign = '-';
    }
    printf("%lg %c j %lg\n",result.real, sign, fabs(result.imag));
}
