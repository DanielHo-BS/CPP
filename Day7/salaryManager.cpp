/* Subscript operator : Salary Manager */

#include <iostream>
#include <cstring>
using namespace std;

struct Employee {  // Employee information
    char const *name;
    double salary;
};

class SalaryManager {
    public:
        SalaryManager(int maxEmps) {  // Constructor
            maxEmployees = maxEmps;
            employees = new Employee[maxEmployees];
            numEmployees = 0;
        }

        double& operator[] (const char *Name) {  //
            Employee *p;
            for (p = employees; p < employees + numEmployees; p++) {
                if (strcmp(p->name, Name) == 0)  // If the name is found
                    return p->salary;
            }
            p = employees + numEmployees++;  // If the name is not found
            p->name = new char[strlen(Name) + 1]; 
            strcpy(const_cast<char*>(p->name), Name); 
            p->salary = 0;  // Initialize salary to 0
            return p->salary;
        }

        void display() {
            for (int i = 0; i < numEmployees; i++) {
                cout << employees[i].name << ": " << employees[i].salary << endl;
            }
        }

    private:
        Employee *employees;
        int numEmployees; // Number of employees
        int maxEmployees; // Maximum number of employees
};

int main() {
    SalaryManager manager(10);
    // Initialize salaries
    manager["John"] = 1000;  // manager.operator[]("John") = 1000;
    manager["Peter"] = 1200; // manager.operator[]("Peter") = 1200;
    manager["Mary"] = 1400;  // manager.operator[]("Mary") = 1400;
    // Display salaries
    cout << "Salaries:" << endl;
    cout << "John: " << manager["John"] << endl;   // manager.operator[]("John")
    cout << "Peter: " << manager["Peter"] << endl; // manager.operator[]("Peter")
    cout << "Mary: " << manager["Mary"] << endl;   // manager.operator[]("Mary")S
    // Change salaries
    manager["John"] += 200;  // manager.operator[]("John") += 200;
    manager["Peter"] -= 200; // manager.operator[]("Peter") -= 200; 
    manager["Mary"] *= 1.1;  // manager.operator[]("Mary") *= 1.1;
    // Display all salaries
    cout << endl << "Salaries (Display with changed):" << endl;
    manager.display(); // Display all salaries

    return 0;
}