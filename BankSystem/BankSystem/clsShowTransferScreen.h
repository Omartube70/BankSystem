#pragma once
#include <string>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsBankClient.h"



class clsShowTransferScreen : protected clsScreen
{


private:
	static string _RadeAcountNumber(string Messge)
	{
		cout << Messge;
		return clsInputValidate::RadeString();
	}

	static void _PrintClientCardShort(clsBankClient Client)
	{
		cout << "\nClient Card:\n";
		cout << "___________________\n\n";
		cout << "Full Name   : " << Client.FullName() <<endl;
		cout << "Aco. Number : " << Client.GetAcountNumber() << endl;
		cout << "Aco. Blance : " << Client.GetAcountBlance() << endl;
		cout << "\n___________________\n\n";
	}

	static clsBankClient _RadeClient(string Meessge)
	{
		string AcountNumber = _RadeAcountNumber(Meessge);
		while (!clsBankClient::IsClientExist(AcountNumber))
		{
			cout << "!Client Not Found entered again: \n";
			AcountNumber = _RadeAcountNumber(Meessge);
		}
		clsBankClient Client = (clsBankClient::Find(AcountNumber));
		return Client;
	}

public:

	static void ShowTransferScreen()
	{
		system("cls");
		_DrawScreenHeader1("      Transfer Screen");


           clsBankClient ClientFrom = _RadeClient("\n\nPlease Enter Acount Number to Transfer From : ");
		   _PrintClientCardShort(ClientFrom);

		   clsBankClient ClientTo = _RadeClient("\n\nPlease Enter Acount Number to Transfer To : ");
		   _PrintClientCardShort(ClientTo);


		   if (ClientFrom.GetAcountNumber() == ClientTo.GetAcountNumber())
		   {
			   cout << "\n!Acount From Is Epcal Acount To\n";
			   return;
		   }

		   cout << "Enter Transfer Amount? ";
		   double TransferAmount = clsInputValidate::RadeNumber <double>();

		   while (TransferAmount > ClientFrom.GetAcountBlance())
		   {
			   cout << "Amount Exceeds the Available Balance, Enter another Amount ? ";
			   TransferAmount = clsInputValidate::RadeNumber <double>();
		   }


		   

		   char Confirem;
		   cout << "\nAre you sure want to perform this Transactions Y/N? ";
		   cin >> Confirem;

		   if (toupper(Confirem) == 'Y')
		   {
			   if (ClientFrom.Transfer(ClientTo, TransferAmount))
			   {
				   cout << "\nTransfer Done Successfull :-)\n";
			   }
			   else {
				   cout << "\n!Transfer Done Faild \n";
			   }
		   }
		   else {
			   cout << "\nOperation was cancelled.\n";
		   }

		   cout << endl;
		   _PrintClientCardShort(ClientFrom);
		   _PrintClientCardShort(ClientTo);

	}


};

