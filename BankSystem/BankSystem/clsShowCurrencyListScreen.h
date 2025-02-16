#pragma once
#include "clsCurrency.h"
#include "clsScreen.h"
#include <iomanip>

class clsShowCurrencyListScreen : protected clsScreen
{

	private:

		static void _PrintCurrencyRecordLine(clsCurrency Currency)
		{
			cout << setw(8) << left << "" << "| " << setw(27) << left << Currency.Country();
			cout << "| " << setw(8) << left << Currency.CurrencyCode();
			cout << "| " << setw(45) << left << Currency.CurrencyName();
			cout << "| " << setw(0) << left << Currency.Rate();
		}

public:
		static void ShowCurrencyList()
		{
			vector <clsCurrency> Currencies = clsCurrency::GetCurrenciesList();
			system("cls");

			clsScreen::_DrawScreenHeader1(" Currencies List Screen", " (" + to_string(Currencies.size()) + ") Currency.");

			cout << setw(8) << left << "" << "\n\t_____________________________________________________________";
			cout << "_________________________________________\n" << endl;

			cout << setw(8) << left << "" << "| " << left << setw(27) << "Country";
			cout << "| " << left << setw(8) << "Code";
			cout << "| " << left << setw(45) << "Name";
			cout << "| " << left << setw(0) << "Rate/(1$)";


				cout << setw(8) << left << "" << "\n\t_____________________________________________________________";
			cout << "_________________________________________\n" << endl;


			if (Currencies.size() == 0)
				cout << "\t\t\tNo Currenciies Availble In The Systeem!\n";

			else {

				for (clsCurrency& C : Currencies) {


					_PrintCurrencyRecordLine(C);
					cout << endl;

				}

			}



			cout <<
				"\t_____________________________________________________________";
			cout << "_________________________________________\n" << endl;

		}


};

