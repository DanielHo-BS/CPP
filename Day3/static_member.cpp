/* Static Member1 */
/*
1. Static members belong to the class rather than individual objects.
2. Non-const static members need to be initialized outside the class definition.
3. They can be accessed using the name of an object instance or the class name followed by the :: operator. 
   Typically, the class name followed by :: is used to access them, which can help avoid confusion with non-static data members.
4. Static members also adhere to public, protected, and private access restrictions.
*/

#include <iostream>
using namespace std;

class Application {
    public:
        // static int non_const_variable = 0;  // compile-error
        static int non_const_variable;
        // compile error: C++ forbids in-class initialization of non-const static member

        static const int const_variable = 9;  // compile OK
        // Const static member can be initialized in class definition

        static void f();
        static void g();
    
    private:
        static int private_variable;
};

// Application::non_const_variable = 3;  // compile-error
int Application::non_const_variable = 3;  // compile OK
/*
the variable is not defined in the class definition, 
so it needs to be defined outside the class definition
*/

int Application:: private_variable = 5;
void Application::f() { private_variable = 10; }
void Application::g() { cout << private_variable << endl; }

int main() {
    Application app1;
    Application app2;

    cout << "---public---" << endl;
    cout << "non_const_variable: " << endl;
    cout << app1.non_const_variable <<" ";  // 3
    cout << app2.non_const_variable<<" ";  // 3
    cout << Application::non_const_variable << endl;  // 3

    app1.non_const_variable = 1;  // change the value of non_const_variable
    cout << "non_const_variable: (After change)" << endl;
    cout << app1.non_const_variable <<" ";  // 1
    cout << app2.non_const_variable <<" ";  // 1
    cout << Application::non_const_variable << endl;  // 1

    cout << "const_variable: " << endl;
    cout << app1.const_variable <<" ";  // 9
    cout << app2.const_variable <<" ";  // 9
    cout << Application::const_variable << endl;  // 9

    cout << "---private---" << endl;
    Application::g();  // 5

    // change the value of private_variable in f()
    Application::f();
    cout << "After change: " << endl;
    Application::g();  // 10
    app1.g();
    app2.g();
    // app1.private_variable = 20; // compile_error: private_variable is private

    return 0;
}