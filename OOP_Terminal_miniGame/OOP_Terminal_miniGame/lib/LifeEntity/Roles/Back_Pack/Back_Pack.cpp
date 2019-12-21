#include "../../../../include/LifeEntity/Roles/Back_Pack/Back_Pack.h"
#include "../../../../include/LifeEntity/Roles/Back_Pack/Consumables.h"

//#define Read_Back_Pack_int_ini( lpAppName,lpKeyName) GetPrivateProfileInt((lpAppName).c_str(), lpKeyName, INT_MAX, "Data/Account/"+ user_Account +"/Back_Pack/Back_Pack.ini")

Back_Pack::Back_Pack(Account& _account, int _Money) :
    user_account(_account),
    Money(_Money),
    Sub_Back_Pack(_account, 0)
{
    //Read_BackPack();
}

Back_Pack::~Back_Pack() {
}

int Back_Pack::getMoney() { return Money; }

void Back_Pack::setMoney(int _money) { Money = _money; }

int Back_Pack::AddMoney(int _money) { return Money += _money; }

//void Back_Pack::Read_BackPack() {
//    //Read_BackPack_Consumables();
//    //Read_BackPack_Equipment();
//}

void Back_Pack::Save_BackPack() {
    Sub_Back_Pack::Save_BackPack();
}