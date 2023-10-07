/* Recursive Factorial*/
#include <iostream>
using namespace std;

int rec(int n);

int main() {
    cout << "Enter a number: ";
    int n;
    cin >> n;
    cout << "Sum of digits: " << rec(n) << endl;

    return 0;
}

int rec(int n) {
    if (n == 0) return 1;
    else return n * rec(n - 1);
}