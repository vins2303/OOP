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
#include "../Restricted.h"
#include <conio.h>

using namespace std;

#define Read_Back_Pack_PATH "Data/Attributes/Back_Pack.ini"
#define Read_Back_Pack_Type_ini_PATH (_acc, _name) ("Data/Attributes/Account/"+ (_acc) +"/"+(_name)+"/Total_Back_Pack.ini")
#define Read_Equipment_Attributes_int_ini( lpAppName,lpKeyName) GetPrivateProfileInt((lpAppName).c_str(), lpKeyName, INT_MAX, Read_Back_Pack_PATH)

class Goods : public Attributes, public Restricted {
private:
    int LV;
    int Money;
    int Quantity;
    string name;
    int Weight;
    Back_Pack_Type type;
public:
    Goods(string _name, int _lv, int _Quantity = 1);
    virtual ~Goods();

    bool operator== (const Goods& _god) const;

    int getWight();
    int getWight_one();
    int getQuantity();
    void setQuantity(int _num = 1);
    void addQuantity(int _num = 1);
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
