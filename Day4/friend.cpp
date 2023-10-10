/* friend class */
#include <iostream>
using namespace std;

class YourClass {
    friend class YourOtherClass; // yourOtherClass can access private members of yourClass
    public:
        YourClass() : topSecret(0) {} // constructor
        void printMember() { cout << topSecret << endl; }
    private:
        int topSecret;
};

class YourOtherClass {
    public:
        void change(YourClass& yc, int x) { yc.topSecret = x; } // can access private members of YourClass
};


int main() {
    YourClass yc1;
    YourOtherClass yoc1;
    yc1.printMember();
    yoc1.change(yc1, 99);
    yc1.printMember();
}