#include <iostream>

using std::cout;
using std::endl;

class SoSimple
{
private:
    int num1;
    int num2;
public:
    SoSimple() : num1(0), num2(0) {cout<<"Called SoSimple()"<<endl;}
    SoSimple(int n1, int n2) : num1(n1), num2(n2) {}
    SoSimple(const SoSimple &copy)
    : num1(copy.num1), num2(copy.num2) {cout<<"Called SoSimple(Sosimple &copy)"<<endl;}
    void ShowSimpleData()
    {
        cout<<num1<<endl;
        cout<<num2<<endl;
    }
};

int main(void)
{
    SoSimple sim1(15, 30);
    cout<<"생성 및 초기화 직전"<<endl;
    SoSimple sim2 = sim1;
    cout<<"생성 및 초기화 직후"<<endl;
    sim2.ShowSimpleData();

    return 0;
}