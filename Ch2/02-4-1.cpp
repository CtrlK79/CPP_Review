#include <iostream>
#include <cstring>
using std::cout;
using std::endl;
using std::strlen;
using std::strcat;
using std::strcpy;
using std::strcmp;

int main(void)
{
    char str1[] = "CPP is so engaging that I cannot stop doing it";
    cout<<"sentence: "<<str1<<endl;
    cout<<"length of the sentence is "<<strlen(str1)<<endl;
    cout<<"wanna add ! in the end"<<endl;
    strcat(str1, "!");
    cout<<str1<<endl;
    char str2[50];
    strcpy(str2, str1);
    cout<<"copy: "<<str2<<endl;
    cout<<"str1 and str2 is same? ";
    if(!strcmp(str1, str2))
        cout<<"Yes!"<<endl;
    else
        cout<<"No!"<<endl;
    
    return 0;
}