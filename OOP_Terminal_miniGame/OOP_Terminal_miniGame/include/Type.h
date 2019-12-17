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
	    etype(Weapon, "武器", Equipment) \
	    etype(Deputy, "副武器", Equipment) \
	    etype(Helmet, "頭盔", Equipment) \
        etype(Breastplate, "胸甲", Equipment)\
        etype(Pants, "褲子", Equipment)\
        etype(Shoes, "鞋子", Equipment)\
        etype(Consumables, "消耗品", Consumables)\
        etype(Sundries, "雜物", Sundries)\
        etype(SubBackPack, "子背包", SubBackPack)

#define etype(a, b, c) a,
enum class Back_Pack_Type : int { VALUE_Back_Pack_Type };
#undef etype

const string toString(Back_Pack_Type value);
const Back_Pack_Type toBack_Pack_Type(string value);

#define VALUE_Back_Pack_Type_Category \
        etypeX(Equipment)\
        etypeX(Consumables)\
        etypeX(Sundries)\
        etypeX(SubBackPack)

#define etypeX(a) a,
enum class Back_Pack_Type_Category :int { VALUE_Back_Pack_Type_Category };
#undef etypeX

const Back_Pack_Type_Category toBack_Pack_Type_Category(Back_Pack_Type value);

//const Back_Pack_Type_

/*
                            背包大小
*/
#define VALUE_BACK_PACK_SIZE\
	   etype(Back_Pack_Min, "小型背包") \
	   etype(Back_Pack_Mid, "中型背包") \
	   etype(Back_Pack_Max, "大型背包") \

#define etype(a,b) a,
enum class Back_Pack_Szie : int { VALUE_BACK_PACK_SIZE };
#undef etype

const Back_Pack_Szie toBack_Pack_Size(string _back_pack_size);
const string toString(Back_Pack_Szie _size);

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