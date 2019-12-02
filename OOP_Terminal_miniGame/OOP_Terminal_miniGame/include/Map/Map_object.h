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
    bool operator == (const Map_object& object);
    static objectType StringToObjectType(string _str);

	objectType getObject();

	Map_object setObject(objectType _M);

	int get_seat_X();
	int get_seat_Y();
	int getWidth();
	int getHeigh();
	string getImage();
	string getName();

	void set_seat_X(int _x);
	void set_seat_Y(int _y);
    /*Map_object* set_seat_X(int _x, vector<Map_object*> &_object);
    Map_object* set_seat_Y(int _y, vector<Map_object*> & _object);*/

	void setWidth(int _width);
	void setHeight(int _height);

    void showObject();
    void clear_Draw_Object();

    /*Map_object* Object_overlapping(Map_object& obj, vector<Map_object*>& _object);*/

};

#endif