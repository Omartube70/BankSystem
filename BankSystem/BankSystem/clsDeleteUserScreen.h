#pragma once
#include <string>
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

class clsDeleteUserScreen : protected clsScreen
{
private:
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
	

public:

	static void ShowDeleteUserScreen()
	{

		clsScreen::_DrawScreenHeader1("   Delete User Screen");

		cout << "Place Enter a UserName : ";
		string UserName = clsInputValidate::RadeString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "!User Not Found enter again: ";
			UserName = clsInputValidate::RadeString();
		}

		clsUser User = (clsUser::Find(UserName));

		_PrintUser(User);

		cout << "\nYou are Sure To Dalete this User Y/N? ";
		char ConfireamDalete = clsInputValidate::RadeChar();


		if (toupper(ConfireamDalete) == 'Y')
		{

			if (User.Delete())
			{
				system("cls");
				cout << "\nUser Deleted successfully :-)\n";
				_PrintUser(User);
			}
			else {
				cout << "\n!Not Delated User place try again\n";
			}

		}
		else {
			cout << "\n!You Canseld Delete User From Date\n";
		}


	}


};




