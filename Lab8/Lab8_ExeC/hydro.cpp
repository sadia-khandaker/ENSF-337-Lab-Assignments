/* File Name: hydro.cpp
 * Assignment: Lab 8 Exercise C
 * Lab Section: B04
 * Completed By: Sadia Khandaker
 * Submission Date: November 25, 2021
 */
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "hydro.h"
using namespace std;
int main() {
    FlowList x;
    int numRecords
    int quit =0;
    displayHeader();
    numRecords = readData(x);
    while(true) {
       switch(menu()) {
           case 1:
               display(numRecords, x);
               pressEnter();
               break;
           case 2:
               addData(x, numRecords);
               pressEnter();
               break;
           case 3:
               saveData(x, numRecords);
               pressEnter();
               break;
           case 4:
               removeData(x, numRecords);
               pressEnter();
               break;
           case 5:
               cout << "\nProgram terminated!\n\n";
               quit = 1;
               break;
           default:
               cout << "\nNot a valid input.\n";
               pressEnter();
       }
       if(quit == 1) break;
    }
}

void displayHeader()
{
    cout<<"Program: Flow Studies - Fall 2021\n";
    cout<<"Version: 1.0\n";
    cout<<"Lab section: B04\n";
    cout<<"Produced by: Sadia Khandaker\n";
}

int readData(FlowList &x) {
    ifstream inObj;
    inObj.open("flow.txt");
    int year,i = 0;
    double flow;
    if(!inObj) {
        cout<<"Error: cannot open the file: flow.txt.";
        exit(1);
    }
    while(!inObj.eof()) {
        inObj >> year >> flow;
        ListItem temp = {year, flow};
        x.insert(temp);
        i++;
        }
    inObj.close();
    return i;

}

int menu(){
    cout<<"Please select on the following operations.\n";
    cout<<"1. Display flow list and the average\n";
    cout<<"2. Add data\n";
    cout<<"3. Save data into the file\n";
    cout<<"4. Remove data\n";
    cout<<"5. Quit.\n";
    cout<<"Enter your choice (1, 2, 3, 4, or 5):";
    int choice; cin>>choice;
    return choice;
}
void display(int n, FlowList &x) {
    Node* crsr = x.headM;
    cout << "Year    Flow(in billions of cubic meters)\n" ;
    for (int i = 0; i < n; i++) {
        cout << crsr -> item.year <<"             " << crsr -> item.flow << endl;
        crsr = crsr ->next;
        }
    cout << "The annual average of the flow is: " << average(n,x) <<  " billion cubic meters \n" ;
}

int addData(FlowList &x, int &n) {
    ListItem temp{};
    cout << "Please enter a year: "; cin >> temp.year;
    cout << "Please enter the flow: "; cin >> temp.flow;
    if ( x.insert(temp))
    {
        cout << "New record inserted successfully.";
        n++;
    }
    else
    {
        cout << "Error: duplicate data." ;
    }
    return 0;
}

int removeData(FlowList &x, int & n){
    int year;
    cout << "Please enter the year that you want to remove: " ; cin >> year;
    ListItem temp = {year};
    if (x.remove(temp)) {
        cout << "Record was successfully removed.";
        return n--;
    }
    else {
        cout << "Error: No such a data.";
        return n;
    }
}

double average(int n, FlowList &x) {
    Node* head = x.headM;
    double sum = 0;
    int i = 0;
    while(head!=nullptr){
        sum += head->item.flow;
        i++;
        head = head->next;
    }
    return sum/n;
}

void saveData(FlowList &x, int n) {
    ofstream outObj;
    outObj.open("flow.txt");
    Node* head = x.headM;
    if(! outObj) {
        cout<<"\nError: cannot open the file."<<"flow.txt"<<endl;
        exit(1);
    }
    for(int i = 0; i < n; i++) {
        string text =  to_string(head->item.year) + " " + to_string(head->item.flow);
        outObj<<text<<"\n";
        head = head -> next;
    }

    outObj.close();
    cout << "Data are saved into the file.";
    }

void pressEnter(){
    cout<<"\n<<< Press Enter to Continue >>>\n";
    cin.get();
}