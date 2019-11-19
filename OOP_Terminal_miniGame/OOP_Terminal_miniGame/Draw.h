#ifndef DRAW_H
#define DRAW_H

#include<iostream>
#include<string>
#include<windows.h>
#include"Map.h"
using namespace std;

#define Warrior_width 3
#define Warrior_high  4


class Draw {
private:


public:
	static void setXY(int _x, int _y);
	static void showMap_wall(Map &_map);
	static void showHoust(int _x, int _y);
	static void showWarrior(int _x, int _y);
	static void clearMap(int _x, int _y, int _width, int _heigh);
};

#endif
