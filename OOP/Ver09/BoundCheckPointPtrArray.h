/*
 * File Name : BoundChechPointPtrArray.h
 * Author : Jaewoo Kim
 * File Ver : 0.8
 */

#ifndef __BOUND_CHECK_POINT_PTR_ARRAY_H__
#define __BOUND_CHECK_POINT_PTR_ARRAY_H__

#include "Account.h"

typedef Account* ACC_PTR;

class BoundCheckPointPtrArray
{
private:
    ACC_PTR* arr;
    int arrlen;
public:
    BoundCheckPointPtrArray(const int len);
    ACC_PTR& operator[] (int idx);
    ACC_PTR operator[] (int idx) const;
    int GetArrLen() const;
    ~BoundCheckPointPtrArray();
};

#endif