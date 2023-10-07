/* Static */
#include <iostream>
using namespace std;

int i = 1; // i is a global variable

int main(void) {
    static int a; // a is a static variable
    int b = -10; // b is a local variable
    int c = 0; // c is a local variable

    void func(void);
    cout << "---MAIN---\n";
    cout << "i = " << i << " a = " << a << " b = " << b << " c = " << c 
        << endl; // i = 1, a = 0, b = -10, c = 0

    c = c + 8;
    func(); // i = 33, a = 4, b = 0, c = 15
    cout << "---MAIN---\n";
    cout << " i: " << i << " a: " << a << " b: " << b << " c: " << c
        << endl; // 33 0 -10 8
    i = i + 10;
    func(); // i = 75, a = 6, b = 4, c = 15
    func(); // i = 107, a = 8, b = 6, c = 15

    return 0;
}

void func(void) {
    static int a = 2;
    static int b = 0; 
    //a, b are static variables. 
    //They are initialized in first time.
    int c = 10; 
    // c is a local variable
    // It is initialized to 10 by default every times.

    cout << "---FUNC---\n";
    a = a + 2;
    i = i + 32;
    c = c + 5;
    cout << "i = " << i << " a = " << a << " b = " << b << " c = " << c 
        << endl;
    b = a;
}