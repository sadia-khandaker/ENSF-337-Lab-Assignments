/*
* File Name: Lab1Exe_B.c
        *  Assignment: Lab 1 Exercise B
        *  Lab section: B04
        *  Completed by: Sadia Khandaker
        *  Submission Date: September 23, 2021
        */

#include <stdio.h>
int main()
{
    double num1 = -34.5;
    double num2 = 98.7;

    double sum;     // sum of num1 and num2
    double sumSquared;      // the square of num2 plus num2

    // calculating sum
    sum = num1 + num2;
    // squaring sum
    sumSquared = sum * sum;
    printf( "The sum squared is: %f \n", sumSquared);
    // doubling sumsquared
    sumSquared = sumSquared * 2;
    printf( "The sum squared is now: %f \n",  sumSquared);
    return 0;
}
