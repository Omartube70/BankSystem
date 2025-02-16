#pragma once
#include <string>
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include <iomanip>


class clsLoginRsgisterListScreen : protected clsScreen
{

	static void _PrintUserLoginRecordLine(clsUser::stLoginRegister User)
	{
		cout << setw(8) << left << "" << "| " << setw(35) << left << User.Date_Time;
		cout << "| " << setw(20) << left << User.Username;
		cout << "| " << setw(20) << left << User.Password;
		cout << "| " << setw(10) << left << User.Permissions;
	}

public:
	static void ShowLoginRegisterList()
	{

		if (!clsScreen::ChackAccessRigth(clsUser::pLoginRegister))
		{
			return;
		}

		vector <clsUser::stLoginRegister> Users = clsUser::GetLoginRegisterList();

		system("cls");
		clsScreen::_DrawScreenHeader1("   Login Register List Screen", "   (" + to_string(Users.size()) + ") Record(s).");

		cout << setw(8) << left << "" << "\n\t_____________________________________________________________";
		cout << "_________________________________________\n" << endl;


		cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
		cout << "| " << left << setw(20) << "UserName";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(10) << "Permissions";


		cout << setw(8) << left << "" << "\n\t_____________________________________________________________";
		cout << "_________________________________________\n" << endl;


		if (Users.size() == 0)
			cout << "\t\t\tNo Login Register Availble In The Systeem!\n";

		else {

			for (clsUser::stLoginRegister& C : Users) {

				_PrintUserLoginRecordLine(C);
				cout << endl;
			}

		}



		cout <<
			"\t_____________________________________________________________";
		cout << "_________________________________________\n" << endl;

	}



};

