/* inline */
#include <iostream>
using namespace std;

class Point
{
public:
    // Define "accessor" functions as
    //  reference types.
    unsigned& x();
    unsigned& y();
private:
    unsigned _x;
    unsigned _y;
};

inline unsigned& Point::x() {return _x;}
inline unsigned& Point::y() {return _y;}

int main() {
    Point p;
    p.x() = 5;
    p.y() = 6;
    cout << "p.x() = " << p.x() << endl;
    cout << "p.y() = " << p.y() << endl;
    
    return 0;
}