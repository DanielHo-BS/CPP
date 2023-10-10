/* Static data */
/*
Using 'static' will make the variable shared by all instances of the class.
must be initialized outside the class.
*/

#include <iostream>
using namespace std;

class Point {
    public:
        Point(int x, int y) {
            X = x;
            Y = y;
            countP++;
        }
        Point(Point &p);
        int getX() { return X; }
        int getY() { return Y; }
        void GetC() { cout << " Object id=" << countP << endl; }
        
    private:
        int X, Y;
        static int countP;
};

Point::Point(Point &p) {  // copy constructor
  X = p.X;
  Y = p.Y;
  countP++;
}

int Point::countP = 0;  // initialize static data

int main() {
    Point A(1, 3);
    cout << "A: " << A.getX() << ", " << A.getY();
    A.GetC();
    Point B(2,4);
    cout << "B: " << B.getX() << ", " << B.getY();
    B.GetC();
    Point C(B);
    cout << "C: " << C.getX() << ", " << C.getY();
    C.GetC();
    
    return 0;
}