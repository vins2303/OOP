#ifndef _BACKPACK_H_
#define _BACKPACK_H_

#include "Goods.h"
#include <string>
#include <fstream>
#include "../Equipment/Equipment_Attributes.h"
using namespace std;

class Back_Pack {
private:
    string user_Account;
    string user_Name;
    int Money;
    vector<Goods*> goods;
public:
    Back_Pack(string _account, string _user_name, int _Money);
    ~Back_Pack();

    int getMoney();
    void setMoney(int _money);

    void Read_BackPack();
    void Save_BackPack();

private:
    void Read_BackPack_Equipment();
    void Read_BackPack_Consumables();
    void Save_BackPack_Equipment();
    void Save_BackPack_Consumables();
};

#endif // !1