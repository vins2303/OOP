#ifndef _MONSTER_H_
#define _MONSTER_H_

#include <Windows.h>
#include <string>
using std::string;

#include "../../Map/Map_object.h"
#include "../../LifeEntity/LifeAttributes.h"

#define Read_Moater_Attributes_ini( _lpAppName, _lpKeyName) GetPrivateProfileInt(_lpAppName, _lpKeyName, INT_MAX, "Data/Map/Map_Monster/Moster_Attributes.ini")

class Monster : public Map_object, public LifeAttributes {
private:
    int exp;
public:
    Monster(Map_object _object);
    virtual ~Monster();
    void show_info(int _x, int _y = 0);

    int getExp();
    //void setExp(int);
};

#endif