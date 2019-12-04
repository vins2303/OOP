#include "../../include/keyboard_Event/Keyboard_Event.h"

Keyboard_Event::Keyboard_Event(map<string, Game_Map*>* _map, RolesList* _roleslist)
    :maplist(_map), roleslist(_roleslist) {}

void Keyboard_Event::Run() {
    bool isDrawMap = true;
    while (true) {
        roleslist->AccountMenu();
        roleslist->RolesListMenu();
        //system("cls");

        if (roleslist->getRoles() != NULL) {
            maplist->find(roleslist->getRoles()->getMap_Now())->second->setRoles(roleslist->getRoles());
            maplist->find(roleslist->getRoles()->getMap_Now())->second->Rand_Monster();
        }
        while (roleslist->getRoles() != NULL) {
            //maplist[roleslist->getRoles()->getMap_Now()]->setRoles(roleslist->getRoles());

            Read_Key(isDrawMap);
        }
    }
}

void Keyboard_Event::Read_Key(bool& _isDrawMap) {
    static bool isDraw = true;
    static Map_object* overlapping_object;
    overlapping_object = NULL;
    if (_kbhit()) {
        isDraw = true;
        switch (_getch())
        {
        case 72:// Move Up
            isDraw = true;
            overlapping_object = roleslist->getRoles()->set_Roles_Move_Y(roleslist->getRoles()->get_seat_Y() - 1, maplist->find(roleslist->getRoles()->getMap_Now())->second->get_Object_List());
            break;
        case 75:// Move Left
            isDraw = true;
            overlapping_object = roleslist->getRoles()->set_Roles_Move_X(roleslist->getRoles()->get_seat_X() - 1, maplist->find(roleslist->getRoles()->getMap_Now())->second->get_Object_List());

            break;
        case 80:// Move Down
            isDraw = true;
            overlapping_object = roleslist->getRoles()->set_Roles_Move_Y(roleslist->getRoles()->get_seat_Y() + 1, maplist->find(roleslist->getRoles()->getMap_Now())->second->get_Object_List());
            break;

        case 77:// Move Right
            isDraw = true;
            overlapping_object = roleslist->getRoles()->set_Roles_Move_X(roleslist->getRoles()->get_seat_X() + 1, maplist->find(roleslist->getRoles()->getMap_Now())->second->get_Object_List());
            break;

        case 'm':
            Show_Map_Pos();
            isDraw = true;
            _isDrawMap = true;
            break;

        default:
            break;
        }
    }
    if (overlapping_object != NULL) {
        _isDrawMap = Overlapping_Object(overlapping_object);
        overlapping_object = NULL;
    }
    maplist->find(roleslist->getRoles()->getMap_Now())->second->Main_Draw(isDraw, _isDrawMap);
}

//碰撞到物件
bool Keyboard_Event::Overlapping_Object(Map_object* _obj) {
    switch (_obj->get_Object_Type())
    {
    case Map_object::objectType::Boor:
        maplist->find(roleslist->getRoles()->getMap_Now())->second->Map_Transmission(maplist->find(_obj->getName())->second, _obj);
        roleslist->getRoles()->wire_Roles_info();
        maplist->find(roleslist->getRoles()->getMap_Now())->second->Rand_Monster();

        return true;
        break;
    default:
        break;
    }
    return false;
}
//顯示世界地圖
void Keyboard_Event::Show_Map_Pos() {
    system("cls");
    for (map<string, Game_Map*>::iterator it = maplist->begin(); it != maplist->end(); it++)
        it->second->Show_Map_Pos(it->second->getRoles() == NULL ? 7 : 3);
    _getch();
}