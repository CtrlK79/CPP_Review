#include <iostream>

int main(void)
{
    int dan;
    std::cout<<"몇 단을 출력할까요? ";
    std::cin>>dan;

    std::cout<<"******"<<dan<<"단******"<<std::endl;
    for(int i = 0; i < 9; i++)
        std::cout<<dan<<" x "<<i+1<<" = "<<dan*(i+1)<<std::endl;
    std::cout<<"******끝******"<<std::endl;
    
    return 0;
}