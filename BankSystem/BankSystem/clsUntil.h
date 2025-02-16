#pragma once
#include <iostream>
#include <vector>
#include "clsDate.h"
#include "clsUser.h"
using namespace std;


class clsUntil
{

private:

public:

	static void Srand() {
		srand((unsigned)time(NULL));
	}

	enum enCrecter { Smail = 1, Keptel = 2, Number = 3, digit = 4, MixChars = 5 };


	//srand((unsigned)time(NULL));
	static int RandomNumber(int From, int To)
	{
		//Function to generate a random number
		return (rand() % (To - From + 1) + From);
	}


	static char Random_Number_or_Char_or_digit(enCrecter Crecter) {
		switch (Crecter) {

		case enCrecter::Smail:
			return char(RandomNumber(97, 122));

		case enCrecter::Keptel:
			return char(RandomNumber(65, 90));

		case enCrecter::Number:
			return RandomNumber(48, 57);

		case enCrecter::digit:
			return char(RandomNumber(33, 47));

		case enCrecter::MixChars:
			return Random_Number_or_Char_or_digit((enCrecter)RandomNumber(1, 4));
			
		default:
			return 'F';
		}
	}


	static string GenretWord(enCrecter Crecter = enCrecter::MixChars, short length_Char = 4) {
		string word ;
		for (int i = 1; i <= length_Char; i++) {
			word += Random_Number_or_Char_or_digit(Crecter);
		}
		return word;
	}


	static string GenretKay(enCrecter Crecter = enCrecter::MixChars, short length_Char = 4, short lenth_Words = 4) {
		string Kay = "";

		for (int i = 1; i <= lenth_Words; i++) {
			Kay += GenretWord(Crecter, length_Char);
			if (i != 4) {
				Kay += "-";
			}
		}
		return Kay;
	}


	static vector <string>  GenretKays(enCrecter Crecter = enCrecter::MixChars, short length_Char = 4, short lenth_Words = 4, int Length_Kays = 10) {

		vector <string> vKays;
		for (int i = 1; i <= Length_Kays; i++) {
			vKays.push_back(GenretKay(Crecter, length_Char, lenth_Words));
		}
		return vKays;
	}


	static void PrintKays(enCrecter Crecter = enCrecter::MixChars, short length_Char = 4, short lenth_Words = 4, int Length_Kays = 10) {
		vector <string> vKays = GenretKays(Crecter, length_Char, lenth_Words, Length_Kays);
		int Id = 0;
		for (string& S1 : vKays)
		{
			cout << "Kay [" << ++Id << "] : " << S1 << "\n";
		}


	}


	static void swap(int& number1, int& number2)
	{
		int temp;

		temp = number1;
		number1 = number2;
		number2 = temp;
	}

	static void swap(double& number1, double& number2)
	{
		double temp;

		temp = number1;
		number1 = number2;
		number2 = temp;
	}

	static void swap(bool& flag1, bool& flag2)
	{
		bool temp;

		temp = flag1;
		flag1 = flag2;
		flag2 = temp;
	}

	static void swap(string& text1, string& text2)
	{
		string temp;

		temp = text1;
		text1 = text2;
		text2 = temp;
	}

	static void swap(clsDate& Date1, clsDate& Date2)
	{
		clsDate temp;
		temp = Date1;
		Date1 = Date2;
		Date2 = temp;
	}

	static void shuffleArray(int arr[], int length)
	{
		for (int i = 0; i < length; i++)
		{

			swap(arr[RandomNumber(0, length - 1)],
				arr[RandomNumber(0, length - 1)]);
		}
	}

	static void shuffleArray(string arr[], int length)
	{
		for (int i = 0; i < length; i++)
		{

			swap(arr[RandomNumber(0, length - 1)],
				arr[RandomNumber(0, length - 1)]);
		}
	}

	static void fillArrayWithRandomNumbers(int arr[], int length, int from, int to)
	{
		for (int i = 0; i < length; i++)
		{
			arr[i] = RandomNumber(from, to);
		}
	}

	static void fillArrayWithRandomWords(string arr[], int length, enCrecter charType, short wordLength)
	{
		for (int i = 0; i < length; i++)
		{
			arr[i] = GenretWord(charType, wordLength);
		}
	}


	static void fillArrayWithRandomKeys(string arr[], int length, enCrecter charType)
	{
		for (int i = 0; i < length; i++)
		{
			arr[i] = GenretKay(charType);
		}
	}


	static string tabs(short numberOfTabs = 1)
	{
		string tab = "";

		for (short i = 1; i <= numberOfTabs; i++)
		{
			tab += "\t";
		}

		return tab;
	}

	static string encryptText(string text, float key = 34)
	{
		string encryptionText = "";

		for (short i = 0; i < text.length(); i++)
		{
			encryptionText += char(text[i] + key);
		}

		return encryptionText;
	}

	static string decryptText(string text, float key = 34)
	{
		string decryptionText = "";

		for (short i = 0; i < text.length(); i++)
		{
			decryptionText += char(text[i] - key);
		}

		return decryptionText;
	}

	static string NumberToText(double number) {
		if (number < 0) {
			return "Negative " + NumberToText(-number);
		}

		if (number == 0) {
			return "Zero";  // Return "Zero" for 0.
		}

		// Handle integer part
		int integerPart = static_cast<int> (number);
		string result;

		static const std::string arr1[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
											 "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen",
											 "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen",
											 "Nineteen" };

		static const std::string arr2[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty",
											 "Sixty", "Seventy", "Eighty", "Ninety" };

		if (integerPart < 20) {
			result += arr1[integerPart] + " ";
		}
		else if (integerPart < 100) {
			result += arr2[integerPart / 10] + " " + arr1[integerPart % 10] + " ";
		}
		else if (integerPart < 1000) {
			result += arr1[integerPart / 100] + " Hundred " + NumberToText(static_cast<float>(integerPart % 100));
		}
		else if (integerPart < 1000000) {
			result += NumberToText(static_cast<float>(integerPart / 1000)) + " Thousand " + NumberToText(static_cast<float>(integerPart % 1000));
		}
		else if (integerPart < 1000000000) {
			result += NumberToText(static_cast<float>(integerPart / 1000000)) + " Million " + NumberToText(static_cast<float>(integerPart % 1000000));
		}
		else {
			result += NumberToText(static_cast<float>(integerPart / 1000000000)) + " Billion " + NumberToText(static_cast<float>(integerPart % 1000000000));
		}

		// Handle decimal part
		int decimalPart = static_cast<int>(std::round((number - integerPart) * 100)); // Convert to two decimal places
		if (decimalPart > 0) {
			result += "point ";
			if (decimalPart < 10) {
				result += "Zero ";  // Handle single-digit decimals
			}
			result += NumberToText(static_cast<float>(decimalPart));
		}

		return result;
	}


};
