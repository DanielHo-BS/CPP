/* Assignment Operator = */
#include <iostream>
using namespace std;

class X {
    public:
    X &operator=(const X &rhs) {
        cout << "Assignment operator called" << endl;
        return *this;
    };
};

int main() {
    X obj1, obj2, obj3;
    obj2 = obj1;
    obj1.operator=(obj2);
    obj1 = obj2 = obj3;

    return 0;
}