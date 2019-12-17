#include "../../../../include/LifeEntity/Roles/Back_Pack/Goods.h"

Goods::Goods(string _name, int _lv, int _Quantity) :
    Money(Read_Equipment_Attributes_int_ini(_name, "Money")),
    name(_name),
    LV(_lv),
    type(toBack_Pack_Type(Tool::ReadStringIni(_name, "TYPE", "NULL", Read_Back_Pack_PATH))),
    Quantity(_Quantity),
    Attributes(
        Read_Equipment_Attributes_int_ini(_name, "HP"),
        Read_Equipment_Attributes_int_ini(_name, "MP"),
        Read_Equipment_Attributes_int_ini(_name, "Attack"),
        Read_Equipment_Attributes_int_ini(_name, "SP"),
        Read_Equipment_Attributes_int_ini(_name, "DEF"),
        Read_Equipment_Attributes_int_ini(_name, "CRT"),
        Read_Equipment_Attributes_int_ini(_name, "Drop")

    ),
    Weight(Read_Equipment_Attributes_int_ini(_name, "Weight"))
    ,
    //Restricted_Role(toRoleType_List(Tool::SplitString(Tool::ReadStringIni(_name, "Role", "NULL", Read_Back_Pack_PATH), " "))),
    Restricted(
        toRoleType_List(Tool::SplitString(Tool::ReadStringIni(_name, "Role", "NULL", Read_Back_Pack_PATH), " ")),
        toRaceType_List(Tool::SplitString(Tool::ReadStringIni(_name, "Race", "NULL", Read_Back_Pack_PATH), " "))
    )
{
}

Goods::~Goods() { }

bool Goods::operator==(const Goods& _god) const
{
    return name == _god.name;
}

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

int Goods::getMoney() { return Money; }

int Goods::getWight() { return Quantity * Weight; }
int Goods::getWight_one() { return Weight; }

int Goods::getQuantity() { return Quantity; }

void Goods::setQuantity(int _num) {
    if (_num >= 0) Quantity = _num;
    else {
        assert(false);
    }
}

void Goods::addQuantity(int _num) { Quantity += _num; }

int Goods::getLV() { return LV; }

string Goods::getName() { return name; }

bool Goods::isEquipment()
{
    if (type == Back_Pack_Type::Breastplate ||
        type == Back_Pack_Type::Deputy ||
        type == Back_Pack_Type::Helmet ||
        type == Back_Pack_Type::Pants ||
        type == Back_Pack_Type::Shoes ||
        type == Back_Pack_Type::Weapon
        ) return true;
    return false;
}

bool Goods::isConsumables() {
    if (type == Back_Pack_Type::Consumables)
        return true;
    return false;
}

void Goods::show_info() { assert(false); }

bool Goods::isUse() { assert(false); return false; }

string Goods::getType_S() { return toString(type); }
Back_Pack_Type& Goods::getType() { return type; }