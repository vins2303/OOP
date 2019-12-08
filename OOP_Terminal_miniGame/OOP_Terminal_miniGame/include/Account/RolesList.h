#ifndef _ROLESLIST_H_
#define _ROLESLIST_H_

#include<iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include "Account.h"
#include "../LifeEntity/Roles/Roles.h"
#include "../../include/Tool/Tool.h"
//#include "../../include/Map/Draw.h"

using std::string;
#define SELROLESP_COL(num) ((num) * 16 + ((num)==0   ? 0 : 1))

#define SHOWRACEINFO_COUNT 8
#define SHOWRACEINFO_COL(num) ((num) * SHOWRACEINFO_COUNT * 2)

class RolesList : public Account {
private:
    Roles* roles;
public:
    RolesList();
    ~RolesList();
    Roles* getRoles();
    void FindRoles(vector<Roles*>&);
    void RolesListMenu();
    bool Selete_Roles();
    bool addRoles();
    void DeleteRoles();
    void Clear_Now_Roles();
private:
    void clearRolesList(vector<Roles*>&);
    void showRolesList(vector<Roles*>&, unsigned int row);
    void showRaceInfo(const vector<string>& raceList, const string _file, const unsigned int _row);
    void showRoleInfo(const vector<string>& rolesList, const string _file, const unsigned int _row);
};
#endif