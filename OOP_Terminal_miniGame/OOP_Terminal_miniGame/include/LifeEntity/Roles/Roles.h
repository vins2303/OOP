#ifndef FOOT_COLOR
#define FOOT_COLOR

#include "../LifeAttributes.h"
#include <string>
#include <math.h>
#include <Windows.h>
#include "../../Map/Map_object.h"
#include "Equipment.h"
#include "Race.h"
using std::string;

class Roles : public  LifeAttributes, public Equipment, public Race {
public:
    enum class RoleType {
        劍士, //劍士
        法師,//法師
        海盜    //海盜
    };

private:
    string name;
    int exp; // (LV-1)^3 + 60
    int drop; //調寶率
    Map_object *object;//腳色物件
    RoleType role;
    //Race::RaceType race;
public:
    Roles(string _name, int _LV, int _nowHP, int _nowMP, int _Exp, Race::RaceType _race, RoleType _role);

    ~Roles();

    string getName();
    int getExp();
    int getUpExp();
    int getDrop();
    string getRoleType();
   
    string setName(string _name);
    int setExp(int _exp);
    int setDrop(int _drop);


    int addExp(int _exp, bool percent = false);
    int addDrop(int _drop);

    bool isUpLv();

    static RoleType StringToRolesType(string _type);
    static string RolesTypeToString(RoleType _type);
    static inline int sum_Attributes(Race::RaceType _race, RoleType _role, string _att);
};

#endif