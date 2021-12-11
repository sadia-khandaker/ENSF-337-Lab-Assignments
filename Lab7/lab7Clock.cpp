/* ENSF 337 - Lab 7 Exercise C
 * File name: lab7Clock.cpp
 * Completed by: Sadia Khandaker
 * Submission Date: Nov 18, 2021
 */

#include <iostream>
#include <iomanip>
#include "lab7Clock.h"
using std::cout;
using std::endl;
using std::setw;
using std::setfill;

Clock::Clock() {
    hour = 0;
    minute = 0;
    second = 0;
}

Clock::Clock(int sec) {
    hour = 0;
    minute = 0;
    second = 0;
    sec_to_hms(sec);
}

Clock::Clock(int hr, int min, int sec) {
    hour = 0;
    minute = 0;
    second = 0;
    while(hr>=0 && hr<=23 && min>=0 && min <=59&& sec>=0 && sec<=59) {
        set_hour(hr);
        set_minute(min);
        set_second(sec);
        break;
    }
}

void Clock::set_hour(int hr) {
    while(hr>=0 && hr<=23) {
        hour = hr;
        break;
    }
}

void Clock::set_minute(int min) {
    while(min>=0 && min<=59) {
        minute = min;
        break;
    }
}

void Clock::set_second(int sec) {
    while(sec>=0 && sec<=59) {
        second = sec;
        break;
    }
}

int Clock::get_hour() const {
    return hour;
}

int Clock::get_minute() const {
    return minute;
}

int Clock::get_second() const {
    return second;
}

void Clock::increment() {
    second++;
    if (second==60) {
        second = 0;
        minute++;
        if (minute==60) {
            minute = 0;
            hour++;
            if (hour==24) {
                hour = 0;
            }
        }
    }
}

void Clock::decrement() {
    if(second==0) {
        second=59;
        if(minute==0)
            minute = 59;
        else
            minute--;
        if(hour==0)
            hour = 23;
    }
    else
    {
        second--;
    }
}


void Clock::add_seconds(int sec) {
    for(int i=1;i<=sec;i++) {
        increment();
    }
}

int Clock::hms_to_sec() {
    return(second+minute*60+hour*60*60);
}

void Clock::sec_to_hms(int n) {
    int hr=0;
    int min=0;
    int sec=0;
    if(n>0){
        hr=n/(3600);
        n=n-hr*(3600);

        if(n>=60){
            min=n/60;
            n=sec%60;
        }else
            sec=n;
        if(hr==24)
            set_hour(0);
        else
            set_hour(hr);
        set_minute(min);
        set_second(sec);
    }
}


void print(const Clock & t);
// REQUIRES: t refers to an object of class Clock with valid values.
// PROMISES: displays the time values in an object of class Clock:
//           in the following hh:mm:ss.

void print(const Clock & t) {
    cout << setw(2) << setfill('0') << t.get_hour() << ":" << setw(2) << t.get_minute() << ":" << setw(2) << t.get_second() << endl;

}

int main(void) {
    Clock t1;
    cout << "Object t1 is created. Expected time is: 00:00:00\n";
    print(t1);

    for (int i = 0; i < 86400; i++)
        t1.increment();

    cout << "Object t1 incremented by 86400 seconds. Expected time is: 00:00:00\n";
    print(t1);

    Clock t2(86405);
    cout << "Object t2 is created. Expected time is: 00:00:05\n";
    print(t2);

    for (int i = 0; i < 6; i++)
        t2.decrement();

    cout << "Object t2 decremented by 6 seconds. Expected time is: 23:59:59\n";
    print(t2);

    t1.set_hour(21);
    cout << "After setting t1's hour to 21. Expected time is: 21:00:00\n";
    print(t1);

    t1.set_hour(60);
    cout << "Setting t1's hour to 60 (invalid value). Expected time is: 21:00:00\n";
    print(t1);

    t2.set_minute(20);
    cout << "Setting t2's minute to 20. Expected time is: 23:20:59\n";
    print(t2);

    t2.set_second(50);
    cout << "Setting t2's second to 50. Expected time is 23:20:50\n";
    print(t2);

    t2.add_seconds(2350);
    cout << "Adding 2350 seconds to t2. Expected time is: 00:00:00\n";
    print(t2);

    t2.add_seconds(72000);
    cout << "Adding 72000 seconds to t2. Expected time is: 20:00:00\n";
    print(t2);

    t2.add_seconds(216000);
    cout << "Adding 216000 seconds to t2. Expected time is: 08:00:00\n";
    print(t2);

    Clock t3(0, 0, 0);
    cout << "Object t3 is created. Expected time is: 00:00:00\n";
    print(t3);

    t3.increment();
    cout << "Adding 1 second to clock t3. Expected time is: 00:00:01\n";
    print(t3);

    t3.decrement();
    cout << "After calling decrement for t3. Expected time is: 00:00:00\n";
    print(t3);

    for (int i = 0; i < 86400; i++)
        t3.increment();

    cout << "After incrementing t3 by 86400 seconds. Expected time is: 00:00:00\n";
    print(t3);

    for (int i = 0; i < 86401; i++)
        t3.decrement();

    cout << "After decrementing t3 by 86401 seconds. Expected time is: 23:59:59\n";
    print(t3);

    for (int i = 0; i < 864010; i++)
        t3.decrement();

    cout << "After decrementing t3 by 864010 seconds. Expected time is: 23:59:49\n";
    print(t3);

    // Object t4 is created with invalid value of hour (i.e. 25), and valid values
    // for other members, minute and second respectively.
    Clock t4(25, 0, 0);
    cout << "t4 is created with invalid value (25 for hour). Expected to show: 00:00:00\n";
    print(t4);

    // Object t5 is created with invalid value of minute (i.e. -8), and valid values
    // for other member, hour and second.
    Clock t5(23, -8, 59);
    cout << "t5 is created with invalid value (-8 for minute). Expected to show: 00:00:00\n";
    print(t5);

    // Object t6 is created with invalid value of second (i.e. 61), and valid values
    // for other members.
    Clock t6(23, 59, 61);
    cout << "t6 is created with invalid value (61 for second). Expected to show: 00:00:00\n";
    print(t6);

    Clock t7(-10);
    cout << "t7 is created with invalid value (negative value). Expected to show: 00:00:00\n";
    print(t7);

    return 0;
}