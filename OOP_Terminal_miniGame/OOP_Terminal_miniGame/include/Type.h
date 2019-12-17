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
	    etype(Weapon, "�Z��", Equipment) \
	    etype(Deputy, "�ƪZ��", Equipment) \
	    etype(Helmet, "�Y��", Equipment) \
        etype(Breastplate, "�ݥ�", Equipment)\
        etype(Pants, "�Ǥl", Equipment)\
        etype(Shoes, "�c�l", Equipment)\
        etype(Consumables, "���ӫ~", Consumables)\
        etype(Sundries, "����", Sundries)\
        etype(SubBackPack, "�l�I�]", SubBackPack)

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
                            �I�]�j�p
*/
#define VALUE_BACK_PACK_SIZE\
	   etype(Back_Pack_Min, "�p���I�]") \
	   etype(Back_Pack_Mid, "�����I�]") \
	   etype(Back_Pack_Max, "�j���I�]") \

#define etype(a,b) a,
enum class Back_Pack_Szie : int { VALUE_BACK_PACK_SIZE };
#undef etype

const Back_Pack_Szie toBack_Pack_Size(string _back_pack_size);
const string toString(Back_Pack_Szie _size);

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