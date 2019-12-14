#ifndef FOOT_COLOR
#define FOOT_COLOR

#include <iomanip>
#include "../../../include/LifeEntity/Roles/Back_Pack/Consumables.h"
#include "../LifeAttributes.h"
#include <string>
#include <math.h>
#include <Windows.h>
#include "../../Map/Map_object.h"
//#include "../../Map/Game_Map.h"
#include "Equipment/Equipment.h"
#include "Back_Pack/Back_Pack.h"
#include "Race.h"
#include "Role.h"

using std::string;

#define MAP_WIDTH_DEF 150
#define MAP_HIGH_DEF  50
#define ROLES_OBJECT_WIDTH "6"
#define ROLES_OBJECT_HEIGHT "3"

class Roles : public  LifeAttributes, public Equipment, public Race, public Role, public Map_object, public Back_Pack {
private:
    string account;
    string name;
    int exp; // (LV-1)^3 + 60
    //int drop; //½ÕÄ_²v
    //RoleType role;
    string Map_Now;
    //Race::RaceType race;
public:
    Roles(string _name, int _LV, int _nowHP, int _nowMP, int _Exp, string Map_Now, string account, RaceType _race, RoleType _role, Map_object _object);

    ~Roles();

    string getName();
    int getExp();
    int getUpExp();
    //int getDrop();
    /*string getRoleType_S();
    RoleType getRoleType();*/
    string getMap_Now();

    string setName(string _name);
    int setExp(int _exp);
    void setMap_Now(const string _map);

    int addExp(int _exp, bool percent = false);
    //int addDrop(int _drop);

    bool isUpLv();
    bool UP_LV(); //¨¤¦â¤É¯Å

    Map_object* set_Roles_Move_X(int _x, vector<Map_object*>& _object);
    Map_object* set_Roles_Move_Y(int _y, vector<Map_object*>& _object);
    void Save_Roles();
    void show_State();
    void show_EXP(bool show = true, bool LF = true);

    void Open_BackPack();
    void Back_Pack_User_Item(Goods*& _gds);

    static int sum_Attributes(RaceType _race, RoleType _role, string _att);
private:
    void Save_Roles_info();
};

#endif