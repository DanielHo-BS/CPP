/* Inheritance Access */

#include <iostream>
using namespace std;

class A {
    public:
        int x;
    protected:
        int y;
    private:
        int z;
};

class B : public A {
    // x is public
    // y is protected
    // z is not accessible from B
};

class C : protected A {
    // x is protected
    // y is protected
    // z is not accessible from C
};

class D : private A {
    // x is private
    // y is private
    // z is not accessible from D
};

int main() {
    A obj;
    obj.x = 10; // Allowed
    // obj.y = 20; // Not allowed
    // obj.z = 30; // Not allowed

    B obj1;
    obj1.x = 10; // Allowed
    // obj1.y = 20; // Not allowed
    // obj1.z = 30; // Not allowed

    C obj2;
    // obj2.x = 10; // Not allowed
    // obj2.y = 20; // Not allowed
    // obj2.z = 30; // Not allowed
    
    return 0;
}