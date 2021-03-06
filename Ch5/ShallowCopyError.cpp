#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::strlen;
using std::strcpy;

class Person
{
private:
    char *name;
    int age;
public:
    Person(const char *myname, const int myage) : age(myage)
    {
        name = new char[strlen(myname)+1];
        strcpy(name, myname);
    }
    void ShowPersonInfo() const
    {
        cout<<"이름: "<<endl;
        cout<<"나이: "<<endl;
    }
    ~Person()
    {
        delete []name;
        cout<<"called destructor!"<<endl;
    }
};

int main(void)
{
    Person man1("Lee dong woo", 29);
    Person man2 = man1;
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();

    return 0;
}