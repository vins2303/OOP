#ifndef MAP_H
#define MAP_H

#include "Map_object.h"
#include <map>
#include "../LifeEntity/Roles/Roles.h"
#include "../../include/LifeEntity/Monster/Monster.h"
#include "Map_Pos.h"
using std::vector;
using std::string;

#define Map_Object_Path(_Map_name)  "Data/Map/Map_object/" + _Map_name + (_Map_name.find(".txt") == -1 ? ".txt" : "")
#define Map_Monster_Path(_Map_name) "Data/Map/Map_Monster/" + _Map_name + (_Map_name.find(".txt") == -1 ? ".txt" : "")
//#define MAP_WIDTH_DEF 150
//#define MAP_HIGH_DEF  50

class Game_Map : public Map_Pos {
private:
    //Map_object::objectType** MapType;
    int width, high;
    string Map_Name;
    vector<Map_object*> object;
    Roles* roles;
    void Read_Map_Object(string _Map_name);
public:
    Game_Map(const string Map_name, int _width = MAP_WIDTH_DEF, int _high = MAP_HIGH_DEF);
    ~Game_Map();

    //Map_object::objectType getMap(int _x, int _y);
    int getWidth();
    int getHigh();
    Roles* getRoles();
    string get_Map_Name();

    vector<Map_object*>& get_Object_List();

    void setRoles(Roles* _roles);

    void addObject(Map_object* obj);
    void showObject();
    void showWall();

    void Main_Draw(bool& _isDraw, bool& _isDrawMap);
    bool Map_Transmission(Game_Map* _map, Map_object* _obj);

    static void Read_Map(map<string, Game_Map*>&);

    /*                    Monster                    */
    void Rand_Monster(string _Map_Path = "");

    /*                    show                       */
    void show_Map_And_Roles(const bool is_Draw_Map_Object, const bool is_Draw_Roles_Object = true);
};

#endif