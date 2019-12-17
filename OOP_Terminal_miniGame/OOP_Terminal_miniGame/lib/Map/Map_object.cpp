#include "../../include/Map/Map_object.h"

Map_object::Map_object(string _objectPath, string _object_name, objectType _object, int _x, int _y, int _width, int _heigh)
    :object(_object),
    object_name(_object_name),
    X(_x), Y(_y),
    width(_width),
    heigh(_heigh),
    image(Draw::getImage(_objectPath, _object_name)) {
}

Map_object::~Map_object() {}

//判斷兩個物件重疊
bool Map_object::operator == (const Map_object& object) {
    //if (&object == NULL) return false;
    if (this->get_Point_X() + this->get_Width() > object.X&&
        object.X + object.width > this->get_Point_X() &&
        this->get_Point_Y() + this->getHeigh() > object.Y&&
        object.Y + object.heigh > this->get_Point_Y()
        )
        return true;
    else
        return false;
}

objectType Map_object::get_Object_Type() { return object; }

Map_object Map_object::setObject(objectType _M) {
    object = _M;
    return *this;
}

int Map_object::get_Point_X() { return X; }
int Map_object::get_Point_Y() { return Y; }
int Map_object::get_Width() { return width; }
int Map_object::getHeigh() { return heigh; }
string Map_object::getImage() { return image; }

void Map_object::set_Point_X(int _x) { X = _x; }
void Map_object::set_Point_Y(int _y) { Y = _y; }
void Map_object::setWidth(int _width) { width = _width; }
void Map_object::setHeight(int _height) { heigh = _height; }

string Map_object::getName() { return object_name; }

objectType StringToObjectType(string _str) {
    transform(_str.begin(), _str.end(), _str.begin(), tolower);

    if (_str == "null")
        return objectType::null;
    if (_str == "warrior")
        return objectType::Warrior;
    if (_str == "houst")
        return objectType::Houst;
    if (_str == "wall")
        return objectType::Wall;
    if (_str == "boor")
        return objectType::Boor;
    if (_str == "monster")
        return objectType::Monster;
    if (_str == "foorColor")
        return objectType::FoorColor;

    return objectType::null;
}

void Map_object::showObject(int _x, int _y) {
    Draw::show(_x == INT_MAX ? X : _x, _y == INT_MAX ? Y : _y, image);
}

void Map_object::clear_Draw_Object() {
    Draw::clearMap(X, Y, this->width, this->heigh);
}

Map_object* Map_object::Object_Overlapping(vector<Map_object*>& _object) {
    for (vector<Map_object*>::iterator it = _object.begin(); it != _object.end(); it++) {
        if ((*this == **it) && (*it) != this) {
            return *it;
        }
    }
    return NULL;
}