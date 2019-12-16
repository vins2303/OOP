#include "../../../include/LifeEntity/Roles/Restricted.h"

Restricted::Restricted(vector<RoleType> rolelist, vector<RaceType> racelist) :
    Restricted_Role(rolelist),
    Restricted_Race(racelist)
{}

Restricted::~Restricted()
{
}

bool Restricted::Usable(const RoleType& _role, const RaceType& _race)
{
    return Usable_Role(_role) && Usable_Race(_race);
}

bool Restricted::Usable_Role(const RoleType& _role)
{
    if (find(Restricted_Role.begin(), Restricted_Role.end(), RoleType::null) != Restricted_Role.end()) return true;
    return (find(Restricted_Role.begin(), Restricted_Role.end(), _role) == Restricted_Role.end() ? false : true);
}

bool Restricted::Usable_Race(const RaceType& _race)
{
    if (find(Restricted_Race.begin(), Restricted_Race.end(), RaceType::null) != Restricted_Race.end()) return true;
    return (find(Restricted_Race.begin(), Restricted_Race.end(), _race) == Restricted_Race.end() ? false : true);
}

vector<RoleType>& Restricted::getRestricted_Role() { return Restricted_Role; }

vector<RaceType>& Restricted::getRestricted_Race() { return Restricted_Race; }