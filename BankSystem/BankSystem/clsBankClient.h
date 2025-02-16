#pragma once
#include <iostream>
#include "clsPerson.h"
#include "clsString.h"
#include <fstream>
using namespace std;


class clsBankClient : public clsPerson
{

private:
	// enMode 
	enum enMode { EmptyMode = 1, UpdateMode = 2 , AddNewMode = 3 };


	//  _FileName = "Clients.txt";

	// Varibla Private
	enMode _Mode;
	string _AcountNumber;
	string _PinCode;
	double _AcountBlance;
	bool _MarkToDelate = false;


	 string _PrepareTransferLogRecord(clsBankClient ClientTo , double TransferAmount,string Seperator = "#//#")
	{
		return   (clsDate::DateToString(clsDate()) + " - " + clsDate::GetTimeHours() + Seperator + _AcountNumber + Seperator + ClientTo._AcountNumber
			+ Seperator + to_string(TransferAmount) + Seperator + to_string(_AcountBlance) + Seperator + to_string(ClientTo._AcountBlance) + Seperator + CurrentUser.GetUserName());
	}

	 void _RegsiterTransfer(clsBankClient& ClientTo, double TransferAmount)
	 {
		 clsString::AddDataLineToFile(_PrepareTransferLogRecord(ClientTo, TransferAmount, "#//#"), "TransferLog.txt");
	 }


	// Save Date To File Functions
	static clsBankClient _ReversLineToObject(vector <string> vString) {
		return clsBankClient(UpdateMode, vString[0], (vString[1]), (vString[2]), (vString[3]), (vString[4]), clsUntil::decryptText(vString[5]), stod(vString[6]));
	}
	static string        _ReversObjectToLine(clsBankClient Client, string dellm)
	{
		return (Client.GetFirstName() + dellm) + (Client.GetListName() + dellm) + (Client.GetEmail() + dellm) + (Client.GetPhone() + dellm) + (Client._AcountNumber + dellm) + clsUntil::encryptText(Client._PinCode) + dellm + to_string(Client._AcountBlance);
	}



	static void          _SaveDateToFile(vector <clsBankClient> vBankClients)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);

		if (MyFile.is_open())
		{
			for (clsBankClient& C : vBankClients)
			{
				if(C._MarkToDelate != true)
				MyFile << _ReversObjectToLine(C,"#//#") << endl;
			}

		}

	}
	static vector <clsBankClient> _LoadDateFromFile()
	{
		fstream MyFile;
		vector <clsBankClient> _BankClients;
		MyFile.open("Clients.txt", ios::in);
		string line = "";
		if (MyFile.is_open()) {

			while (getline(MyFile, line)) {

				if (line != "") {

					clsBankClient Client = _ReversLineToObject(clsString::Spilt_String(line, "#//#"));
					_BankClients.push_back(Client);
				}

			}

		}
		return _BankClients;
	}


	// Get Empty Object For Only Developer
	static clsBankClient _GetEmptyObject()
	{
		return  clsBankClient(EmptyMode, "", "", "", "", "", "", 0);
	}


	// Update Date In File
	void _Update()
	{
		vector <clsBankClient> _BankClients = _LoadDateFromFile();
		for (clsBankClient& C : _BankClients)
		{
			if (C.GetAcountNumber() == _AcountNumber)
			{
				C = *this;
				break;
			}
		}
		_SaveDateToFile(_BankClients);
	}


	// Add Client
	void _AddNew()
	{
		vector <clsBankClient> _BankClients = _LoadDateFromFile();
		_BankClients.push_back(*this);	
		_SaveDateToFile(_BankClients);
		_Mode = UpdateMode;
	}
	struct stRigsterTransfer;

	static stRigsterTransfer _ConvertLineToStructTransfer(string Line, string Seperator = "#//#")
	{
		vector <string> vDate = clsString::Spilt_String(Line, Seperator);
		stRigsterTransfer RigsterTransfer;

		if (vDate.size() >= 6)
		{
			RigsterTransfer.Date_Time = vDate[0];
			RigsterTransfer.S_AcountNumber = vDate[1];
			RigsterTransfer.D_AcountNumber = vDate[2];
			RigsterTransfer.Amount = stof(vDate[3]);
			RigsterTransfer.S_AcountBlanace = stof(vDate[4]);
			RigsterTransfer.D_AcountBlanace = stof(vDate[5]);
			RigsterTransfer.Username = vDate[6];
		}
		return RigsterTransfer;
	}


