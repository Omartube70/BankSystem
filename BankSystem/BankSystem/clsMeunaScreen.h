#pragma once
#include <string>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsMeuneScreen.h"
#include "clsManageUsersScreen.h"
#include "Global.h"
#include "clsLoginRsgisterListScreen.h"
#include "clsMainCurrencyScreen.h"

using namespace std;



class clsMeunaScreen : protected clsScreen
{

private:

	enum enMainMeuneOptions { enClientList = 1, enAddNewClient = 2 , enDelateClient = 3 , enUpdateClient = 4 
	, enFindClient = 5 , enTransactions = 6 , enManageUsers = 7 , eLoginRegister = 8, eCurrencyMain = 9, enExit = 10
	};


	static short _RadeMainMeuneOption()
	{
		cout << Clbs(5) << "     Choose what do you want to do ?[1 to 10]: ";
		return clsInputValidate::RadeNumberBetween <short>(1, 10, "!Place enter number Between 1 To 10\n");
	}

	static void _BackToMainMeuna()
	{
		cout << "\tPress any key to Back Main Meune . . . ";
		system("pause>0");
		_MainMeuneScreen();
	}

	static void _ShowClientList()
	{
		//cout << "\tClient List will be here\n";
		clsClientListScreen::ShowClientList();
	}

	static void _ShowAddNewClientScreen()
	{
		//cout << "\tAdd New Client will be here\n";
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _ShowDelateClientScreen()
	{
		//cout << "\tDelate Client will be here\n";
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientScreen()
	{
		//cout << "\tUpdate Client will be here\n";
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen()
	{
		//cout << "\tFind Client will be here\n";
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsScreen()
	{
		//cout << "\tTransactions will be here\n";
		clsTransactionsMeuneScreen::ShowTransactionsMeune();
	}

	static void _ShowManageUsersScreen()
	{
		//cout << "\tMange Users will be here\n";
		clsManageUsersScreen::ShowManageUsersMeune();
	}

	static void _ShowLoginRegisterScreen()
	{
		clsLoginRsgisterListScreen::ShowLoginRegisterList();
	}

	static void _ShowCurrencyScreen()
	{
		clsMainCurrencyScreen::ShowMeuneCurrencyScreen();
	}

	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");
	}


	static void _PerformMainMeunaOption(enMainMeuneOptions MainMeuneOptions)
	{
		switch (MainMeuneOptions)
		{

		case clsMeunaScreen::enClientList:
			system("cls");
			_ShowClientList();
			_BackToMainMeuna();
			break;

		case clsMeunaScreen::enAddNewClient:
			system("cls");
			_ShowAddNewClientScreen();
			_BackToMainMeuna();
			break;

		case clsMeunaScreen::enDelateClient:
			system("cls");
			_ShowDelateClientScreen();
			_BackToMainMeuna();
			break;

		case clsMeunaScreen::enUpdateClient:
			system("cls");
			_ShowUpdateClientScreen();
			_BackToMainMeuna();
			break;

		case clsMeunaScreen::enFindClient:
			system("cls");
			_ShowFindClientScreen();
			_BackToMainMeuna();
			break;

		case clsMeunaScreen::enTransactions:
			system("cls");
			_ShowTransactionsScreen();
			_BackToMainMeuna();
			break;

		case clsMeunaScreen::enManageUsers:
			system("cls");
			_ShowManageUsersScreen();
			_BackToMainMeuna();
			break;

		case clsMeunaScreen::eLoginRegister:
			system("cls");
			_ShowLoginRegisterScreen();
			_BackToMainMeuna();
			break;

		case clsMeunaScreen::eCurrencyMain:
			system("cls");
			_ShowCurrencyScreen();
			_BackToMainMeuna();
			break;

		case clsMeunaScreen::enExit:
			system("cls");
			_Logout();
			break;

		}
	}
	static void _MainMeuneScreen()
	{
		system("cls");
		_DrawScreenHeader1("      Main Screen");
		_DrawScreenHeader("\t         Main Meune");
		cout <<  Clbs(6)  << "  [1] Show Client List.\n";
		cout <<  Clbs(6)  << "  [2] Add New Client.\n";
		cout <<  Clbs(6)  << "  [3] Delete Client.\n";
		cout <<  Clbs(6)  << "  [4] Update Client Info.\n";
		cout <<  Clbs(6)  << "  [5] Find Client.\n";
		cout <<  Clbs(6)  << "  [6] Transactions.\n";
		cout <<  Clbs(6)  << "  [7] Manage Users.\n";
		cout <<  Clbs(6)  << "  [8] Login Register.\n";
		cout <<  Clbs(6)  << "  [9] Currency Exchange.\n";
		cout <<  Clbs(6)  << "  [10] Logout.\n";
		cout <<  Clbs(5)  << "     =========================================\n";
		_PerformMainMeunaOption((enMainMeuneOptions)_RadeMainMeuneOption());
	}


public:

	static void ShowMeuneScreen()
	{
		_MainMeuneScreen();
	}

};

