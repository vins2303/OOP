#ifndef KEYBOARD_EVENT_H
#define KEYBOARD_EVENT_H

#include<string>
#include "../Map/Game_Map.h"
#include "../Account/RolesList.h"
using namespace std;


class Keyboard_Event {
private:
    map<string, Game_Map*> *maplist;
    RolesList *roleslist;

public:
    Keyboard_Event(map<string, Game_Map*>* _map, RolesList* _roleslist);

    void Run();
    bool Overlapping_Object(Map_object*);
private:
    void read_Key(bool& _isDrawMap);
};

#endif