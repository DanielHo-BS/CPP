/* Binary arithmetic operation: calculate Complex */

#include <iostream>
using namespace std;

class Complex {
    public:
        Complex(double real=0, double imag=0) : _real(real), _imag(imag) {}
        Complex operator+(Complex b);
        Complex operator-(Complex b);
        Complex operator*(Complex b);
        Complex operator/(Complex b);
        void display();
    private:
        double _real, _imag;
};


Complex Complex::operator+(Complex b) {return Complex(_real + b._real, _imag + b._imag);}
Complex Complex::operator-(Complex b) {return Complex(_real - b._real, _imag - b._imag);}
Complex Complex::operator*(Complex b) {
    Complex t;
    t._real = _real * b._real - _imag * b._imag;
    t._imag = _real * b._imag - _imag * b._real;

    return t;
    }

Complex Complex::operator/(Complex b) {
  Complex t;
  double x;
  x = 1 / (b._real * b._real + b._imag * b._imag);
  t._real = x * (_real * b._real + _imag * b._imag);
  t._imag = x * (_imag * b._real - _real * b._imag);
  return t;
}

void Complex::display() {
  cout << _real;
  if (_imag > 0)
    cout << "+";
  if (_imag != 0)
    cout << _imag << "i" << endl;
  //}display();
};

int main() {
    Complex a(3, 4), b(1, -1), c;
    a = b + 2;
    // a = 2 + b; // Error: no match for 'operator+' (operand types are 'int' and 'Complex')
    cout << "a = ";
    a.display();
    c = a + b;
    cout << "a + b = ";
    c.display();
    c = a - b;
    cout << "a - b = ";
    c.display();
    c = a * b;
    cout << "a * b = ";
    c.display();
    c = a / b;
    cout << "a / b = ";
    c.display();

    return 0;
}