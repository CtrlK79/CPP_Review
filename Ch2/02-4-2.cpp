#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(void)
{
    int randnum[5];
    int i;
    srand(time(NULL));
    
    for(i=0; i<5; i++)
        randnum[i] = rand()%100;
    
    for(i=0; i<5; i++)
        cout<<randnum[i]<<" ";
    
    cout<<endl;
    
    return 0;
}