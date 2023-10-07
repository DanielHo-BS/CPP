/* x^n */
#include <iostream>
using namespace std;

double power(double x, int n);

int main() {
    double x;
    int n;
    cout << "Enter x and n: ";
    cin >> x >> n;
    cout << "x^n = " << power(x, n) << endl;
    
    return 0;
}

double power(double x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;
    if (n % 2 == 0) return power(x * x, n / 2);
    else return power(x * x, n / 2) * x;
}