#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "Global.h"
class clsTransferScreen: protected clsScreen 
{
private:

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\n Client Card:";
		cout << "\n------------------";
		cout << "\nFull Name	:" << Client.FullName();
		cout << "\nAcc. Number     :" << Client.AccountNumber();
		cout << "\nBalance		:" << Client.AccountBalance;
		cout << "\n-------------------\n";
	}

	static string _ReadAccountNumber(string Messsage)
	{
		string AccountNumber = "";
		cout << "\n" << Messsage;
		AccountNumber = clsInputValidate::ReadString();
		if (!clsBankClient::ISClientExist(AccountNumber))
		{
			cout << "\nClient with [ " << AccountNumber << "] does not exist , please enter another AccountNumber";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}

	static double _ReadAmount( clsBankClient SourceClient)
	{
		double Amount = 0;
		cout << "\nPlease, Enter transfer Amount?";
		Amount = clsInputValidate::ReadDblNumber();

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\n Amount Exceeds the avalible Balance , Enter another amount?";
			Amount = clsInputValidate::ReadDblNumber();
		}

		return Amount;

	}


public:
	static void ShowTransferScreen()
	{
		_DrawMainScreenHeader("\t\t Transfer Screen");
		
		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("Please enter AccountNumber to transfer from ?"));
		_PrintClient(SourceClient);


		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("Please enter AccountNumber to transfer To ?"));
		_PrintClient(DestinationClient);
		
		double Amount = _ReadAmount(SourceClient);

		cout << "\nAre you sure you want to preform this opertation?";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient , CurrentUser.UserName))
			{
				
				cout << "\nTransfer  Done  successfully\n";
				
			}
			else
			{
				cout << "\nTransfer Faild \n";
			}
			
			
			
		}
		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);

		
		
	}







};


