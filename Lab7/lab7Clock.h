/* ENSF 337 - Lab 7 Exercise C
 * File name: lab7Clock.h
 * Completed by: Sadia Khandaker
 * Submission Date: Nov 18, 2021
 */

#ifndef LAB7EXEC_LAB7CLOCK_H
#define LAB7EXEC_LAB7CLOCK_H

class Clock {
private:
    int hour;
    int minute;
    int second;

    int hms_to_sec();
    void sec_to_hms(int n);

public:
    Clock();
    Clock(int sec);
    Clock(int hr,int min,int sec);

    void set_hour(int hr);
    void set_minute(int min);
    void set_second(int sec);

    int get_hour() const;
    int get_minute() const;
    int get_second() const;

    void increment();
    void decrement();

    void add_seconds(int sec);
};
#endif //LAB7EXEC_LAB7CLOCK_H
