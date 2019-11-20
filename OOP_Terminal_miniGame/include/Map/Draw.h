#ifndef DRAW_H
#define DRAW_H

#include<iostream>
#include<string>
#include<windows.h>
#include<fstream>
#include<vector>

// #include"Map.h"
using namespace std;

#define Warrior_width 3
#define Warrior_high  4
#define Houst_width   14
#define Houst_high    6

namespace Draw{
	void setXY(int _x, int _y);
	//static void showMap_wall();
	void showObject(int _x, int _y, string path, string _image);
	void clearMap(int _x, int _y, int _width, int _heigh);
	string getImage(string path, string _image, string end = "END");
	void show(int _x, int _y, string _image);
}

#endif
