/*
 * File Name : AccountHandler.h
 * Author : Jaewoo Kim
 * File Ver : 0.8
 */

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "BoundCheckPointPtrArray.h"
#include "BankingCommonDecl.h"

class AccountHandler
{
private:
    BoundCheckPointPtrArray accArr;
    int accNum;
public:
    AccountHandler();
    void ShowMenu(void) const;
    void MakeAccount(void);
    void DepositMoney(void);
    void WithdrawMoney(void);
    void ShowAllAccInfo(void) const;
    ~AccountHandler();
};
#endif