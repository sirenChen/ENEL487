//
// ENEL 487 Assignment 2
// Siren Chen
//
// main.c
//


#include <stdio.h>
#include <stdlib.h>
#include "ComplexNumber.h"
#include "string.h"

// Read a line from user input
// @pre Total char size of input must small than 100
void readLine(char userInput[100]) {
    fgets(userInput, 100, stdin);
}

// Convert the Upper case to lower case
void toLowerCase (char (*str)[100]){
    for (int i = 0; (*str)[i] != '\0'; i++) {
        if ((*str)[i] >= 'A' && (*str)[i] <= 'Z') {
            (*str)[i] = (*str)[i] + 32;
        }
    }
}

// Determine the if the input is complete or not
// @pre Total char size of input must small than 100
int inputComplete(char userInput[100]) {
    char aOperator[100] = "", aReal[100] = "", aImag[100] = "",
         bReal[100] = "", bImag[100] = "";
    sscanf(userInput, "%s %s %s %s %s", aOperator, aReal, aImag,
           bReal, bImag);
    
    toLowerCase(&aOperator);
    
    if ((!strcmp(aOperator, "a") || !strcmp(aOperator, "s") || !strcmp(aOperator, "m") ||
        !strcmp(aOperator, "d")) && strlen(bImag) == 0) {
        return 1;
    }
    
    if ((!strcmp(aOperator, "abs") || !strcmp(aOperator, "arg") ||!strcmp(aOperator, "argdeg") ||
         !strcmp(aOperator, "exp") || !strcmp(aOperator, "inv")) && strlen(aImag) == 0) {
        return 1;
    }
    
    return 0;
}

// Map the operate command to int number
int mapOperatorToInt (char aOperator[100]) {
    if (!(*aOperator)) {
        return -1;
    } else if (!strcmp(aOperator, "q")) {
        return 0;
    } else if (!strcmp(aOperator, "a")) {
        return 1;
    } else if (!strcmp(aOperator, "s")) {
        return 2;
    } else if (!strcmp(aOperator, "m")) {
        return 3;
    } else if (!strcmp(aOperator, "d")) {
        return 4;
    } else if (!strcmp(aOperator, "abs")) {
        return 5;
    } else if (!strcmp(aOperator, "arg")) {
        return 6;
    } else if (!strcmp(aOperator, "argdeg")) {
        return 7;
    } else if (!strcmp(aOperator, "exp")) {
        return 8;
    } else if (!strcmp(aOperator, "inv")) {
        return 9;
    }
    else {
        return 99;
    }
}


int main(int argc, const char * argv[]) {
    printf("Enter exp: \n");
    
    while (1) {
        char userInput[100] = "", aOperator[100]="";
        double aReal=0,aImag=0,bReal=0,bImag=0;
        int operatorNumber;
        
        readLine(userInput);
        sscanf(userInput, "%s %lg %lg %lg %lg",
               aOperator, &aReal,&aImag,&bReal,&bImag);
        toLowerCase(&aOperator);
        
        if (inputComplete(userInput)) {
            operatorNumber = 98;
        } else {
            operatorNumber = mapOperatorToInt(aOperator);
        }
        
        struct complexNumber a = creatComplexNumber(aReal, aImag);
        struct complexNumber b = creatComplexNumber(bReal, bImag);
        
        switch (operatorNumber) {
            case -1:
                printf("\n");
                break;
                
            case 0:
                printf("QUIT\n");
                return 0;
                break;
                
            case 1:
                addComplex(a,b);
                break;
            
            case 2:
                subComplex(a,b);
                break;
            
            case 3:
                mulComplex(a,b);
                break;
            
            case 4:
                divComplex(a,b);
                break;
            
            case 5:
                absComplex(a);
                break;
            
            case 6:
                argComplex(a);
                break;
            
            case 7:
                argDegComplex(a);
                break;
            
            case 8:
                expComplex(a);
                break;
            
            case 9:
                invComplex(a);
                break;
            
            case 98:
                fprintf(stderr, "COMMAND NOT COMPLETE\n");
                break;
            
            case 99:
                fprintf(stderr, "COMMADN ERROR\n");
                break;
                
            default:
                break;
        }
        
    }
    
    return 0;
}


