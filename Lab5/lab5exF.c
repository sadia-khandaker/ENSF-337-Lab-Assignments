/* File Name: lab5exF.c
 * Assignment: Lab 5 Exercise F
 * Lab Section: B04
 * Completed by: Sadia Khandaker
 */

#include "lab5exF.h"
#include <stdio.h>
#include <math.h>
#include<string.h>

int main(void)
{
    Point struct_array[10];
    int i;
    int position;
    
    populate_struct_array(struct_array, 10);
    
    printf("\nArray of Points contains: \n");
    
    for(i=0; i < 10; i++)
        display_struct_point(struct_array[i], i);
    
    
    printf("\nTest the search function");
    
    position = search(struct_array, "v0", 10);
    if(position != -1)
        printf("\nFound: struct_array[%d] contains %s", position,
               struct_array[position].label);
    else
        printf("\nstruct_array doesn't have label: %s.", "v0");
    
    position = search(struct_array, "E1", 10);
    if(position != -1)
        printf("\nFound: struct_array[%d] contains %s", position,
               struct_array[position].label);
    else
        printf("\nstruct_array doesn't have label: %s.", "E1");
    
    position = search(struct_array, "C5", 10);
    
    if(position != -1)
        printf("\nFound: struct_array[%d] contains %s", position,
               struct_array[position].label);
    else
        printf("\nstruct_array doesn't have label: %s.", "C5");
    
    position = search(struct_array, "B7", 10);
    if(position != -1)
        printf("\nFound: struct_array[%d] contains %s", position,
               struct_array[position].label);
    else
        printf("\nstruct_array doesn't have label: %s.", "B7");
    position = search(struct_array, "A9", 10);
    if(position != -1)
        printf("\nFound: struct_array[%d] contains %s", position,
               struct_array[position].label);
    else
        printf("\nstruct_array doesn't have label: %s.", "A9");
    position = search(struct_array, "E11", 10);
    if(position != -1)
        printf("\nFound: struct_array[%d] contains %s", position,
               struct_array[position].label);
    else
        printf("\nstruct_array doesn't have label: %s.", "E11");
    
    position = search(struct_array, "M1", 10);
    if(position != -1)
        printf("\nFound: struct_array[%d] contains %s", position,
               struct_array[position].label);
    else
        printf("\nstruct_array doesn't have label: %s.", "M1");
    
    printf("\n\nTesting the reverse function:");
    
    reverse(struct_array, 10);
    
    printf("\nThe reversed array is:");
    
    for(i=0; i < 10; i++)
        display_struct_point(struct_array[i], i);
    
    return 0;
}

void display_struct_point(const Point x , int i)
{
    printf("\nstruct_array[%d]: %s <%.2lf, %.2lf, %.2lf>\n",
           i, x.label, x.x, x.y, x.z);
}

void populate_struct_array(Point* array, int n)
{
    int i;
    char ch1 = 'A';
    char ch2 = '9';
    char ch3 = 'z';
    
    for( i = 0; i < 10; i++)
    {
        /* generating some random values to fill them elements of the array: */
        array[i].x = (7 * (i + 1) % 11) * 100 - i /2;
        array[i].y = (7 * (i + 1) % 11) * 120 - i / 3;
        array[i].z = (7 * (i + 1) % 11) * 150 - i /4;
        
        if(i % 2 == 0)
            array[i].label[0] = ch1++;
        else
            array[i].label[0] = ch3--;
        array[i].label[1] = ch2--;
        array[i].label[2] = '\0';
    }
}

int search(const Point* struct_array, const char* label, int n)
{
    for(int i = 0; i < n; i++) {
        int j = 0, temp = 0;
        while(label[j]!='\0' && struct_array[i].label[j]!='\0') {
            if(label[j]!=struct_array[i].label[j]) {
                temp=1;
                break;
            }
            j++;
        }
        if(temp==0 && label[j]=='\0' && struct_array[i].label[j]=='\0') {
            return i;
        }
    }
    return -1;
}

void reverse (Point *a, int n)
{
    int i=0,j=n-1;
    while (i<j){
        Point temp = a[i];
        a[i]=a[j];
        a[j]=temp;
        i++;
        j--;

    }
}

