#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTransferScreen.h"
#include "clsShowTransfersLogScreen.h"
#include  "clsTotalBalanceScreen.h"
using namespace std;

class clsTransactionsScreen : protected clsScreen
{
private:

    enum enTransactionsMenueOptions {
        eDeposit = 1, eWithdraw = 2,
        eShowTotalBalance = 3, eTransfer = 4,
        eShowTransferLog = 5,
        eShowMainMenue = 6
        
    };
    static short _ReadTransactionMenuOption()
    {
        cout << setw(37) << left << "";
        cout << "Choose do you want to do ?[1 to 6]";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6 :");
        return Choice;
    }

    static void _ShowDePositScreen()
    {
        /* cout << "\n_ShowDePositScreen will be here.....";*/
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithdrowScreen()
    {
        /*cout << "\nShow Withdraw Screen will be here.....";*/
        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _showTotalBalanceScreen()
    {
        /*cout << "\nshow Total Balance Screen will be here.....";*/
        clsTotalBalanceScreen::ShowTotalBalances();
    }

    static void _ShowTransferScreen()
    {
        /*cout << "\nshow Show Transfer  Screen will be here.....";*/
        clsTransferScreen::ShowTransferScreen();
    }

    static void _ShowTransferLogScreen()
    {
        /*cout << "\nshow Show Transfer  Screen will be here.....";*/
        clsShowTransfersLogScreen::ShowTransferLogScreen();
    }

    static void _GoBackToTransactionMenu()
    {
        cout << "\nPress any key to back to transaction menu ...";
        system("pause > 0");
        ShowTransactionScreen();
    }

   

    static void  _PerformanceTransactioMenuOption(enTransactionsMenueOptions MenuOption)
    {
        switch (MenuOption)
        {
        case clsTransactionsScreen::eDeposit:
            system("cls");
            _ShowDePositScreen();
            _GoBackToTransactionMenu();
            break;
        case clsTransactionsScreen::eWithdraw:
            system("cls");
            _ShowWithdrowScreen();
            _GoBackToTransactionMenu();
            break;
        case clsTransactionsScreen::eShowTotalBalance:
            system("cls");
            _showTotalBalanceScreen();
            _GoBackToTransactionMenu();
            break;

        case clsTransactionsScreen::eTransfer:
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionMenu();
            break;

        case clsTransactionsScreen::eShowTransferLog:
            system("cls");
            _ShowTransferLogScreen();
            _GoBackToTransactionMenu();
            break;

        case clsTransactionsScreen::eShowMainMenue:
            //do nothing here the main screen will handle it :-) ;
            break;

        }
    }

public:

    static void ShowTransactionScreen()
    {
        system("cls");
        if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            return;// this will exit the function and it will not continue
        }

        _DrawMainScreenHeader("\t\t Transaction Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerformanceTransactioMenuOption((enTransactionsMenueOptions)_ReadTransactionMenuOption());
    }


};


