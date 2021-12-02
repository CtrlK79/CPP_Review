#include <iostream>

using std::cout;
using std::endl;

class Person
{
public:
    void Sleep() const {cout<<"Sleep"<<endl;}
};

class Student : public Person
{
public:
    void Study() const {cout<<"Study"<<endl;}
};

class PartTimeStudent : public Student
{
public:
    void Work() const {cout<<"Work"<<endl;}
};

int main(void)
{
    Person* ptr1 = new Student();
    Person* ptr2 = new PartTimeStudent();
    Student* ptr3 = new Student();
    
    ptr1->Sleep();
    ptr2->Sleep();
    ptr3->Study();

    return 0;
}