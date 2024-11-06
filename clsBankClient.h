#pragma once
#include<vector>
#include<fstream>
#include<string>
#include"clsString.h"
#include"clsPerson.h"
#include "clsUtil.h"

class clsBankClient : public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNew = 2 };
	enMode _Mode;
	string _AccountNumber;
	string _Pincode;
	double _AccountBalance;
	bool _MarkToDelete = false;

	struct stTransferLog;

	static stTransferLog _ConvertTransferLineToRecod(string Line, string Seperator = "#//#")
	{
		stTransferLog TransferLogRecord;

		 vector <string> vTransferLog = clsString::Split(Line,Seperator);

		 TransferLogRecord.DateTime = vTransferLog[0];
		 TransferLogRecord.SourceClient = vTransferLog[1];
		 TransferLogRecord.DestinationClient = vTransferLog[2];
		 TransferLogRecord.Amount = stod(vTransferLog[3]);
		 TransferLogRecord.SourceBalanceAfterTransfer = stod(vTransferLog[4]);
		 TransferLogRecord.DestinationBalanceAfterTransfer = stod(vTransferLog[5]);
		 TransferLogRecord.UserName = vTransferLog[6];

		 return TransferLogRecord;

	}

	static clsBankClient _ConvertLineToClientObject(string Line, string SeParator = "#//#")
	{
		vector <string> vClients;

		vClients = clsString::Split(Line, SeParator);

		return clsBankClient(enMode::UpdateMode, vClients[0], vClients[1],
			vClients[2], vClients[3], vClients[4],vClients[5] = clsUtil::DecryptionText(vClients[5],10), stod(vClients[6]));
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static string _ConvertClientObjectToLine(clsBankClient Client, string separator = "#//#")
	{
		string ClientDataRecord = "";
		
		
		ClientDataRecord += Client.FirstName + separator;
		ClientDataRecord += Client.LastName + separator;
		ClientDataRecord += Client.Email + separator;
		ClientDataRecord += Client.Phone + separator;
		ClientDataRecord += Client.AccountNumber() + separator;
		ClientDataRecord += clsUtil::EncrptionText(Client.Pincode , 10) + separator;
		ClientDataRecord += to_string(Client.AccountBalance);

		return ClientDataRecord;
	}

	static void _SaveClientsDataLineToFile(vector <clsBankClient> _vClients)
	{
		fstream MyFile;
		MyFile.open("Client.text", ios::out); // writed mode

		if (MyFile.is_open())
		{
			string DataLine;

			for (clsBankClient C : _vClients)
			{
				//we only write records that are not marked for delete.
				if (C._MarkToDelete == false)
				{
					DataLine = _ConvertClientObjectToLine(C);
					MyFile << DataLine << endl;
				}
			}

			MyFile.close();
		}
	}

	static vector <clsBankClient> _LoadClientDataLineFromFile()
	{
		vector <clsBankClient> _vClient;

		fstream MyFile;

		MyFile.open("Client.text", ios::in);// Read mode

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				_vClient.push_back(Client);
			}

			MyFile.close();
		}
		return _vClient;
	}

	void _Update()
	{
		vector <clsBankClient> _vClient;

		_vClient = _LoadClientDataLineFromFile();

		for (clsBankClient& C : _vClient)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}
		_SaveClientsDataLineToFile(_vClient);
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	void _AddDataLineToFile(string DataLine)
	{
		fstream MyFile;

		MyFile.open("Client.text", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << DataLine << endl;
		}

		MyFile.close();
	}

    string _PrepareTransferRecord(double Amount, clsBankClient DestinationClient, string UserName,string Separator ="#//#")
	{
		string TransferRecord = "";

		TransferRecord += clsDate::GetSystemDateTimeString() + Separator;
		TransferRecord += this->AccountNumber() + Separator;
		TransferRecord += DestinationClient.AccountNumber() + Separator;
		TransferRecord += to_string(Amount) + Separator;
		TransferRecord += to_string(this->AccountBalance) + Separator;
		TransferRecord += to_string(DestinationClient.AccountBalance) + Separator;
		TransferRecord += UserName;

		return TransferRecord;
	}

	void _RegisterTransferLog(double Amount, clsBankClient Destination , string UserName)
	{
		string stDataLine = _PrepareTransferRecord(Amount, Destination , UserName);

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;

			MyFile.close();
		}
	}
