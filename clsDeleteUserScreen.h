#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
using namespace std;
class clsDeleteUserScreen : protected clsScreen
{
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
	static void ShowDeleteUserScreen()
	{
		_DrawMainScreenHeader("\t\tDelete Screen");
		string UserName = "";
		cout << "\nPlease , Enter User Name : " << endl;
		UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser Name  is Not Existed !" << endl;
			UserName = clsInputValidate::ReadString();
		}

		clsUser User1 = clsUser::Find(UserName);
		_Print(User1);

		cout << "\nAre you sure you want to delete this User?" << endl;
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			if (User1.Delete())
			{
				cout << "\nUser Deleted successfully :-) ";
				_Print(User1);
			}
			else
			{
				cout << "\nError User was not deleted :-(";
			}
		}

	}
};

