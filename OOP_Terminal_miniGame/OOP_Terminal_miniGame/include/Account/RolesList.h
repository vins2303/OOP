#ifndef _ROLESLIST_H_
#define _ROLESLIST_H_

#include<iostream>
#include "Account.h"
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include "../LifeEntity/Roles/Roles.h"
#include "../../include/Tool/Tool.h"

using std::string;

class RolesList : Account {
private:
    Roles* roles;
public:
    RolesList(Account &);

    void FindRoles(vector<Roles*>&);
    
    void Menu();

    bool addRoles();



};
#endif