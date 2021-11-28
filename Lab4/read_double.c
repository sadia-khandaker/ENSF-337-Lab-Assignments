/*
 * File Name: read_double.c
 * Assignment: Lab 4 Exercise E
 * Lab Section: B04
 * Completed By: Sadia Khandaker
 * Submission Date: Oct 19, 2021
*/

#include "read_input.h"

int read_real(char *digits, int n, double *num)
{
    if(get_string(digits, n)== EOF)
        return EOF;

    if(is_valid_double(digits)){
        if(digits[0] == '-')
            *num = -convert_to_double(digits + 1);
        else if(digits[0] == '+')
            *num = convert_to_double(digits + 1);
        else
            *num = convert_to_double(digits);
        return 1;
    }
    return 0;
}


int is_valid_double(const char* digits) {
    int i, valid = 1, dec = 0;
    if(digits[0] == '+' || digits[0] == '-')
        i = 1;
    else
        i = 0;
    if (digits[i] == '\0')
        valid = 0;
    else
        while ((digits[i] != '\0') && valid) {
            if((digits[i] < '0' ||  digits[i] > '9') && (digits[i] != '.' || dec > 1))
                valid = 0;
            i++;
            if(digits[i] == '.')
                dec++;
        }
    return valid;
}

double convert_to_double(const char* digits) {
    int i = 0;
    double sum = 0, sum2 = 0;
    while(*digits != '\0') {
        if(digits[i] == '.'){
            while(digits[i] != '\0'){
                digits++;
            }
            digits--;
            while(digits[i] != '.'){
                sum2 = 0.1*sum2 + (digits[i] - '0');
                i--;
            }
            sum2 *= 0.1;
            break;
        }
        sum = 10 * sum + (digits[i] - '0');
        i++;
    }
    sum += sum2;
    return sum;
}