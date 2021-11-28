/*
    * File Name: lab1exe_E.c
        *  Assignment: Lab 1 Exercise E
        *  Lab section: B04
        *  Completed by: Sadia Khandaker
        *  Submission Date: September 23, 2021
        */

#include <stdio.h>
#include <math.h>

int main() {

    double a,b,c,determinant,root1,root2,rp,ip;
    printf("Enter a nonzero value for coefficient a: ");
    scanf("%lf",&a);
    printf("Enter a nonzero value for coefficient b: ");
    scanf("%lf",&b);
    printf("Enter a nonzero value for coefficient c: ");
    scanf("%lf",&c);

    determinant = pow(b,2)-(4*a*c);

     if (determinant>0) {
         root1 = (-b + sqrt(determinant))/(2*a);
         root2 = (-b - sqrt(determinant))/(2*a);
         printf("The roots are: root 1 = %lf and root 2 = %lf",root1,root2);
     }
     else if (determinant==0) {
         root1 = root2=-b/(2*a);
         printf("The root is root 1 = root 2 = %lf",root1);
     }
     else {
         rp = -b/(2*a);
         ip = sqrt(fabs(determinant))/(2*a);
         printf("The roots are: root 1 = %lf+i(%lf) and root 2 = %lf-i(%lf)",rp,ip,rp,ip);
     }
     
    return 0;
}