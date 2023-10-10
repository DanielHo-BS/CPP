/* Constructor & Destructor */
#include <iostream>
using namespace std;

class myClass {
    public:
        int d[10];
        myClass() {
            cout << "Constructor!" << endl;
        }

        myClass(myClass &obj) {
            cout << "Copy Constructor!" << endl;
        }

        ~myClass() {
            cout << "Destructor!" << endl;
        }
};

void print(const myClass &obj) {
    // call by value: copy constructor >> temporary constructor
    // use const to prevent copy constructor >> call by reference
    for(int i=0; i<10; i++) {
        cout << obj.d[i] << " ";
    }
    cout << endl;
}

int main() {
    myClass obj1; // Create object: Constructor

    print(obj1);

    for(int i=0; i<10; i++) { // Set value
        obj1.d[i] = i;
    }

    print(obj1);

    myClass obj2 = obj1; // Copy object: Copy Constructor

    print(obj2);

    return 0; // Destructor
}