#ifndef _MONSTER_H_
#define _MONSTER_H_

#include "../../Map/Map_object.h"
class Monster : public Map_object {
public:
    Monster(Map_object _object);
    virtual void* getClass() { return this; }
};

#endif