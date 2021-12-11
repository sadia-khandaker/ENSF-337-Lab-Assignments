/* File Name: hydro.h
 * Assignment: Lab 8 Exercise C
 * Lab Section: B04
 * Completed By: Sadia Khandaker
 * Submission Date: November 25, 2021
 */


#ifndef HYDRO_H
#define HYDRO_H
#include "list.h"

int main();
void displayHeader();
int readData(FlowList &x);
int menu();
void display(int n, FlowList &x);
int addData(FlowList &x, int &n);
int removeData(FlowList &x, int & n);
double average(int n, FlowList &x);
void saveData(FlowList &x, int n);
void pressEnter();

#endif
