#include "../../include/keyboard_Event/Keyboard_Event.h"
#include "../../include/LifeEntity/Fighting/Fighting.h"
#include "../../include/Map/Store.h"

Keyboard_Event::Keyboard_Event(map<string, Game_Map*>* _map, RolesList* _roleslist) :
    maplist(_map),
    roleslist(_roleslist), Buff_Key(0)
{}

void Keyboard_Event::Run() {
    bool isDrawMap = true;
    while (true) {
        roleslist->getAccount()->AccountMenu();
        roleslist->RolesListMenu();
        //system("cls");

        if (roleslist->getRoles() != NULL) {
            maplist->find(roleslist->getRoles()->getMap_Now())->second->setRoles(roleslist->getRoles());
            maplist->find(roleslist->getRoles()->getMap_Now())->second->Rand_Monster();
        }
        //SetTimer(;
        while (roleslist->getRoles() != NULL) {
            Read_Key(isDrawMap);
        }
    }
}

void Keyboard_Event::Read_Key(bool& _isDrawMap) {
    static bool isDraw = true;
    static Map_object* overlapping_object;
    static int get_Key;
    overlapping_object = NULL;

    maplist->find(roleslist->getRoles()->getMap_Now())->second->Monster_Move_Time();
    if (_kbhit() || Buff_Key != 0) {
        isDraw = true;
        get_Key = Buff_Key != 0 ? Buff_Key : _getch();
        switch (get_Key)
        {
        case 72:// Move Up
            isDraw = true;

            overlapping_object = roleslist->getRoles()->set_Roles_Move_Y(roleslist->getRoles()->get_Point_Y() - 1, maplist->find(roleslist->getRoles()->getMap_Now())->second->get_Object_List());
            break;
        case 75:// Move Left
            isDraw = true;
            overlapping_object = roleslist->getRoles()->set_Roles_Move_X(roleslist->getRoles()->get_Point_X() - 1, maplist->find(roleslist->getRoles()->getMap_Now())->second->get_Object_List());
            break;

        case 80:// Move Down
            isDraw = true;
            overlapping_object = roleslist->getRoles()->set_Roles_Move_Y(roleslist->getRoles()->get_Point_Y() + 1, maplist->find(roleslist->getRoles()->getMap_Now())->second->get_Object_List());
            break;

        case 77:// Move Right
            isDraw = true;
            overlapping_object = roleslist->getRoles()->set_Roles_Move_X(roleslist->getRoles()->get_Point_X() + 1, maplist->find(roleslist->getRoles()->getMap_Now())->second->get_Object_List());
            break;
        case 'i':
            roleslist->getRoles()->show_State();
            _getch();
            isDraw = true;
            _isDrawMap = true;
            break;
        case 'm':
            Show_Map_Pos();
            isDraw = true;
            _isDrawMap = true;
            break;
        case 'b':
        case 'B':
            roleslist->getRoles()->Open_BackPack();
            isDraw = true;
            _isDrawMap = true;
            break;
        case 'k':
            roleslist->getRoles()->Skill_Menu();
            isDraw = true;
            _isDrawMap = true;
            break;

        case 27:
            Esc_Table();
            isDraw = true;
            _isDrawMap = true;
            break;
        default:
            break;
        }
        Buff_Key = 0;
    }
    if (overlapping_object != NULL) {
        _isDrawMap = Overlapping_Object(overlapping_object);
        overlapping_object = NULL;
    }
    if (roleslist->getRoles() != NULL)
        maplist->find(roleslist->getRoles()->getMap_Now())->second->Main_Draw(isDraw, _isDrawMap);
}

