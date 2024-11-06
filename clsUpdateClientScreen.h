#pragma once
#include"clsBankClient.h"
#include"clsString.h"
#include"clsDate.h"
#include"clsUtil.h"
#include"clsInputValidate.h"
#include "clsScreen.h"
using namespace std;
class clsUpdateClientScreen : protected clsScreen
{
private:

	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nPlease, Enter First Name:";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "\nPlease, Enter Last Name:";
		Client.LastName = clsInputValidate::ReadString();

		cout << "\nPlease, Enter Email:";
		Client.Email = clsInputValidate::ReadString();

		cout << "\nPlease, Enter Phone :";
		Client.Phone = clsInputValidate::ReadString();

		cout << "\nPlease, Enter Password :";
		Client.Pincode = clsInputValidate::ReadString();

		cout << "\nPlease, Enter  Balance:";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber();


	}

	static void _Print(clsBankClient Client)
	{
		cout << "\n Client Card:";
		cout << "\n------------------";
		cout << "\nFirst Name	:" << Client.FirstName;
		cout << "\nLast Name	:" << Client.LastName;
		cout << "\nFull Name	:" << Client.FullName();
		cout << "\nEmail		:" << Client.Email;
		cout << "\nPhone		:" << Client.Phone;
		cout << "\nAcc. Number     :" << Client.AccountNumber();
		cout << "\nPassword	:" << Client.Pincode;
		cout << "\nBalance		:" << Client.AccountBalance;
		cout << "\n-------------------\n";
	}

public:

	static void UpdateClient()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
		{
			return;// this will exit the function and it will not continue
		}
		_DrawMainScreenHeader("\t\t Update client Info");

		string AccountNumber = "";

		cout << "Please enter your AccountNumber:\n";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::ISClientExist(AccountNumber))
		{
			cout << "Account Number is not found , choose anther one:" << endl;
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_Print(Client1);

		cout << "\n Update client Info :";
		cout << "\n ----------------------\n";

		_ReadClientInfo(Client1);

		clsBankClient::enSaveResults SaveResult;

		SaveResult = Client1.Save();

		switch (SaveResult)
		{
		case clsBankClient::enSaveResults::SvSucceed:
		{
			cout << "\nAccount Updated Successfully :-)\n";
			_Print(Client1);
			break;
		}
		case clsBankClient::enSaveResults::SvFaildEmptyObject:
		{
			cout << "\nError account was not saved because it's Empty";
			break;
		}
		}


	}
};



