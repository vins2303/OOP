
#include "../../include/Map/Game_Map.h"
//讀取物件
void Game_Map::getObject(string _Map_name) {
	ifstream Read(_Map_name);
	Map_object* obj;
	string name;
    string file_path;
	string type;
	int x, y, width, heigh;

    if (!Read.is_open()) {
        assert(Read);

        //Error::showOpenError("Map.cpp", "getObject()", _Map_name);
        return;
    }

    //讀取地圖物件
	while (Read >> file_path >> name >> type >> x >> y >> width >> heigh) {
		
		setMapType(x, y, width, heigh, Map_object::StringToObjectType(type));
		obj = new Map_object(file_path, name, Map_object::StringToObjectType(type), x, y, width, heigh);
		object.push_back(obj);
	}
	Read.close();
}


Game_Map::Game_Map(string _Map_name, int _width, int _high) :width(_width), high(_high), Map_name(_Map_name), roles(NULL) {
	MapType = new Map_object::objectType * [_high];
	for (int i = 0; i < _high; i++)
		MapType[i] = new Map_object::objectType[_width];
	getObject("Data\\Image\\Map_object\\" + _Map_name + (_Map_name.find(".txt")==-1?".txt":""));
}

Game_Map::~Game_Map() {
	for (int i = 0; i < high; i++)
		delete[] MapType[i];
	delete[] MapType;
	for (vector<Map_object*>::iterator it = object.begin(); it != object.end(); it++)
		delete* it;
	object.clear();
}

Map_object::objectType Game_Map::getMap(int _x, int _y) {
	return MapType[_y][_x];
}

Map_object::objectType** Game_Map::getMap() {
	return MapType;
}

void Game_Map::setMapType(int _x, int _y, Map_object::objectType _object) {
	MapType[_y][_x] = Map_object::objectType(_object);

}

void Game_Map::setMapType(int _x, int _y, int width, int heigh, Map_object::objectType _object) {
	for (int i = _y; i < _y + heigh; i++)
		for (int j = _x; j < _x + width; j++)
			MapType[_y][_x] = Map_object::objectType(_object);
}


int Game_Map::getWidth() { return width; }
int Game_Map::getHigh() { return high; }

void Game_Map::addObject(Map_object* obj) {
	object.push_back(obj);
}

void Game_Map::showWall() {
	Draw::setXY(0, 0);

	for (int i = 0; i < MAP_WIDTH_DEF / 2 + 1; i++)
		cout << "＝";
	Draw::setXY(0, 42);
	for (int i = 0; i < MAP_WIDTH_DEF / 2 + 1; i++)
		cout << "＝";

	for (int i = 1; i < MAP_HIGH_DEF; i++) {
		Draw::setXY(0, i);
		cout << "∥";
		Draw::setXY(102, i);
		cout << "∥";
	}

}

void Game_Map::showObject() {
	showWall();

	for (vector<Map_object*>::iterator it = object.begin(); it != object.end(); it++) {
		Draw::show((*it)->get_seat_X(), (*it)->get_seat_Y(), (*it)->getImage());
	}
}




void Game_Map::read_Map(map<string, Game_Map*>& map_list) {
    vector<string> getMapName;
    Game_Map* Read_Map;
    Tool::findFile("Data/Image/Map_object", getMapName);
    for (vector<string>::iterator it = getMapName.begin(); it != getMapName.end(); it++) {
        Read_Map = new Game_Map(*it);
        map_list[(*it).substr(0, (*it).rfind("."))] = Read_Map;
    }
}


void Game_Map::show_Map_And_Roles(const bool is_Draw_Map_Object, const bool is_Draw_Roles_Object) {
    if (roles != NULL) {
        if (is_Draw_Map_Object) {
            this->showObject();
        }

        if (is_Draw_Roles_Object) {
            this->roles->showObject();
        }

    }
}


void Game_Map::setRoles(Roles* _roles) {
    if (_roles != NULL) roles = _roles;
}

Roles* Game_Map::getRoles() {return roles;}

vector<Map_object*>& Game_Map::get_Object_List() { return object; }

void Game_Map::Main_Draw(bool& _isDraw, bool& _isDrawMap) {
    if (_isDraw) {
        _isDraw = false;
        if (getRoles() != NULL) {
            show_Map_And_Roles(_isDrawMap);
            _isDrawMap = false;
               
        }
    }
}