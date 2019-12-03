
#ifndef DRAW_H
#define DRAW_H

//#define NDEBUG

#include <cassert>
#include<iostream>
#include<string>
#include<windows.h>
#include<fstream>
#include<vector>
#include "../../include/Tool/Tool.h"

using namespace std;

#define Warrior_width 3
#define Warrior_high  4
#define Houst_width   14
#define Houst_high    6

class Draw {
public:
    static void setXY(int _x = 0, int _y = 0);
    static void showObject(int _x, int _y, string path, string _image);
    static void clearMap(int _x, int _y, int _width, int _heigh);
    static string getImage(string path, string _image, string end = "END");
    static void show(int _x, int _y, string _image);
};

#endif
