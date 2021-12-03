/*
 * File Name : NormalAccount.h
 * Author : Jaewoo Kim
 * File Ver : 0.8
 */

#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"

class NormalAccount : public Account
{
private:
    double interestRatio;
public:
    NormalAccount(const int ID, const int money, const char* name, const double ratio);
    double GetInterestRatio() const;
    void Deposit(const int money);
};
#endif