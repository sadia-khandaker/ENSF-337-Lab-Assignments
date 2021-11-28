/*
* File Name: lab2exe_A.c
* Assignment: Lab 2 Exercise A
* Lab section: B04
* Completed by: Sadia Khandaker
* Submission Date: Sept 28, 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double g = 9.8;
const double pi = 3.141592654;

void create_table(double v);
double projectile_travel_time(double a, double v);
double projectile_travel_distance(double a, double v);
double degree_to_radian(double d);

void create_table(double v) {
    int degree;
    double radian, time, distance;
    printf("Angle(deg)\tTime(sec)\tDistance(m)\n");

    for (degree=0; degree<=90; degree +=5) {
        radian = degree_to_radian(degree);
        time = projectile_travel_time(radian,v);
        distance = projectile_travel_distance(radian,v);
        printf("%d \t %lf \t %lf\n", degree , time, distance);
    }

}

double projectile_travel_time(double a, double v) {
    return (2*v* sin(a))/(g);
}

double projectile_travel_distance(double a, double v) {
    return (pow(v,2)* sin(2*a))/(g);
}
double degree_to_radian(double d) {
    return d*(pi/180);
}

int main() {
    int n;
    double velocity;
    printf ("Please enter the velocity at which the projectile is launched (m/s): ");
    n = scanf("%lf" ,&velocity);

    if(n != 1) {
        printf("Invalid input. Bye...");
        exit(1);
    }

    while (velocity < 0 )
    {
        printf ("Please enter a POSITIVE number for velocity: ");
        n = scanf("%lf", &velocity);
        if(n != 1)
        {
            printf("Invalid input. Bye...");
            exit(1);
        }
    }
    create_table(velocity);
    return 0;
}
