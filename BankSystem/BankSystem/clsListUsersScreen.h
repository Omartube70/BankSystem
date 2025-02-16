#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsBankClient.h"
using namespace std;


class clsListUsersScreen : protected clsScreen
{

private:

	static void PrintUserRecordLine(clsUser User)
	{
		cout << setw(8) << left << "" << "| " << setw(12) << left << User.GetUserName();
		cout << "| " << setw(25) << left << User.FullName();
		cout << "| " << setw(12) << left << User.GetPhone();
		cout << "| " << setw(20) << left << User.GetEmail();
		cout << "| " << setw(10) << left << User.GetPassword();
		cout << "| " << setw(12) << left << User.GetPermissions();
	}

public:
	static void ShowUsersList()
	{
		vector <clsUser> Users = clsUser::GetUsersList();
		system("cls");
		clsScreen::_DrawScreenHeader1("   Users List Screen", "   (" + to_string(Users.size()) + ") User(s).");

		cout << setw(8) << left << "" << "\n\t_____________________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
		cout << "| " << left << setw(25) << "Full Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(12) << "Parmissons";
	

			cout << setw(8) << left << "" << "\n\t_____________________________________________________________";
		cout << "_________________________________________\n" << endl;


		if (Users.size() == 0)
			cout << "\t\t\tNo Users Availble In The Systeem!\n";

		else {

			for (clsUser & C : Users) {

				
				PrintUserRecordLine(C);
				cout << endl;

			}

		}



		cout <<
			"\t_____________________________________________________________";
		cout << "_________________________________________\n" << endl;

	}


};

