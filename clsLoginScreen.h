#pragma once
#include <iostream>
#include "clsScreen.h"
#include "Global.h"
#include "clsClientListScreen.h"
#include "clsMainScreen.h"
#include "clsUser.h"
using namespace std;
class clsLoginScreen : protected clsScreen
{
private:
	static bool _Login()
	{
		bool IsLoginFailed = false;
		string Password, UserName;
		short Trail = 0;

		do
		{
			if (IsLoginFailed)
			{
				Trail++;
				cout << "\nInvalid Username/Password!";
				cout << "\nYou have " << (3 - Trail) << " trails to login\n\n";
			}
			if (Trail == 3)
			{
				cout << "\nYour are Locked after 3 failed trails \n\n";
				return false;
			}
			cout << "Enter Username?";
			cin >> UserName;
			cout << "Enter Password?";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);

			IsLoginFailed = CurrentUser.IsEmpty();
		} while (IsLoginFailed);
		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenu();

		return true;

	}

public:
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawMainScreenHeader("\t\t Login Screen");
		return _Login();
	}

};

