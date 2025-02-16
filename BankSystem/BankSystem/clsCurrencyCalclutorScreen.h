#pragma once
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsString.h"
#include <iomanip>

class clsCurrencyCalclutorScreen : protected clsScreen
{

private:

	static float _RadeAmount()
	{
		cout << "\nEnter Amount to Exchange: ";
		return clsInputValidate::RadeNumber <float>();
	}

	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "______________________\n\n";
		cout << "Country    : " << Currency.Country() << endl;
		cout << "Code       : " << Currency.CurrencyCode() << endl;
		cout << "Name       : " << Currency.CurrencyName() << endl;
		cout << "Rate(1$) = : " << Currency.Rate() << endl;
		cout << "\n______________________\n\n";
	}

	static clsCurrency _GetCurrency(string Messge) 
	{
		string CurrencyCode;
		cout << endl << Messge;
		CurrencyCode = clsInputValidate::RadeString();

		while (!clsCurrency::IsCurrencyExistCurrencyCode(CurrencyCode))
		{
			cout << "!Currency Was Not Found entered again: ";
			CurrencyCode = clsInputValidate::RadeString();
		}
			
		return clsCurrency::FindByCode(CurrencyCode);
	}

	static void _PrintCalclationstResults(float Amount , clsCurrency CurrencyFrom , clsCurrency CurrencyTo)
	{


		if (CurrencyFrom.Country() == CurrencyTo.Country())
		{
			cout << "\nCurrency From Is Epcal Currency To\n";
			return;
		}

		cout << "\nConvert From:\n";
		_PrintCurrencyCard(CurrencyFrom);

		cout << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << CurrencyFrom.ConvertToUSD(Amount) << " USD" << "\n";


		if ((CurrencyTo.CurrencyCode() != "USD"))
		{
			cout << "\nConfverting From USD to:\n";
			cout << "\nTo:\n";
			_PrintCurrencyCard(CurrencyTo);
			cout << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << CurrencyFrom.ConvertToOtherCurrency(Amount, CurrencyTo) << " " << CurrencyTo.CurrencyCode() << "\n\n";
		}


	}

public:

	static void ShowCurrencyClaclutorScrren()
	{
		/*
		if (!ChackAccessRigth(clsUser::pListClient))
		{
			return;
		}
		*/

		char Contine = 'y';

		while ( Contine == 'Y' || Contine == 'y')
		{
			system("cls");
			_DrawScreenHeader1("Claclutor Currency Screen");

			clsCurrency CurrencyFrom = _GetCurrency("Please Enter Currency1 Code: ");
			clsCurrency CurrencyTo   = _GetCurrency("Please Enter Currency2 Code: ");

			float Amount = _RadeAmount();

			_PrintCalclationstResults(Amount, CurrencyFrom, CurrencyTo);


			cout << "Do You want to Perfrom another Calclation? Y/N? ";
			Contine = (clsInputValidate::RadeChar());
		}
	}
};

