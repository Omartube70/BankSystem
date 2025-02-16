#pragma once
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>


class clsUpdateCurrencyScreen : protected clsScreen
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

	static float _UpdateCurrencyRate()
	{
		cout << "\nUpdate Currency Rate:\n";
		cout << "_____________________\n";
		cout << "\nEnter New Rate: ";
		return clsInputValidate::RadeNumber <double>();
	}

public:

	static void ShowUpdateCurrencyScreen()
	{

		/*
		if (!ChackAccessRigth(clsUser::pListClient))
		{
			return;
		}
		*/
		_DrawScreenHeader1("   Update Currency Screen");

		cout << "Please Enter Currency Code: ";
		string CurrencyCode = clsInputValidate::RadeString();

		while (!clsCurrency::IsCurrencyExistCurrencyCode(CurrencyCode))
		{
			cout << "!Currency Was Not Found entered again: ";
			CurrencyCode = clsInputValidate::RadeString();
		}


		clsCurrency Currency = (clsCurrency::FindByCode(CurrencyCode));
		_PrintCurrencyCard(Currency);


		cout << "Are you Sure you want to Update the rate this Currency Y/N? ";
		if(toupper(clsInputValidate::RadeChar()) == 'Y')
		{
			if(Currency.UpdateRate(_UpdateCurrencyRate()))
			{
				cout << "\nCurrency Rate Updated Successfully :-)\n";
				_PrintCurrencyCard(Currency);
			}
			else {
				cout << "\nCurrency Rate Was Not Compleat Pleaes Try Agin";
			}
		}
	}

};

