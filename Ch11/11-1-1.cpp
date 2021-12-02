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
    int GetBullet() const {return bullet;}
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
    Police(const Police& copy)
    : handcuffs(copy.handcuffs)
    {
        if(copy.pistol!=NULL)
            pistol = new Gun(*(copy.pistol));
        else
            pistol = NULL;
    }
    Police& operator=(const Police& ref)
    {
        if(pistol!=NULL)
            delete pistol;
        if(ref.pistol!=NULL)
            pistol = new Gun(*(ref.pistol));
        else
            pistol = NULL;
        handcuffs = ref.handcuffs;
        return *this;
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
    Police pman2 = pman1;
    Police pman3(0, 3);
    
    pman1.Shot();
    pman2.Shot();
    pman3.Shot();
    
    return 0;
}