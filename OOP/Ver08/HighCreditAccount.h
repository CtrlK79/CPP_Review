/*
 * File Name : HighCreditAccount.h
 * Author : Jaewoo Kim
 * File Ver : 0.8
 */

#ifndef __HIGH_CREDIT_ACCOUNT_H__
#define __HIGH_CREDIT_ACCOUNT_H__

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount
{
private:
    int rank;
public:
    HighCreditAccount(const int ID, const int money, const char* name, const double ratio, const int rank);
    void Deposit(const int money);
};
#endif