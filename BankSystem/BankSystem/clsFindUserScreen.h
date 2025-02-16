#pragma once
#include <string>
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsScreen.h"


class clsFindUserScreen : protected clsScreen
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




public:

	static void ShowFindUserScreen()
	{
		_DrawScreenHeader1("   Find User Screen");

		cout << "Place Enter a UsarName: ";
		string UserName = clsInputValidate::RadeString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "!User Not Found entered again: ";
			UserName = clsInputValidate::RadeString();
		}

		clsUser User = (clsUser::Find(UserName));


		if (User.IsUserExist(UserName))
		{
			cout << "\nUser Found :-)\n";
			_PrintUser(User);
		}
		else {
			cout << "\n!User Not Found\n";
		}

	}

};

