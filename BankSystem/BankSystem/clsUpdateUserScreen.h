#pragma once
#include <string>
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsScreen.h"



class clsUpdateUserScreen : protected clsScreen
{
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
	static void _PrintUserToUpdate(clsUser User) {
		cout << "\nInfo:\n";
		cout << "____________________\n";
		cout << "[1] FirstName  : " << User.GetFirstName() << endl;
		cout << "[2] ListName   : " << User.GetListName() << endl;
		cout << "[3] Email      : " << User.GetEmail() << endl;
		cout << "[4] Phone      : " << User.GetPhone() << endl;
		cout << "[5] Password   : " << User.GetPassword() << endl;
		cout << "[6] Permissoins: " << User.GetPermissions() << endl;
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
			Permissions += (clsUser::pManageUsers);
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
	static void _UpdateDateInObject(clsUser& User)
	{
		char UpdateAllDate;
		cout << "Update All Date Y/N? ";
		cin >> UpdateAllDate;
		if (toupper(UpdateAllDate) == 'Y')
		{
			cout << "\n\nUpdate User Info\n";
			cout << "_______________________\n\n";
			_RadeUserInfo(User);
			return;
		}

		system("cls");
		_DrawScreenHeader1("Update User Screen");
		_PrintUserToUpdate(User);


		cout << "Place enter Choise [1 To 6] To Update: ";
		short Choise = clsInputValidate::RadeNumberBetween <short>(1, 6);

		switch (Choise)
		{

		case 1:
			cout << "\nEnter a First Name: ";
			User.SatFirstName(clsInputValidate::RadeString());
			break;

		case 2:
			cout << "\n Enter a List Name: ";
			User.SatListName(clsInputValidate::RadeString());
			break;

		case 3:
			cout << "\n Enter a Email: ";
			User.SatEmail(clsInputValidate::RadeString());
			break;

		case 4:
			cout << "\n Enter a Phone Number: ";
			User.SatPhone(clsInputValidate::RadeString());
			break;

		case 5:
			cout << "\n Enter a Password: ";
			User.SetPassword(clsInputValidate::RadeString());
			break;

		case 6:
			cout << "\n Enter a Permissions: ";
			User.SetPermissions(_RadePermissionsToSat());
			break;

		}

	}

public:
	static void ShowUpdateUserScreen() {

		_DrawScreenHeader1("   Update User Screen");

		cout << "Place Enter a UserName: ";
		string UserName = clsInputValidate::RadeString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "!User Not Found entered again: ";
			UserName = clsInputValidate::RadeString();
		}

		clsUser User = (clsUser::Find(UserName));
		_PrintUser(User);

		char Confirem;
		cout << "Are you sure want to update User Y/N? ";
		cin >> Confirem;

		if (toupper(Confirem) == 'Y')
		{
			_UpdateDateInObject(User);

		}
		else {
			cout << "\n!You Canseld Update User \n";
			return;
		}

		clsUser::enSaveResults SaveResult;

		SaveResult = User.Save();

		switch (SaveResult)
		{
		case clsUser::svFaildEmptyObject:
			cout << "\n!The operation failed, please try again.\n\n";
			break;
		case clsUser::svSucceeded:
			cout << "\nThe operation was completed successfully :-)\n\n";
			_PrintUser(User);
			break;
		}

	}

};

