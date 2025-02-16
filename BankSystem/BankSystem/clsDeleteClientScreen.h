#pragma once
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsClientListScreen.h"



class clsDeleteClientScreen : protected clsScreen
{
private:

	static void _PrintClient(clsBankClient Client) {
		cout << "Client Info:\n";
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

	static void ShowDeleteClientScreen()
	{

		if (!ChackAccessRigth(clsUser::pDelateClient))
		{
			return;
		}
		clsScreen::_DrawScreenHeader1("   Delete Client Screen");

		cout << "Place Enter a acount number : ";
		string AcountNumber = clsInputValidate::RadeString();


		while (!clsBankClient::IsClientExist(AcountNumber))
		{
			cout << "!Client Not Found enter again: ";
			AcountNumber = clsInputValidate::RadeString();
		}

		clsBankClient Client = (clsBankClient::Find(AcountNumber));
		_PrintClient(Client);

		cout << "\nYou are Sure To Dalete this client Y/N? ";
		char ConfireamDalete = clsInputValidate::RadeChar();


		if (toupper(ConfireamDalete) == 'Y')
		{

			if (Client.Delate())
			{
				system("cls");
				cout << "\nClient Delated successfully :-)\n";
				_PrintClient(Client);
			}
			else {
				cout << "\n!Not Delated Client place try again\n";
			}

		}
		else {
			cout << "\n!You Canseld Dalted Client From Datebase\n";
		}


	}

};


