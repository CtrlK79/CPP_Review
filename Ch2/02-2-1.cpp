#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
    const int num = 12;
    const int* ptr = &num;
    const int* (&pref) = ptr;

    cout<<"By ptr: "<<*ptr<<endl;
    cout<<"By ref: "<<*pref<<endl;

    return 0;
}