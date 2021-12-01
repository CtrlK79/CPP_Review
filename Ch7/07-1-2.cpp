#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::strlen;
using std::strcpy;

class MyFriendInfo
{
private:
    char* name;
    int age;
public:
    MyFriendInfo(const char* name, const int age)
    : age(age)
    {
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
    }
    ~MyFriendInfo() {delete []name;}
    void ShowMyFriendInfo() const
    {
        cout<<"이름: "<<name<<endl;
        cout<<"나이: "<<age<<endl;
    }
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
    char* addr;
    char* phone;
public:
    MyFriendDetailInfo(const char* name, const int age, const char* addr, const char* phone)
    : MyFriendInfo(name, age)
    {
        this->addr = new char[strlen(addr)+1]; strcpy(this->addr, addr);
        this->phone = new char[strlen(phone)+1]; strcpy(this->phone, phone);
    }
    ~MyFriendDetailInfo() {delete []addr; delete []phone;}
    void ShowMyFriendDetailInfo()
    {
        ShowMyFriendInfo();
        cout<<"주소: "<<addr<<endl;
        cout<<"전화: "<<phone<<endl;
    }
};

int main(void)
{
    MyFriendDetailInfo info("Kim", 25, "Seoul", "010-1234-5678");
    info.ShowMyFriendInfo();
    cout<<endl;
    info.ShowMyFriendDetailInfo();

    return 0;
}