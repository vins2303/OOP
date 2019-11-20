#pragma execution_character_set("utf-8")
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include <conio.h>
#include <atlstr.h>
#include "Attributes.h"
#include "Draw.h"
#include "keyboard.h"
#include "Map_object.h"
#include "Map.h"
using namespace std;

Map Now_Map;

COORD point;
#define MAX_LENGTH 500
void Game_initial() {
	

}


void Key() {
	if (_kbhit()) {
		switch (_getch())
		{
		case 'W':
		case 'w':
			Draw::clearMap(point.X, point.Y, Warrior_width, Warrior_high);
			Draw::showObject(point.X, --point.Y, "./Image/object.txt", "Warrior");
			break;
		case 'A':
		case 'a':
			Draw::clearMap(point.X, point.Y, Warrior_width, Warrior_high);
			Draw::showObject(--point.X, point.Y, "./Image/object.txt", "Warrior");
			break;
		case 'S':
		case 's':
			Draw::clearMap(point.X, point.Y, Warrior_width, Warrior_high);
			Draw::showObject(point.X, ++point.Y, "./Image/object.txt", "Warrior");
			break;

		case 'D':
		case 'd':
			Draw::clearMap(point.X, point.Y, Warrior_width, Warrior_high);
			Draw::showObject(++point.X, point.Y, "./Image/object.txt", "Warrior");

			break;
		default:
			break;
		}

	}
}



int main() {
	Game_initial();
	point.X = 2;
	point.Y = 1;
	//Draw::showMap_wall();

	Draw::showObject(60, 20, "./Image/Monster.txt", "Rabbit");
	//Map::setXY(50, 50);
	while (1)
	{
		Key();
		
	}

	return 0;
}