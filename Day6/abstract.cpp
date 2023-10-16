/* Pure virtual function: Abstract */
/*
Pure virtual function is a function that has no definition in the base class.
Abstract class is a class that has at least one pure virtual function.
Limitation of abstract class is that we cannot create object of abstract class.
*/

#include <iostream>
using namespace std;

class Animal {
    public:
        virtual void sound() = 0;  // Pure virtual function
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
    //Unknown u;  // Error: Cannot declare variable 'u' to be of abstract type 'Unknown'
    a = &d;  // Base pointer pointing to derived class
    a->sound();
    
    a = &c;  // Base pointer pointing to derived class
    a->sound();
    
    cout << "------------------" << endl;

    Dog d1;
    d1.sound();
    Cat c1;
    c1.sound();
    
    return 0;
}