#pragma once
#include <iostream>
#include<string>
#include"clsString.h"
#include"clsDate.h"
#include"clsUtil.h"
using namespace std;
class clsInputValidate
{
public:
	static bool ISNumberBetween(short  Number, short From , short To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool ISNumberBetween(int  Number, int From, int To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool ISNumberBetween(float   Number, float From, float To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool ISNumberBetween(double  NumberToCheck, double StartOfRange, double EndOfRange)
	{
		if (NumberToCheck >= StartOfRange && NumberToCheck <= EndOfRange)
			return true;
		else
			return false;
	}

	static bool ISDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		// Date >= From && Date <= To
		if (
			clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)
			&&
			clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)
			)
		{
			return true;
		}

		// Date >= To && Date <= From
		if (
			clsDate::IsDate1BeforeDate2(Date,To) || clsDate::IsDate1EqualDate2(Date, To)
			&&
			clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)
			)
		{
			return true;
		}
		return false;
	}

	static int ReadIntNumber(string ErrorMessage = "Number is not within range")
	{
		int Number = 0;
		
		while (!(cin >> Number))
		{
			//User didn't input a number.
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMessage << endl;
		}
		return Number;
	}

	static int ReadIntNumberBetween(int From, int To , string ErrorMessage = "Number is not within range")
	{
		int Number = ReadIntNumber();
	
		while (!ISNumberBetween(Number,From,To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}
		return Number;

	}

	static int ReadShortNumber(string ErrorMessage = "Number is not within range")
	{
		short Number = 0;

		while (!(cin >> Number))
		{
			//User didn't input a number.
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMessage << endl;
		}
		return Number;
	}

	static int ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within range")
	{
		short Number = ReadIntNumber();

		while (!ISNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}
		return Number;

	}

	static double ReadDblNumber(string ErrorMessage = "Number is not within range")
	{
		double Number = 0;

		while (!(cin >> Number))
		{
			//User didn't input a number.
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMessage << endl;
		}
		return Number;
	}

	static double ReadDblNumberBetween(double From, double To, string ErrorMessage)
	{
		double Number = ReadDblNumber();

		while (!ISNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}
		return Number;

	}

	static float ReadFloatNumber(string ErrorMessage = "Number is not within range")
	{
		float Number = 0;

		while (!(cin >> Number))
		{
			//User didn't input a number.
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMessage << endl;
		}
		return Number;
	}

	static float ReadfloatNumberBetween(float From, float To, string ErrorMessage)
	{
		float Number = ReadFloatNumber();

		while (!ISNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadFloatNumber();
		}
		return Number;

	}

	static bool IsVaildDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}

	static string ReadString()
	{
		string S1 = "";
		// usage of std::ws will extract all the whitespace character
		getline(cin >> ws, S1);
		return S1;
	}

};




