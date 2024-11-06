#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrency.h"
#include "clsUpdateCurrencyRate.h"
#include "clsCurrencyCalculatorScreen.h"

class clsCurrencyMainScreen : protected clsScreen
{
private:
	enum enCurrencyMenuOptions {
		eListCurrencies = 1, eFindCurrency = 2, eUpdateRate= 3,
		eCurrencyCalculator = 4, eMainMenu = 5	
	};

    static short _ReadCurrencyMenuOption()
    {
        cout << setw(37) << left << "";
        cout << "Choose do you want to do ?[1 to 5]";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5 :");
        return Choice;
    }

    static void _ShowCurrencyListScreen()
    {
        /* cout << "\n_Show Currency List will be here.....";*/
        clsCurrenciesListScreen::ShowCurrenciesListScreen();
    }

    static void _ShowFindCurrencyScreen()
    {
        /* cout << "\n_Show Find Currency will be here.....";*/
        clsFindCurrency::ShowFindCurrencyScreen();
    }

    static void _ShowUpdateRateScreen()
    {
        /* cout << "\n_Show Update Rate will be here.....";*/
        clsUpdateCurrencyRate::ShowUpdateCurrencyRate();
    }

    static void _ShowCurrencyCalculatorScreen()
    {
        /* cout << "\n_Show Currency Calculator will be here.....";*/
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();

    }

    static void _GoBackToCurrencyMainMenuScreen()
    {
        /* cout << "\n_Go Back To Main Menu Screen will be here.....";*/
        cout << setw(37) << left << "" << "\nPress any key to go Back To Main Menu...\n";
        system("pause>0");
        ShowCurrencyScreen();
    }

    static void _PerformanceCurrencyMenuOption(enCurrencyMenuOptions  MenuOption)
    {
        switch (MenuOption)
        {
        case enCurrencyMenuOptions::eListCurrencies:
        {
            system("cls");
            _ShowCurrencyListScreen();
            _GoBackToCurrencyMainMenuScreen();
            break;
        }

        case enCurrencyMenuOptions::eFindCurrency:
        {
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrencyMainMenuScreen();
            break;
        }

        case enCurrencyMenuOptions::eUpdateRate:
        {
            system("cls");
            _ShowUpdateRateScreen();
            _GoBackToCurrencyMainMenuScreen();
            break;
        }

        case enCurrencyMenuOptions::eCurrencyCalculator:
        {
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrencyMainMenuScreen();
            break;
        }

        case enCurrencyMenuOptions::eMainMenu:
            //do nothing here the main screen will handle it :-) ;
            break;
        
        }
    }

public:

    static void ShowCurrencyScreen()
    {
        system("cls");
     
        _DrawMainScreenHeader("\t Currency Exchange Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Currency Exchange Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currnecy.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerformanceCurrencyMenuOption((enCurrencyMenuOptions)_ReadCurrencyMenuOption());
    }

};

