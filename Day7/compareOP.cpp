/* operator comparison overloading */
#include <iostream>
using namespace std;

class Cents{
    public:
        Cents(int cents) : m_cents(cents) {}

        friend bool operator== (const Cents& c1, const Cents& c2) { return c1.m_cents == c2.m_cents; };
        friend bool operator!= (const Cents& c1, const Cents& c2) { return !(operator==(c1, c2));};

        friend bool operator< (const Cents& c1, const Cents& c2) { return c1.m_cents < c2.m_cents; };
        friend bool operator> (const Cents& c1, const Cents& c2) { return operator<(c2, c1);};
        friend bool operator<= (const Cents& c1, const Cents& c2) { return !(operator>(c1, c2));};
        friend bool operator>= (const Cents& c1, const Cents& c2) { return !(operator<(c1, c2));};
    
    private:
        int m_cents;
};

int main() {
    
    cout << "Enter two cents values: " << endl;
    int cents1, cents2;
    cin >> cents1 >> cents2;

    Cents dime(cents1), nickel(cents2);

    if (nickel > dime)
        cout << "a nickel is greater than a dime.\n";
    
    if (nickel < dime)
        cout << "a nickel is not greater than a dime.\n";

    if (nickel >= dime)
        cout << "a nickel is greater than or equal to a dime.\n";
    
    if (nickel <= dime)
        cout << "a nickel is not greater than or equal to a dime.\n";

    if (nickel == dime)
        cout << "a nickel is equal to a dime.\n";
    
    if (nickel != dime)
        cout << "a nickel is not equal to a dime.\n";

    return 0;
}