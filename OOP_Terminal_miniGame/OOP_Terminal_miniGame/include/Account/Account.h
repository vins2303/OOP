#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <io.h>
#include <iostream>
#include <conio.h>
#include<windows.h>
#include<string>
#include <atlstr.h>
#include "../../include/Tool/Tool.h"
using namespace std;

#define AccountPath "Data/Account.ini"

class Account {
    friend class RolesList;
private:
    bool isSignIn;
    string account;
    string password;
    string Roles_Name;
public:
    Account();
    ~Account();
    void AccountMenu();
    void Sign_out();
    bool IsSignIn();
    bool rmAccount();
    _declspec(dllexport) inline string getAccount();

    _declspec(dllexport) inline string getRolesName();
private:
    bool SignIn();
    void Registered();
    string isAccount(string _accout);
};

#endif