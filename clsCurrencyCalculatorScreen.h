#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsCurrencyCalculatorScreen : protected clsScreen
{
private:
	static void _PrintCurrencyCard(clsCurrency Currency , string Title = "Currency Card :")
	{
		cout << Title;
		cout << "\n-----------------------------------------";
		cout << "\nCountry   :" << Currency.Country();
		cout << "\nCode      :" << Currency.CurrencyCode();
		cout << "\nName      :" << Currency.CurrencyName();
		cout << "\nRate(1$) =:" << Currency.Rate();
		cout << "\n-----------------------------------------\n\n";
	}

	static float _ReadAmount()
	{
		float Amount = 0;
		cout << "\nEnter Amount to Exchange:";
		Amount = clsInputValidate::ReadFloatNumber();

		return Amount;
	}

	static void ExchangeToDollar(clsCurrency CurrencyFrom, float Amount)
	{
		cout << "\nConvert From:\n";

		_PrintCurrencyCard(CurrencyFrom);

		cout << Amount << CurrencyFrom.CurrencyCode() << " = ";
		cout << Amount / CurrencyFrom.Rate();
		cout << "USD";
	}

	static void _ShowExchangeResult(clsCurrency CurrencyFrom , clsCurrency CurrencyTo , float Amount)
	{
		if (CurrencyTo.CurrencyCode() == "USD")
		{
			ExchangeToDollar(CurrencyFrom, Amount);
		}
		else
		{
			ExchangeToDollar(CurrencyFrom, Amount);

			cout << "\nTo:\n";
			_PrintCurrencyCard(CurrencyTo);
			cout << Amount << CurrencyFrom.CurrencyCode() << " = ";
			float ToDOllar = Amount / CurrencyFrom.Rate();
			cout << ToDOllar * CurrencyTo.Rate();
			cout << CurrencyTo.CurrencyCode();
		}
	}

	static void _PrintCalculationsResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
	{

		_PrintCurrencyCard(Currency1, "Convert From:");

		float AmountInUSD = Currency1.ConvertToUSD(Amount);

		cout << Amount << " " << Currency1.CurrencyCode()
			<< " = " << AmountInUSD << " USD\n";

		if (Currency2.CurrencyCode() == "USD")
		{
			return;
		}

		cout << "\nConverting from USD to:\n";

		_PrintCurrencyCard(Currency2, "To:");

		float AmountInCurrrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);

		cout << Amount << " " << Currency1.CurrencyCode()
			<< " = " << AmountInCurrrency2 << " " << Currency2.CurrencyCode();

	}

	static clsCurrency _GetCurrency(string Message)
	{

		string CurrencyCode;
		cout << Message << endl;

		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency is not found, choose another one: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return Currency;

	}

public:
	static void ShowCurrencyCalculatorScreen()
	{
		char Answer = 'y';

		while (Answer == 'Y' || Answer == 'y')
		{
			system("cls");

			_DrawMainScreenHeader("\tUpdateCurrencyScreen");

			clsCurrency CurrencyFrom = _GetCurrency("\nPlease, Enter Your Currency1 Code:");

			clsCurrency CurrencyTo = _GetCurrency("\nPlease, Enter Your Currency2 Code:");

			float Amount = _ReadAmount();

			_PrintCalculationsResults(Amount, CurrencyFrom, CurrencyTo);
			
			cout << "\nDo you want to perform another calculation?";
				cin >> Answer;
		} 
		

	}
};

