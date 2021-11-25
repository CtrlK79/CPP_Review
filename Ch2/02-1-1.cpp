#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void PlusOne(int &ref)
{
    ref++;
}

void ChangeSign(int &ref)
{
    ref *= -1;
}

int main(void)
{
    int num = 10;
    
    PlusOne(num);
    cout<<"num: "<<num<<endl;
    ChangeSign(num);
    cout<<"num: "<<num<<endl;
    
    return 0;
}