

#include<iostream>
#include<string>
#include<cstring>
#include <conio.h>
#include<map>
#include "include/Map/Draw.h" 
#include "include/Map/Game_Map.h" 
#include "include/Map/Figure_Rect.h" 
#include "include/Account/Account.h"
#include "include/Account/RolesList.h"

using namespace std;

void Game_start();
void Game_initial();
void Key(bool& _isDrawMap);


//Game_Map* map;
map<string, Game_Map*> maplist;
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
    Game_Map::read_Map(maplist);
    //maplist.find("市集")->second->showObject();
    //_getch();

}

void Game_start() {
    bool isDrawMap = true;
    while (true){
        roleslist->AccountMenu();
        roleslist->RolesListMenu();
        system("cls");
        while (roleslist->getRoles() != NULL) {
            maplist.find(roleslist->getRoles()->getMap_Now())->second->setRoles(roleslist->getRoles());
            Key(isDrawMap);
           /* maplist.find("市集")->second->showObject();
            roleslist->getRoles()->showObject();*/
        }

    }

}


void Key(bool &_isDrawMap) {
    static bool isDraw = true;
    static Map_object* overlapping_object;
    overlapping_object = NULL;
    if (_kbhit()) {
        isDraw = true;
        switch (_getch())
        {
        case 72:// Move Up
            isDraw = true;
            overlapping_object = roleslist->getRoles()->set_seat_Y( roleslist->getRoles()->get_seat_Y() - 1, maplist.find(roleslist->getRoles()->getMap_Now())->second->get_Object_List() );
            break;
        case 75:// Move Left
            isDraw = true;
            overlapping_object = roleslist->getRoles()->set_seat_X( roleslist->getRoles()->get_seat_X() - 1, maplist.find(roleslist->getRoles()->getMap_Now())->second->get_Object_List() );

            break;
        case 80:// Move Down
            isDraw = true;
            overlapping_object = roleslist->getRoles()->set_seat_Y( roleslist->getRoles()->get_seat_Y() + 1, maplist.find(roleslist->getRoles()->getMap_Now())->second->get_Object_List() );
            break;

        case 77:// Move Right
            isDraw = true;
            overlapping_object = roleslist->getRoles()->set_seat_X( roleslist->getRoles()->get_seat_X() + 1, maplist.find(roleslist->getRoles()->getMap_Now())->second->get_Object_List() );
            break;
        default:
            break;
        }
        if (overlapping_object != NULL) {
            cout << "";
        }
        
    }
    maplist.find(roleslist->getRoles()->getMap_Now())->second->Main_Draw(isDraw,_isDrawMap);
}



