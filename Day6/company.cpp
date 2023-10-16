/* Company.cpp */
/*
A company has three kind of employees:     
    - Manager: salary = week*1000
    - SaleWorker: salary = 800 + sale*0.05
    - HourWorker: salary = hour*100
All employees have name, ID, and salary.
Write a program to show salary of employees.
*/

#include <iostream>
using namespace std;

class Employee {
    public:
        Employee(string name, int id): Name(name), Id(id){}
        string getName() const { return Name;}
        int getId() const { return Id;}
        virtual float getSalary() = 0;
        virtual void display() {
            cout << "Name: " << Name << "\tID: " << Id << endl;
        }
        
    private:
        string Name;
        int Id;
};

class Manager: public Employee {
    public:
        Manager(string name, int id, int week): Employee(name, id), WeeklySalary(week*1000){}
        float getSalary() {
            return WeeklySalary;
        }
        void display() {
            cout << "Manager: "
                 << "\t\tName: " << getName() 
                 << "\tID: " << getId() 
                 << "\tSalary: " << getSalary() << endl;
        }

    private:
        float WeeklySalary;
};

class SaleWorker: public Employee {
    public:
        SaleWorker(string name, int id, int sale): Employee(name, id), WorkerSalary(800 + sale*0.05){}
        float getSalary() {
            return WorkerSalary;
        }
        void display() {
            cout << "SaleWorker: "
                 << "\t\tName: " << getName() 
                 << "\tID: " << getId() 
                 << "\tSalary: " << getSalary() << endl;
        }
    private:
        float WorkerSalary;
};

class HourWorker: public Employee {
    public:
        HourWorker(string name, int id, int hour): Employee(name, id), HourSalary(hour*100){}
        float getSalary() {
            return HourSalary;
        }
        void display() {
            cout << "HourWorker: "
                 << "\t\tName: " << getName() 
                 << "\tID: " << getId() 
                 << "\tSalary: " << getSalary() << endl;
        }
    private:
        int HourSalary;
};


int main() {
    Employee *e[3];
    e[0] = new Manager("John", 1, 2);
    e[1] = new SaleWorker("Mary", 2, 100);
    e[2] = new HourWorker("Peter", 3, 10);
    
    for (int i = 0; i < 3; i++) {
        e[i]->display();
    }
    
    return 0;
}   