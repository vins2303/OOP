#include "../../../include/LifeEntity/Roles/Roles.h"

Roles::Roles(string _name, int _LV, int nowHP, int nowMP, int Exp, string _Map_Now, Race::RaceType _race, RoleType _role, Map_object _object) :
    name(_name),
    exp(Exp),
    Map_Now(_Map_Now),
    drop(sum_Attributes(_race, _role, "Drop")),
    role(_role),
    Map_object(_object),//暫時
    Race(_race),
    Equipment(),//暫時
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
    //if (object != NULL) delete object;
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
    if (_type == "劍士")
        return RoleType::劍士;
    if (_type == "海盜")
        return RoleType::海盜;
    if (_type == "法師")
        return RoleType::法師;

    return RoleType::劍士;
}

string Roles::RolesTypeToString(Roles::RoleType _type) {
    string out = "";
    switch (_type)
    {
    case Roles::RoleType::劍士:
        out = "劍士";
        break;
    case Roles::RoleType::法師:
        out = "法師";
        break;
    case Roles::RoleType::海盜:
        out = "海盜";
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

string Roles::getMap_Now() { return Map_Now; }

//*********************************** 角色移動 ***********************************
//物件移動
Map_object* Roles::set_seat_X(int _x, vector<Map_object*>& _object) {
    static Map_object* over;
    static int posX;
    over = NULL;
    posX = get_seat_X();
    Map_object::set_seat_X(_x);
    if ((over = Object_overlapping(*this, _object)) != NULL || get_seat_X() < 2 || get_seat_X() > 99) {
        Map_object::set_seat_X(posX);
        //Y = posY;
    }
    else {
        Map_object::set_seat_X(posX);
        clear_Draw_Object();
        Map_object::set_seat_X(_x);
    }
    return over;
}

//物件移動
Map_object* Roles::set_seat_Y(int _y, vector<Map_object*>& _object) {
    static Map_object* over;
    static int posY;
    over = NULL;
    posY = get_seat_Y();
    Map_object::set_seat_Y(_y);
    if ((over = Object_overlapping(*this, _object)) != NULL || get_seat_Y() < 1 || get_seat_Y() >38) {
        Map_object::set_seat_Y(posY);
        //Y = posY;
    } else {
        Map_object::set_seat_Y(posY);
        clear_Draw_Object();
        Map_object::set_seat_Y(_y);
    }
    return over;
}

//判斷是否重疊
Map_object* Roles::Object_overlapping(Map_object& obj, vector<Map_object*>& _object) {
    for (vector<Map_object*>::iterator it = _object.begin(); it != _object.end(); it++)
        if (obj == (**it))
            return *it;
    return NULL;
}
//**********************************************************************************************