#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"

class clsFindCurrency :protected clsScreen
{
private:

	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\nCurrency Card :";
		cout << "\n-----------------------------------------";
		cout << "\nCountry   :" << Currency.Country();
		cout << "\nCode      :" << Currency.CurrencyCode();
		cout << "\nName      :" << Currency.CurrencyName();
		cout << "\nRate(1$) =:" << Currency.Rate();
		cout << "\n-----------------------------------------\n\n";
	}

	static void _ShowResult(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCourency Found :-)\n";

			_PrintCurrencyCard(Currency);
		}
		else
		{
			cout << "\nCourency Not Found :-(\n";

			_PrintCurrencyCard(Currency);
		}
	}


public:
	static void ShowFindCurrencyScreen()
	{
		_DrawMainScreenHeader("\t\tFind Currency Screen");
		
		short Choice = 1;
		cout << "\nFind By : [1] Code or [2] Country ?";
		Choice = clsInputValidate::ReadShortNumberBetween(1, 2);

		if (Choice == 1)
		{
			string CurrencyCode;
			cout << "\nplease Enter Currency Code :";
			CurrencyCode = clsInputValidate::ReadString();

			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

			_ShowResult(Currency);

		}
		else
		{
			string CurrencyCountry;
			cout << "\nplease Enter Currency Country :";
			cin >> CurrencyCountry;

			clsCurrency Currency = clsCurrency::FindByCountry(CurrencyCountry);

			_ShowResult(Currency);
		}


	}

};

