#pragma once
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>


class clsFindCurrencyScreen : protected clsScreen
{
private:

	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "______________________\n\n";
		cout << "Country    : " << Currency.Country() << endl;
		cout << "Code       : " << Currency.CurrencyCode() << endl;
		cout << "Name       : " << Currency.CurrencyName() << endl;
		cout << "Rate(1$) = : " << Currency.Rate() << endl;
		cout << "\n______________________\n\n";
	}


public:


	static void ShowFindCurrencyScreen()
	{

		/*
		if (!ChackAccessRigth(clsUser::pListClient))
		{
			return;
		}
		*/

	    	_DrawScreenHeader1("   Find Currency Screen");


			cout << "\nPlease Enter [Currency Code / Country Name] ? : ";
			string CurrencyKay = clsInputValidate::RadeString();

			while (!(clsCurrency::IsCurrencyExistCurrencyCode(CurrencyKay) || clsCurrency::IsCurrencyExistCountry(CurrencyKay)))
			{
				cout << "!Currency Was Not Found entered again: ";
				CurrencyKay = clsInputValidate::RadeString();
			}


			clsCurrency Currency = (clsCurrency::FindByKay(CurrencyKay));	
			_PrintCurrencyCard(Currency);
		

	}


};

