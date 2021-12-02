#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::strlen;

class First
{
private:
    char* strOne;
public:
    First(const char* str) {strOne = new char[strlen(str)+1];}
    ~First() {cout<<"~First"<<endl; delete []strOne;}
};

class Second : public First
{
private:
    char* strTwo;
public:
    Second(const char* str1, const char* str2)
    : First(str1){strTwo = new char[strlen(str2)+1];}
    ~Second() {cout<<"~Second"<<endl; delete []strTwo;}
};

int main(void)
{
    First* ptr1 = new Second("simple", "complex");
    Second* ptr2 = new Second("simple", "complex");
    
    delete ptr1;
    delete ptr2;

    return 0;
}