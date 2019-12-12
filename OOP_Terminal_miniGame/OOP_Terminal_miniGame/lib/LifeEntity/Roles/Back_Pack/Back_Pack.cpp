#include "../../../../include/LifeEntity/Roles/Back_Pack/Back_Pack.h"

//#define Read_Back_Pack_int_ini( lpAppName,lpKeyName) GetPrivateProfileInt((lpAppName).c_str(), lpKeyName, INT_MAX, "Data/Account/"+ user_Account +"/Back_Pack/Back_Pack.ini")

Back_Pack::Back_Pack(string _account, string _user_name, int _Money) :
    user_Account(_account),
    user_Name(_user_name),
    Money(_Money)
{
}

Back_Pack::~Back_Pack() { }

int Back_Pack::getMoney() { return Money; }

void Back_Pack::setMoney(int _money) { Money = _money; }