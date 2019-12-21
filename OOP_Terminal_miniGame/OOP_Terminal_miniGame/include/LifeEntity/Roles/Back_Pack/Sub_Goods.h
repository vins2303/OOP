#include "../../../Type.h"
#ifndef _SUB_GOODS_H
#define _SUB_GOODS_H

#include <Windows.h>
#include <algorithm>
#include <cassert>
#include <conio.h>
#include "../../../../include/Tool/Tool.h"
#include "../../../Account/Account.h"

#define Read_Back_Pack_PATH "Data/Attributes/Back_Pack.ini"

#define Read_Equipment_Attributes_int_ini( lpAppName,lpKeyName) GetPrivateProfileInt((lpAppName).c_str(), lpKeyName, INT_MAX, Read_Back_Pack_PATH)

#define BACK_PACK_PAHT(Acc, name) "Data/Account/" + (Acc) + "/" + (name) + "/BakcPack"

#define BACK_PACK_INFO_PAHT(Acc, Name, ID) ("Data/Account/" + (Acc) + "/" + (Name) + "/BakcPack/" + (ID) +".txt")
#define BACK_PACK_INI_PAHT(Acc, Name) ("Data/Account/" + (Acc) + "/" + (Name) + "/BakcPack/BackPack.ini")
class Sub_Goods {
private:
    int Weight;
    Back_Pack_Type type;
    int Quantity;
    int Money;
    string name;

public:
    Account& user_account;
    Sub_Goods(Account& _user_account, string _name, int _Quantity = 1);
    virtual ~Sub_Goods();

    bool operator== (const Sub_Goods& _god) const;
    virtual void show_info();
    virtual bool isUse();
    int getWight();
    int getWight_one();
    string getType_S();
    Back_Pack_Type& getType();
    string getName();
    void setName(string _name);
    int getMoney();
    int getQuantity();
    void setQuantity(int _num = 1);
    void addQuantity(int _num = 1);
};

#endif // !_SUB_GOODS_H
