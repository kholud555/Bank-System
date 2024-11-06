#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include<vector>

class clsShowTransfersLogScreen : protected clsScreen
{
private:

    static void _PrintTransferLog (clsBankClient::stTransferLog TransferLog)
    {

        cout << setw(8) << left << "" << "| " << setw(20) << left << TransferLog.DateTime;
        cout << "| " << setw(8) << left << TransferLog.SourceClient;
        cout << "| " << setw(8) << left << TransferLog.DestinationClient;
        cout << "| " << setw(8) << left << TransferLog.Amount;
        cout << "| " << setw(8) << left << TransferLog.SourceBalanceAfterTransfer;
        cout << "| " << setw(8) << left << TransferLog.DestinationBalanceAfterTransfer;
        cout << "| " << setw(8) << left << TransferLog.UserName;
        
    }

public:

    static void ShowTransferLogScreen()
    {
        vector <clsBankClient::stTransferLog> vTransferLog = clsBankClient::GetTransferLogList();

        string Title = "\tTransfer Log List Screen";
        string SubTitle = "\t\t(" + to_string(vTransferLog.size()) + ") Record(s).";

        _DrawMainScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(20) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(8) << "s.Balance";
        cout << "| " << left << setw(8) << "d.Balance";
        cout << "| " << left << setw(8) << "User";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransferLog.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (clsBankClient::stTransferLog Record : vTransferLog)
            {

                _PrintTransferLog(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};

