/* Virtual */
/*
The virtual keyword is used to avoid ambiguity in multiple inheritance.
*/
#include <iostream>
using namespace std;

class A {
    public:
     int x = 5;
};
class B : virtual public A{
    public:
      int i = 6;
};
class C : virtual public A{
    public:
      int i = 7;
};
class D : public B, public C{
    
};

int main(){
    D obj;
    // using virtual keyword
    cout << "obj.x = " << obj.x << endl;
    // using scope resolution operator
    cout << "obj.B::x = " << obj.B::x << endl;
    cout << "obj.C::x = " << obj.C::x << endl;
    

}