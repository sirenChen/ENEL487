//
//  ENEL 487 assignment 1
//  Siren Chen
//  200315360
//
//  ComplexNumber.cpp
//
//  Copyright (c) 2015 Siren Chen. All rights reserved.
//

#include "ComplexNumber.h"
using namespace std;

//Creat a complex number struct
complex creatComplexNumber(double real, double imag) {
    complex tempComplex;
    
    tempComplex.real = real;
    tempComplex.imag = imag;
    
    return tempComplex;
}

//add two complex number
void add(complex a, complex b) {
    complex result;
    
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    
    printComplexNumber(result);
}

//subtraction two complex number
//complex a - complex b
void sub(complex a, complex b) {
    complex result;
    
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    
    printComplexNumber(result);
}

//multiple two complex number
void mul(complex a, complex b) {
    complex result;
    
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.imag * b.real + a.real * b.imag;
    
    printComplexNumber(result);
}

//devide complex a by complex b
void div(complex a, complex b) {
    complex result;
    
    result.real = (a.real * b.real + a.imag * b.imag)
                / (b.real * b.real + b.imag * b.imag);
    result.imag = (a.imag * b.real - a.real * b.imag)
                / (b.real * b.real + b.imag * b.imag);
    
    printComplexNumber(result);
}

/**
 Print the complex number
 If the value of the real part or image part is between 0.1 to 100,
 print the value directly。
 If the value of the real part or image part is not betwwen 0.1 to 100,
 print the value by using exponential notation*/
void printComplexNumber(complex complexNumber) {
    if (useExponentialnotation(complexNumber.real)) {
        cout.setf(ios::scientific);
        cout.precision(3);
        cout << complexNumber.real;
    } else {
        cout.unsetf(ios::scientific);
        cout << complexNumber.real;
    }
    
    if (complexNumber.imag < 0) {
        cout << " - ";
    } else {
        cout << " + ";
    }
    
    if (useExponentialnotation(complexNumber.imag)) {
        cout.setf(ios::scientific);
        cout.precision(3);
        cout << "j" << fabs(complexNumber.imag);
    } else {
        cout.unsetf(ios::scientific);
        cout << "j" << fabs(complexNumber.imag);
    }
    
    cout << endl;
}

//Determine whether use exponential notation or not
bool useExponentialnotation(double number) {
    number = fabs(number);
    if (number >= 100 || number <0.1) {
        return true;
    } else {
        return false;
    }
}