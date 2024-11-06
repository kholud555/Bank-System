#pragma once
#include "iomanip"
#include "Global.h"
#include "clsDate.h"
#pragma warning(disable : 4996)  
#include"clsString.h"
#include "clsUtil.h"
using namespace std;

class clsScreen
{
protected:

	static void _DrawMainScreenHeader(string Title , string SubTitle = "")
	{
		cout << "\t\t\t\t\t----------------------------------";
		cout << "\n\n\t\t\t\t " << Title;
		if (SubTitle != "")
		{
			cout << "\n\n\t\t\t\t\t " << SubTitle;
	    }
		cout << setw(37) << left << "" << "\t\t\n";
		cout << "\t\t\t\t\t----------------------------------\n";

		string RegisterDate = clsDate::DateToString(clsDate());
		cout << "\t\t\t\t\tUser:" << CurrentUser.UserName << endl;
		cout << "\t\t\t\t\tDate:" << RegisterDate;
		cout << "\n\n";
		

	}

	static bool CheckAccessRights(clsUser::enPermissions Permission)
	{
		if (!CurrentUser.CheckAccessPermission(Permission))
		{
			cout << "\t\t\t\t\t______________________________________";
			cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
			cout << "\n\t\t\t\t\t______________________________________\n\n";
			return false;
		}
		else
		{
			return true;
		}
	}
};


