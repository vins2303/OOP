#ifndef _TYPE_H_
#define _TYPE_H_

#include <string>
#include <map>
#include <vector>
using namespace std;

/*
                                 �I�]���~
*/
#define VALUE_Back_Pack_Type \
	etype(Weapon, "�Z��") \
	etype(Deputy, "�ƪZ��") \
	etype(Helmet, "�Y��") \
    etype(Breastplate, "�ݥ�")\
    etype(Pants, "�Ǥl")\
    etype(Shoes, "�c�l")\
    etype(Consumables, "���ӫ~")\
    etype(Sundries, "����")

#define etype(a, b) a,
enum class Back_Pack_Type : int { VALUE_Back_Pack_Type };
#undef etype

const string toString(Back_Pack_Type value);
const Back_Pack_Type toEquipment_Type(string value);

/*
                               �ر�
*/
#define VALUE_Race_Type \
	etype(Human, "�H��") \
	etype(Orc, "�~�H") \
	etype(Dwarf, "�G�H")\
    etype(null, "NULL")

#define etype(a,b) a,
enum class RaceType : int { VALUE_Race_Type };
#undef etype

const RaceType toRace_Type(string _race);
const string toString(RaceType _race);
vector<RaceType> toRaceType_List(vector<string>);

/*
                               ¾�~
*/
#define VALUE_Role_Type \
	etype(Warrior, "�C�h") \
	etype(Magician, "�k�v") \
	etype(Pirate, "���s")\
    etype(null, "NULL")

#define etype(a,b) a,
enum class RoleType : int { VALUE_Role_Type };
#undef etype

const RoleType toRole_Type(string   _type);
const string toString(RoleType _type);
vector<RoleType> toRoleType_List(vector<string>);

#endif