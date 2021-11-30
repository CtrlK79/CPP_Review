#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::strlen;
using std::strcpy;

namespace COMP_POS {
    enum {CLERK = 0, SENIOR, ASSIST, NAMAGER};
    char pos[4][10] = {"사원", "주임", "대리", "팀장"};
}

class NameCard
{
private:
    char *name;
    char *comName;
    char *phone;
    int pos;
public:
    NameCard(const char *myname, const char *mycomname, const char *myphone, const int mypos) : pos(mypos)
    {
        name = new char[strlen(myname)+1]; strcpy(name, myname);
        comName = new char[strlen(mycomname)+1]; strcpy(comName, mycomname);
        phone = new char[strlen(myphone)+1]; strcpy(phone, myphone);
    }
    ~NameCard()
    {
        delete name; delete comName; delete phone;
    }
    void ShowNameCardInfo()
    {
        cout<<"이름: "<<name<<endl;
        cout<<"회사: "<<comName<<endl;
        cout<<"전화번호: "<<phone<<endl;
        cout<<"직급: "<<COMP_POS::pos[pos]<<endl<<endl;
    }
};

int main(void)
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
    manClerk.ShowNameCardInfo();
    manSenior.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();

    return 0;
}