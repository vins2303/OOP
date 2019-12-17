#include "../../include/Map/Game_Map.h"
//讀取物件
void Game_Map::Read_Map_Object(string _Map_name) {
    ifstream Read(_Map_name);
    Map_object* obj;
    string name;
    string file_path;
    string type;
    int x, y, width, heigh;

    if (!Read.is_open()) {
        assert(Read);
        return;
    }

    //讀取地圖物件
    while (Read >> file_path >> name >> type >> x >> y >> width >> heigh) {
        obj = new Map_object(file_path, name, StringToObjectType(type), x, y, width, heigh);
        object.push_back(obj);
    }
    Read.close();
}

Game_Map::Game_Map(string _Map_name, int _width, int _high) :
    width(_width),
    high(_high),
    Map_Name(_Map_name),
    roles(NULL),
    Map_Pos(_Map_name)
{
    Read_Map_Object(Map_Object_Path(_Map_name));
    //SetTimer(this->GetSafeHwnd(), 1, 1000, Monster_Move_Time);
}

Game_Map::~Game_Map() {
    //KillTimer(1);
    for (vector<Map_object*>::iterator it = object.begin(); it != object.end(); it++)
        delete* it;
    object.clear();
}

int Game_Map::get_Width() { return width; }
int Game_Map::get_Map_High() { return high; }

void Game_Map::addObject(Map_object* obj) { object.push_back(obj); }

void Game_Map::showWall() {
    Draw::setXY(0, 0);
    cout << "┌";
    for (int i = 0; i < MAP_WIDTH_DEF - 1; i++)
        cout << "─";
    cout << "┐";

    Draw::setXY(0, MAP_HIGH_DEF - 1);
    cout << "└";
    for (int i = 0; i < MAP_WIDTH_DEF - 1; i++)
        cout << "─";
    cout << "┘";

    for (int i = 1; i < MAP_HIGH_DEF - 1; i++) {
        Draw::setXY(0, i);
        cout << "│";
        Draw::setXY(MAP_WIDTH_DEF, i);
        cout << "│";
    }
}

void Game_Map::showObject() {
    showWall();

    for (vector<Map_object*>::iterator it = object.begin(); it != object.end(); it++) {
        Draw::show((*it)->get_Point_X(), (*it)->get_Point_Y(), (*it)->getImage());
    }
}

void Game_Map::Read_Map(map<string, Game_Map*>& map_list) {
    vector<string> getMapName;
    Game_Map* Read_Map;
    Tool::findFile("Data/Map/Map_object", getMapName);
    for (vector<string>::iterator it = getMapName.begin(); it != getMapName.end(); it++) {
        Read_Map = new Game_Map((*it).substr(0, (*it).rfind('.')));
        map_list[(*it).substr(0, (*it).rfind("."))] = Read_Map;
    }
}

void Game_Map::show_Map_And_Roles(const bool is_Draw_Map_Object, const bool is_Draw_Roles_Object) {
    if (roles != NULL) {
        if (is_Draw_Map_Object) system("cls");

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

Roles* Game_Map::getRoles() { return roles; }
string Game_Map::get_Map_Name() { return Map_Name; }

int Game_Map::getNumber_of_Monster() {
    int number = 0;
    for (vector<Map_object*>::iterator it = object.begin(); it != object.end(); it++)
        if ((*it)->get_Object_Type() == objectType::Monster) number++;
    return number;
}

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

void Game_Map::Clear_0HP_Monster() {
    for (vector<Map_object*>::iterator it = object.begin(); it != object.end(); it++) {
        if ((*it)->get_Object_Type() == objectType::Monster && ((Monster*)(*it))->getHP() == 0) {
            object.erase(it);
            it = object.begin();
        }
    }
}

bool Game_Map::Map_Transmission(Game_Map* _map, Map_object* _obj) {
    _map->setRoles(roles);
    roles->setMap_Now(_map->get_Map_Name());
    if (roles->get_Point_X() > width / 3 * 2)
        roles->set_Point_X(1 + _obj->get_Width());
    else if (roles->get_Point_X() < width / 3)
        roles->set_Point_X(width - roles->get_Width() - _obj->get_Width());

    if (roles->get_Point_Y() > high / 3 * 2)
        roles->set_Point_Y(1 + _obj->getHeigh());
    else if (roles->get_Point_Y() < high / 3)
        roles->set_Point_Y(high - roles->getHeigh() - _obj->getHeigh() - 1);

    this->roles = NULL;
    return true;
}

void Game_Map::Rand_Monster(string _Map_Name) {
    if (_Map_Name == "") _Map_Name = Map_Monster_Path(Map_Name);
    ifstream Read(_Map_Name);
    Monster* monster;
    int point_x, point_y;
    string name;
    string file_path;
    string type;
    int min_size, max_szie, width, heigh, rand_size;

    if (!Read.is_open()) {
        assert(Read);
        return;
    }

    for (vector<Map_object*>::iterator it = object.begin(); it != object.end(); it++) {
        if ((*it)->get_Object_Type() == objectType::Monster) {
            delete* it;
            object.erase(it);
            it = object.begin();
        }
    }

    //讀取怪物物件
    while (Read >> file_path >> name >> type >> width >> heigh >> min_size >> max_szie) {
        rand_size = ((max_szie - min_size) == 0 ? max_szie : (rand() % (max_szie - min_size)) + min_size);
        for (int i = 0; i < rand_size; i++) {
            monster = NULL;
            do {
                point_x = rand() % (this->width - width - 1) + 1;
                point_y = rand() % (this->high - heigh - 2) + 1;

                if (monster == NULL) {
                    monster = new Monster(Map_object(file_path, name, StringToObjectType(type), point_x, point_y, width, heigh));
                }
                else {
                    monster->set_Point_X(point_x);
                    monster->set_Point_Y(point_y);
                }
            } while (monster->Object_Overlapping(object) != NULL || (*monster == *roles));
            object.push_back(monster);
        }
    }
    Read.close();
}

void Game_Map::Monster_Move_Time() {
    static int back_x, back_y;
    static int save_time = time(NULL);
    if (time(NULL) - save_time >= 1) {
        save_time = time(NULL);
        for (vector<Map_object*>::iterator it = object.begin(); it != object.end(); it++) {
            if ((*it)->get_Object_Type() == objectType::Monster) {
                if (rand() % 2) {
                    back_x = (*it)->get_Point_X();
                    back_y = (*it)->get_Point_Y();

                    switch (rand() % 4) {
                    case 0:
                        (*it)->set_Point_X(back_x - 2);
                        break;
                    case 1:
                        (*it)->set_Point_X(back_x + 2);
                        break;

                    case 2:
                        (*it)->set_Point_Y(back_y - 1);

                        break;
                    case 3:
                        (*it)->set_Point_Y(back_y + 1);

                        break;
                    }
                    if ((*it)->Object_Overlapping(object) != NULL || ((**it) == *roles) || (*it)->get_Point_X() <= 1 || (*it)->get_Point_Y() <= 1 || (*it)->get_Point_X() + (*it)->get_Width() >= width || (*it)->get_Point_Y() + (*it)->getHeigh() >= high) {
                        (*it)->set_Point_X(back_x);
                        (*it)->set_Point_Y(back_y);
                    }
                    else
                    {
                        Draw::clearMap(back_x, back_y, (*it)->get_Width(), (*it)->getHeigh());
                        (*it)->showObject();
                    }
                }
            }
        }
    }
}