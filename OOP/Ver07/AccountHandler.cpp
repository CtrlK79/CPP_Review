/*
 * File Name : AccountHandler.cpp
 * Author : Jaewoo Kim
 * File Ver : 0.7
 */

#include "AccountHandler.h"
#include "BankingCommonDecl.h"

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
