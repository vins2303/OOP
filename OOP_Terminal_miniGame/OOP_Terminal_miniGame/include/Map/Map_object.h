#ifndef MAP_OBHECT_H
#define MAP_OBHECT_H
#include<iostream>
#include <algorithm>
#include"Draw.h"

using std::string;

enum class objectType : int {
    null = 0,    //�L
    Warrior = 1, //�H
    Houst = 2,   //�Фl
    Wall = 3,    //���
    Boor = 4,  //�ǰe��
    Monster = 5,  //�Ǫ�
    FoorColor = 6 //���a
};

objectType StringToObjectType(string _str);

class Map_object {
private:
    objectType object;
    int X, Y, width, heigh;
    string image;
    string object_name;
public:
    Map_object(string _objectPath, string _object_name, objectType _objectType, int _x, int _y, int _width, int _heigh);
    virtual void* get_This();

    bool operator == (const Map_object& object);

    objectType get_Object_Type();

    Map_object setObject(objectType _M);

    int get_seat_X();
    int get_seat_Y();
    int get_Map_Width();
    int getHeigh();
    string getImage();
    string getName();

    void set_Point_X(int _x);
    void set_Point_Y(int _y);

    void setWidth(int _width);
    void setHeight(int _height);

    void showObject();
    void clear_Draw_Object();

    Map_object* Object_Overlapping(vector<Map_object*>& _object);
};

#endif