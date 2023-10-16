/* Virtual Function: Base & Derived*/
#include <iostream>
using namespace std;

class Base {
    public:
        virtual void show() {
            cout << "Base class" << endl;
        }
};

class Derived: public Base {
    public:
        void show() {  // Overriding
            cout << "Derived class" << endl;
        }
};

int main() {
    Base *bptr;
    Derived d;
    bptr = &d;  // Base pointer pointing to derived class
    bptr->show();

    cout << "------------------" << endl;

    Base b1;
    b1.show();
    Derived d1;
    d1.show();
    Base *d2 = new Derived();  // Base pointer pointing to derived class
    d2->show();

    return 0;
}