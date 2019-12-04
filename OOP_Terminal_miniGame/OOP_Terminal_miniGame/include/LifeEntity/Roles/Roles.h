#ifndef FOOT_COLOR
#define FOOT_COLOR

#include "../LifeAttributes.h"
#include <string>
#include <math.h>
#include <Windows.h>
#include "../../Map/Map_object.h"
//#include "../../Map/Game_Map.h"
#include "Equipment.h"
#include "Race.h"
using std::string;

#define MAP_WIDTH_DEF 150
#define MAP_HIGH_DEF  50
#define ROLES_OBJECT_WIDTH "6"
#define ROLES_OBJECT_HEIGHT "3"

class Roles : public  LifeAttributes, public Equipment, public Race, public Map_object {
public:
    enum class RoleType {
        劍士, //劍士
        法師,//法師
        海盜    //海盜
    };

private:
    string account;
    string name;
    int exp; // (LV-1)^3 + 60
    int drop; //調寶率
    //Map_object *object;//腳色物件
    RoleType role;
    string Map_Now;
    //Race::RaceType race;
public:
    Roles(string _name, int _LV, int _nowHP, int _nowMP, int _Exp, string Map_Now, string account, Race::RaceType _race, RoleType _role, Map_object _object);

    ~Roles();

    string getName();
    int getExp();
    int getUpExp();
    int getDrop();
    string getRoleType();
    string getMap_Now();

    string setName(string _name);
    int setExp(int _exp);
    int setDrop(int _drop);
    void setMap_Now(const string _map);

    int addExp(int _exp, bool percent = false);
    int addDrop(int _drop);

    bool isUpLv();

    Map_object* set_Roles_Move_X(int _x, vector<Map_object*>& _object);
    Map_object* set_Roles_Move_Y(int _y, vector<Map_object*>& _object);
    //Map_object* Object_overlapping(Map_object& obj, vector<Map_object*>& _object);

    void wire_Roles_info();
    static RoleType StringToRolesType(string _type);
    static string RolesTypeToString(RoleType _type);
    static int sum_Attributes(Race::RaceType _race, RoleType _role, string _att);
};

#endif