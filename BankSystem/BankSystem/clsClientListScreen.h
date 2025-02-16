#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
using namespace std;



class clsClientListScreen : protected clsScreen
{
private:

	static void PrintClientRecordLine(clsBankClient Client)
	{
		cout << "| " << setw(15) << left << Client.GetAcountNumber();
		cout << "| " << setw(20) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.GetPhone();
		cout << "| " << setw(20) << left << Client.GetEmail();
		cout << "| " << setw(10) << left << Client.GetPinCode();
		cout << "| " << setw(12) << left << Client.GetAcountBlance();

	}

public:
	static void ShowClientList()
	{

		if (!ChackAccessRigth(clsUser::pListClient))
		{
			return;
		}

		vector <clsBankClient> Clients = clsBankClient::GetListClient();
		system("cls");
		clsScreen::_DrawScreenHeader1("   Clients List Screen"  , "   (" + to_string(Clients.size()) + ") Client(s).");
		cout <<"\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << "\t| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";
		cout <<
			"\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;


		if (Clients.size() == 0)
			cout << "\t\t\tNo Client Availble In The Systeem!\n";

		else {

			for (clsBankClient& C : Clients) {

				cout << "\t";
				PrintClientRecordLine(C);
				cout << endl;

			}

		}



		cout <<
			"\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}

};

