#include "../../../include/LifeEntity/Roles/Role.h"

Role::Role(RoleType _type) :
    role(_type)
{}

Role::Role(string _roletype) :
    role(toRole_Type(_roletype))
{}

string Role::getRoleType_S() { return toString(role); }

RoleType& Role::get_RoleType() { return role; }