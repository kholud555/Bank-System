#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"

class clsUpdateCurrencyRate : protected clsScreen
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

	static float _ReadRate()
	{
		float NewRate = 0;
		
		cout << "\nEnter New Rate: ";
		NewRate = clsInputValidate::ReadFloatNumber();

		return NewRate;
	}

public:

	static void ShowUpdateCurrencyRate() 
	{
		_DrawMainScreenHeader("\tUpdate Currency Screen");

		string CurrencyCode = "";
		cout << "\nPlease, Enter Your Currency Code:";
		CurrencyCode = clsInputValidate::ReadString();
	  
		if (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCourency is not found, choose another one:";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		_PrintCurrencyCard(Currency);

		char Answer = 'n';
		cout << "\nAre You Sure You want to update the rate of this Currency y/n?";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			cout << "\nUpdate Currency Rate:";
			cout << "\n---------------------------------";
			
			Currency.UpdateRate(_ReadRate());

			cout << "\nCurrency Rate Updated Successfully :-)\n";
			_PrintCurrencyCard(Currency);
		}
		else
		{
			cout << "\nUpdate did not accour \n\n";
		}


	}


};

