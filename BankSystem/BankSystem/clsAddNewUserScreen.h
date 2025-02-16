#pragma once
#include <string>
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

class clsAddNewUserScreen : protected clsScreen
{
private:
	// Print Date
	static void _PrintUser(clsUser User) {
		cout << "\nUser Info:\n";
		cout << "____________________\n";
		cout << "FirstName  : " << User.GetFirstName() << endl;
		cout << "ListName   : " << User.GetListName() << endl;
		cout << "Full Name  : " << User.FullName() << endl;
		cout << "Email      : " << User.GetEmail() << endl;
		cout << "Phone      : " << User.GetPhone() << endl;
		cout << "UserName   : " << User.GetUserName() << endl;
		cout << "Password   : " << User.GetPassword() << endl;
		cout << "Permissions : " << User.GetPermissions() << endl;
		cout << "____________________\n\n";
	}
	static int  _RadePermissionsToSat() {
		char chack;
		cout << "\nGive You Full Acses For System Y/N : ";
		cin >> chack;
		if (toupper(chack) == 'Y') {
			return clsUser::eAll;
		}

			int Permissions = 0;
			cout << "\nGive You Show Client Y/N  : ";
			cin >> chack;
			if (toupper(chack) == 'Y')
			{
				Permissions += clsUser::pListClient;
			}

			cout << "\nGive You Add New Client Y/N : ";
			cin >> chack;

			if (toupper(chack) == 'Y') {
				Permissions += (clsUser::pAddNewClient);
			}
			cout << "\nGive You Dalete  Client Y/N : ";
			cin >> chack;

			if (toupper(chack) == 'Y') {
				Permissions += (clsUser::pDelateClient);
			}

			cout << "\nGive You Update Client Y/N : ";
			cin >> chack;

			if (toupper(chack) == 'Y') {
				Permissions += (clsUser::pUpdateClient);

			}
			cout << "\nGive You Find Client Y/N  : ";
			cin >> chack;
			if (toupper(chack) == 'Y') {
				Permissions += (clsUser::pFindClient);

			}

			cout << "\nGive You Transactions  Y/N : ";
			cin >> chack;
			if (toupper(chack) == 'Y') {
				Permissions += (clsUser::pTransactions);
			}

			cout << "\nGive You Menage Users  Y/N : ";
			cin >> chack;

			if (toupper(chack) == 'Y') {
				Permissions +=  (clsUser::pManageUsers);
			}


			cout << "\nGive You Login Registe Y/N : ";
			cin >> chack;

			if (toupper(chack) == 'Y') {
				Permissions += (clsUser::pLoginRegister);
			}

			return Permissions;
		}

	static void _RadeUserInfo(clsUser& User)
	{
		cout << "Enter a First Name: ";
		User.SatFirstName(clsInputValidate::RadeString());

		cout << "Enter a List Name: ";
		User.SatListName(clsInputValidate::RadeString());

		cout << "Enter a Email: ";
		User.SatEmail(clsInputValidate::RadeString());

		cout << "Enter a Phone Number: ";
		User.SatPhone(clsInputValidate::RadeString());

		cout << "Enter a Password: ";
		User.SetPassword(clsInputValidate::RadeString());

		cout << "Enter a Permissions: ";
		User.SetPermissions(_RadePermissionsToSat());
		if (User.GetPermissions() == 255)
			User.SetPermissions(clsUser::eAll);
	}


public:
	static void ShowAddNewUser()
	{
		_DrawScreenHeader1("   Add New User Screen");

		cout << "Place Enter a UserName?";
		string UserName = clsInputValidate::RadeString();

		while (clsUser::IsUserExist(UserName))
		{
			cout << "!User Name Is Used Choouse anutor?";
			UserName = clsInputValidate::RadeString();
		}

		clsUser NewUser = (clsUser::GetAddNewUserObject(UserName));

		_RadeUserInfo(NewUser);


    	clsUser::enSaveResults SaveResult;

		SaveResult = NewUser.Save();

		switch (SaveResult)
		{
		case clsUser::svFaildEmptyObject:
			cout << "\n!Error UserName was not saved bacause it 's Empty\n";
			break;
		case clsUser::svSucceeded:
			system("cls");
			cout << "\nUser Addeeded successfully :-)\n";
			_PrintUser(NewUser);
			break;

		case clsUser::svFaildUserExists:
			cout << "\n!Faild UserName Is Used place try again \n";
			break;

		}
	}
};


