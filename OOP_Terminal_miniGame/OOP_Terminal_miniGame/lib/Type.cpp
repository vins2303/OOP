#include "../include/Type.h"

/*
                背包物品
*/
const string toString(Back_Pack_Type value) {
    static map<Back_Pack_Type, string> table;
    static bool isInit = false;
    if (isInit) return table[value];
#define etype(a,b) table[ Back_Pack_Type::a ] = b;
    VALUE_Back_Pack_Type
#undef etype
        isInit = true;
    return table[value];
}

const Back_Pack_Type toEquipment_Type(string value) {
    static map<string, Back_Pack_Type> table;
    static bool isInit = false;
    if (isInit) return table[value];
#define etype(a,b) table[ b ] = Back_Pack_Type::a;
    VALUE_Back_Pack_Type
#undef etype
        isInit = true;
    return table[value];
}

/*
                種族
*/
const RaceType toRace_Type(string _race) {
    static map<string, RaceType> table;
    static bool isInit = false;
    if (isInit) return table[_race];
#define etype(a,b) table[ b ] = RaceType::a;
    VALUE_Race_Type
#undef etype
        isInit = true;
    return table[_race];
}

const string toString(RaceType _type) {
    static map<RaceType, string> table;
    static bool isInit = false;
    if (isInit) return table[_type];
#define etype(a,b) table[ RaceType::a ] = b;
    VALUE_Race_Type
#undef etype
        isInit = true;
    return table[_type];
}

vector<RaceType> toRaceType_List(vector<string> v) {
    vector<RaceType> out;
    for (vector<string>::iterator it = v.begin(); it != v.end(); it++)
        out.push_back(toRace_Type(*it));
    return out;
}

/*
                職業
*/
const RoleType toRole_Type(string _race) {
    static map<string, RoleType> table;
    static bool isInit = false;
    if (isInit) return table[_race];
#define etype(a,b) table[ b ] = RoleType::a;
    VALUE_Role_Type
#undef etype
        isInit = true;
    return table[_race];
}

const string toString(RoleType _type) {
    static map<RoleType, string> table;
    static bool isInit = false;
    if (isInit) return table[_type];
#define etype(a,b) table[ RoleType::a ] = b;
    VALUE_Role_Type
#undef etype
        isInit = true;
    return table[_type];
}

vector<RoleType> toRoleType_List(vector<string> v) {
    vector<RoleType> out;
    for (vector<string>::iterator it = v.begin(); it != v.end(); it++)
        out.push_back(toRole_Type(*it));
    return out;
}