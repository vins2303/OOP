#include "..\\..\\include\LifeEntity\FootColor.h"

FoorColor::FoorColor(int _id, string _name, int _exp, int _LV, Attributes_range* _HP, Attributes_range* _MP, int _attack, int _sp) :
    Attributes(_LV, _HP, _MP, _attack, _sp),
    id(_id),
    name(_name),
    exp(_exp),
    object(NULL)
{}

int FoorColor::getID() { return id; }
string FoorColor::getName() { return name; }
int FoorColor::getExp() { return exp; }
int FoorColor::UpExp() { return (int)(pow(getLV() - 1, 3) + 60); }

int FoorColor::setID(int _id) { return id = _id; }
string FoorColor::setName(string _name) { return name = _name; }
int FoorColor::setExp(int _exp) { return exp = _exp > UpExp() ? UpExp() : exp; }

int FoorColor::addExp(int _exp) { return setExp(_exp + getExp()); }


