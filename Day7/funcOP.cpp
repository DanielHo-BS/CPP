/* Function call operation */
#include <iostream>
#include <vector>
#include <algorithm> // Added to include for_each function

using namespace std;

struct Linear // Function call operator
{
    double a, b;

    double operator()(double x) { // Linear function:  a * x + b
        return a * x + b;
    }
};


struct Sum
{
    double sum = 0;
    void operator()(double x) { // Summation: sum += x
        sum += x;
    }
};


int main() {
    Linear f{2,1}; // f(x) = 2x + 1
    Linear g{-3,0}; // g(x) = -3x

    double f_0 = f(0); // f(0) = 1
    double f_1 = f(1); // f(1) = 3
    cout << "f(0) = " << f_0 << endl;
    cout << "f(1) = " << f_1 << endl;

    double g_3 = g(3); // g(3) = -9
    cout << "g(3) = " << g_3 << endl;

    vector<double> v = {f_0, f_1, g_3};
    Sum s = for_each(v.begin(), v.end(), Sum());
    cout << "The Sum is " << s.sum << endl;

    return 0;
}