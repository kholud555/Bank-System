#pragma once
#include <iomanip>
#include "clsBankClient.h"
#include "clsUtil.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsClientsListScreen : protected clsScreen
{
private:
	static void  PrintClientRecordLine(clsBankClient Client)
	{
		cout << "|" << setw(20) << left << Client.AccountNumber();
		cout << "|" << setw(20) << left << Client.FullName();
		cout << "|" << setw(20) << left << Client.Email;
		cout << "|" << setw(12) << left << Client.Phone;
		cout << "|" << setw(10) << left << Client.Pincode;
		cout << "|" << setw(12) << left << Client.AccountBalance;

	}
public:

	static void ShowClientList()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pListClients))
		{
			return;// this will exit the function and it will not continue
		}

		vector <clsBankClient> vClients = clsBankClient::GetClientList();

		string Title = "\t Client List screen";
		string SubTitle = "\t (" + to_string(vClients.size()) + ") client(s)";

		_DrawMainScreenHeader(Title, SubTitle);

		cout << setw(8) << left << ""<<"\n---------------------------------------------------------";
		cout << "-------------------------------------------------------" << endl;
		cout << "|" << setw(20) << "Account Number";
		cout << "|" << setw(20) << "Client Name";
		cout << "|" << setw(20) << "Email"; 
		cout << "|" << setw(12) << "Phone";
		cout << "|" << setw(10) << "Pin code";
		cout << "|" << setw(12) << "Balance";
		cout << "\n\n---------------------------------------------------------";
		cout << "-------------------------------------------------------" << endl;

		if (vClients.size() == 0)
		{
			cout << "\t\t\tNo Clients Available In The System !";
		}
		else
		{
			for (clsBankClient Client : vClients)
			{
				PrintClientRecordLine(Client);
				cout << endl;
			}
		}
		cout << "\n---------------------------------------------------------";
		cout << "-------------------------------------------------------" << endl;


	}
};


