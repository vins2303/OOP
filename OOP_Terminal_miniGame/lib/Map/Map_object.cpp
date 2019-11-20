#include "../../include/Map/Map_object.h"

Map_object::Map_object(string _object_name, objectType _object, int _x, int _y, int _width, int _heigh)
:object(_object),  
object_name(_object_name), 
X(_x), Y(_y),
 width(_width), 
 heigh(_heigh),
 image(Draw::getImage("Image/object.txt",_object_name)){

}

objectType Map_object::getObject() {
	return object;
}

Map_object Map_object::setObject(objectType _M) {
	object = _M;
	return *this;
}

int Map_object::getX(){ return X;}
int Map_object::getY(){return Y;}
int Map_object::getWidth(){return width;}
int Map_object::getHeigh(){return heigh;}
string Map_object::getImage(){return image;}
Map_object Map_object::setX(int _x){
	X = _x;
	return *this;	
}
Map_object Map_object::setY(int _y){
	Y = _y;
	return *this;	
}
Map_object Map_object::setWidth(int _width){
	width = _width;
	return *this;	
}
Map_object Map_object::setHeight(int _height){
	heigh = heigh;
	return *this;		
}

string Map_object::getName(){
	return object_name;
}