public:

	//parameterize Constructor 
	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone
		, string AccountNumber, string Pincode, double AccountBalance)
		:clsPerson(FirstName, LastName, Email,Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_Pincode = Pincode;
		_AccountBalance = AccountBalance;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string AccountNumber()
	{
		return _AccountNumber;
	}

	// Set Property
	void setPincode(string Pincode)
	{
		_Pincode = Pincode;
	}
	// Get Property
	string GetPincode()
	{
		return _Pincode;
	}

	__declspec(property(get = GetPincode, put = setPincode)) string Pincode;

	// Set Property
	void setAccountBalance(double AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	// Get Property
	double GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = setAccountBalance)) double AccountBalance;
	// No UI exist inside Object
	/*void Print()
	{
		cout << "\n Client Card:";
		cout << "\n------------------";
		cout << "\nFirst Name	:" << FirstName;
		cout << "\nLast Name	:" << LastName;
		cout << "\nFull Name	:" << FullName();
		cout << "\nEmail		:" << Email;
		cout << "\nPhone		:" << Phone;
		cout << "\nAcc. Number     :" << _AccountNumber;
		cout << "\nPassword	:" << _Pincode;
		cout << "\nBalance		:" << _AccountBalance;
		cout << "\n-------------------\n";
	}*/

	struct stTransferLog
	{
		string DateTime;
		string SourceClient;
		string DestinationClient;
		double Amount;
		double SourceBalanceAfterTransfer;
		double DestinationBalanceAfterTransfer;
		string UserName;
	};

	static clsBankClient Find(string AccountNumber)
	{
		vector<clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Client.text", ios::in); // Read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);

				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
				vClients.push_back(Client);
			}
			MyFile.close();
		}

		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string Password)
	{
		vector<clsBankClient> vClients;

		fstream Myfile;
		Myfile.open("Client.text", ios::in); // Read Mode

		if (Myfile.is_open())
		{
			string Line;
			while (getline(Myfile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);

				if (Client.AccountNumber() == AccountNumber && Client.Pincode == Password)
				{
					Myfile.close();
					return Client;
				}
				vClients.push_back(Client);
			}
		}
		Myfile.close();

		return _GetEmptyClientObject();
	}

	static bool ISClientExist(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);

		return (!Client.IsEmpty());
	}

	enum enSaveResults { SvFaildEmptyObject = 0, SvSucceed = 1, svFaildAccountNumberExists = 3 };

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			if (IsEmpty())
			{
				return enSaveResults::SvFaildEmptyObject;
			}
		}

		case enMode::UpdateMode:

		{
			_Update();

			return enSaveResults::SvSucceed;
		}
		case enMode::AddNew:
		{

			// This will add new record to file or database 
			if (clsBankClient::ISClientExist(_AccountNumber))
			{
				return enSaveResults::svFaildAccountNumberExists;
			}
			else
			{

				_AddNew();
				//we need to set the mode to update after add new
				_Mode = enMode::UpdateMode;
				return enSaveResults::SvSucceed;
			}
		}

		}
	}

	static clsBankClient  GetAddNewClientObject(string AccountNumer)
	{
		return clsBankClient(enMode::AddNew, "", "", "", "", AccountNumer, "", 0);
	}

	bool Delete()
	{
		vector <clsBankClient> _vClients;

		_vClients = _LoadClientDataLineFromFile();


		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C._MarkToDelete = true;

				_SaveClientsDataLineToFile(_vClients);
				*this = _GetEmptyClientObject();

				return  true;
			}

		}

		return false;
	}

	static vector <clsBankClient> GetClientList()
	{
		return _LoadClientDataLineFromFile();
	}

	static double GetTotalBalance()
	{
		vector <clsBankClient> vClient = _LoadClientDataLineFromFile();
		double TotalBalance = 0;

		for (clsBankClient Client : vClient)
		{
			TotalBalance += Client.AccountBalance;
		}

		return TotalBalance;
	}

    void Deposit( double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	bool Withdraw (double Amount)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}
		else
		{
			_AccountBalance -= Amount;
			Save();
			return true;
		}
	}

	bool Transfer(double Amount, clsBankClient& Destination , string UserName)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}

		Withdraw(Amount);
		Destination.Deposit(Amount);

		_RegisterTransferLog(Amount, Destination ,UserName);
		return true;
	}

	static vector<stTransferLog> GetTransferLogList()
	{
		vector<stTransferLog> vTransferLog;

		fstream Myfile;

		Myfile.open("TransferLog.txt", ios::in);
		
		if (Myfile.is_open())
		{
			string Line;

			stTransferLog TransferLog;


			while (getline(Myfile, Line))
			{
				TransferLog = _ConvertTransferLineToRecod(Line);
				vTransferLog.push_back(TransferLog);
			}
			Myfile.close();
		}

		return vTransferLog;
	}
};


