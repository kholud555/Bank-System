#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsDepositScreen : protected clsScreen
{
	static void _PrintClient(clsBankClient Client)
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

	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "\nPlease enter AccountNumber? ";
		cin >> AccountNumber;
		return AccountNumber;
	}

public:

	static void ShowDepositScreen()
	{
		_DrawMainScreenHeader("\t\tDeposit Screen");


		string AccountNumber = _ReadAccountNumber();

		while ((!clsBankClient::ISClientExist(AccountNumber)))
		{
			cout << "\nClient with [ " << AccountNumber << "] does not exist";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		double Amount = 0;
		cout << "\nPlease,Enter Deposit Amount";
		Amount = clsInputValidate::ReadDblNumber();

		cout << "\nAre you sure , you want this perform this transaction " << endl;
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			Client1.Deposit(Amount);
			cout << "\nAmount deposited successfully." << endl;
			cout << "New Balance is :" << Client1.AccountBalance;
		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}


	}

};


