#ifndef _TYPE_H_
#define _TYPE_H_

#include <string>
#include <map>
#include <vector>
using namespace std;

/*
                                 背包物品
*/
#define VALUE_Back_Pack_Type \
	etype(Weapon, "武器") \
	etype(Deputy, "副武器") \
	etype(Helmet, "頭盔") \
    etype(Breastplate, "胸甲")\
    etype(Pants, "褲子")\
    etype(Shoes, "鞋子")\
    etype(Consumables, "消耗品")\
    etype(Sundries, "雜物")

#define etype(a, b) a,
enum class Back_Pack_Type : int { VALUE_Back_Pack_Type };
#undef etype

const string toString(Back_Pack_Type value);
const Back_Pack_Type toEquipment_Type(string value);

/*
                               種族
*/
#define VALUE_Race_Type \
	etype(Human, "人族") \
	etype(Orc, "獸人") \
	etype(Dwarf, "矮人")\
    etype(null, "NULL")

#define etype(a,b) a,
enum class RaceType : int { VALUE_Race_Type };
#undef etype

const RaceType toRace_Type(string _race);
const string toString(RaceType _race);
vector<RaceType> toRaceType_List(vector<string>);

/*
                               職業
*/
#define VALUE_Role_Type \
	etype(Warrior, "劍士") \
	etype(Magician, "法師") \
	etype(Pirate, "海盜")\
    etype(null, "NULL")

#define etype(a,b) a,
enum class RoleType : int { VALUE_Role_Type };
#undef etype

const RoleType toRole_Type(string   _type);
const string toString(RoleType _type);
vector<RoleType> toRoleType_List(vector<string>);

#endif