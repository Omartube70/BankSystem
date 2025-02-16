#pragma once
#include <string>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

class clsManageUsersScreen : protected clsScreen
{

private:
	enum enManageUsersMeuneOptions {
		enUserList = 1, enAddNewUser = 2, enDelateUser = 3, enUpdateUser = 4
		, enFindUser = 5
		, enMainMeune = 6
	};


	static short _RadeManageUsersMeuneOption()
	{
		cout << Clbs(5) << "     Choose what do you want to do ?[1 to 6]: ";
		return clsInputValidate::RadeNumberBetween <short> (1, 6, "!Place enter number Between 1 To 6\n");
	}
	static void _BackToManageUsersMeuna()
	{
		cout << "\tPress any key to Back Mange Users Meune . . . ";
		system("pause>0");
		_ShowManageUsersScreen();
	}


	static void _ShowListUserScreen()
	{
		//cout << "\nList User Will be Here\n";
		clsListUsersScreen::ShowUsersList();
	}
	
	static void _ShowAddNewUserScreen()
	{
		//cout << "\nAdd New User Will be Here\n";
		clsAddNewUserScreen::ShowAddNewUser();
	}
	  
	static void _ShowDeleteUserScreen()
	{
		//cout << "\nDelete User Will be Here\n";
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		//cout << "\nUpdate User Will be Here\n";
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		//cout << "\nFind User Will be Here\n";
		clsFindUserScreen::ShowFindUserScreen();
	}


	static void _PerformMainMeunaOption(enManageUsersMeuneOptions ManageUsersMeuneOptions)
	{
		switch (ManageUsersMeuneOptions)
		{
		case enUserList:
			system("cls");
			_ShowListUserScreen();
			_BackToManageUsersMeuna();
			break;

		case enAddNewUser:
			system("cls");
			_ShowAddNewUserScreen();
			_BackToManageUsersMeuna();
			break;

		case enDelateUser:
			system("cls");
			_ShowDeleteUserScreen();
			_BackToManageUsersMeuna();
			break;

		case enUpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			_BackToManageUsersMeuna();
			break;

		case enFindUser:
			system("cls");
			_ShowFindUserScreen();
			_BackToManageUsersMeuna();
			break;

		case enMainMeune:
			cout << Clbs(5);
			break;

		}

	}
	static void _ShowManageUsersScreen()
	{


		if (!ChackAccessRigth(clsUser::pManageUsers))
		{
			return;
		}

		system("cls");
		_DrawScreenHeader1("   Manage Users Screen");
		_DrawScreenHeader("\t  Manage Users Menue Screen");
		cout << Clbs(6) << "  [1] List Users.\n";
		cout << Clbs(6) << "  [2] Add New User.\n";
		cout << Clbs(6) << "  [3] Delete User.\n";
		cout << Clbs(6) << "  [4] Update User.\n";
		cout << Clbs(6) << "  [5] Find User.\n";
		cout << Clbs(6) << "  [6] Main Menue.\n";
		cout << Clbs(5) << "     =========================================\n";
		_PerformMainMeunaOption((enManageUsersMeuneOptions)_RadeManageUsersMeuneOption());
	}

public:

	static void ShowManageUsersMeune()
	{

		_ShowManageUsersScreen();
	}

};

