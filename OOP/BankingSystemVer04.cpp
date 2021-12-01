/*
 * Banking System Ver 0.4
 * Author : Jaewoo Kim
 * Content : OOP Project
 */

#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;
using std::strlen;
using std::strcpy;
const int NAME_LEN = 20;

void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccInfo(void);

enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

class Account
{
private:
    int accID;
    int balance;
    char *cusName;
public:
    Account(const int ID, const int money, const char *name)
    : accID(ID), balance(money) 
    {
        cusName = new char[strlen(name)+1];
        strcpy(cusName, name);
    }
    Account(const Account& copy)
    : accID(copy.accID), balance(copy.balance)
    {
        cusName = new char[strlen(copy.cusName)+1];
        strcpy(cusName, copy.cusName);
    }
    int GetAccID() const {return accID;}
    void Deposit(const int money) {balance += money;}
    int WithDraw(const int money)
    {
        if(balance<money)
            return 0;
        
        balance -= money; return money;
    }
    void ShowAccInfo() const
    {
        cout<<"계좌ID: "<<accID<<endl;
        cout<<"이름: "<<cusName<<endl;
        cout<<"잔액: "<<balance<<endl;
    }
    ~Account()
    {
        delete []cusName;
    }
};

Account *accArr[100];
int accNum = 0;

int main(void)
{
    int choice;

    while(1)
    {
        ShowMenu();
        cout<<"선택: ";
        cin>>choice;
        cout<<endl;

        switch(choice)
        {
        case MAKE:
            MakeAccount();
            break;
        case DEPOSIT:
            DepositMoney();
            break;
        case WITHDRAW:
            WithdrawMoney();
            break;
        case INQUIRE:
            ShowAllAccInfo();
            break;
        case EXIT:
            for(int i=0; i<accNum; i++)
                delete accArr[i];
            return 0;
        default:
            cout<<"illegal selection.."<<endl;
        }
    }

    return 0;
}