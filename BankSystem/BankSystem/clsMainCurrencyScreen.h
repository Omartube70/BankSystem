#pragma once
#include <iostream>
#include "clsShowCurrencyListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyScreen.h"
#include "clsCurrencyCalclutorScreen.h"
using namespace std;


class clsMainCurrencyScreen : protected clsScreen
{

private:

	enum enMainCurrencyOptions {
		enCurrencyList = 1, enFindCurrency = 2, enUpdateRate = 3 , enCurrencyCalculator, enExit = 5
	};

	static short _RadeMeuneCurrencyOption()
	{
		cout << Clbs(5) << "     Choose what do you want to do ?[1 to 5]: ";
		return clsInputValidate::RadeNumberBetween <short>(1, 5, "!Place enter number Between 1 To 5\n");
	}

	static void _BackToMeunaCurrency()
	{
		cout << "\tPress any key to Back Main Currency . . . ";
		system("pause>0");
		_ShowMeuneCurrencyScreen();
	}

	static void _ShowCurrencyListScreen()
	{
		//cout << "\nCurrency List Will Be Here" <<endl;
		clsShowCurrencyListScreen::ShowCurrencyList();
	}

	static void _ShowFindCurrencyScreen()
	{
		//cout << "\nFind Currency Will Be Here" << endl;
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		//cout << "\n Update Rate Will Be Here" << endl;
		clsUpdateCurrencyScreen::ShowUpdateCurrencyScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		//cout << "\nCurrency Calclutor  Will Be Here" << endl;
		clsCurrencyCalclutorScreen::ShowCurrencyClaclutorScrren();
	}




	static void _PerformMeuneOption(enMainCurrencyOptions MainCurrencyOptions)
	{ 
		switch (MainCurrencyOptions)
		{
		case clsMainCurrencyScreen::enCurrencyList:
			system("cls");
			_ShowCurrencyListScreen();
			_BackToMeunaCurrency();
			break;

		case clsMainCurrencyScreen::enFindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			_BackToMeunaCurrency();
			break;

		case clsMainCurrencyScreen::enUpdateRate:
			system("cls");
			_ShowUpdateRateScreen();
			_BackToMeunaCurrency();
			break;

		case clsMainCurrencyScreen::enCurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_BackToMeunaCurrency();
			break;

		case clsMainCurrencyScreen::enExit:
			cout << Clbs(5);
			break;

		}

	}


	static void _ShowMeuneCurrencyScreen()
	{
		system("cls");
		_DrawScreenHeader1("Currency Exchange Main Screen");
		_DrawScreenHeader("\t       Currency Exchange Meune");
		cout << Clbs(6) << "  [1] List Currencies.\n";
		cout << Clbs(6) << "  [2] Find Currency.\n";
		cout << Clbs(6) << "  [3] Update Rate.\n";
		cout << Clbs(6) << "  [4] Currency Calculator.\n";
		cout << Clbs(6) << "  [5] Main Menue.\n";
		cout << Clbs(5) << "     =========================================\n";
		_PerformMeuneOption((enMainCurrencyOptions)_RadeMeuneCurrencyOption());
	}



public:

	static void ShowMeuneCurrencyScreen()
	{
		_ShowMeuneCurrencyScreen();
	}


};

