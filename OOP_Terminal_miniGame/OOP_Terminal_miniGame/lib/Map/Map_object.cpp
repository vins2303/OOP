#include "../../include/Map/Map_object.h"

Map_object::Map_object(string _objectPath, string _object_name, Map_object::objectType _object, int _x, int _y, int _width, int _heigh)
	:object(_object),
	object_name(_object_name),
	X(_x), Y(_y),
	width(_width),
	heigh(_heigh),
	image(Draw::getImage(_objectPath, _object_name)) {
}

Map_object::objectType Map_object::getObject() {
	return object;
}

Map_object Map_object::setObject(Map_object::objectType _M) {
	object = _M;
	return *this;

}

int Map_object::getX() { return X; }
int Map_object::getY() { return Y; }
int Map_object::getWidth() { return width; }
int Map_object::getHeigh() { return heigh; }
string Map_object::getImage() { return image; }
void Map_object::setX(int _x) {
	X = _x;
}
void Map_object::setY(int _y) {
	Y = _y;
}
void Map_object::setWidth(int _width) {
	width = _width;
}
void Map_object::setHeight(int _height) {
	heigh = heigh;
}

string Map_object::getName() {
	return object_name;
}
Map_object::objectType Map_object::StringToObjectType(string _str) {
    transform(_str.begin(), _str.end(), _str.begin(), tolower);
   
        if (_str == "null")
            return Map_object::objectType::null;
        if (_str == "warrior")
            return Map_object::objectType::Warrior;
        if (_str == "houst")
            return Map_object::objectType::Houst;
        if (_str == "wall")
            return Map_object::objectType::Wall;
        if (_str == "boor")
            return Map_object::objectType::Boor;
        if (_str == "monster")
            return Map_object::objectType::Monster;
        if (_str == "foorColor")
            return Map_object::objectType::FoorColor;
 
    return Map_object::objectType::null;
}
