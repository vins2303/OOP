#include "..\\..\\include\LifeEntity\FootColor.h"

FoorColor::FoorColor(int _id, string _name, int _exp, int _maxHP, int _maxMP, Attributes &_attributes, Equipment &_Equipment) :
    Attributes(_attributes),
    Equipment(_Equipment),
    id(_id),
    name(_name),
    exp(_exp),
    object(NULL),
    maxHP(_maxHP),
    maxMP(_maxMP)

{

}

FoorColor::~FoorColor() {
    if (object != NULL) delete object;
}

int FoorColor::getID() { return id; }
string FoorColor::getName() { return name; }
int FoorColor::getExp() { return exp; }
int FoorColor::getUpExp() { return (int)(pow(getLV() - 1, 3) + 60); }

int FoorColor::getMaxHP() { return maxHP; }
int FoorColor::getMaxMP() { return maxMP; }



int FoorColor::setID(int _id) { return id = _id; }
string FoorColor::setName(string _name) { return name = _name; }
int FoorColor::setExp(int _exp) { return exp = _exp > getUpExp() ? getUpExp() : exp; }
int FoorColor::setHP(int _num) { return Attributes::setHP(_num > getMaxHP() ? getMaxHP() : _num); }
int FoorColor::setMP(int _num) { return Attributes::setMP(_num > getMaxMP() ? getMaxMP() : _num); }
int FoorColor::setMaxHP(int _num) { return maxHP = _num; }
int FoorColor::setMaxMP(int _num) { return maxMP = _num; }



int FoorColor::addExp(int _exp, bool percent) { 
    int exp = ADD_FUN(getExp(), _exp, percent);
    if (exp > getUpExp()) exp = getUpExp();
    return setExp(exp); 
}

int FoorColor::addHP(int _hp, bool percent) { return setHP(ADD_FUN(getHP(), _hp, percent)); }
int FoorColor::addMP(int _mp, bool percent) { return setMP(ADD_FUN(getMP(), _mp, percent)); }
int FoorColor::addMaxHP(int _maxhp, bool percent) { 
    addHP(_maxhp);
    return setHP(ADD_FUN(getHP(), _maxhp, percent)); 
}
int FoorColor::addMaxMP(int _maxmp, bool percent) {
    addMP(_maxmp);
    return setHP(ADD_FUN(getHP(), _maxmp, percent)); 
}

bool FoorColor::isUpLv() { return getExp() >= getUpExp() ? true : false; }