/* Virtual Function: Polymorphism & Unknown */
#include <iostream>
using namespace std;

class Animal {
    public:
        virtual void sound() {
            cout << "Animal sound" << endl;
        }
};

class Dog: public Animal {
    public:
        void sound() {  // Overriding
            cout << "Dog sound" << endl;
        }
};

class Cat: public Animal {
    public:
        void sound() {  // Overriding
            cout << "Cat sound" << endl;
        }
};

class Unknown: public Animal {
};

int main() {
    Animal *a;
    Dog d;
    Cat c;
    Unknown u;
    //a.sound(); // Error: pointer to incomplete class type is not allowed
    a = &d;  // Base pointer pointing to derived class
    a->sound();
    a = &c;  // Base pointer pointing to derived class
    a->sound();
    a = &u;  // Base pointer pointing to derived class
    a->sound(); // No overriding, so derived class will use base class function

    cout << "------------------" << endl;

    Dog d1;
    d1.sound();
    Cat c1;
    c1.sound();
    Unknown u1;
    u1.sound();

    return 0;
}