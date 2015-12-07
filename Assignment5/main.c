//
//  main.c
//  LookUpTable
//
//  Created by Siren Chen on 15/12/6.
//  Copyright © 2015年 Siren Chen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "math.h"

#define PI 3.14159265354

/**
 * creat a look up table
 */
void creatTable(int table[])
{
    double angle;
    for (int i = 0; i < 720; i++)
    {
        angle = (i * 0.5) * (PI/180) ;
        table[i] = sin(angle) * 100000;
    }
}

/**
 * calculate the sin value using look up table
 */
int sinTable(double angle, int table[])
{
    return table[(int)(angle * 2)];
}

int main(int argc, const char * argv[])
{
    int test[720];
    int rs1, rs2; double angle;
    float timeTable, timeSin, temp1, temp2;
    
    creatTable(test);
    printf("Please enter the angle to calculate the sin: \n");
    scanf("%lf", &angle);
    
    //calculate the sin value using the look up table function 1000 times
    //measure the time
    if (angle >=0 && angle <= 359.5)
    {
        temp1 = (float)(clock())/CLOCKS_PER_SEC;
        for (int i=0; i<1000; i++) {
            rs1 = sinTable(angle, test);
        }
        rs1 = sinTable(angle, test);
        temp2 = (float)(clock())/CLOCKS_PER_SEC;
        timeTable = temp2 - temp1;
    }
    else if (angle < 0 && angle >= -359.5)
    {
        temp1 = (float)(clock())/CLOCKS_PER_SEC;
        for (int i=0; i<1000; i++) {
            rs1 = -sinTable(angle, test);
        }
        rs1 = -sinTable(fabs(angle), test);
        temp2 = (float)(clock())/CLOCKS_PER_SEC;
        timeTable = temp2 - temp1;
    }
    else
    {
        printf("WRONG\n");
        return 0;
    }
    
    //calculate the sin value using the build-in sin(x) function 1000 times
    //measure the time 
    temp1 = (float)(clock())/CLOCKS_PER_SEC;
    for (int i=0; i<1000; i++)
    {
        rs2 = sin(angle * (PI/180));
    }
    rs2 = sin(angle * (PI/180)) * 100000;
    temp2 = (float)(clock())/CLOCKS_PER_SEC;
    timeSin = temp2 - temp1;
    
    printf("rs1: %d, rs2: %d \n" ,rs1 ,rs2);
    printf("timeTable: %lf, timeSin: %lf\n ", timeTable, timeSin);
    
    return 0;
}
