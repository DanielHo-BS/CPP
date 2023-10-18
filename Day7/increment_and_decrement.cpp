/* increment and decrement */

#include <iostream>
using namespace std;

class Point {
    public:
        // Declare prefix and postfix increment operators
        Point& operator++(); // Prefix increment
        Point operator++(int); // Postfix increment

        // Declare prefix and postfix decrement operators
        Point& operator--(); // Prefix decrement
        Point operator--(int); // Postfix decrement

        // Declare output operator
        Point() { _x = _y = 0; }

        // Define accessor functions.
        int x() const { return _x; }
        int y() const { return _y; }

    private:
        int _x, _y;
};


// Define prefix increment operator.
Point& Point::operator++() {
    _x++;
    _y++;
    return *this;
}

// Define postfix increment operator.
Point Point::operator++(int) {
    Point temp = *this;
    ++*this;
    return temp;
}

// Define prefix decrement operator.
Point& Point::operator--() {
    _x--;
    _y--;
    return *this;
}

// Define postfix decrement operator.
Point Point::operator--(int) {
    Point temp = *this;
    --*this;
    return temp;
}

int main() {
    Point p1;
    cout << "p1: " << p1.x() << ", " << p1.y() << endl;

    cout << "Prefix increment" << endl;
    Point p2 = ++p1;
    cout << "p1: " << p1.x() << ", " << p1.y() << endl;
    cout << "p2: " << p2.x() << ", " << p2.y() << endl;

    cout << "Postfix increment" << endl;
    Point p3 = p1++;
    cout << "p1: " << p1.x() << ", " << p1.y() << endl;
    cout << "p3: " << p3.x() << ", " << p3.y() << endl;

    cout << "Prefix decrement" << endl;
    Point p4 = --p1;
    cout << "p1: " << p1.x() << ", " << p1.y() << endl;
    cout << "p4: " << p4.x() << ", " << p4.y() << endl;

    cout << "Postfix decrement" << endl;
    Point p5 = p1--;
    cout << "p1: " << p1.x() << ", " << p1.y() << endl;
    cout << "p5: " << p5.x() << ", " << p5.y() << endl;

    return 0;
}