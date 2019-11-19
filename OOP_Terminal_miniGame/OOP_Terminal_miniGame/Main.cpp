#include<iostream>
#include<fstream>
#include<string>
#include <conio.h>
#include "Attributes.h"
#include "Draw.h"
#include "keyboard.h"
#include "Map_object.h"
#include "Map.h"
using namespace std;

Map Now_Map;

COORD point;

void Game_initial() {
	

}


void Key() {
	switch (getch())
	{
	case 'W':
	case 'w':
		Draw::clearMap(point.X, point.Y, Warrior_width, Warrior_high);
		Draw::showWarrior(point.X, --point.Y);
		break;
	case 'A':
	case 'a':
		Draw::clearMap(point.X, point.Y, Warrior_width, Warrior_high);
		Draw::showWarrior(--point.X, point.Y);
		break;
	case 'S':
	case 's':
		Draw::clearMap(point.X, point.Y, Warrior_width, Warrior_high);
		Draw::showWarrior(point.X, ++point.Y);
		break;

	case 'D':
	case 'd':
		Draw::clearMap(point.X, point.Y, Warrior_width, Warrior_high);
		Draw::showWarrior(++point.X, point.Y);

		break;
	default:
		break;
	}


}



int main() {
	Game_initial();
	point.X = 2;
	point.Y = 1;
	Draw::showMap_wall(Now_Map);
	Draw::showHoust(60, 20);
	Draw::showWarrior(point.X, point.Y);
	//Map::setXY(50, 50);
	while (1)
	{
		Key();
		Draw::setXY(0,0);
		cout << point.X << " " << point.Y;
	}

	
	//system("pause");
	return 0;
}