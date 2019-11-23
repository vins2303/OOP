#ifndef MAP_OBHECT_H
#define MAP_OBHECT_H
#include<iostream>
#include<vector>
#include "objectType.h"
#include"Draw.h"

using std::string;

class Map_object {
private:
	objectType object;
	int X, Y, width, heigh;
	string image;
	string object_name;
public:
	Map_object(string _objectPath, string _object_name, objectType _objectType, int _x, int _y, int _width, int _heigh);

	objectType getObject();

	Map_object setObject(objectType _M);

	int getX();
	int getY();
	int getWidth();
	int getHeigh();
	string getImage();
	string getName();

	void setX(int _x);
	void setY(int _y);
	void setWidth(int _width);
	void setHeight(int _height);

};

#endif