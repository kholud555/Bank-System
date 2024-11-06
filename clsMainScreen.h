#pragma once
#include "clsScreen.h"
#include<iomanip>
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include  "clsTransactionScreen.h"
#include "clsManageUsersScreen.h"
#include "clsCurrencyMainScreen.h"
#include "MYIssue.h"
#include "Global.h"

using namespace std;

class clsMainScreen :protected clsScreen
{
private:
	enum enMainMenuOptions
	{
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenu = 6,
		eManageUsers = 7, eLoginRegister = 8 , eCurrencyExchange = 9 ,eExit = 10
	};

	static short _ReadMainMenuOption()
	{
		cout << setw(37) << left << "";
		cout << "Choose do you want to do ?[1 to 10]";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 10, "Enter Number between 1 to 10 :");
		return Choice;
	}

	static void _GoBackToMainMenu()
	{
		cout << setw(37) << left << "" << "\nPress any key to go Back To Main Menu...\n";
		system("pause>0");
		ShowMainMenu();
	}

	static void _ShowAllClientsScreen()
	{
		clsClientsListScreen::ShowClientList();
	}

	static void _ShowAddNewClientsScreen()
	{
		/*cout << "\nShowAddNewClientsScreen here....\n";*/
		clsAddNewClientScreen::AddNewclient();
	}

	static void _ShowDeleteClientScreen()
	{
		/*cout << "\nShow Delete Client Screen here....\n";*/
		clsDeleteClientScreen::DeletClient();
	}

	static void _ShowUpdateClientScreen()
	{
		/*cout << "\nShow Update Client Screen here....\n";*/
		clsUpdateClientScreen::UpdateClient();
	}

	static void _ShowFindClientsScreen()
	{
		/*cout << "\nShow Find Clients Screen here....\n";*/
		clsFindClientScreen::ShowFindClientList();
	}

	static void _ShowTransactionsMenuScreen()
	{
		/*cout << "\n_Show Transactions Menu Screen here....\n";*/
		clsTransactionsScreen::ShowTransactionScreen();
	}

	static void _ShowManageUsersScreen()
	{
		/*cout << "\nShowManageUsersScreen here....\n";*/
		clsManageUsersScreen::ShowUserMainMenu();
	}

	static void _ShowLoginRegisterScreen()
	{
		/*cout << "\nShowLoginRegisterScreen here....\n";*/
		MYIssue::ShowLoginRegisterScreen();
	}

	static void _ShowCurrencyExChangeScreen()
	{
		/*cout << "\nShow Currency ExChange Screen here....\n";*/
		clsCurrencyMainScreen::ShowCurrencyScreen();
	}
	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");
		//then it will back to main function.
	}
	static void _PerformanceMainMenuOption(enMainMenuOptions MainMenuOption)
	{
		switch (MainMenuOption)
		{
		case enMainMenuOptions::eListClients:
		{
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eAddNewClient:
		{
			system("cls");
			_ShowAddNewClientsScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eDeleteClient:
		{
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eUpdateClient:
		{
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eFindClient:
		{
			system("cls");
			_ShowFindClientsScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eShowTransactionsMenu:
		{
			system("cls");
			_ShowTransactionsMenuScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eManageUsers:
		{
			system("cls");
			_ShowManageUsersScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eLoginRegister:
		{
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenu();
			break;
		}

		case enMainMenuOptions::eCurrencyExchange:
		{
			system("cls");
			_ShowCurrencyExChangeScreen();
			_GoBackToMainMenu();
			break;
		}

		case enMainMenuOptions::eExit:
		{
			system("cls");
			_Logout();
			break;
		}
		}

	}

public:

	static void ShowMainMenu()
	{
		system("cls");
		_DrawMainScreenHeader("\t\tMain Screen");

		cout << setw(37) << left << "" << "\t\t\n";
		cout << setw(37) << left << "" << "==================================\n";
		cout << setw(37) << left << "" << "\t\tMain Menu \n";
		cout << setw(37) << left << "" << "==================================\n";
		cout << setw(37) << left << "" << "\t[1]show client list.\n";
		cout << setw(37) << left << "" << "\t[2]Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3]Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4]Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5]Find Client.\n";
		cout << setw(37) << left << "" << "\t[6]Transactions.\n";
		cout << setw(37) << left << "" << "\t[7]Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8]login Register.\n";
		cout << setw(37) << left << "" << "\t[9]Currency Exchange.\n";
		cout << setw(37) << left << "" << "\t[10]log out.\n";
		cout << setw(37) << left << "" << "======================================\n";

		_PerformanceMainMenuOption((enMainMenuOptions)_ReadMainMenuOption());

	}

};

