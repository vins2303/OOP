#ifndef MAP_H
#define MAP_H

#include "Map_object.h"
#include "..\\Error\\Error.h"
using std::vector;
using std::string;
#define MAP_WIDTH_DEF 102
#define MAP_HIGH_DEF  42



class Map {
private:
	Map_object::objectType** MapType;
	int width, high;
	string Map_name;
	vector<Map_object*> object;

	void getObject(string _Map_name);
public:
	Map(const string Map_name, int _width = MAP_WIDTH_DEF, int _high = MAP_HIGH_DEF);
	~Map();

	Map_object::objectType getMap(int _x, int _y);
	Map_object::objectType** getMap();
	void setMapType(int _x, int _y, Map_object::objectType _object);
	void setMapType(int _x, int _y, int width, int heigh, Map_object::objectType _object);
	int getWidth();
	int getHigh();
	void addObject(Map_object* obj);
	void showObject();
	void showWall();
};

#endif