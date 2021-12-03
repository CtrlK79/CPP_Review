/*
 * File Name : Account.cpp
 * Author : Jaewoo Kim
 * File Ver : 0.8
 */

#include "Account.h"
#include "BankingCommonDecl.h"

Account::Account(const int ID, const int money, const char* name)
    : accID(ID), balance(money) 
{
    cusName = new char[strlen(name)+1];
    strcpy(cusName, name);
}

Account::Account(const Account& copy)
: accID(copy.accID), balance(copy.balance)
{
    cusName = new char[strlen(copy.cusName)+1];
    strcpy(cusName, copy.cusName);
}

Account& Account::operator=(const Account& ref)
{
    delete []cusName;
    accID = ref.accID; balance = ref.balance; strcpy(cusName, ref.cusName);
    return *this;
}

int Account::GetAccID() const {return accID;}

int Account::GetBalance() const {return balance;}

void Account::Deposit(const int money) {balance += money;}

int Account::WithDraw(const int money)
{
    if(balance<money)
        return 0;
    
    balance -= money; return money;
}

void Account::ShowAccInfo() const
{
    cout<<"계좌ID: "<<accID<<endl;
    cout<<"이름: "<<cusName<<endl;
    cout<<"잔액: "<<balance<<endl;
}

Account::~Account() {delete []cusName;}