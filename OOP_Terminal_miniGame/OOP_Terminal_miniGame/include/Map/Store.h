#ifndef _STORE_H_
#define _STORE_H_

#include "../LifeEntity/Roles/Back_Pack/Back_Pack.h"
#include "../LifeEntity/Roles/Roles.h"
#define MAP_STORE_PATH(Store_Name) ("Data/Map/Map_Store/" + (Store_Name) + ".txt")
class Store {
private:
    string Store_Name;
    vector<Sub_Goods*> Stroe_Goods;
    Account& user_account;
public:
    Store(Account& _user_account, string _Store_Name);
    ~Store();
    void Store_Menu(Roles& roles);

private:
    void Shopping(Roles& roles);
    void Sell(Roles& roles);
    void show_Store();
    void Read_Store();
};

#endif // !_STORE_H_
