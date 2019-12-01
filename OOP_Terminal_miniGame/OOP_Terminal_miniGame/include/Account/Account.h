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
    string getAccount();
    void clear();
    bool IsSignIn();
    bool rmAccount();

private:
    bool SignIn();
    void Registered();
    string isAccount(string _accout);

};


#endif
