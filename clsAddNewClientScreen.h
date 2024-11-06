#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
using namespace std;
class clsAddNewClientScreen :protected clsScreen
{
private:
	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "Please, Enter First Name:";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "Please, Enter Last Name:" ;
		Client.LastName = clsInputValidate::ReadString();

		cout << "Please, Enter Email:";
		Client.Email = clsInputValidate::ReadString();

		cout << "Please, Enter Phone :";
		Client.Phone = clsInputValidate::ReadString();

		cout << "Please, Enter PassWord :";
		Client.Pincode = clsInputValidate::ReadString();

		cout << "Please, Enter  Balance:";
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

	static void AddNewclient()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
		{
			return;// this will exit the function and it will not continue
		}
		_DrawMainScreenHeader("\t\tAdd New Client");

		string AccountNumber = "";
		cout << "\nPlease , Enter Account Number : " << endl;
		AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::ISClientExist(AccountNumber))
		{
			cout << "\n Account Number is already used choose , anther one" << endl;
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
		_ReadClientInfo(NewClient);

		clsBankClient::enSaveResults SaveResult;
		SaveResult = NewClient.Save();

		switch (SaveResult)
		{
		case clsBankClient::enSaveResults::SvSucceed:
		{
			cout << "\nAccount Addeded Successfully :-)\n";
			_Print(NewClient);
			break;
		}
		case clsBankClient::enSaveResults::SvFaildEmptyObject:
		{
			cout << "\nError account was not saved because it's Empty";
			break;
		}
		case clsBankClient::svFaildAccountNumberExists:
		{
			cout << "\nError account was not saved because account number is used!\n";
			break;
		}
		}

	}

};



