#include <iostream>

using std::cout;
using std::endl;

template <typename T>
T SumArray(T arr[], int len)
{
    T sum = 0;
    for(int i=0; i<len; i++)
        sum+=arr[i];
    return sum;
}

int main(void)
{
    int arr1[] = {1, 2, 3, 4, 5, 6, 7};
    double arr2[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};

    cout<<SumArray<int>(arr1, 7)<<endl;
    cout<<SumArray<double>(arr2, 6)<<endl;

    return 0;
}