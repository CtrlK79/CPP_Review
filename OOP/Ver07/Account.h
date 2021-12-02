/*
 * File Name : Account.h
 * Author : Jaewoo Kim
 * File Ver : 0.7
 */

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account
{
private:
    int accID;
    int balance;
    char* cusName;
public:
    Account(const int ID, const int money, const char* name);
    Account(const Account& copy);
    int GetAccID() const;
    int GetBalance() const;
    virtual void Deposit(const int money);
    int WithDraw(const int money);
    void ShowAccInfo() const;
    virtual ~Account();
};
#endif