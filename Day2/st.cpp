/* Stract */
#include <iostream>
using namespace std;

struct student {
    string name;
    int age;
    double gpa;
};

int main() {
    student s1 = {"John", 20, 3.5};
    student s2 = {"Mary", 19, 3.8};

    cout << "Name\tAge\tGPA\n";
    cout << s1.name << "\t" << s1.age << "\t" << s1.gpa << endl;
    cout << s2.name << "\t" << s2.age << "\t" << s2.gpa << endl;
    
    return 0;
}