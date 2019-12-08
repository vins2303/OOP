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

#define AccountFile "Data/Account.ini"

class Account {
private:
    bool isSignIn;
    string account;
    string password;
public:
    Account();
    ~Account();
    void AccountMenu();
    void Sign_out();
    bool IsSignIn();
    bool rmAccount();
    string GetAccount();

private:
    bool SignIn();
    void Registered();
    string isAccount(string _accout);
};

#endif