#ifndef MAP_H
#define MAP_H

#include "Figure_Rect.h"
#include "Draw.h"
#include <vector>
#include <fstream>
#include <string.h>
// #include "./Map_object.h"
using std::vector;
using std::string;
#define MAP_WIDTH_DEF 102
#define MAP_HIGH_DEF  42


class Map{
private:
	objectType **MapType;
	int width, high;
	string Map_name;
	vector<Map_object*> object;

	void getObject(string _Map_name);
public:
	Map(const string Map_name, int _width = MAP_WIDTH_DEF, int _high = MAP_HIGH_DEF);
	~Map();

	objectType getMap(int _x, int _y);
	objectType** getMap();
	Map setMapType(int _x, int _y, objectType _object);
	Map setMapType(int _x, int _y, int width, int heigh, objectType _object);
	int getWidth();
	int getHigh();
	Map addObject(Map_object *obj);
	Map showObject();
	Map showWall();
};

#endif