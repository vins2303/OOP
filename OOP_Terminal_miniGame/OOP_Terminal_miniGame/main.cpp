

#include<iostream>
#include<string>
#include<cstring>
#include <conio.h>
#include<map>
#include "include/Map/Draw.h" 
#include "include/Map/Map.h" 
#include "include/Map/Figure_Rect.h" 
#include "include/Account/Account.h"
#include "include/Account/RolesList.h"

using namespace std;

void Game_start();
void Game_initial();
void Key();


//Map* map;
map<string, Map*> maplist;
#define MAX_LENGTH 500
RolesList* roleslist;

int main() {
	Game_initial();
    
    Game_start();
    //system("pause");
	return 0;
}

void Game_initial() {

    roleslist = new RolesList();
    Map::read_Map(maplist);
}

void Game_start() {
    while (true){
        roleslist->AccountMenu();
        roleslist->RolesListMenu();
        system("cls");
        if (roleslist->getRoles() != NULL) {

            //map = new Map("Market");
            //map->showObject();
            //_getch();
        }

    }

}


void Key() {

    /*static int k;
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

    }*/
}