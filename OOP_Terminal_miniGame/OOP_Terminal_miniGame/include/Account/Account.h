#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <iostream>
#include <conio.h>
#include<windows.h>
#include<string>
#include <atlstr.h>
using namespace std;

#define AccountFile "Data/Account.ini"

class Account {
private:
    bool isSignIn;
    string  account;
    string password;
public:
    Account();
    ~Account();
    void Menu();

private:
    bool SignIn();
    void Registered();
    string isAccount(string _accout);
};


#endif
