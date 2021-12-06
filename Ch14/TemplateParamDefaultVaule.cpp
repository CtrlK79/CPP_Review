#include <iostream>
using namespace std;

template <typename T=int, int len=7>
class SimpleArray
{
private:
    T arr[len];
public:
    T& operator[] (int idx) {return arr[idx];}
    SimpleArray<T, len>& operator=(const SimpleArray<T, len>& ref)
    {
        for(int i=0; i<len; i++)
            arr[i] = ref.arr[i];
        return *this;
    }
};

int main(void)
{
    SimpleArray<> arr1;
    for(int i=0; i<7; i++)
        arr1[i] = i*10;
    
    SimpleArray<> arr2;
    arr2 = arr1;
    for(int i=0; i<7; i++)
        cout<<arr2[i]<<", ";
    cout<<endl;

    return 0;
}