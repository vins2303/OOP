#ifndef _RESTRICTED_H_
#define _RESTRICTED_H_

#include "../../Type.h"

class Restricted {
private:
    vector<RoleType> Restricted_Role;//職業限定
    vector<RaceType> Restricted_Race;//總族限定
public:
    Restricted(vector<RoleType> rolelist, vector<RaceType> racelist);
    ~Restricted();

    /*                  種族 or 職業限定              */
    bool Usable(const RoleType& _role, const RaceType& _race);
    bool Usable_Role(const RoleType& _role);
    bool Usable_Race(const RaceType& _race);

    vector<RoleType>& getRestricted_Role();
    vector<RaceType>& getRestricted_Race();
};

#endif // !
