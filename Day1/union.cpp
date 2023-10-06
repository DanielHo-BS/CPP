/* union.cpp */
#include <iostream>
#include <cstring>
using namespace std;

union student{
    int id;
    char name[32];
};

struct student2{
    int id;
    union {
        int age;
        char class_name[32];
    } data; 
};


int main(){
    // show the size of int
    cout << "int size = " << sizeof(int) << endl;

    // show the size of union student with int
    union student s1;
    s1.id = 1;
    cout << "union size = " << sizeof(s1) << endl;

    // show the size of union student with char array
    union student s2;
    s2.id = 2;
    cout << "s2.id = " << s2.id << endl;
    strcpy(s2.name, "Tom");
    cout << "s2.name = " << s2.name << endl;
    cout << "s2.id = " << s2.id << endl;  // overwrite the id by name, because they share the same memory
    
    // show different methods to access the data in union
    struct student2 s3;
    s3.id = 3;
    s3.data.age = 20;
    cout << "s3.id = " << s3.id << endl;
    cout << "s3.data.age = " << s3.data.age << endl;
    strcpy(s3.data.class_name, "CS");
    cout << "s3.data.class_name = " << s3.data.class_name << endl;
    cout << "s3.data.age = " << s3.data.age << endl;  // overwrite the age by class_name, because they share the same memory

    return 0;
}