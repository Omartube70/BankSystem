#pragma once
#include <string>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"



class clsWithdrawScreen : protected clsScreen
{

private:
	static void _PrintClient(clsBankClient Client) {
		cout << "\nClient Info:\n";
		cout << "____________________\n";
		cout << "FirstName  : " << Client.GetFirstName() << endl;
		cout << "ListName   : " << Client.GetListName() << endl;
		cout << "Full Name  : " << Client.FullName() << endl;
		cout << "Email      : " << Client.GetEmail() << endl;
		cout << "Phone      : " << Client.GetPhone() << endl;
		cout << "Ac. Number : " << Client.GetAcountNumber() << endl;
		cout << "Pin Code   : " << Client.GetPinCode() << endl;
		cout << "Ac. Blance : " << Client.GetAcountBlance() << endl;
		cout << "____________________\n\n";
	}
public:


	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader1("   Withdraw Screen");

		cout << "Place Enter a acount number: ";
		string AcountNumber = clsInputValidate::RadeString();

		while (!clsBankClient::IsClientExist(AcountNumber))
		{
			cout << "!Client Not Found Try again: ";
			AcountNumber = clsInputValidate::RadeString();
		}

		clsBankClient Client = (clsBankClient::Find(AcountNumber));
		_PrintClient(Client);

		cout << "Place enter Withdraw Amount? ";
		double Amount = clsInputValidate::RadeNumber <double>();

		char Confirem;
		cout << "\nAre you sure want to perform this Transactions Y/N? ";
		cin >> Confirem;

		if (toupper(Confirem) == 'Y')
		{
			if (Client.Withdraw(Amount))
			{
				cout << "\nAmount Withdraw Successfully -:).\n";
				cout << "\nNew Blance Is : " << Client.GetAcountBlance() << "\n\n";
			}
			else {
				cout << "\nCannot Withdraw, Insuffecient Balance!\n";
				cout << "\nAmount to Withdraw is: " << Amount;
				cout << "\nYour Blance Is : " << Client.GetAcountBlance() << "\n\n";
			}

		}

		else {
			cout << "\nOperation was cancelled.\n";
		}
	}


};

