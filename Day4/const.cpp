/* Constant Member Function */
#include <iostream>
using namespace std;

class Date {
    public:
        int Mon_Day_Year[3];
        Date (int mn, int dy, int yr); // Constructor
        int getMonth () const; // A read-only function
        void setMonth (int mn); // A write function; can't be const
    private:
        int month, day, year;
};

int Date::getMonth () const { // The const here means that this function
    // promises not to change the state of the object.
    return month; // Therefore, the compiler will enforce this promise
    // by not allowing the function to change any of the object's data.
}

void Date::setMonth (int mn) { // The const here would be an error
    month = mn; // if uncommented, since setMonth() changes the state
    // of the object.
}

Date::Date (int mn, int dy, int yr)  {
            month = mn;
            day = dy;
            year = yr;
            Mon_Day_Year[0] = mn;
            Mon_Day_Year[1] = dy;
            Mon_Day_Year[2] = yr;
        };

void printDate (const Date &D) { // Const reference parameter >> call by reference
    cout << "Date: ";
    for(int i=0; i<3; i++) {
        cout << D.Mon_Day_Year[i] << " ";
    }
    cout << endl;
}


int main () {
    Date Today(10, 11, 2023);
    const Date BirthDate(11, 4, 1999);
    Today.setMonth(12);  // OK
    // BirthDate.setMonth(12); // Error
    cout << Today.getMonth() << endl; // OK
    cout << BirthDate.getMonth() << endl; // OK

    printDate(Today);
    printDate(BirthDate);
}