#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

class Gun
{
private:
    int bullet;
public:
    Gun(const int bnum) : bullet(bnum) {}
    void Shot() {cout<<"BBANG!"<<endl; bullet--;}
};

class Police
{
private:
    int handcuffs;
    Gun* pistol;
public:
    Police(const int bnum, const int bcuff) : handcuffs(bcuff)
    {
        if(bnum>0)
            pistol = new Gun(bnum);
        else
            pistol = NULL;
    }
    void PutHandcuff() {cout<<"SNAP!"<<endl; handcuffs--;}
    void Shot()
    {
        if(pistol==NULL)
            cout<<"Hut BBANG!"<<endl;
        else
            pistol->Shot();
    }
};

int main(void)
{
    Police pman1(5, 3);
    pman1.Shot();
    pman1.PutHandcuff();

    Police pman2(0, 3);
    pman2.Shot();
    pman2.PutHandcuff();
    
    return 0;
}