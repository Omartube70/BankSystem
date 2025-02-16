#pragma once
#include <string>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"



class clsUpdateClientScreen : protected clsScreen
{

private:
	// Print Date
	static void _PrintClient(clsBankClient Client) {
		cout << "Client Info:\n";
		cout << "____________________\n";
		cout << "FirstName  : " << Client.GetFirstName() << endl;
		cout << "ListName   : " << Client.GetListName() << endl;
		cout << " Name      : " << Client.FullName() << endl;
		cout << "Email      : " << Client.GetEmail() << endl;
		cout << "Phone      : " << Client.GetPhone() << endl;
		cout << "Ac. Number : " << Client.GetAcountNumber() << endl;
		cout << "Pin Code   : " << Client.GetPinCode() << endl;
		cout << "Ac. Blance : " << Client.GetAcountBlance() << endl;
		cout << "____________________\n\n";
	}

	static void _PrintClientToUpdate(clsBankClient Client) {
		cout << "Info:\n";
		cout << "____________________\n";
		cout << "[1] FirstName  : " << Client.GetFirstName() << endl;
		cout << "[2] ListName   : " << Client.GetListName() << endl;
		cout << "[3] Email      : " << Client.GetEmail() << endl;
		cout << "[4] Phone      : " << Client.GetPhone() << endl;
		cout << "[5] Pin Code   : " << Client.GetPinCode() << endl;
		cout << "[6] Ac. Blance : " << Client.GetAcountBlance() << endl;
		cout << "____________________\n\n";
	}

	static void _RadeClientInfo(clsBankClient &Client)
	{
		cout << "Enter a First Name: ";
		Client.SatFirstName(clsInputValidate::RadeString());

		cout << "Enter a List Name: ";
		Client.SatListName(clsInputValidate::RadeString());

		cout << "Enter a Email: ";
		Client.SatEmail(clsInputValidate::RadeString());

		cout << "Enter a Phone Number: ";
		Client.SatPhone(clsInputValidate::RadeString());

		cout << "Enter a Pin Code: ";
		Client.SatPinCode(clsInputValidate::RadeString());

		cout << "Enter a Aco.Blance: ";
		Client.SatAcountBlance((clsInputValidate::RadeNumber <double>()));
	}

	static void _UpdateDateInObject(clsBankClient &Client)
	{
		char UpdateAllDate;
		cout << "Update All Date Y/N? ";
		cin >> UpdateAllDate;

		if (toupper(UpdateAllDate) == 'Y')
		{
			cout << "\n\nUpdate Client Info\n";
			cout << "_______________________\n\n";
			_RadeClientInfo(Client);
			return;
		}

			system("cls");
			_DrawScreenHeader1("Update Client Screen");
			_PrintClientToUpdate(Client);
			cout << "Place enter Choise [1 To 6] To Update: ";
			short Choise = clsInputValidate::RadeNumberBetween <short>(1, 6);
			switch (Choise)
			{

			case 1:
				cout << "\nEnter a First Name: ";
				Client.SatFirstName(clsInputValidate::RadeString());
				break;

			case 2:
				cout << "\n Enter a List Name: ";
				Client.SatListName(clsInputValidate::RadeString());
				break;

			case 3:
				cout << "\n Enter a Email: ";
				Client.SatEmail(clsInputValidate::RadeString());
				break;

			case 4:
				cout << "\n Enter a Phone Number: ";
				Client.SatPhone(clsInputValidate::RadeString());
				break;

			case 5:
				cout << "\n Enter a Pin Code: ";
				Client.SatPinCode(clsInputValidate::RadeString());
				break;

			case 6:
				cout << "\n Enter a Aco. Blance: ";
				Client.SatAcountBlance((clsInputValidate::RadeNumber <double>()));
				break;

			}


	}

public:
	static void ShowUpdateClientScreen() {



		if (!ChackAccessRigth(clsUser::pUpdateClient))
		{
			return;
		}

		_DrawScreenHeader1("   Update Client Screen");

		cout << "Place Enter a acount number: ";
		string AcountNumber = clsInputValidate::RadeString();

		while (!clsBankClient::IsClientExist(AcountNumber))
		{
			cout << "!Client Not Found entered again: ";
			 AcountNumber = clsInputValidate::RadeString();
		}

		clsBankClient Client = (clsBankClient::Find(AcountNumber));
		_PrintClient(Client);

		char Confirem;
		cout << "Are you sure want to update client Y/N? ";
		cin >> Confirem;

		if (toupper(Confirem) == 'Y')
		{
			_UpdateDateInObject(Client);

		}
		else {
			cout << "\n!You Canseld Update Client \n";
			return;
		}

		clsBankClient::enSaveResult SaveResult;

		SaveResult = Client.Save();

		switch (SaveResult)
		{
		case clsBankClient::svFaildEmptyObject:
			cout << "\n!The operation failed, please try again.\n\n";
			break;
		case clsBankClient::svSucceeded:
			cout << "\nThe operation was completed successfully :-)\n\n";
			_PrintClient(Client);
			break;
		}

	}


};

