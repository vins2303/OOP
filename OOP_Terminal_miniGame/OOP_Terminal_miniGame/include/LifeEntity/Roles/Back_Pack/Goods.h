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
//#include "../Roles.h"
//#include "Back_Pack.h"
//#include "../Roles.h"
using namespace std;

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

    int getLV();
    int getMoney();
    string getName();
    Back_Pack_Type& getType();

    bool isEquipment();
    bool isConsumables();

    virtual void show_info();
    virtual bool User_Items();
    string getType_S();
};

#endif // !
