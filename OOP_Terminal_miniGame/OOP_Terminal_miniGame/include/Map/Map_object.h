#ifndef MAP_OBHECT_H
#define MAP_OBHECT_H
#include<iostream>
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
    bool operator == (const Map_object& object);
    static objectType StringToObjectType(string _str);

	objectType get_Object_Type();

	Map_object setObject(objectType _M);

	int get_seat_X();
	int get_seat_Y();
	int getWidth();
	int getHeigh();
	string getImage();
	string getName();

	void set_Point_X(int _x);
	void set_Point_Y(int _y);

	void setWidth(int _width);
	void setHeight(int _height);

    void showObject();
    void clear_Draw_Object();
};

#endif