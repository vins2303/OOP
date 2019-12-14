#pragma once
#ifndef _GOODS_H_
#define _GOODS_H_

#include <iostream>

#include <vector>
#include <Windows.h>
#include <algorithm>
#include "../../../../include/Tool/Tool.h"
#include "../../Attributes.h"
#include <cassert>
#include "../../../Type.h"
#include <conio.h>
//#include "../Roles.h"
//#include "Back_Pack.h"
//#include "../Roles.h"
using namespace std;

#define Read_Equipment_Attributes_int_ini( lpAppName,lpKeyName) GetPrivateProfileInt((lpAppName).c_str(), lpKeyName, INT_MAX, "Data/Attributes/Equipment.ini")

class Goods : public Attributes {
private:
    int LV;
    int Money;
    int Quantity;
    string name;
    vector<RoleType> Restricted_Role;//職業限定
    vector<RaceType> Restricted_Race;//總族限定
    Back_Pack_Type type;
public:
    Goods(string _name, int _lv, Back_Pack_Type _type, int _Quantity = 1);
    virtual ~Goods();

    /*                  種族 or 職業限定              */
    bool Usable(const RoleType& _role, const RaceType& _race);
    bool Usable_Role(const RoleType& _role);
    bool Usable_Race(const RaceType& _race);

    int getQuantity();
    void setQuantity(int _num = 1);
    int getLV();
    int getMoney();
    string getName();
    Back_Pack_Type& getType();

    bool isEquipment();
    bool isConsumables();

    virtual void show_info();
    virtual bool isUse();
    string getType_S();
};

#endif // !
