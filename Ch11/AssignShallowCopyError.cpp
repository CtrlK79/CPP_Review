#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::strlen;
using std::strcpy;

class Person
{
private:
    char* name;
    int age;
public:
    Person(const char* name, int age)
    : age(age)
    {
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
    }
    void ShowPersonInfo() const {cout<<"이름: "<<name<<endl; cout<<"나이: "<<age<<endl;}
    ~Person() {delete []name; cout<<"called destructor!"<<endl;}
};

int main(void)
{
    Person man1("Lee dong woo", 29);
    Person man2("Yoon ji yul", 22);
    man2 = man1;
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();

    return 0;
}