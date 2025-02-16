#pragma once
#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "Global.h"
#include "clsMeunaScreen.h"

class clsLoginScreen : clsScreen
{
private:

	static void _Login()
	{
		short Trials = 3;
		string UserName;
		string Password;
		bool LoginFaild = false;

		do {

			if (LoginFaild)
			{
				cout << "\n!Invaild UserName/Password\n";
				cout << "You Have " << --Trials << " Trials to login.\n\n";
				if (Trials == 0)
				{
					system("cls");
					_DrawScreenHeader1("Locked Secssfully Concet To Admin To UnLocked :-)");
					cout << "\n\nYour are Locked after 3 faild trials\n";
					Locked = true;
					SaveLockedToFile(Locked);
					return;
				}
			}

			cout << "Enter a UserName? ";
			cin >> UserName;

			cout << "Enter a Password? ";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFaild = CurrentUser.IsEmpty();
		} while (LoginFaild );
		

		CurrentUser.RegisterLogIn();
		Trials = 3;
		clsMeunaScreen::ShowMeuneScreen();
	}

public:
	static void ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader1("   Login Screen");
		_Login();
	}


};

