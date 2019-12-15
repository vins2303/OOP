#ifndef _MONSTER_H_
#define _MONSTER_H_

#include <Windows.h>
#include <string>
using std::string;

#include "../../Map/Map_object.h"
#include "../../LifeEntity/LifeAttributes.h"
#include "Drop.h"

#define Read_Moater_Attributes_ini( _lpAppName, _lpKeyName) GetPrivateProfileInt(_lpAppName, _lpKeyName, INT_MAX, "Data/Attributes/Monster/Moster.ini")
#define Read_Moater_DROP_PATH(Monst_Name) ("Data/Attributes/Monster/Drop/" + (Monst_Name) + ".txt")

class Monster : public Map_object, public LifeAttributes {
private:
    int exp;
    int Money;
    vector<Drop*> drop;
public:
    Monster(Map_object _object);
    virtual ~Monster();
    void show_info(int _x, int _y = 0);

    int getExp();
    int getMoney();
    vector<Drop*>& getDrop();
private:
    vector<Drop*> Read_Drop();
};

#endif