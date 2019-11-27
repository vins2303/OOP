// #pragma execution_character_set("utf-8")
#include<iostream>
// #include<fstream>
#include<string>
#include<cstring>
#include <conio.h>

#include "include/Map/Draw.h" 
#include "include/Map/Map.h" 
#include "include/Map/Figure_Rect.h" 
#include "include/Account/Account.h"
#include "include/Account/RolesList.h"

using namespace std;

void Game_initial();
void Key();

Map* map;

COORD point;
#define MAX_LENGTH 500
Account* account;
RolesList* roleslist;
int main() {
	Game_initial();
	point.X = 2;
	point.Y = 1;
	while (1)
	{
		//Draw::setXY(0,0);
		//cout<< _getch();
		Key();
		

	}

	return 0;
}

void Game_initial() {
    account = new Account();
    account->Menu();
    roleslist = new RolesList(*account);
    roleslist->Menu();
    map = new Map("Market");
    map->showObject();

}

void Key() {

    static int k;
    if (_kbhit()) {
        switch (_getch())
        {
        case 72:

            Draw::clearMap(point.X, point.Y, Warrior_width, Warrior_high);
            Draw::showObject(point.X, --point.Y, "data/Image/object.txt", "Warrior");
            break;
        case 75:
            Draw::clearMap(point.X, point.Y, Warrior_width, Warrior_high);
            Draw::showObject(--point.X, point.Y, "data/Image/object.txt", "Warrior");
            break;
        case 80:
            Draw::clearMap(point.X, point.Y, Warrior_width, Warrior_high);
            Draw::showObject(point.X, ++point.Y, "data/Image/object.txt", "Warrior");
            break;

        case 77:
            Draw::clearMap(point.X, point.Y, Warrior_width, Warrior_high);
            Draw::showObject(++point.X, point.Y, "data/Image/object.txt", "Warrior");

            break;
        default:
            break;
        }

    }
}