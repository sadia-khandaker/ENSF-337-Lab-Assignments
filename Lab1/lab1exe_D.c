/*
* File Name: lab1exe_D.c
        *  Assignment: Lab 1 Exercise D
        *  Lab section: B04
        *  Completed by: Sadia Khandaker
        *  Submission Date: September 23, 2021
        */

#include <stdio.h>
#include <math.h>

int main()
{
    double angle;
    double sinoutput;
    double taylorseries;

    printf("Enter the angle (in radians): ");
    scanf("%lf", &angle);

    sinoutput = sin(angle);
    printf("Sine of theta -> %f is %f radians \n", angle, sinoutput);

    taylorseries = angle - (pow(angle, 3))/(6) + (pow(angle,5))/(120) - (pow(angle,7))/(5040);
    printf("Taylor Series approximation of sin(%f) up to the seventh order is %f \n", angle, taylorseries);
    return 0;
}

