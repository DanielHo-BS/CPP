/* Calculate the price of pool */
/*
It is a circular swimming pool. Now, it is required to build a circular walkway around it and install a fence around its perimeter. The cost of the fence is 35 ￥ per meter, and the cost of the walkway is 20 ￥ per square meter.

The walkway has a width of 3 meters, and the radius of the swimming pool is entered from the keyboard. Please program to calculate and output the cost of the walkway and the cost of the fence.

Diagram Description: A large circle enclosing a small circle:
The small circle is in the middle of the large circle, the small circle represents the swimming pool, and the space between the large and small circles is the walkway.
*/
#include <iostream>
using namespace std;
const double FENCE_PRICE = 35;
const double CONCRETE_PRICE = 20;
const double PI = 3.1415926;

class Circle {
    private:
        double radius;
    public:
        Circle(double r);
        double Circumference();
        double Area();
};

// Initialize the radius of the circle
Circle::Circle(double r) { radius = r; }
// Calculate the circumference of the circle
double Circle::Circumference() { return 2 * PI * radius; }
// Calculate the area of the circle
double Circle::Area() { return PI * radius * radius; }

int main() {
    double radius;
    double fenceCost, concreteCost;

    cout << "Enter the radius of the pool: ";
    cin >> radius;

    // define an object of the class Circle: pool and poolRim
    Circle pool(radius);
    Circle poolRim(radius + 3);

    // Calculate the cost of the fence
    fenceCost = poolRim.Circumference() * FENCE_PRICE;
    cout << "Fencing Cost is ￥" << fenceCost << endl;

    // Calculate the cost of the concrete walkway
    concreteCost = (poolRim.Area() - pool.Area()) * CONCRETE_PRICE;
    cout << "Concrete Cost is ￥" << concreteCost << endl;

    // Calculate the total cost
    cout << "Total Cost is ￥" << fenceCost + concreteCost << endl;

    return 0;
}