#include "../../include/Map/Map_object.h"

Map_object::Map_object(string _objectPath, string _object_name, Map_object::objectType _object, int _x, int _y, int _width, int _heigh)
	:object(_object),
	object_name(_object_name),
	X(_x), Y(_y),
	width(_width),
	heigh(_heigh),
	image(Draw::getImage(_objectPath, _object_name)) {
}

//判斷兩個物件重疊
bool Map_object::operator == (const Map_object& object) {
    if (this->get_seat_X() + this->getWidth() > object.X &&
        object.X     + object.width     > this->get_seat_X() &&
        this->get_seat_Y() + this->getHeigh() > object.Y &&
        object.Y     + object.heigh     > this->get_seat_Y()
        )
        return true;
    else
        return false;
}


Map_object::objectType Map_object::getObject() {
	return object;
}

Map_object Map_object::setObject(Map_object::objectType _M) {
	object = _M;
	return *this;

}

int Map_object::get_seat_X() { return X; }
int Map_object::get_seat_Y() { return Y; }
int Map_object::getWidth() { return width; }
int Map_object::getHeigh() { return heigh; }
string Map_object::getImage() { return image; }

void Map_object::set_seat_X(int _x) { X = _x; }
void Map_object::set_seat_Y(int _y) { Y = _y; }

////判斷是否重疊
//Map_object* Map_object::Object_overlapping(Map_object & obj, vector<Map_object*>& _object) {
//    for (vector<Map_object*>::iterator it = _object.begin(); it != _object.end(); it ++ )
//        if (obj == (**it))
//            return *it;
//    return NULL;
//}

////物件移動
//Map_object* Map_object::set_seat_X(int _x, vector<Map_object*>& _object) {
//    static Map_object* over;
//    static int posX;
//    static int posX2;
//    over = NULL;
//    posX = X;
//    X = _x;
//    if ((over = Object_overlapping(*this, _object)) != NULL || X < 2 || X>99) {
//        X = posX;
//    }else {
//        posX2 = X;
//        X = posX;
//        clear_Draw_Object();
//        X = posX2;
//    }
//    return over;
//}
//
////物件移動
//Map_object* Map_object::set_seat_Y(int _y, vector<Map_object*>& _object) {
//    static Map_object* over;
//    static int posY;
//    static int posY2;
//    over = NULL;
//    posY = Y;
//    Y = _y;
//    if ((over = Object_overlapping(*this, _object)) != NULL) {
//        Y = posY;
//    }
//    else {
//        posY2 = Y;
//        Y = posY;
//        clear_Draw_Object();
//        Y = posY2;
//    }
//    return over;
//}


void Map_object::setWidth(int _width) {width = _width;}
void Map_object::setHeight(int _height) {heigh = _height;}

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

void Map_object::showObject() {
    Draw::show(X,Y, image);
}

void Map_object::clear_Draw_Object() {
    Draw::clearMap(X, Y, this->width, this->heigh);

}