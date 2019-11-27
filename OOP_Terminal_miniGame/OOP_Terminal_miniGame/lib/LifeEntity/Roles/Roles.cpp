#include "../../../include/LifeEntity/Roles/Roles.h"

Roles::Roles(string _name, int _LV, int nowHP, int nowMP, int Exp, Race::RaceType _race, RoleType _role) :
    name(_name),
    exp(Exp),
    drop(INITIAL(_race, _role, "Drop")),
    role(_role),
    race(_race),
    object(NULL),//¼È®É
    Equipment(),//¼È®É
    LifeAttributes(_LV,
        nowHP,
        nowMP,
        INITIAL(_race, _role, "Attack"),
        INITIAL(_race, _role, "SP"),
        INITIAL(_race, _role, "DEF"),
        INITIAL(_race, _role, "CRT"),
        INITIAL(_race, _role, "HP"),
        INITIAL(_race, _role, "MP"))
{}


Roles::~Roles() {
    if (object != NULL) delete object;
}

string Roles::getName() { return name; }
int Roles::getExp() { return exp; }
int Roles::getUpExp() { return (int)(pow(getLV() - 1, 3) + 60); }
int Roles::getDrop() { return drop; }

string Roles::setName(string _name) { return name = _name; }
int Roles::setExp(int _exp) { return exp = _exp > getUpExp() ? getUpExp() : exp; }
int Roles::setDrop(int _drop) { return drop = drop > 100 ? 100 : drop; }

int Roles::addExp(int _exp, bool percent) { 
    int exp = ADD_FUN(getExp(), _exp, percent);
    if (exp > getUpExp()) exp = getUpExp();
    return setExp(exp); 
}

int Roles::addDrop(int _drop) { return setDrop(getDrop() + _drop); }

bool Roles::isUpLv() { return getExp() >= getUpExp() ? true : false; }

Roles::RoleType  Roles::StringToRolesType(string _type) {
    transform(_type.begin(), _type.end(), _type.begin(), tolower);
    if (_type == "warrior")
        return RoleType::Warrior;
    if (_type == "thief")
        return RoleType::Thief;
    if (_type == "magician")
        return RoleType::Magician;

    return RoleType::Warrior;
}

string Roles::RolesTypeToString(Roles::RoleType _type) {
    string out = "";
    switch (_type)
    {
    case Roles::RoleType::Warrior:
        out = "Warrior";
        break;
    case Roles::RoleType::Magician:
        out = "Magician";
        break;
    case Roles::RoleType::Thief:
        out = "Thief";
        break;
    }
    return out;
}

int Roles::INITIAL(Race::RaceType _race, RoleType _role, string _att) {
    return
    GetPrivateProfileInt(Race::RaceTypeToString(_race).c_str(), _att.c_str(), 0, "Data/Attributes/Race.ini") +
    GetPrivateProfileInt(RolesTypeToString(_role).c_str(), _att.c_str(), 0, "Data/Attributes/Role.ini");
}