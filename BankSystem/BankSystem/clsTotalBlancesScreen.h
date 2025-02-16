#pragma once
#include <string>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include <iomanip>
#include <cmath>
#include "clsUntil.h"

class clsTotalBlancesScreen : protected clsScreen
{

private:

	static	void _PrintClientRecordLine(clsBankClient Client)
	{
		cout << "\t     | " << setw(15) << left << Client.GetAcountNumber();
		cout << "\t     | " << setw(40) << left << Client.FullName();
		cout << "\t     | " << setw(12) << left << Client.GetAcountBlance();
	}

public:


	static void ShowTotalBlances()
	{
		vector <clsBankClient> Clients = clsBankClient::GetListClient();
		system("cls");

		_DrawScreenHeader1("Blances List Screen", "(" + to_string(Clients.size()) + ") Client(s).");

		cout << "\n\t________________________________________________________________________________________________\n" << endl;
		cout << "\t     | " << left << setw(15) << "Accout Number";
		cout << "\t     | " << left << setw(40) << "Client Name";
		cout << "\t     | " << left << setw(12) << "Balance";
		cout << "\n\t________________________________________________________________________________________________\n" << endl;


		if (Clients.size() == 0)
			cout << "\t\t\tNo Client Availble In The Systeem!\n";

		else {
			for (clsBankClient& C : Clients) {

				_PrintClientRecordLine(C);
				cout << endl;
			}

		}



		cout << "\n\t________________________________________________________________________________________________\n" << endl;


		double TotalBlances = clsBankClient::GetTotalBlance();

		cout << Clbs(9) << "Total Blances = ( " << TotalBlances << " )\n";
		cout << Clbs(7) << "( " << clsUntil::NumberToText(TotalBlances) << " )\n\n";
	}




};

