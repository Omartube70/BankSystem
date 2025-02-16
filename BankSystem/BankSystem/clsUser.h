#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include "clsDate.h"
#include "clsUntil.h"

using namespace std;
class clsUser : public clsPerson
{
private:
    struct stLoginRegister;
    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _Mode;
    string _UserName;
    string _Password;
    int _Permissions;
    bool _MarkedForDelete = false;

    static stLoginRegister _ConvertLineToStLoginRegster(string Line, string Sprator = "#//#")
    {
        vector <string> vDate = clsString::Spilt_String(Line, Sprator);
        stLoginRegister LoginRegister;
        LoginRegister.Date_Time = vDate[0];
        LoginRegister.Username = vDate[1];
        LoginRegister.Password = clsUntil::decryptText(vDate[2]);
        LoginRegister.Permissions = stoi(vDate[3]);
        return  LoginRegister;
    }

   string _PrepareLogRecord(string Seperator = "#//#")
    {
       return   (clsDate::DateToString(clsDate()) + " - " + clsDate::GetTimeHours()) + Seperator + _UserName + Seperator + clsUntil::encryptText(_Password) + Seperator + to_string(_Permissions);

    }

    static clsUser _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
    {
        vector<string> vUserData;
        vUserData = clsString::Spilt_String(Line, Seperator);

        return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
            vUserData[3], vUserData[4], clsUntil::decryptText(vUserData[5]), stoi(vUserData[6]));

    }

    static string _ConverUserObjectToLine(clsUser User, string Seperator = "#//#")
    {
        string UserRecord = (User.GetFirstName() + Seperator + User.GetListName() + Seperator + User.GetEmail() + Seperator + User.GetPhone()
            + Seperator + User.GetUserName() + Seperator
            + clsUntil::encryptText(User.GetPassword())
            + Seperator + to_string(User.GetPermissions()) );
        return UserRecord;
    }



    static  vector <clsUser> _LoadUsersDataFromFile()
    {

        vector <clsUser> vUsers;

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {
                vUsers.push_back(_ConvertLinetoUserObject(Line));
            }

            MyFile.close();

        }

        return vUsers;

    }

    static void _SaveUsersDataToFile(vector <clsUser> vUsers)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsUser U : vUsers)
            {
                if (U.MarkedForDeleted() == false)
                {
                    //we only write records that are not marked for delete.  
                    DataLine = _ConverUserObjectToLine(U);
                    MyFile << DataLine << endl;
                }

            }

            MyFile.close();
        }

    }


    void _Update()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.GetUserName() == _UserName)
            {
                U = *this;
                break;
            }

        }

        _SaveUsersDataToFile(_vUsers);

    }

    void _AddNew()
    {
        clsString::AddDataLineToFile(_ConverUserObjectToLine(*this) , "Users.txt");
    }

    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

public:

    enum enPermissions {
        eAll = -1, pListClient = 1, pAddNewClient = 2,
        pDelateClient = 4,
        pUpdateClient = 8,
        pFindClient = 16,
        pTransactions = 32,
        pManageUsers = 64,
        pLoginRegister = 128
    };
    struct stLoginRegister
    {
        string Date_Time;
        string Username;
        string Password;
        int Permissions;
    };


    clsUser(enMode Mode , string FirstName, string LastName,
        string Email, string Phone, string UserName, string Password,
        int Permissions) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _UserName = UserName;
        _Password = Password;
        _Permissions = Permissions;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }

    string GetUserName()
    {
        return _UserName;
    }

    void SetUserName(string UserName)
    {
        _UserName = UserName;
    }

    __declspec(property(get = GetUserName, put = SetUserName)) string UserName;

    void SetPassword(string Password)
    {
        _Password = Password;
    }

    string GetPassword()
    {
        return _Password;
    }
    __declspec(property(get = GetPassword, put = SetPassword)) string Password;

    void SetPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }

    int GetPermissions()
    {
        return _Permissions;
    }
    __declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

    static clsUser Find(string UserName)
    {
        vector <clsUser> vUsers = _LoadUsersDataFromFile();


        for (clsUser& User : vUsers)
        {
            if (User.GetUserName() == UserName)
            {

                return User;
            }
        }

        return _GetEmptyUserObject();
    }



    static clsUser Find(string UserName, string Password)
    {    
         vector <clsUser> vUsers =  _LoadUsersDataFromFile();


         for (clsUser& User : vUsers)
         {
             if (User.GetUserName() == UserName && User.GetPassword() == Password)
             {

                 return User;
             }
         }

        return _GetEmptyUserObject();
    }



     bool ChackAccessPermissions(enPermissions Permissions)
    {
        return (Permissions & _Permissions || Permissions == clsUser::eAll);
    }


    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };

    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {
                return enSaveResults::svFaildEmptyObject;
            }
        }

        case enMode::UpdateMode:
        {
            _Update();
            return enSaveResults::svSucceeded;

            break;
        }

        case enMode::AddNewMode:
        {
            //This will add new record to file or database
            if (clsUser::IsUserExist(_UserName))
            {
                return enSaveResults::svFaildUserExists;
            }
            else
            {
                _AddNew();
                //We need to set the mode to update after add new
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }

            break;
        }
        }
        return svSucceeded;
    }

    static bool IsUserExist(string UserName)
    {

        clsUser User = clsUser::Find(UserName);
        return (!User.IsEmpty());
    }


    bool Delete()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.GetUserName() == _UserName)
            {
                U._MarkedForDelete = true;
                break;
            }

        }
        _SaveUsersDataToFile(_vUsers);
        *this = _GetEmptyUserObject();
        return true;

    }

    static clsUser GetAddNewUserObject(string UserName)
    {
        return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
    }

    static vector <clsUser> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }


    void RegisterLogIn()
    {
        clsString::AddDataLineToFile(_PrepareLogRecord(),"LoginRegister.txt");
    }

    static vector <stLoginRegister> GetLoginRegisterList()
    {
        vector <stLoginRegister> vUsers;

        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                vUsers.push_back(_ConvertLineToStLoginRegster(Line));
            }

            MyFile.close();

        }
        return vUsers;
    }

};