//碰撞到物件
bool Keyboard_Event::Overlapping_Object(Map_object* _obj) {
    static Store* store;
    switch (_obj->get_Object_Type()) {
    case objectType::Boor:
        maplist->find(roleslist->getRoles()->getMap_Now())->second->Map_Transmission(maplist->find(_obj->getName())->second, _obj);
        roleslist->getRoles()->Save_Roles();
        maplist->find(roleslist->getRoles()->getMap_Now())->second->Rand_Monster();
        return true;
        //break;
    case objectType::Monster:
        ((Monster*)_obj)->show_info(maplist->find(roleslist->getRoles()->getMap_Now())->second->get_Width() + 3);
        Buff_Key = _getch();
        if (Buff_Key == 'q' || Buff_Key == 'Q') {
            Fighting_Fun((Monster*)_obj);
            roleslist->getRoles()->Save_Roles();
            return true;
        }
        else Draw::clearMap(maplist->find(roleslist->getRoles()->getMap_Now())->second->get_Width() + 2, 0, 25, 30);
        return false;
    case objectType::Store:
        store = new Store(*roleslist->getRoles()->user_account, _obj->getName());
        store->Store_Menu(*roleslist->getRoles());
        delete store;
        return true;
    default:
        break;
    }
    return false;
}

/*列印世界地圖*/
void Keyboard_Event::Show_Map_Pos() {
    system("cls");
    for (map<string, Game_Map*>::iterator it = maplist->begin(); it != maplist->end(); it++)
        it->second->Show_Map_Pos(it->first == roleslist->getRoles()->getMap_Now() ? 3 : 7);
    _getch();
}

void Keyboard_Event::Esc_Table() {
    int getKey;
    system("cls");
    cout << "功能列表 (Esc返回)" << endl;
    cout << "1. 返回選擇角色" << endl;
    cout << "2. 返回登入畫面" << endl;
    cout << "3. 存檔" << endl << endl;
    cout << "4. 離開遊戲" << endl << endl;
    while (1) {
        getKey = _getch();
        switch (getKey) {
        case '1':
            Back_To_Selete_Roles();
            return;

        case '2':
            Back_To_Selete_Account();
            return;
        case '3':
            roleslist->getRoles()->Save_Roles();
            cout << "角色以存檔!" << endl;
            system("pause");
            return;
        case '4':
            roleslist->getRoles()->Save_Roles();
            exit(1);
            return;
        case 27:
            return;
        }
    }
}

void Keyboard_Event::Back_To_Selete_Roles() {
    roleslist->getRoles()->Save_Roles();
    maplist->find(roleslist->getRoles()->getMap_Now())->second->setRoles(NULL);
    roleslist->Clear_Now_Roles();
}

void Keyboard_Event::Back_To_Selete_Account() {
    Back_To_Selete_Roles();
    roleslist->getAccount()->Sign_out();
}

void Keyboard_Event::Fighting_Fun(Monster* _obj) {
    Fighting fig(*roleslist->getRoles()->user_account, roleslist->getRoles(), _obj);
    fig.Fighting_Start();
    maplist->find(roleslist->getRoles()->getMap_Now())->second->Clear_0HP_Monster();
    if (roleslist->getRoles()->getHP() == 0) {
        //cout << "你已經死亡!" << endl;

        roleslist->getRoles()->setHP(roleslist->getRoles()->getMaxHP());
        maplist->find(roleslist->getRoles()->getMap_Now())->second->Map_Transmission(maplist->find("市集")->second, _obj);
        roleslist->getRoles()->set_Point_X(maplist->find(roleslist->getRoles()->getMap_Now())->second->get_Width() / 2 - roleslist->getRoles()->get_Width() / 2);
        roleslist->getRoles()->set_Point_Y(maplist->find(roleslist->getRoles()->getMap_Now())->second->get_High() / 2 - roleslist->getRoles()->get_Heigh() / 2);
        //system("pause");
    }
    else {
        if (maplist->find(roleslist->getRoles()->getMap_Now())->second->getNumber_of_Monster() < 3)
            maplist->find(roleslist->getRoles()->getMap_Now())->second->Rand_Monster();
    }
}