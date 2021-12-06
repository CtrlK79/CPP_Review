#ifndef __ARRAY_TEMPLATE_H__
#define __ARRAY_TEMPLATE_H__

#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

template <typename T>
class BoundCheckArray
{
private:
    T* arr;
    int arrlen;
    BoundCheckArray(const BoundCheckArray& arr) {}
    BoundCheckArray& operator=(const BoundCheckArray& arr) {}
public:
    BoundCheckArray(const int len);
    T& operator[] (const int idx);
    T operator[] (const int idx) const;
    int GetArrLen() const;
    ~BoundCheckArray();
};

template <typename T>
BoundCheckArray<T>::BoundCheckArray(const int len)
: arrlen(len) {arr = new T[len];}

template <typename T>
T& BoundCheckArray<T>::operator[] (const int idx)
{
    if(idx<0 || idx>=arrlen)
    {
        cout<<"Array index out of bound exception"<<endl;
        exit(1);
    }
    return arr[idx];
}

template <typename T>
T BoundCheckArray<T>::operator[] (const int idx) const
{
    if(idx<0 || idx>=arrlen)
    {
        cout<<"Array index out of bound exception"<<endl;
        exit(1);
    }
    return arr[idx];
}

template <typename T>
int BoundCheckArray<T>::GetArrLen() const {return arrlen;}

template <typename T>
BoundCheckArray<T>::~BoundCheckArray() {delete []arr;}
#endif