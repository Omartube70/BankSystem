#pragma once
#include <iostream>
#include <vector>
using namespace std;
class clsPerson
{

private:
    string _FirstName;
    string _ListName;
    string _Email;
    string _Phone;

public:
    // constrautor For New Object
    clsPerson(string FirstName, string LastName, string Email, string Phone)
    {
        _FirstName = FirstName;
        _ListName = LastName;
        _Email = Email;
        _Phone = Phone;
    }

    // Get Full Name 
    string FullName() {
        return _FirstName + " " + _ListName;
    }

    // Sat Date Functions
    void SatFirstName(string FirstName) {
        _FirstName = FirstName;
    }
    void SatListName(string ListName) {
        _ListName = ListName;
    }
    void SatEmail(string Email) {
        _Email = Email;
    }
    void SatPhone(string phone) {
        _Phone = phone;
    }

    // Get Date Functions
    string  GetFirstName() {
        return _FirstName;
    }
    string  GetListName() {
        return _ListName;
    }
    string  GetEmail() {
        return _Email;
    }
    string  GetPhone() {
        return _Phone;
    }

    // For Reusplitey
    __declspec(property (get = GetFirstName, put = SatFirstName)) string FirstName;
    __declspec(property (get = GetListName, put = SatListName))  string ListName;
   __declspec(property (get = GetEmail, put = SatEmail))     string Email;
   __declspec(property (get = GetPhone, put = SatPhone))     string Phone;
    ///


    // Send Email
    void SendEmail(string Subject, string Body)
    {
        /*
         Code To Send Email
        */

        cout << "The follwoing message sent successfully to email: " << _Email << endl;
        cout << "Subject: " << Subject << endl;
        cout << "Body: " << Body << "\n\n";
    }

    // Send SMS
    void SendSMS(string TxtMessge) {
        /*
            Code To Send SMS
         */

        cout << "The Following SMS sent successfully to phone: " << _Phone << endl;
        cout << TxtMessge << "\n\n";
    }


};



