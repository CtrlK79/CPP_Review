/*
 * File Name : NormalAccount.cpp
 * Author : Jaewoo Kim
 * File Ver : 0.7
 */

#include "NormalAccount.h"
#include "BankingCommonDecl.h"

NormalAccount::NormalAccount(const int ID, const int money, const char* name, const double ratio)
: Account(ID, money, name), interestRatio(ratio/100) {}

void NormalAccount::Deposit(const int money) {Account::Deposit(GetBalance()*interestRatio + money);}

double NormalAccount::GetInterestRatio() const {return interestRatio;}
