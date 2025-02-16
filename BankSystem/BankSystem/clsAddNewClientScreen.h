#pragma once
#include <string>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsClientListScreen.h"



class clsAddNewClientScreen : protected clsScreen
{

private:
	// Print Date
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
	static void _RadeClientInfo(clsBankClient& Client)
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


public:
	static void ShowAddNewClientScreen()
	{


		if (!ChackAccessRigth(clsUser::pAddNewClient))
		{
			return;
		}

		clsScreen::_DrawScreenHeader1("   Add New Client Screen");

		cout << "Place Enter a acount number?";
		string AcountNumber = clsInputValidate::RadeString();

		while (clsBankClient::IsClientExist(AcountNumber))
		{
		cout << "!Acount Number Is Used Choouse anutor?";
		AcountNumber = clsInputValidate::RadeString();
		}

		clsBankClient NewClient = (clsBankClient::GetAddNewClient(AcountNumber));

		_RadeClientInfo(NewClient);


		clsBankClient::enSaveResult SaveResult;

		SaveResult = NewClient.Save();

		switch (SaveResult)
		{
		case clsBankClient::svFaildEmptyObject:
			cout << "\n!Error acount was not saved bacause it 's Empty\n";
			break;
		case clsBankClient::svSucceeded:
			system("cls");
			cout << "\nAcount Addeeded successfully :-)\n";
			_PrintClient(NewClient);
			break;

		case clsBankClient::svFaildAcountNumberExists:
			cout << "\n!Faild Acount Number Is Used place try again \n";
			break;

		}
	}
};

