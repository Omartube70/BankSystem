#pragma once
#include <string>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"


class clsFindClientScreen : protected clsScreen
{


private:
	// Print Date
	static void _PrintClient(clsBankClient Client) {
		cout << "\nClient Info:\n";
		cout << "____________________\n";
		cout << "FirstName  : " << Client.GetFirstName() << endl;
		cout << "ListName   : " << Client.GetListName() << endl;
		cout << "Name       : " << Client.FullName() << endl;
		cout << "Email      : " << Client.GetEmail() << endl;
		cout << "Phone      : " << Client.GetPhone() << endl;
		cout << "Ac. Number : " << Client.GetAcountNumber() << endl;
		cout << "Pin Code   : " << Client.GetPinCode() << endl;
		cout << "Ac. Blance : " << Client.GetAcountBlance() << endl;
		cout << "____________________\n\n";
	}



public:

	static void ShowFindClientScreen()
	{


		if (!ChackAccessRigth(clsUser::pListClient))
		{
			return;
		}

		_DrawScreenHeader1("   Find Client Screen");

		cout << "Place Enter a acount number: ";
		string AcountNumber = clsInputValidate::RadeString();

		while (! clsBankClient::IsClientExist(AcountNumber))
		{
			cout << "!Client Not Found entered again: ";
			 AcountNumber = clsInputValidate::RadeString();
		}

		clsBankClient Client = (clsBankClient::Find(AcountNumber));


		if (Client.IsClientExist())
		{
			cout << "\nClient Found :-)\n";
			_PrintClient(Client);
		}
		else {
			cout << "\n!Client Not Found\n";
		}

	}


};

