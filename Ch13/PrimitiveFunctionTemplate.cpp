#include <iostream>

using std::cout;
using std::endl;

template <class T1, class T2>
void ShowData(double num)
{
    cout<<(T1)num<<", "<<(T2)num<<endl;
}

int main(void)
{
    ShowData<char, int>(65);
    ShowData<char, int>(67);
    ShowData<char, double>(68.9);
    ShowData<short, int>(69.2);
    ShowData<short, int>(70.4);

    return 0;
}