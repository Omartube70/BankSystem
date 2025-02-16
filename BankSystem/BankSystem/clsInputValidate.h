#pragma once
#include <iostream>
#include <string>
using namespace std;

class clsInputValidate
{

public:



	 template <typename T> static T IsNumberBetween(T Number , T From , T To )
	{
		 return (Number >= From && Number <= To);
	}

	 template <typename T> static T RadeNumber()
	{
		T Number = 0;
		cin >> Number;
		while (cin.fail() || Number <= 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "!Invalid Number, Enter Agin?\n" << endl;
			cin >> Number;
		}

		return Number;
	}
	 template <typename T> static T RadeNumberBetween(T From, T To , string MessgeError = "!Place enter number Between\n")
	{
		T Number = 0;
		do {
			Number = RadeNumber<T>();

		} while (!(Number >= From && Number <= To));
		return Number;
	}


	static string RadeString()
	{
		string S1;
		getline(cin >> ws, S1);
		return S1;
	}
	static char RadeChar()
	{
		char S1;
		cin >> S1;
		return S1;
	}


};

