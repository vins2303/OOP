#include "../../../../include/LifeEntity/Roles/Equipment/Equipment_Attributes.h"
#include "../../../../include/Tool/Tool.h"

#define Read_Equipment_Attributes_int_ini( lpAppName,lpKeyName) GetPrivateProfileInt((lpAppName).c_str(), lpKeyName, INT_MAX, "Data/Attributes/Equipment.ini")

Equipment_Attributes::Equipment_Attributes(string _name, int _lv, Back_Pack_Type _type) :
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

Equipment_Attributes::~Equipment_Attributes() {}
Back_Pack_Type& Equipment_Attributes::getType() { return type; }

//bool Equipment_Attributes::Usable(Roles& _roles) {
//    return Usable(_roles.getRoleType(), _roles.getRaceType());
//}

bool Equipment_Attributes::Usable(const RoleType& _role, const RaceType& _race) {
    return Usable_Role(_role) && Usable_Race(_race);
}

bool Equipment_Attributes::Usable_Role(const RoleType& _role) {
    return (find(Restricted_Role.begin(), Restricted_Role.end(), _role) == Restricted_Role.end() ? false : true);
}

bool Equipment_Attributes::Usable_Race(const RaceType& _race) {
    return (find(Restricted_Race.begin(), Restricted_Race.end(), _race) == Restricted_Race.end() ? false : true);
}

int Equipment_Attributes::getHP() { return LV_Magnification(Attributes::getHP()); }

int Equipment_Attributes::getMP() { return LV_Magnification(Attributes::getMP()); }

int Equipment_Attributes::getAttack() { return LV_Magnification(Attributes::getAttack()); }

int Equipment_Attributes::getSP() { return LV_Magnification(Attributes::getSP()); }

int Equipment_Attributes::getDef() { return LV_Magnification(Attributes::getDef()); }

int Equipment_Attributes::getCRT() { return LV_Magnification(Attributes::getCRT()); }

int Equipment_Attributes::getDrop() { return LV_Magnification(Attributes::getDrop()); }

int Equipment_Attributes::getLV() { return LV; }

string Equipment_Attributes::getName() { return name; }