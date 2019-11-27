#ifndef MAP_OBHECT_H
#define MAP_OBHECT_H
#include<iostream>
//#include<vector>
#include <algorithm>
#include"Draw.h"

using std::string;



class Map_object {
public:
    enum class objectType : int{
        null = 0,    //無
        Warrior = 1, //人
        Houst = 2,   //房子
        Wall = 3,    //牆壁
        Boor = 4,  //傳送門
        Monster = 5,  //怪物
        FoorColor= 6 //玩家
    };

private:
	objectType object;
	int X, Y, width, heigh;
	string image;
	string object_name;
public:
	Map_object(string _objectPath, string _object_name, objectType _objectType, int _x, int _y, int _width, int _heigh);
    
    static objectType StringToObjectType(string _str);

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