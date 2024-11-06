#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUser.h"
using namespace std;
class clsFindUserScreen : protected clsScreen
{
private:

	static void _Print(clsUser User)
	{
		cout << "\n Client Card:";
		cout << "\n------------------";
		cout << "\nFirst Name	:" << User.FirstName;
		cout << "\nLast Name	:" << User.LastName;
		cout << "\nFull Name	:" << User.FullName();
		cout << "\nPhone		:" << User.Phone;
		cout << "\nEmail		:" << User.Email;
		cout << "\nUser Name       :" << User.UserName;
		cout << "\nPassword        :" << User.Password;
		cout << "\nPermission      :" << User.Permissions;
		cout << "\n-------------------\n";
	}

public:
	static void ShowFindUserScreen()
	{
		_DrawMainScreenHeader("\t\tUpdate User Screen");

		string UserName = "";
		cout << "\nPlease , Enter User Name : " << endl;
		UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser Name  is Not Existed !" << endl;
			UserName = clsInputValidate::ReadString();
		}
		clsUser User1 = clsUser::Find(UserName);

		if (User1.IsUserExist(UserName))
		{
			cout << "\nUser Info";
			cout << "\n-------------\n";
			_Print(User1);
		}
		else
		{
			cout << "\nUser does not exist";
		}
	}
};

