#ifndef _RESTRICTED_H_
#define _RESTRICTED_H_

#include "../../Type.h"

class Restricted {
private:
    vector<RoleType> Restricted_Role;//¾�~���w
    vector<RaceType> Restricted_Race;//�`�ڭ��w
public:
    Restricted(vector<RoleType> rolelist, vector<RaceType> racelist);
    ~Restricted();

    /*                  �ر� or ¾�~���w              */
    bool Usable(const RoleType& _role, const RaceType& _race);
    bool Usable_Role(const RoleType& _role);
    bool Usable_Race(const RaceType& _race);

    vector<RoleType>& getRestricted_Role();
    vector<RaceType>& getRestricted_Race();
};

#endif // !
