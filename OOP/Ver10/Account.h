/*
 * File Name : Account.h
 * Author : Jaewoo Kim
 * File Ver : 0.8
 */

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"

class Account
{
private:
    int accID;
    int balance;
    String cusName;
public:
    Account(const int ID, const int money, String name);
    Account(const Account& copy);
    Account& operator=(const Account& ref);

    int GetAccID() const;
    int GetBalance() const;
    virtual void Deposit(const int money);
    int WithDraw(const int money);
    void ShowAccInfo() const;
};
#endif