/*
 * File Name : NormalAccount.h
 * Author : Jaewoo Kim
 * File Ver : 0.8
 */

#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"
#include "String.h"

class NormalAccount : public Account
{
private:
    double interestRatio;
public:
    NormalAccount(const int ID, const int money, String name, const double ratio);
    double GetInterestRatio() const;
    void Deposit(const int money);
};
#endif