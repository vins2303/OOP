#pragma once
#include<iostream>
#include <string>
#include "Map_object.h"
using std::string;

class Figure_Rect {
public:
	int X;
	int Y;
	const int width;
	const int height;
	objectType type;
	string Figure;

	Figure_Rect(int _x, int _y, int _width, int _height, string _figure, objectType _type);
	static bool isOverlap(const Figure_Rect rc1, const Figure_Rect rc2); //¯x°}­«Å|
};