#ifndef MAP_H
#define MAP_H

#include "Map_object.h"
#include <map>
#include "../LifeEntity/Roles/Roles.h"
using std::vector;
using std::string;
#define MAP_WIDTH_DEF 150
#define MAP_HIGH_DEF  48



class Game_Map{
private:
	//Map_object::objectType** MapType;
	int width, high;
	string Map_name;
	vector<Map_object*> object;
    Roles* roles;
	void getObject(string _Map_name);
public:
	Game_Map(const string Map_name, int _width = MAP_WIDTH_DEF, int _high = MAP_HIGH_DEF);
	~Game_Map();

	//Map_object::objectType getMap(int _x, int _y);
	//Map_object::objectType** getMap();
	//void setMapType(int _x, int _y, Map_object::objectType _object);
	//void setMapType(int _x, int _y, int width, int heigh, Map_object::objectType _object);
	int getWidth();
	int getHigh();
    Roles* getRoles();
    string get_Map_Name();

    vector<Map_object*>& get_Object_List();

    void setRoles(Roles *_roles);

	void addObject(Map_object* obj);
	void showObject();
	void showWall();
    static void read_Map(map<string, Game_Map*>&);

    void show_Map_And_Roles(const bool is_Draw_Map_Object, const bool is_Draw_Roles_Object = true);

    void Main_Draw(bool& _isDraw, bool& _isDrawMap);

    bool Map_Transmission(Game_Map* _map, Map_object* _obj);
};

#endif