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
#define SELROLESP_COL(num) ((int)(num) * 16 + ((num)==0   ? 0 : 1))

#define SHOWRACEINFO_COUNT 8
#define SHOWRACEINFO_COL(num) (int)((num) * SHOWRACEINFO_COUNT * 2)

class RolesList {
    friend class Account;
private:
    Account user_account;
    Roles* roles;
public:
    RolesList();
    ~RolesList();
    Roles* getRoles();
    Account* getAccount();
    void FindRoles(vector<Roles*>&);
    void RolesListMenu();
    bool Selete_Roles();
    bool addRoles();
    void DeleteRoles();
    void Clear_Now_Roles();
    void Save_Roles();

private:
    void clearRolesList(vector<Roles*>&);
    void show_Total_RolesList(vector<Roles*>&, unsigned int row);
    void show_Total_RaceInfo(const vector<string>& raceList, const string _file, const unsigned int _row);
    void show_Total_RoleInfo(const vector<string>& rolesList, const string _file, const unsigned int _row);
};
#endif