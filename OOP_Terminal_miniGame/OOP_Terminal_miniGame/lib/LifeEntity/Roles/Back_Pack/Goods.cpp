#include "../../../../include/LifeEntity/Roles/Back_Pack/Goods.h"

#define Read_Equipment_Attributes_int_ini( lpAppName,lpKeyName) GetPrivateProfileInt((lpAppName).c_str(), lpKeyName, INT_MAX, "Data/Attributes/Equipment.ini")

Goods::Goods(string _name, int _lv, Back_Pack_Type _type) :
    Money(Read_Equipment_Attributes_int_ini(_name, "Money")),
    name(_name),
    LV(_lv),
    type(_type),
    Attributes(
        Read_Equipment_Attributes_int_ini(_name, "HP"),
        Read_Equipment_Attributes_int_ini(_name, "MP"),
        Read_Equipment_Attributes_int_ini(_name, "Attack"),
        Read_Equipment_Attributes_int_ini(_name, "SP"),
        Read_Equipment_Attributes_int_ini(_name, "DEF"),
        Read_Equipment_Attributes_int_ini(_name, "CRT"),
        Read_Equipment_Attributes_int_ini(_name, "Drop")

    ),
    //Restricted_Role(toRoleType_List(Tool::SplitString(Tool::ReadStringIni(_name, "Role", "NULL", "Data/Attributes/Equipment.ini"), " "))),
    Restricted_Role(toRoleType_List(Tool::SplitString(Tool::ReadStringIni(_name, "Role", "NULL", "Data/Attributes/Equipment.ini"), " "))),
    Restricted_Race(toRaceType_List(Tool::SplitString(Tool::ReadStringIni(_name, "Race", "NULL", "Data/Attributes/Equipment.ini"), " ")))
{
}

Goods::~Goods() { }

bool Goods::Usable(const RoleType& _role, const RaceType& _race) {
    return Usable_Role(_role) && Usable_Race(_race);
}

bool Goods::Usable_Role(const RoleType& _role) {
    if (find(Restricted_Role.begin(), Restricted_Role.end(), RoleType::null) != Restricted_Role.end()) return true;
    return (find(Restricted_Role.begin(), Restricted_Role.end(), _role) == Restricted_Role.end() ? false : true);
}

bool Goods::Usable_Race(const RaceType& _race) {
    if (find(Restricted_Race.begin(), Restricted_Race.end(), RaceType::null) == Restricted_Race.end()) return true;
    return (find(Restricted_Race.begin(), Restricted_Race.end(), _race) == Restricted_Race.end() ? false : true);
}

int Goods::getMoney() { return Money; }

int Goods::getLV() { return LV; }

string Goods::getName() { return name; }

Back_Pack_Type& Goods::getType() { return type; }