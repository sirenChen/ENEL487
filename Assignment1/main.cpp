//
//  ENEL 487 assignment 1
//  Siren Chen
//  200315360
//
//  main.cpp
//
//  Copyright (c) 2015 Siren Chen. All rights reserved.
//

#include <iostream>
#include "ComplexNumber.h"
#include <stdlib.h>

using namespace std;

char toLowerCase(char letter);

int main(int argc, const char * argv[]) {
    char arithmeticOperator;
    double firstReal, firstImag, secondReal, secondImag;
    cout << "Type a letter to specify the arithmetic operator (A, S, M, D) ";
    cout << "followed by two complex numbers expressed as pairs of doubles. ";
    cout << "Type Q to quit" << endl;
    cout << endl;
    
    cout << "Enter exp: ";
    
    //get the input from user and determine which operation
    //should perform
    while (arithmeticOperator != 'q') {
        cin >> arithmeticOperator;
        arithmeticOperator = toLowerCase(arithmeticOperator);
        if (arithmeticOperator == 'q') {
            exit(0);
        }

        cin >> firstReal >> firstImag >> secondReal >> secondImag;
        
        complex a = creatComplexNumber(firstReal, firstImag);
        complex b = creatComplexNumber(secondReal, secondImag);
        
        switch (arithmeticOperator) {
            case 'a':
                add(a,b);
                break;
            
            case 's':
                sub(a, b);
                break;
            
            case 'm':
                mul(a, b);
                break;
                
            case 'd':
                div(a, b);
                break;
                
            default:
                cout << "Your operation command is not defined!" << endl;
                exit(0);
                break;
        }
        
    }
    return 0;
}

//Converting the upper case to lower case
char toLowerCase(char letter) {
    if (letter >= 'A' && letter <= 'Z') {
        return letter = letter + 32;
    } else {
        return letter;
    }
}