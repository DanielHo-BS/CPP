/* Overload Stream Operation */
#include <iostream>
using namespace std;

class Date {
    public:
        Date(int d, int m, int y) : day(d), month(m), year(y) {}
        friend ostream &operator<<(ostream &os, const Date &dt);
    private:
        int day, month, year;
};

ostream &operator<<(ostream &os, const Date &dt) {
    os << dt.day << "/" << dt.month << "/" << dt.year << "\n";
    return os;
}

int main() {
    Date dt(18, 10, 2023);
    cout << dt;
    return 0;
}