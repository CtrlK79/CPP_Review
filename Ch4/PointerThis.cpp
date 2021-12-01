#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

class SoSimple
{
private:
    int num;
public:
    SoSimple(int n) : num(n)
    {
        cout<<"num="<<num<<", "<<"adress="<<this<<endl;
    }
    void ShowSimpleData() const
    {
        cout<<num<<endl;
    }
    SoSimple *GetThisPointer() // const is invalid
    {
        return this;
    }
};

int main(void)
{
    SoSimple sim1(100);
    SoSimple *ptr1 = sim1.GetThisPointer();
    cout<<ptr1<<", ";
    ptr1->ShowSimpleData();

    SoSimple sim2(200);
    SoSimple *ptr2 = sim2.GetThisPointer();
    cout<<ptr2<<", ";
    ptr2->ShowSimpleData();

    return 0;
}