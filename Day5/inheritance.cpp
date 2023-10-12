// Example: Inheritance

#include <iostream>
using namespace std;

class Person {
    int id;
    char name[100];
    public:
        void set_p();
        void get_p();
};

void Person::set_p() {
    cout << "Enter id: ";
    cin >> id;
    cout << "Enter name: ";
    cin >> name;
}

void Person::get_p() {
    cout << "Id: " << id << endl;
    cout << "Name: " << name << endl;
}

class Student: public Person {
    char course[100];
    int fee;
    public:
        void set_s();
        void get_s();
};

void Student::set_s() {
    set_p();
    cout << "Enter course: ";
    cin >> course;
    cout << "Enter fee: ";
    cin >> fee;
}

void Student::get_s() {
    get_p();
    cout << "Course: " << course << endl;
    cout << "Fee: " << fee << endl;
}

int main() {
    Student s;
    s.set_s();
    s.get_s();
    return 0;
}