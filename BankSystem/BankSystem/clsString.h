#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
class clsString
{
private:
	string _Value;
	vector <string> Spilt_String_Class;
public:

	static void AddDataLineToFile(string stDataLine, string FileName)
	{
		fstream MyFile;
		MyFile.open(FileName, ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}
	}



	clsString()
	{
		_Value = "";
	}
	clsString(string Value)
	{
		_Value = Value;
	}
	void SetValue(string Value) {
		_Value = Value;
	}
	string GetValue() {
		return _Value;
	}

	static short CountWords(string Words)
	{
		short Count = 0;


		for (char& c : Words)
		{
			if (c == ' ') {
				Count++;
			}
		}
		return ++Count;
	}
	short CountWords() {
		return CountWords(_Value);
	}

	static vector <string> Spilt_String(string word, string dellm) {

		vector <string> vString;
		int pos = 0;
		string sWord = "";


		while ((pos = word.find(dellm)) != string::npos)
		{

			sWord = word.substr(0, pos);
		
				vString.push_back(sWord);
			

			word.erase(0, pos + dellm.length());

		}

		if (word != " ") {
			vString.push_back(word);
		}
		return vString;
	}
	vector <string> Spilt_String() {
		Spilt_String_Class = Spilt_String(_Value, " ");
		return Spilt_String_Class;
	}
	vector <string> Spilt_String(string word, string dellm, bool IsObject) {
		Spilt_String_Class = Spilt_String(word, dellm);
		return Spilt_String_Class;
	}


	static string Join_String(vector <string> vString, string dellm) {
		string word = "";

		for (string& S1 : vString) {
			if (vString.back() == S1) {
				word += (S1);
			}
			else
				word += (S1 + dellm);
		}

		return word;
	}
	string Join_String() {
		return (Spilt_String_Class.size() > 1) ? (Join_String(Spilt_String_Class, " ")) : "Place Spilt String First";
	}

	static short CounterOfChack(char chacked, string word) {
		short counter = 0;
		for (int i = 0; i < word.length(); i++) {
			if (word[i] == chacked) {
				counter++;
			}
		}
		return counter;
	}
	short CounterOfChack(char chacked) {
		return CounterOfChack(chacked, _Value);
	}

	static int CountSmall(string Word) {
		short count = 0;
		for (int i = 0; i < Word.length(); i++) {
			if (islower(Word[i])) {
				count++;
			}
		}
		return count;
	}
	int CountSmall() {
		return CountSmall(_Value);
	}

	static int CountCaptel(string Word) {
		short count = 0;
		for (int i = 0; i < Word.length(); i++) {
			if (isupper(Word[i])) {
				count++;
			}
		}
		return count;
	}
	int CountCaptel() {
		return CountCaptel(_Value);
	}

	static char Invert(char c) {
		return  (isupper(c)) ? tolower(c) : toupper(c);
	}

	static string InvertWord(string word) {

		for (int i = 0; i < word.length(); i++) {
			word[i] = Invert(word[i]);
		}
		return word;
	}
	string InvertWord() {
		return InvertWord(_Value);
	}


	static char RedaChar() {
		char x;
		cout << "enter to Char : ";
		cin >> x;
		return x;
	}

	static string RedaWord() {
		string word;
		cout << "Enter to Word : ";
		getline(cin, word);
		return word;
	}

	static string Change_Start_Word_To_Upper(string word) {
		bool IsStartWord = true;

		for (int i = 0; i < word.length(); i++) {

			if (word[i] != ' ' && IsStartWord) {

				word[i] = (toupper(word[i]));

			}

			IsStartWord = (word[i] == ' ') ? true : false;
		}

		return word;
	}
	string Change_Start_Word_To_Upper() {
		return Change_Start_Word_To_Upper(_Value);
	}

	static string ToLowerAllString(string s1)
	{
		for (int i = 0; i < s1.length(); i++) {
			s1[i] = tolower(s1[i]);
		}

		return s1;
	}
	string ToLowerAllString() {
		return ToLowerAllString(_Value);
	}

	static string ToUpperAllString(string s1)
	{
		for (int i = 0; i < s1.length(); i++) {
			s1[i] = toupper(s1[i]);
		}

		return s1;
	}
	string ToUpperAllString() {
		return ToUpperAllString(_Value);
	}

};


