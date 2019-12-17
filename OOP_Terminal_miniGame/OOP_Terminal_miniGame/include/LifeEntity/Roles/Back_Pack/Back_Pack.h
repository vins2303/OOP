#ifndef _BACKPACK_H_
#define _BACKPACK_H_

#include "Goods.h"
#include <string>
#include <iomanip>
#include <fstream>
#include "../Equipment/Equipment_Attributes.h"
#include "../Equipment/Equipment.h"
#include "../Role.h"
#include "../Race.h"
#include "Sub_Back_Pack.h"
#include <conio.h>

using namespace std;

class Back_Pack : public Sub_Back_Pack {
private:
    string user_Account;
    string user_Name;
    int Money;
    /*vector<Sub_Goods*> goods;
    int MaxWeigh;*/

public:
    Back_Pack(string _account, string _user_name, int _Money);
    ~Back_Pack();

    int getMoney();
    void setMoney(int _money);
    int AddMoney(int _money);
    void Read_BackPack();
    void Save_BackPack();
    /*void addGoods(Sub_Goods* _g);
    Sub_Goods* findGoods(string _name);
    vector<Sub_Goods*>& getBackPack_Goods();*/
private:
    /*void Read_BackPack_Equipment();
    void Read_BackPack_Consumables();
    void Save_BackPack_Equipment();
    void Save_BackPack_Consumables();*/
};

#endif // !1