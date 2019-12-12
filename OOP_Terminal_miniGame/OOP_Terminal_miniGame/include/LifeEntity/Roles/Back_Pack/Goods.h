#ifndef _GOODS_H_
#define _GOODS_H_

#include <iostream>

#include <vector>
#include <Windows.h>
#include <algorithm>
#include "../../../../include/Tool/Tool.h"
#include "../../Attributes.h"
#include "../../../Type.h"
using namespace std;

class Goods : public Attributes {
private:
    int LV;
    int Money;
    string name;
    vector<RoleType> Restricted_Role;//¾�~���w
    vector<RaceType> Restricted_Race;//�`�ڭ��w
    Back_Pack_Type type;
public:
    Goods(string _name, int _lv, Back_Pack_Type _type);
    virtual ~Goods();

    /*                  �ر� or ¾�~���w              */
    bool Usable(const RoleType& _role, const RaceType& _race);
    bool Usable_Role(const RoleType& _role);
    bool Usable_Race(const RaceType& _race);

    int getLV();
    int getMoney();
    string getName();
    Back_Pack_Type& getType();
};

#endif // !