public:


	struct stRigsterTransfer
	{
		string Date_Time;
		string S_AcountNumber;
		string D_AcountNumber;
		float Amount;
		float S_AcountBlanace;
		float D_AcountBlanace;
		string Username;
	};

	// Costrautor
	clsBankClient(enMode Mode, string FirstName, string ListName, string Email, string Phone, string AcountNumber, string PinCode, double GetAcountBlance)
		: clsPerson(FirstName, ListName, Email, Phone)
	{
		_Mode = Mode;
		_AcountNumber = AcountNumber;
		_PinCode = PinCode;
		_AcountBlance = GetAcountBlance;
	}

	// Is Empty Mode
	bool IsEmpty()
	{
		return (_Mode == EmptyMode);
	}

	// Proprty get
	string GetPinCode() {
		return _PinCode;
	}
	double GetAcountBlance() {
		return _AcountBlance;
	}
	string GetAcountNumber() {
		return _AcountNumber;
	}

	// Proprty Sat
	void SatPinCode(string PinCode) {
		_PinCode = PinCode;
	}
	void SatAcountBlance(double AcountBlance)
	{
		_AcountBlance = AcountBlance;
	}

	//__declspec(property(get = GetPinCode, put = SatPinCode)) string PinCode;
	//_declspec(property(get = GetAcountBlance, put = SatAcountBlance)) string AcountBlance;



	// Find Client Function
	static clsBankClient Find(string AcountNumber)
	{
		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);
		string line = "";

		if (MyFile.is_open()) {

			while (getline(MyFile, line)) {

				if (line != "") {
					clsBankClient Client = _ReversLineToObject(clsString::Spilt_String(line, "#//#"));

					if (Client.GetAcountNumber() == AcountNumber)
					{
						MyFile.close();
						return Client;
					}

				}

			}
			MyFile.close();
		}

		return _GetEmptyObject();
	}
	static clsBankClient Find(string AcountNumber, string PinCode)
	{
		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);
		string line = "";

		if (MyFile.is_open()) {

			while (getline(MyFile, line)) {

				if (line != "") {
					clsBankClient Client = _ReversLineToObject(clsString::Spilt_String(line, "#//#"));

					if (Client.GetAcountNumber() == AcountNumber && Client.GetPinCode() == PinCode)
					{
						MyFile.close();
						return Client;
					}

				}

			}
			MyFile.close();
		}

		return _GetEmptyObject();
	}


	// Chack Client In DateBase
	static bool IsClientExist(string AcountNumber)
	{
		clsBankClient client = Find(AcountNumber);
		return !(client.IsEmpty());
	}

	bool IsClientExist() {
		return IsClientExist(_AcountNumber);
	}



	


	enum enSaveResult { svFaildEmptyObject = 1, svSucceeded = 2 , svFaildAcountNumberExists = 3};
	// Confirem Proses Save Date
	enSaveResult Save()
	{

		switch (_Mode)
		{

		case EmptyMode:
			if(IsEmpty())
			return svFaildEmptyObject;

			break;
		case UpdateMode:
			_Update();
			return svSucceeded;
			break;

		case AddNewMode:

			if (IsClientExist())
			{
				return svFaildAcountNumberExists;
			}
			else {
				_AddNew();
				return svSucceeded;
			}

			break;

		}

		return svFaildEmptyObject;
	}


	// Add New Client To DateBase
	static clsBankClient GetAddNewClient(string AcountNumber)
	{
		return clsBankClient(AddNewMode, "", "", "", "", AcountNumber, "", 0);
	}


	// Dalete Client From Datebase
	bool Delate()
	{
		vector <clsBankClient> _BankClients = _LoadDateFromFile();

		for (clsBankClient& C : _BankClients)
		{
			if (C.GetAcountNumber() == _AcountNumber)
			{
				C._MarkToDelate = true;
				break;
			}

		}


		_SaveDateToFile(_BankClients);


		*this = _GetEmptyObject();
		return true;
	}


	// Get Clients To Print List
	static vector <clsBankClient> GetListClient()
	{
		return _LoadDateFromFile();
	}
	// Get Total Blance Function
	static double GetTotalBlance()
	{
		vector <clsBankClient> Clients = _LoadDateFromFile();
		double SumBlance = 0;

		for (clsBankClient& C : Clients)
		{
			SumBlance += C._AcountBlance;
		}
		return SumBlance;
	}

	void Deposit(double Amount)
	{
		_AcountBlance += Amount;
		Save();
	}
	bool Withdraw(double Amount)
	{
		if (Amount > _AcountBlance)
		{
			return false;
		}
		else {
			_AcountBlance -= Amount;
			Save();
		}
		return true;
	}


	 bool Transfer(clsBankClient &ClientTo , double TransferAmount)
	{
		if (Withdraw(TransferAmount))
		{
			ClientTo.Deposit(TransferAmount);
			_RegsiterTransfer(ClientTo,TransferAmount);
			return true;
		}
		return false;
	}

    // No Ui In Object
	/*
	    static void _PrintClient(clsBankClient Client) {
		cout << "Client Info:\n";
		cout << "____________________\n";
		cout << "FirstName  : " << Client.GetFirstName() << endl;
		cout << "ListName   : " << Client.GetListName() << endl;
		cout << "Full Name  : " << Client.FullName() << endl;
		cout << "Email      : " << Client.GetEmail() << endl;
		cout << "Phone      : " << Client.GetPhone() << endl;
		cout << "Ac. Number : " << Client.GetAcountNumber() << endl;
		cout << "Pin Code   : " << Client.GetPinCode() << endl;
		cout << "Ac. Blance : " << Client.GetAcountBlance() << endl;
		cout << "____________________\n\n";
	}
	*/


	static vector <stRigsterTransfer> GetRigsterTransferList()
	 {
		 vector <stRigsterTransfer> vDate;

		 fstream MyFile;
		 MyFile.open("TransferLog.txt", ios::in);//read Mode

		 if (MyFile.is_open())
		 {
			 string Line;
			 while (getline(MyFile, Line))
			 {
				 vDate.push_back(_ConvertLineToStructTransfer(Line,"#//#"));
			 }

			 MyFile.close();

		 }

		 return vDate;
	 }

};
