/*      File Name: lab3exe_D.c
        *  Assignment: Lab 3 Exercise D
        *  Lab section: B04
        *  Completed by: Sadia Khandaker
        *  Submission Date: October 14, 2021
        */
#include <stdio.h>
#include <stdlib.h>
void pascal_triangle(int n);

int main() {
    int nrow;
    printf("Enter the number of rows (Max 20): ");
    scanf("%d", &nrow);
    if(nrow <= 0 || nrow > 20) {
        printf("Error: the maximum number of rows can be 20.\n");
        exit(1);
    }
    pascal_triangle(nrow);
    return 0;
}

void pascal_triangle(int n) {
    int i, j, c = 1;
    for (i = 0; i < n; i++) {
        printf("Row %d: ",i);
        for (j = 0; j <= i; j++) {
            if (i == 0 || j == 0) {
                c = 1;
            } else {
                c = c * (i - j + 1) / (j);
            }
            printf("%4d", c);
        }
        printf("\n");
    }
}






