#ifndef _SKILL_LIST_H
#define _SKILL_LIST_H

#include <fstream>
#include "Skill.h"
#include "../../LifeAttributes.h"
#define SKILL_PAHT__(_acc, _name) ("Data/Account/" + (_acc) + "/" + (_name) + "/Skill.txt")
#define Roles_PATH__(_acc) ("Data/Account/" + (_acc) + "/Roles.ini")

class Skill_List {
public:
    Account& user_account;
private:
    int Skill_Point;
    vector<Skill*> skill_using;
    vector<Skill*> skill;
    RaceType racet;
    RoleType rolet;
public:
    Skill_List(Account& user_account, RaceType _race, RoleType _role);
    ~Skill_List();

    void Skill_Menu();

    void Save_Skill();
    bool Us_Skill(LifeAttributes& att);
    int Sum_Skill_HP();
    int Sum_Skill_MP();
    int Sum_Skill_Attack();
    int Sum_Skill_SP();
    int Sum_Skill_Def();
    int Sum_Skill_CRT();
    int Sum_Skill_Drop();
    void addSkill_Point(int n = 1);

    void Round_End();
private:
    void New_Skill();
    void UP_Skill();
    vector<Skill*> Read_skill();
    Skill* findSkill(const Skill* _skill);
};

#endif // !_SKILL_LIST_H
