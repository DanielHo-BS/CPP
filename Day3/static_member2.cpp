/* Static Menber */
#include <iostream>
using namespace std;

class Application {
    public:
        static void f(Application app);
    private:
        int x;
};
void Application::f(Application app) {
    // cout << x; // Error: 'x' is a private member of 'Application'
    cout << app.x << endl;
}

int main () {
    Application test;
    test.f(Application());
    test.f(test);
    
    return 0;
}