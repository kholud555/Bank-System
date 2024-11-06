#pragma once
#include<vector>
#include<fstream>
#include<string>
#include"clsString.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsUsersListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
using namespace std;

class clsManageUsersScreen :protected clsScreen
{
private:
	enum enManageUsersMenu
	{
		eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
		eUpdateUser = 4, eFindUser = 5, eMainMenu = 6
	};

	static short _ReadMainMenuOption()
	{
		cout << setw(37) << left << "";
		cout << "Choose do you want to do ?[1 to 6]";
		short Choise = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6 :");
		return Choise;
	}

	static void _GoBackToUsersMainMenu()
	{
		cout << setw(37) << left << "" << "\nPress any key to go Back To User Menu...\n";
		system("pause>0");
		ShowUserMainMenu();
	}

	static void _ShowListUsersScreen()
	{
		/*cout << "\nShow Users List Screen here....\n";*/
		clsListUsersScreen::ShowUsersList();
	}

	static void _ShowAddNewUsersScreen()
	{
		/*cout << "\nShow Add New Users Screen here....\n";*/
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		/*cout << "\nShow Delete User Screen here....\n";*/
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		//cout << "\nShow Update User Screen here....\n";
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		//cout << "\nShow Find User Screen here....\n";
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _PerformanceMainMenuOption(enManageUsersMenu MainMenuOption)
	{
		switch (MainMenuOption)
		{
		case enManageUsersMenu::eListUsers:
		{
			system("cls");
			_ShowListUsersScreen();
			_GoBackToUsersMainMenu();
			break;
		}
		case enManageUsersMenu::eAddNewUser:
		{
			system("cls");
			_ShowAddNewUsersScreen();
			_GoBackToUsersMainMenu();
			break;
		}
		case enManageUsersMenu::eDeleteUser:
		{
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToUsersMainMenu();
			break;
		}
		case enManageUsersMenu::eUpdateUser:
		{
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToUsersMainMenu();
			break;
		}
		case enManageUsersMenu::eFindUser:
		{
			system("cls");
			_ShowFindUserScreen();
			_GoBackToUsersMainMenu();
			break;
		}
		case enManageUsersMenu::eMainMenu:
		{
			//do nothing here the main screen will handle it :-) ;
			break;
		}

		}

	}

public:

	static void ShowUserMainMenu()
	{
		system("cls");
		if (!CheckAccessRights(clsUser::enPermissions::pListClients))
		{
			return;// this will exit the function and it will not continue
		}
		_DrawMainScreenHeader("\t\tMain Sreen");

		cout << setw(37) << left << "" << "\t\t\n";
		cout << setw(37) << left << "" << "==================================\n";
		cout << setw(37) << left << "" << "\t\tMain Menu \n";
		cout << setw(37) << left << "" << "==================================\n";
		cout << setw(37) << left << "" << "\t[1] list Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
		cout << setw(37) << left << "" << "======================================================\n";

		_PerformanceMainMenuOption((enManageUsersMenu)_ReadMainMenuOption());

	}

};

