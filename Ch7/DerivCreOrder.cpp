#include <iostream>

using std::cout;
using std::endl;

class SoBase
{
private:
    int baseNum;
public:
    SoBase() : baseNum(20) {cout<<"SoBase()"<<endl;}
    SoBase(const int n) : baseNum(n) {cout<<"SoBase(const int n)"<<endl;}
    void ShowBaseData() const {cout<<baseNum<<endl;}    
};

class SoDerived : public SoBase
{
private:
    int derivNum;
public:
    SoDerived() : derivNum(30) {cout<<"SoDerived()"<<endl;}
    SoDerived(const int n) : derivNum(n) {cout<<"SoDerived(const int n)"<<endl;}
    SoDerived(const int n1, const int n2) : SoBase(n1), derivNum(n2) {cout<<"SoDerived(const int n1, const int n2)"<<endl;}
    void ShowDerivData()  const {ShowBaseData(); cout<<derivNum<<endl;}
};

int main(void)
{
    cout<<"case1..... "<<endl;
    SoDerived dr1;
    dr1.ShowDerivData();
    cout<<"--------------------"<<endl;
    cout<<"case2..... "<<endl;
    SoDerived dr2(12);
    dr2.ShowDerivData();
    cout<<"--------------------"<<endl;
    cout<<"case3..... "<<endl;
    SoDerived dr3(23, 24);
    dr3.ShowDerivData();

    return 0;
}