#include <iostream>
#include <stdlib.h>
using std::cout;
using std::endl;

class Simple
{
public:
    Simple()
    {
        cout<<"I'm simple constructor!"<<endl;
    }
};

int main(void)
{
    cout<<"case1: ";
    Simple * sp1 = new Simple;

    cout<<"case2: ";
    Simple * sp2 = (Simple*)malloc(sizeof(Simple)*1);

    cout<<endl<<"end of main"<<endl;
    
    delete sp1;
    free(sp2);
    return 0;
}