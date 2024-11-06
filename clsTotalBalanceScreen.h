#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>

class clsTotalBalanceScreen : protected clsScreen
{
	static void  _PrintClientRecordLine(clsBankClient Client)
	{
		cout << "|" << setw(15) << left << Client.AccountNumber();
		cout << "|" << setw(20) << left << Client.FullName();
		cout << "|" << setw(12) << left << Client.AccountBalance;

	}


public:

	static void ShowTotalBalances()
	{
		vector <clsBankClient> vClients = clsBankClient::GetClientList();
		string Title = "Client Total Balances";
		string SubTitle = "Clients" + to_string(vClients.size()) + "Client(s)";
		_DrawMainScreenHeader(Title , SubTitle);

		cout << "\n---------------------------------------------------------";
		cout << "-------------------------------------------------------\n" << endl;

		cout << "|" << setw(15) << "Account Number";
		cout << "|" << setw(20) << "Client Name";
		cout << "|" << setw(12) << "Balance";
		cout << "\n\n---------------------------------------------------------";
		cout << "-------------------------------------------------------" << endl;
		double TotalBalance = clsBankClient::GetTotalBalance();
		if (vClients.size() == 0)
		{
			cout << "\t\t\tNo Clients Available In The System !";
		}
		else
		{
			for (clsBankClient Client : vClients)
			{
				_PrintClientRecordLine(Client);
				cout << endl;
			}
		}
		cout << "\n---------------------------------------------------------";
		cout << "-------------------------------------------------------" << endl;
		clsUtil::Tabs(2);
		cout << "Total Balance = " << TotalBalance << endl;
		clsUtil::Tabs(2);
		cout << "(" << clsUtil::NumberToText(TotalBalance) << ")" << endl;

	}


};

