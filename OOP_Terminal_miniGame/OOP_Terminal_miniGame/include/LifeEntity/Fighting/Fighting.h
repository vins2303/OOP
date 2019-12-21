#ifndef _FIGHTING_H_
#define _FIGHTING_H_

#include "../Monster/Monster.h"
#include "../Roles/Roles.h"
#include <conio.h>
class Fighting {
private:
    Roles* roles;
    Monster* monster;

public:
    Account& user_account;
    Fighting(Account& _user_account, Roles* _roles, Monster* _moster);

    bool Fighting_Start();
private:
    void Fighting_Start_Show();
    void Rand_Drop();
    void Moster_Attack();
    void Roles_Attack();
};

#endif