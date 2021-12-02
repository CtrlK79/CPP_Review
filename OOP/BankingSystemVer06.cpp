/*
 * Banking System Ver 0.6
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

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};
enum {RANK_A=1, RANK_B, RANK_C};
enum {NORMAL=1, CREDIT};

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
    int GetBalance() const;
    virtual void Deposit(const int money);
    int WithDraw(const int money);
    void ShowAccInfo() const;
    virtual ~Account();
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

/*
 * Class Name : NormalAccount
 * Class Type : Entity class
 */
class NormalAccount : public Account
{
private:
    double interestRatio;
public:
    NormalAccount(const int ID, const int money, const char* name, const double ratio);
    double GetInterestRatio() const;
    void Deposit(const int money);
};
NormalAccount::NormalAccount(const int ID, const int money, const char* name, const double ratio)
: Account(ID, money, name), interestRatio(ratio/100) {}
void NormalAccount::Deposit(const int money) {Account::Deposit(GetBalance()*interestRatio + money);}
double NormalAccount::GetInterestRatio() const {return interestRatio;}

/*
 * Class Name : HighCreditAccout
 * Class Type : Entity class
 */
class HighCreditAccount : public NormalAccount
{
private:
    int rank;
public:
    HighCreditAccount(const int ID, const int money, const char* name, const double ratio, const int rank);
    void Deposit(const int money);
};
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

/*
 * Class Name : AccountHandler
 * Class Type : Control class
 */
class AccountHandler
{
private:
    Account* accArr[100];
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
AccountHandler::AccountHandler() : accNum(0) {}
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
    int choice;
    char name[NAME_LEN];
    int balance;
    double ratio;
    cout<<"[계좌종류선택]"<<endl;
    cout<<"1.보통예금계좌 2.신용신뢰계좌"<<endl; cin>>choice;
    if(choice==NORMAL)
    {
        cout<<"[보통예금계좌 개설]"<<endl;
        cout<<"계좌ID: ";cin>>id;
        cout<<"이 름: ";cin>>name;
        cout<<"입금액: ";cin>>balance;
        cout<<"이자율: ";cin>>ratio;
        cout<<endl;
        accArr[accNum++] = new NormalAccount(id, balance, name, ratio);
    }
    else if(choice==CREDIT)
    {
        int rank;
        cout<<"[신용신뢰계좌 개설]"<<endl;
        cout<<"계좌ID: ";cin>>id;
        cout<<"이 름: ";cin>>name;
        cout<<"입금액: ";cin>>balance;
        cout<<"이자율: ";cin>>ratio;
        cout<<"신용등급(1toA, 2toB, 3toC)";cin>>rank;
        cout<<endl;
        accArr[accNum++] = new HighCreditAccount(id, balance, name, ratio, rank);
    }
    else
    {
        cout<<"잘못 입력하셨습니다. 1 또는 2를 입력해주세요."<<endl;
    }
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
AccountHandler::~AccountHandler() {}

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

