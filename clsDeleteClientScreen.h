#pragma once
#include "clsScreen.h"
#include"clsBankClient.h"
#include"clsString.h"
#include"clsDate.h"
#include"clsUtil.h"
#include "clsUser.h"
#include"clsInputValidate.h"
using namespace std;

class clsDeleteClientScreen : protected clsScreen
{
private:
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

	static void DeletClient()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
		{
			return;// this will exit the function and it will not continue
		}
		_DrawMainScreenHeader("\t\t Delete client Screen");

		string AccountNumber = "";

		cout << "\nPlease , Enter Account Number : " << endl;
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::ISClientExist(AccountNumber))
		{
			cout << "\nAccount Number is not found ,choose anther one" << endl;
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_Print(Client1);

		cout << "\nAre you sure you want to delete?" << endl;
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (Client1.Delete())
			{
				cout << "\nclient deleted successfully :-)" << endl;
				_Print(Client1);
			}
			else
			{
				cout << "\nError Client was not Deleted" << endl;
			}
		}

	}

};



