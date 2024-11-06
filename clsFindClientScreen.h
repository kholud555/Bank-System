#pragma once
#include"clsBankClient.h"
#include"clsString.h"
#include"clsDate.h"
#include"clsUtil.h"
#include"clsInputValidate.h"
#include "clsScreen.h"
using namespace std;
class clsFindClientScreen : protected clsScreen
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

	static void ShowFindClientList()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return;// this will exit the function and it will not continue
		}
		_DrawMainScreenHeader("\t\t Find Client List");

		string AccountNumber = "";
		cout << "\nPlease, Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		
		while (!(clsBankClient::ISClientExist(AccountNumber)))
		{
			cout << "\nAccount Number is not found , enter anothre one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		if (!Client1.IsEmpty())
		{
			cout << "\nClient is Found :-)";
		}
		else
		{
			cout << "\nCLient is Not Found :-( ";

		}
		_Print(Client1);
	}

};

