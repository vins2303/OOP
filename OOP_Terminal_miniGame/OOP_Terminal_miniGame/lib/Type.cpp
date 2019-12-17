#include "../include/Type.h"

const Back_Pack_Type_Category toBack_Pack_Type_Category(Back_Pack_Type value) {
    static map<Back_Pack_Type, Back_Pack_Type_Category> table;
    static bool isInit = false;
    if (isInit) return table[value];

#define etype(a,b,c) table[ Back_Pack_Type::a ] = Back_Pack_Type_Category::c;
    VALUE_Back_Pack_Type
#undef etype
        isInit = true;
    return table[value];
}

/*
                �I�]���~
*/
const string toString(Back_Pack_Type value) {
    static map<Back_Pack_Type, string> table;
    static bool isInit = false;
    if (isInit) return table[value];
#define etype(a,b,c) table[ Back_Pack_Type::a ] = b;
    VALUE_Back_Pack_Type
#undef etype
        isInit = true;
    return table[value];
}

const Back_Pack_Type toBack_Pack_Type(string value) {
    static map<string, Back_Pack_Type> table;
    static bool isInit = false;
    if (isInit) return table[value];
#define etype(a,b,c) table[ b ] = Back_Pack_Type::a;
    VALUE_Back_Pack_Type
#undef etype
        isInit = true;
    return table[value];
}

const Back_Pack_Szie toBack_Pack_Size(string _back_pack_size) {
    static map<string, Back_Pack_Szie> table;
    static bool isInit = false;
    if (isInit) return table[_back_pack_size];
#define etype(a,b) table[ b ] = Back_Pack_Szie::a;
    VALUE_BACK_PACK_SIZE
#undef etype
        isInit = true;
    return table[_back_pack_size];
}

const string toString(Back_Pack_Szie _size) {
    static map<Back_Pack_Szie, string> table;
    static bool isInit = false;
    if (isInit) return table[_size];
#define etype(a,b) table[ Back_Pack_Szie::a ] = b;
    VALUE_BACK_PACK_SIZE
#undef etype
        isInit = true;
    return table[_size];
}

/*
                �ر�
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
                ¾�~
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