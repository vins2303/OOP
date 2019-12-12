#ifndef _BACKPACK_H_
#define _BACKPACK_H_

#include "Goods.h"

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
};

#endif // !1