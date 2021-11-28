/*
* File Name: lab2exe_E.c
* Assignment: Lab 2 Exercise E
* Lab section: B04
* Completed by: Sadia Khandaker
* Submission Date: Sept 28, 2021
*/

#include <stdio.h>
#include <stdlib.h>

void time_convert(int ms_time, int *minutes_ptr, double *seconds_ptr);


int main(void)
{
    int millisec;
    int minutes;
    double seconds;
    int nscan;

    printf("Enter a time interval as an integer number of milliseconds: ");
    nscan = scanf("%d", &millisec);

    if (nscan != 1) {
        printf("Unable to convert your input to an int.\n");
        exit(1);
    }

    printf("Doing conversion for input of %d ms ... \n", millisec);

    time_convert(millisec, &minutes, & seconds);

    printf("That is equivalent to %d minute(s) and %f second(s).\n", minutes,
           seconds);

    return 0;
}

void time_convert(int ms_time, int *minutes_ptr, double *seconds_ptr) {
    double s,ds;
    int m;

    s = ms_time / 1000.0;
    m = s / 60;
    ds = s - (m*60);

    *minutes_ptr = m;
    *seconds_ptr = ds;

}