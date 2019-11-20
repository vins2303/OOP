#ifndef MAP_H
#define MAP_H

#include "Map_object.h"
#include "Figure_Rect.h"
#include "Draw.h"
#include <vector>

using std::vector;
#define MAP_WIDTH_DEF 102
#define MAP_HIGH_DEF  42


class Map{
private:
	Map_object **map;
	int width, high;
	vector<Figure_Rect*> object;
public:
	Map(int _width = MAP_WIDTH_DEF, int _high = MAP_HIGH_DEF);
	~Map();

	Map_object getMap(int _x, int _y);
	Map_object** getMap();
	Map setMap(int _x, int _y, Map_object _object);
	
	int getWidth();
	int getHigh();
};

#endif