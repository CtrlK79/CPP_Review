/*
 * Banking System Ver 0.7
 * Author : Jaewoo Kim
 * Content : OOP Project
 */
#include "AccountHandler.h"
#include "BankingCommonDecl.h"

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

