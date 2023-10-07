/* Enumerations for week day */
#include <iostream>
using namespace std;

enum Weekday {SUN, MON, TUE, WED, THU, FRI, SAT};

void print(Weekday day);

int main() {
    cout << "Weekday: " << endl;
    enum Weekday wek = SUN;
    for (int i = 0; i < 7; i++) {
        print(wek);
        cout << "  ";
        wek = (Weekday) ((wek + 1) % 7);
    }
    
    cout << "\n----------------" << endl;
    cout << "Enter today's day (0-6): ";
    int day;
    cin >> day;
    Weekday today = Weekday(day);
    Weekday tomorrow = (Weekday) ((today + 1) % 7);
    cout << "Today is ";
    print(today);
    cout << "\nTomorrow is ";
    print(tomorrow);
    cout << endl;
    return 0;
}

void print(Weekday day) {
    switch (day){
        case SUN: cout << "Sunday"; break;
        case MON: cout << "Monday"; break;
        case TUE: cout << "Tuesday"; break;
        case WED: cout << "Wednesday"; break;
        case THU: cout << "Thursday"; break;
        case FRI: cout << "Friday"; break;
        case SAT: cout << "Saturday"; break;
    }
}