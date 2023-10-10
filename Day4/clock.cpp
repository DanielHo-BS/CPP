/*
Create a class Clock with data members hour, minute and second. 
Write a menu driven program to perform the following operations:
  1. Set the time
  2. Display the time
  3. Operate for one second by ++, 
     and automatically increment minute and hour as necessary.
*/

#include <iostream>
using namespace std;

class Time {
    public:
        Time(int h, int m, int s) : hour(h), minute(m), second(s) {}
        void showTime() { 
            cout << "The time is:";
            cout << hour << ":" << minute << ":" << second << endl; 
        }
        Time operator++();     // Prefix increment operator.
        Time operator++(int);  // Prefix increment operator.
    private:
        int hour, minute, second;
};

Time Time::operator++() { 
    ++second;
    if (second >= 60) {
        second = 0;
        ++minute;
        if (minute >= 60) {
            minute = 0;
            ++hour;
            if (hour >= 24) {
                hour = 0;
            }
        }
    }
    return *this;
}

Time Time::operator++(int n) {
    Time tmp = *this;
    ++(*this);
    return tmp;
}

int main() {
    Time t(5,59,58);
    t.showTime();
    ++t;
    t.showTime();
    (t++).showTime();
    t.showTime();

    return 0;
}