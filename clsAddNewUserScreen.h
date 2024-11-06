#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsUser.h"
using namespace std;

class clsAddNewUserScreen : protected clsScreen
{

	static void _ReadUserInfo(clsUser& User)
	{
		cout << "\nPlease, Enter First Name:";
		User.FirstName = clsInputValidate::ReadString();

		cout << "\nPlease, Enter Last Name:";
		User.LastName = clsInputValidate::ReadString();

		cout << "\nPlease, Enter Email:";
		User.Email = clsInputValidate::ReadString();

		cout << "\nPlease, Enter Phone :";
		User.Phone = clsInputValidate::ReadString();

		cout << "\nPlease, Enter Password :";
		User.Password = clsInputValidate::ReadString();

		cout << "\nPlease, Enter Permissions :";
		User.Permissions = _ReadPermissionsToSet();


	}

	static short _ReadPermissionsToSet()
	{
		short Permissions = 0;
		char Answer = 'n';
		cout << "\nDo you want to give full access ?(y/n) ?";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			return -1;
		}
		cout << "\nDo you want to give access to : \n ";

		cout << "\nShow Client List? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pListClients;
		}
		cout << "\nDo you want to give access to : \n ";

		cout << "\nShow Add New client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pAddNewClient;
		}

		cout << "\nDelete client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pDeleteClient;
		}

		cout << "\nUpdate client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pUpdateClients;
		}

		cout << "\nFind client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pFindClient;
		}

		cout << "\nTransactions ? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pTranactions;
		}

		cout << "\nManage Users ? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pManageUsers;
		}

		cout << "\nShow login Register List ? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pShowLogInRegister;
		}
		return Permissions;
	}

	static void _Print(clsUser User)
	{
		cout << "\n Client Card:";
		cout << "\n------------------";
		cout << "\nFirst Name	:" <<User.FirstName;
		cout << "\nLast Name	:" <<User.LastName;
		cout << "\nFull Name	:" <<User.FullName();
		cout << "\nPhone		:" <<User.Phone;
		cout << "\nEmail		:" <<User.Email;
		cout << "\nUser Name       :" <<User.UserName;
		cout << "\nPassword        :" <<User.Password;
		cout << "\nPermission      :" <<User.Permissions;
		cout << "\n-------------------\n";
	}
public:

	static void ShowAddNewUserScreen()
	{
		_DrawMainScreenHeader("\t\tAdd New Client");

		string UserName = "";
		cout << "\nPlease , Enter User Name : " << endl;
		UserName = clsInputValidate::ReadString();

		while (clsUser::IsUserExist(UserName))
		{
			cout << "\nUser Name  is already Existed !" << endl;
			UserName = clsInputValidate::ReadString();
		}

		clsUser NewUser = clsUser::GetAddNewUserObject(UserName);
		
		_ReadUserInfo(NewUser);

		clsUser::enSaveResults SaveResult;
		SaveResult = NewUser.Save();

		switch (SaveResult)
		{
		case clsUser::enSaveResults::svSucceeded:
		{
			cout << "\nAccount Addeded Successfully :-)\n";
			_Print(NewUser);
			break;
		}
		case clsUser::enSaveResults::svFaildEmptyObject:
		{
			cout << "\nError account was not saved because it's Empty";
			break;
		}
		case clsUser::svFaildUserExists:
		{
			cout << "\nError account was not saved because account number is used!\n";
			break;
		}
		}


	}


};

