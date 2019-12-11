#ifndef _EQUIPMENT_ATTRIBUTES_H_
#define _EQUIPMENT_ATTRIBUTES_H_

#include "../../Attributes.h"
#include "../../../Type.h"
//#include "../Roles.h"
#include <vector>
#include <Windows.h>
#include <algorithm>

using namespace std;

class Equipment_Attributes : public Attributes {
private:
    int LV;
    string name;
    vector<RoleType> Restricted_Role;//職業限定
    vector<RaceType> Restricted_Race;//總族限定
    Back_Pack_Type type;

public:
    Equipment_Attributes(string _name, int _lv, Back_Pack_Type _type);
    virtual ~Equipment_Attributes();

    /*
                        是否可以使用
    */
    //bool Usable(Roles& _roles);
    bool Usable(const RoleType& _role, const RaceType& _race);
    bool Usable_Role(const RoleType& _role);
    bool Usable_Race(const RaceType& _race);
    /*
    */
    int getHP();
    int getMP();
    int getAttack();
    int getSP();
    int getDef();
    int getCRT();
    int getDrop();

    /*
    */
    int getLV();
    string getName();
    Back_Pack_Type& getType();
};

#endif // !_EQUIPMENT_ATTRIBUTES_H_
