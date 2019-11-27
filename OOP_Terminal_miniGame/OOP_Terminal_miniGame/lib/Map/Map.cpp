
#include "../../include/Map/Map.h"

//Åª¨úª«¥ó
void Map::getObject(string _Map_name) {
	ifstream Read(_Map_name);
	Map_object* obj;
	string name;
    string file_path;
	string type;
	int x, y, width, heigh;

    if (!Read.is_open()) {
        Error::showOpenError("Map.cpp", "getObject()", _Map_name);
        return;
    }

	while (!Read.eof()) {
		Read >> file_path >> name >> type >> x >> y >> width >> heigh;
		setMapType(x, y, width, heigh, Map_object::StringToObjectType(type));
		obj = new Map_object(file_path, name, Map_object::StringToObjectType(type), x, y, width, heigh);
		object.push_back(obj);
	}
	Read.close();
}


Map::Map(string _Map_name, int _width, int _high) :width(_width), high(_high), Map_name(_Map_name) {
	MapType = new Map_object::objectType * [_high];
	for (int i = 0; i < _high; i++)
		MapType[i] = new Map_object::objectType[_width];

	getObject("Data\\Image\\Map_object\\" + _Map_name + ".txt");
}

Map::~Map() {
	for (int i = 0; i < high; i++)
		delete[] MapType[i];
	delete[] MapType;
	for (vector<Map_object*>::iterator it = object.begin(); it != object.end(); it++)
		delete* it;
	object.clear();
}

Map_object::objectType Map::getMap(int _x, int _y) {
	return MapType[_y][_x];
}

Map_object::objectType** Map::getMap() {
	return MapType;
}

void Map::setMapType(int _x, int _y, Map_object::objectType _object) {
	MapType[_y][_x] = Map_object::objectType(_object);

}

void Map::setMapType(int _x, int _y, int width, int heigh, Map_object::objectType _object) {
	for (int i = _y; i < _y + heigh; i++)
		for (int j = _x; j < _x + width; j++)
			MapType[_y][_x] = Map_object::objectType(_object);
}


int Map::getWidth() { return width; }
int Map::getHigh() { return high; }

void Map::addObject(Map_object* obj) {
	object.push_back(obj);
}

void Map::showWall() {
	Draw::setXY(0, 0);

	for (int i = 0; i < MAP_WIDTH_DEF / 2 + 1; i++)
		cout << "¡×";
	Draw::setXY(0, 42);
	for (int i = 0; i < MAP_WIDTH_DEF / 2 + 1; i++)
		cout << "¡×";

	for (int i = 1; i < MAP_HIGH_DEF; i++) {
		Draw::setXY(0, i);
		cout << "¡ü";
		Draw::setXY(102, i);
		cout << "¡ü";
	}

}

void Map::showObject() {
	showWall();

	for (vector<Map_object*>::iterator it = object.begin(); it != object.end(); it++) {
		Draw::show((*it)->getX(), (*it)->getY(), (*it)->getImage());
	}
}

