/*
 * Banking System Ver 0.5
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

enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

/*
 * Class Name : Account
 * Class Type : Entity class
 */
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
    void Deposit(const int money);
    int WithDraw(const int money);
    void ShowAccInfo() const;
    ~Account();
};
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
int Account::GetAccID() const {return accID;}
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

/*
 * Class Name : AccountHandler
 * Class Type : Control class
 */
class AccountHandler
{
private:
    Account* accArr[100];
    int accNum = 0;
public:
    AccountHandler();
    void ShowMenu(void) const;
    void MakeAccount(void);
    void DepositMoney(void);
    void WithdrawMoney(void);
    void ShowAllAccInfo(void) const;
    ~AccountHandler();
};
void AccountHandler::ShowMenu(void) const
{
    cout<<"-----Menu-----"<<endl;
    cout<<"1. 계좌개설"<<endl;
    cout<<"2. 입 금"<<endl;
    cout<<"3. 출 금"<<endl;
    cout<<"4. 계좌정보 전체 출력"<<endl;
    cout<<"5. 프로그램 종료"<<endl;
}
void AccountHandler::MakeAccount(void)
{
    int id;
    char name[NAME_LEN];
    int balance;

    cout<<"[계좌개설]"<<endl;
    cout<<"계좌ID: ";cin>>id;
    cout<<"이 름: ";cin>>name;
    cout<<"입금액: ";cin>>balance;
    cout<<endl;

    accArr[accNum++] = new Account(id, balance, name);
}
void AccountHandler::DepositMoney(void)
{
    int money;
    int id;
    cout<<"[입 금]"<<endl;
    cout<<"계좌ID: ";cin>>id;
    cout<<"입금액: ";cin>>money;

    for(int i=0; i<accNum; i++)
    {
        if(accArr[i]->GetAccID() == id)
        {
            accArr[i]->Deposit(money);
            cout<<"입금완료"<<endl<<endl;
            return;
        }
    }
    cout<<"유효하지 않은 ID 입니다."<<endl<<endl;
}
void AccountHandler::WithdrawMoney(void)
{
    int money;
    int id;
    cout<<"[출 금]"<<endl;
    cout<<"계좌ID: ";cin>>id;
    cout<<"출금액: ";cin>>money;

    for(int i=0; i<accNum; i++)
    {
        if(accArr[i]->GetAccID() == id)
        {
            if(accArr[i]->WithDraw(money)==0)
            {
                cout<<"잔액부족"<<endl<<endl;
                return;
            }

            cout<<"출금완료"<<endl<<endl;
            return;
        }
    }
    cout<<"유효하지 않은 ID 입니다."<<endl<<endl;
}
void AccountHandler::ShowAllAccInfo(void) const
{
    for(int i=0; i<accNum; i++)
    {
        accArr[i]->ShowAccInfo();
        cout<<endl;
    }
}

int main(void)
{
    AccountHandler manager;
    int choice;

    while(1)
    {
        manager.ShowMenu();
        cout<<"선택: ";
        cin>>choice;
        cout<<endl;

        switch(choice)
        {
        case MAKE:
            manager.MakeAccount();
            break;
        case DEPOSIT:
            manager.DepositMoney();
            break;
        case WITHDRAW:
            manager.WithdrawMoney();
            break;
        case INQUIRE:
            manager.ShowAllAccInfo();
            break;
        case EXIT:
            return 0;
        default:
            cout<<"illegal selection.."<<endl;
        }
    }
    return 0;
}

