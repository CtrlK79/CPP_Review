/*
 * File Name : BoundChechPointPtrArray.cpp
 * Author : Jaewoo Kim
 * File Ver : 0.8
 */

#include "BoundCheckPointPtrArray.h"
#include "BankingCommonDecl.h"

BoundCheckPointPtrArray::BoundCheckPointPtrArray(const int len)
: arrlen(len)
{
    arr = new ACC_PTR[len];
}
ACC_PTR& BoundCheckPointPtrArray::operator[] (int idx)
{
    if(idx<0 || idx>=arrlen)
    {
        cout<<"Array is out of bound exception"<<endl;
        exit(1);
    }
    return arr[idx];
}
ACC_PTR BoundCheckPointPtrArray::operator[] (int idx) const
{
    if(idx<0 || idx>=arrlen)
    {
        cout<<"Array is out of bound exception"<<endl;
        exit(1);
    }
    return arr[idx];
}
int BoundCheckPointPtrArray::GetArrLen() const {return arrlen;}
BoundCheckPointPtrArray::~BoundCheckPointPtrArray() {delete []arr;}