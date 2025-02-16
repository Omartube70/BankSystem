#pragma once
#include <iostream>
#include "Global.h"
#include "clsDate.h"
using namespace std;

class clsScreen
{

protected:

	static void _DrawScreenHeader1(string Title, string SubTitle = "")
	{
		cout << endl << Clbs(5) << "     ______________________________________";
		cout << "\n\n" << Clbs(6) << "     " << Title;
		if (SubTitle != "")
		{
			cout << endl << Clbs(6) << "        " << SubTitle;
	    }
		cout << endl << Clbs(5) << "     ______________________________________\n\n";


		cout << Clbs(5) << "     User: " << CurrentUser.GetUserName() << endl;
		cout << Clbs(5) << "     Date: " << clsDate::DateToString(clsDate()) <<endl;
		cout << Clbs(5) << "     Time: " << clsDate::GetTimeHours() << endl;

	}

	static void _DrawScreenHeader(string Title)
	{
	cout << endl << Clbs(5) << "     =========================================";
	cout << endl << Clbs(5) << "   " << Title;
	cout << endl << Clbs(5) << "     =========================================\n";
	}

	static string Clbs(short Num = 1)
	{
		string Clbs = "";
		for (short i = 1 ; i < Num; i++)
		{
			Clbs += "\t";
		}
		return Clbs;
	}


	static bool ChackAccessRigth(clsUser::enPermissions Permissions)
	{
		if (!CurrentUser.ChackAccessPermissions(Permissions))
		{
			_DrawScreenHeader("\tAccess Denied! Concet Your Admin");
			cout << "\n";
			return false;
		}

		else {
			return true;
		}

	}

};

