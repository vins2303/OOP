#ifndef _SKILL_H_
#define _SKILL_H_

//#include <iostream>
//using namespace std;
#include "../../Attributes.h"
#include "../../../Type.h"
#include "../../../Account/Account.h"
#include "../Restricted.h"

#define Read_SKILL_INI_PATH "Data/Attributes/Skill/Skill.ini"
#define Read_SKILL_int_ini( lpAppName,lpKeyName) GetPrivateProfileInt((lpAppName).c_str(), lpKeyName, INT_MAX, Read_SKILL_INI_PATH)

class Skill :public Attributes, public Restricted {
private:
    string Name;
    string Help;
    int Cooling_Time;//冷卻時間
    int Duration;//持續時間
    int Now_Cooling_Time;
    int Consume_MP;
    int LV;

public:
    Skill(string _name, int LV);
    ~Skill();

    bool operator==(const Skill& skill);
    int getLV();
    int Up_LV(int num = 1);
    string getName();
    int getCooling_Time();
    int get_Now_Cooling_Time();
    int get_Consume_MP();
    int get_Duration();

    void setDuration(int num = 0);
    void show_info(int _now = false);
    void Casting_Skills();

    int Round_End_US_Skill();
    int Round_End_Restore();

    int getHP();
    int getMP();
    int getAttack();
    int getSP();
    int getDef();
    int getCRT();
    int getDrop();
};

#endif // ! _SKILL_H_
