#pragma once
#include <string>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"



class clsDepositScreen : protected clsScreen
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


	static void ShowDepoitScreen()
	{
		_DrawScreenHeader1("Deposit Screen");

		cout << "Place Enter a acount number: ";
		string AcountNumber = clsInputValidate::RadeString();

		while (!clsBankClient::IsClientExist(AcountNumber))
		{
			cout << "!Client Not Found entered again: ";
			 AcountNumber = clsInputValidate::RadeString();
		}

		clsBankClient Client = (clsBankClient::Find(AcountNumber));
		_PrintClient(Client);

		cout << "Place enter Deposit Amount? ";
		double Amount = clsInputValidate::RadeNumber <double>();

		char Confirem;
		cout << "\nAre you sure want to perform this Transactions Y/N? ";
		cin >> Confirem;

		if (toupper(Confirem) == 'Y')
		{
			Client.Deposit(Amount);
			cout << "\nAmount Deposited Successfully.\n";
			cout << "New Blance Is : " << Client.GetAcountBlance() << "\n\n";
		}

		else {
			cout << "\nOperation was cancelled.\n";
		}
	}


};

