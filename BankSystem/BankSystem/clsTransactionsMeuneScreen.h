#pragma once
#include <string>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBlancesScreen.h"
#include "clsShowTransferScreen.h"
#include "clsShowTransferLogScreen.h"



class clsTransactionsMeuneScreen : protected clsScreen
{
private:

	enum  enTransactionsOptions
	{   eDeposit = 1
		,eWithdraw = 2
		,eTotalBlances = 3
		,eTransfer = 4
		,eShowTransferLog = 5
		,eMainMeune = 6
	};
	
	static short _RadeTransactionsMeuneOption()
	{
		cout << Clbs(5) << "     Choose what do you want to do ?[1 to 6] : ";
		return clsInputValidate::RadeNumberBetween <short> (1, 6, "!Place enter number Between 1 To 6\n");
	}

	static void _GoToBackTransactionsMenue()
	{
		cout << "\tPress any key to Back Transactions Meune . . . ";
		system("pause>0");
		_TransactionsMeuneScreen();
	}
	
	static void _ShowDepositScreen()
	{
		//cout << "\nDeposit Screen Will Be here\n";
		clsDepositScreen::ShowDepoitScreen();
	}

	static void _ShowWithdrawScreen()
	{
		//cout << "\nWithdraw Screen Will Be here\n";
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBlancesScreen()
	{
		//cout << "\nTotal Blances Screen Will Be here\n";
		clsTotalBlancesScreen::ShowTotalBlances();
	}

	static void _ShowTransferScreen()
	{
		clsShowTransferScreen::ShowTransferScreen();
	}

	static void _ShowRigsterTransferLogScreen()
	{
		clsShowTransferLogScreen::ShowTransferRegisterList();
	}


	static void _PerformTransactionsOptions(enTransactionsOptions TransactionsOptions)
	{

		switch (TransactionsOptions)
		{
		case clsTransactionsMeuneScreen::eDeposit:
			system("cls");
			_ShowDepositScreen();
			_GoToBackTransactionsMenue();
			break;

		case clsTransactionsMeuneScreen::eWithdraw:
			system("cls");
			_ShowWithdrawScreen();
			_GoToBackTransactionsMenue();
			break;

		case clsTransactionsMeuneScreen::eTotalBlances:
			system("cls");
			_ShowTotalBlancesScreen();
			_GoToBackTransactionsMenue();
			break;

		case clsTransactionsMeuneScreen::eTransfer:
			system("cls");
			_ShowTransferScreen();
			_GoToBackTransactionsMenue();
			break;


		case clsTransactionsMeuneScreen::eShowTransferLog:
			system("cls");
			_ShowRigsterTransferLogScreen();
			_GoToBackTransactionsMenue();
			break;

		case clsTransactionsMeuneScreen::eMainMeune:
			cout << Clbs(5);
			break;


		}
		
	}
	static void _TransactionsMeuneScreen()
	{

		if (!ChackAccessRigth(clsUser::pTransactions))
		{
			return;
		}

		system("cls");
	   _DrawScreenHeader1("   Transactions Screen");
	   _DrawScreenHeader("\tTransactions Menue Screen");
		cout << Clbs(6) << "  [1] Deposit.\n";
		cout << Clbs(6) << "  [2] Withdraw.\n";
		cout << Clbs(6) << "  [3] Total Balnces.\n";
		cout << Clbs(6) << "  [4] Transfer.\n";
		cout << Clbs(6) << "  [5] Transfer Log.\n";
		cout << Clbs(6) << "  [6] Main Menue.\n";
		cout << Clbs(5) << "     ===========================================\n";		
		_PerformTransactionsOptions( (enTransactionsOptions) _RadeTransactionsMeuneOption());
	}

public:

	static void ShowTransactionsMeune()
	{
		_TransactionsMeuneScreen();
	}

};

