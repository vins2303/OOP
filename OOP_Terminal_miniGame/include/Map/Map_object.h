#ifndef MAP_OBHECT_H
#define MAP_OBHECT_H
#include<iostream>
#include"Draw.h"

using std::string;


enum objectType{
	null ,    //無
	Warrior , //人
	Houst ,   //房子
	Wall,    //牆壁
	Boor,  //傳送門
	Monster  //怪物
};


class Map_object {
private:
	objectType object;
	int X, Y, width, heigh;
	string image;
	string object_name;
public:
	Map_object(string _object_name, objectType _object, int _x, int _y, int _width, int _heigh);

	objectType getObject();

	Map_object setObject(objectType _M);

	int getX();
	int getY();
	int getWidth();
	int getHeigh();
	string getImage();
	string getName();

	Map_object setX(int _x);
	Map_object setY(int _y);
	Map_object setWidth(int _width);
	Map_object setHeight(int _height);
	
};

#endif