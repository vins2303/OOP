#ifndef _ROLE_H_
#define _ROLE_H_
/*
            Â¾·~
*/
#include "../../Type.h"

class Role {
private:
    RoleType role;
public:
    Role(RoleType);
    Role(string _roletype);

    string getRoleType_S();
    RoleType& get_RoleType();
};

#endif // !_ROLE_H_
