#include <iostream>

int main(void)
{
    char name[20];
    char phone[20];
    std::cout<<"이름을 입력하세요: ";
    std::cin>>name;
    std::cout<<"전화번호를 입력하세요: ";
    std::cin>>phone;
    std::cout<<"이름: "<<name<<std::endl<<"전화번호: "<<phone<<std::endl;

    return 0;
}