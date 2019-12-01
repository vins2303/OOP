#include "../../../include/LifeEntity/Roles/Roles.h"

Roles::Roles(string _name, int _LV, int nowHP, int nowMP, int Exp, Race::RaceType _race, RoleType _role) :
    name(_name),
    exp(Exp),
    drop(sum_Attributes(_race, _role, "Drop")),
    role(_role),
    object(NULL),//�Ȯ�
    Race(_race),
    Equipment(),//�Ȯ�
    LifeAttributes(
        _LV,
        nowHP == -1 ? sum_Attributes(_race, _role, "HP") * _LV : nowHP,
        nowMP == -1 ? sum_Attributes(_race, _role, "MP") * _LV : nowMP,
        sum_Attributes(_race, _role, "Attack"),
        sum_Attributes(_race, _role, "SP"),
        sum_Attributes(_race, _role, "DEF"),
        sum_Attributes(_race, _role, "CRT"),
        sum_Attributes(_race, _role, "HP"),
        sum_Attributes(_race, _role, "MP")
    )
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
    //transform(_type.begin(), _type.end(), _type.begin(), tolower);
    if (_type == "�C�h")
        return RoleType::�C�h;
    if (_type == "���s")
        return RoleType::���s;
    if (_type == "�k�v")
        return RoleType::�k�v;

    return RoleType::�C�h;
}

string Roles::RolesTypeToString(Roles::RoleType _type) {
    string out = "";
    switch (_type)
    {
    case Roles::RoleType::�C�h:
        out = "�C�h";
        break;
    case Roles::RoleType::�k�v:
        out = "�k�v";
        break;
    case Roles::RoleType::���s:
        out = "���s";
        break;
    }
    return out;
}

inline int Roles::sum_Attributes(Race::RaceType _race, RoleType _role, string _att) {
    return
    GetPrivateProfileInt(Race::RaceTypeToString(_race).c_str(), _att.c_str(), 0, "Data/Attributes/Race.ini") +
    GetPrivateProfileInt(RolesTypeToString(_role).c_str(), _att.c_str(), 0, "Data/Attributes/Role.ini");
}

string Roles::getRoleType() {
    return RolesTypeToString(role);
}
