/*
 * File Name : HighCreditAccount.cpp
 * Author : Jaewoo Kim
 * File Ver : 0.8
 */

#include "HighCreditAccount.h"
#include "BankingCommonDecl.h"

HighCreditAccount::HighCreditAccount(const int ID, const int money, const char* name, const double ratio, const int rank)
: NormalAccount(ID, money, name, ratio), rank(rank) {}

void HighCreditAccount::Deposit(const int money)
{
    double rankRatio;
    if(rank == RANK_A) rankRatio = 0.07;
    else if(rank == RANK_B) rankRatio = 0.04;
    else rankRatio = 0.02;
    Account::Deposit(GetBalance()*(GetInterestRatio()+rankRatio)+money);
}