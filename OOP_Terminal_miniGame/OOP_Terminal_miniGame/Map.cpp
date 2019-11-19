#include "Map.h"

Map::Map(int _width, int _high):width(_width), high(_high){
	map = new Map_object*[_high];
	for (int i = 0; i < _high; i++)
		map[i] = new Map_object[_width];
}

Map::~Map() {
	for (int i = 0; i < high; i++)
		delete[] map[i];
	delete[] map;
}

Map_object Map::getMap(int _x, int _y) {
	return map[_y][_x];
}

Map_object** Map::getMap() {
	return map;
}

Map Map::setMap(int _x, int _y, Map_object _object) {
	map[_y][_x] = _object;
	return *this;
}

int Map::getWidth() { return width; }
int Map::getHigh()  { return high; }