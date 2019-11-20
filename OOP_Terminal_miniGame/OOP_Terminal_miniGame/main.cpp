// #pragma execution_character_set("utf-8")
#include<iostream>
// #include<fstream>
#include<string>
#include<cstring>
#include <conio.h>

#include "./include/Map/Draw.h" 
#include "./include/Map/Map.h" 
#include "./include/Map/Figure_Rect.h" 

using namespace std;

Map* map;

COORD point;
#define MAX_LENGTH 500
void Game_initial() {
	map = new Map("Market");
	system("pause");
	system("cls");
	map->showObject();

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
	Draw::showObject(20,20,"Image\\Monster.txt", "Rabbit");
	while (1)
	{
		// _getch();
		Key();

	}

	return 0;
}