#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::strcpy;
using std::strlen;

class Person
{
private:
    char* name;
public:
    Person(const char* myname)
    {
        name = new char[strlen(myname)+1];
        strcpy(name, myname);
    }
    ~Person() {delete []name;}
    void WhatYourName() const {cout<<"My name is "<<name<<endl;}
};

class UnivStudent : public Person
{
private:
    char* major;
public:
    UnivStudent(const char* myname, const char* mymajor)
    : Person(myname)
    {
        major = new char[strlen(mymajor)+1];
        strcpy(major, mymajor);
    }
    ~UnivStudent() {delete []major;}
    void WhoAreYou() const
    {
        WhatYourName();
        cout<<"My major is "<<major<<endl<<endl;
    }
};

int main(void)
{
    UnivStudent st1("Lee", "Computer eng.");
    st1.WhoAreYou();

    UnivStudent st2("Yoon", "Electronic eng.");
    st2.WhoAreYou();

    return 0;
}