#pragma once
#include <string>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include <iomanip>


class clsShowTransferLogScreen : protected clsScreen
{

	static void _PrintRigsterTransferRecordLine(clsBankClient::stRigsterTransfer RigsterTransfer)
	{
		cout << setw(8) << left << "" << "| " << setw(25) << left << RigsterTransfer.Date_Time;
		cout << "| " << setw(10) << left << RigsterTransfer.S_AcountNumber;
		cout << "| " << setw(10) << left << RigsterTransfer.D_AcountNumber;
		cout << "| " << setw(10) << left << RigsterTransfer.Amount;
		cout << "| " << setw(10) << left << RigsterTransfer.S_AcountBlanace;
		cout << "| " << setw(10) << left << RigsterTransfer.D_AcountBlanace;
		cout << "| " << setw(10) << left << RigsterTransfer.Username;

	}

public:
	static void ShowTransferRegisterList()
	{

	/*	if (!clsScreen::ChackAccessRigth(clsUser::pLoginRegister))
		{
			return;
		}
		*/

		vector <clsBankClient::stRigsterTransfer> RigsterTransfer = clsBankClient::GetRigsterTransferList();


		system("cls");
		clsScreen::_DrawScreenHeader1(" Transfer Log List Screen", " (" + to_string(RigsterTransfer.size()) + ") Record(s).");

		cout << setw(8) << left << "" << "\n\t_____________________________________________________________";
		cout << "_________________________________________\n" << endl;


		cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
		cout << "| " << left << setw(10) << "F.Acount";
		cout << "| " << left << setw(10) << "T.Acount";
		cout << "| " << left << setw(10) << "Amount";
		cout << "| " << left << setw(10) << "F.Blance";
		cout << "| " << left << setw(10) << "T.Blance";
		cout << "| " << left << setw(10) << "User";


		cout << setw(8) << left << "" << "\n\t_____________________________________________________________";
		cout << "_________________________________________\n" << endl;


		if (RigsterTransfer.size() == 0)
			cout << "\t\t\tNo Login Register Availble In The Systeem!\n";

		else {

			for (clsBankClient::stRigsterTransfer& C : RigsterTransfer) {

				_PrintRigsterTransferRecordLine(C);
				cout << endl;
			}

		}



		cout <<
			"\t_____________________________________________________________";
		cout << "_________________________________________\n" << endl;

	}



};

