#include "../../../../include/LifeEntity/Roles/Back_Pack/Goods.h"

Goods::Goods(Account& _user_account, string _name, int _lv, int _Quantity) :
    user_account(_user_account),
    LV(_lv),
    Sub_Goods(_user_account, _name, _Quantity),
    Attributes(
        Read_Equipment_Attributes_int_ini(_name, "HP"),
        Read_Equipment_Attributes_int_ini(_name, "MP"),
        Read_Equipment_Attributes_int_ini(_name, "Attack"),
        Read_Equipment_Attributes_int_ini(_name, "SP"),
        Read_Equipment_Attributes_int_ini(_name, "DEF"),
        Read_Equipment_Attributes_int_ini(_name, "CRT"),
        Read_Equipment_Attributes_int_ini(_name, "Drop")

    ),

    //Restricted_Role(toRoleType_List(Tool::SplitString(Tool::ReadStringIni(_name, "Role", "NULL", Read_Back_Pack_PATH), " "))),
    Restricted(
        toRoleType_List(Tool::SplitString(Tool::ReadStringIni(_name, "Role", "NULL", Read_Back_Pack_PATH), " ")),
        toRaceType_List(Tool::SplitString(Tool::ReadStringIni(_name, "Race", "NULL", Read_Back_Pack_PATH), " "))
    )
{
}

Goods::~Goods() { }

//bool Goods::Usable(const RoleType& _role, const RaceType& _race) {
//    return Usable_Role(_role) && Usable_Race(_race);
//}
//
//bool Goods::Usable_Role(const RoleType& _role) {
//    if (find(Restricted_Role.begin(), Restricted_Role.end(), RoleType::null) != Restricted_Role.end()) return true;
//    return (find(Restricted_Role.begin(), Restricted_Role.end(), _role) == Restricted_Role.end() ? false : true);
//}
//
//bool Goods::Usable_Race(const RaceType& _race) {
//    if (find(Restricted_Race.begin(), Restricted_Race.end(), RaceType::null) != Restricted_Race.end()) return true;
//    return (find(Restricted_Race.begin(), Restricted_Race.end(), _race) == Restricted_Race.end() ? false : true);
//}

int Goods::getLV() { return LV; }

void Goods::show_info() { assert(false); }

bool Goods::isUse() { assert(false); return false; }