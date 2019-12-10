#include "../Roles/Roles.h"
#include "../Monster/Monster.h"
#ifndef _FIGHTING_H_
#define _FIGHTING_H_

#include <conio.h>

class Fighting {
private:
    Roles* roles;
    Monster* monster;

public:
    Fighting(Roles* _roles, Monster* _moster);

    bool Fighting_Start();
private:
    void Moster_Attack();
    void Roles_Attack();
};

#endif