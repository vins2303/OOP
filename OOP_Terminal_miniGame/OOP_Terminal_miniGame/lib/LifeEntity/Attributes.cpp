#include "../../include/LifeEntity/Attributes.h"
#define SHOW_MAX_HP 20
#define SHOW_HP_FIGURE(_num) ((_num) ? "#" : " ")
#define SHOW_HP_FRAME ("|| ");

#define SHOW_MAX_MP 20
#define SHOW_MP_FIGURE(_num) ((_num) ? "#": " ")
#define SHOW_MP_FRAME ("|| ");

Attributes::Attributes(int _LV, Attributes_range* _HP, Attributes_range* _MP, int _attack, int _sp) :
    HP(_HP),
    MP(_MP),
    Attack(_attack),
    LV(_LV),
    SP(_sp)
{}

Attributes::~Attributes() {
    delete HP;
    delete MP;
}
/*
                            get
*/

int Attributes::getHP()        { return HP->getNow(); }
int Attributes::getMP()        { return MP->getNow(); }
int Attributes::getAttack()    { return Attack; }
int Attributes::getMaxHP()     { return HP->getMax(); }
int Attributes::getMaxMP()     { return MP->getMax(); }
int Attributes::getLV()        { return LV; }
int Attributes::getSP()        { return SP; }

/*
                            set
*/
int Attributes::setHP(int _num)        { return HP->setNow(_num > getMaxHP() ? getMaxHP() : _num);}
int Attributes::setMP(int _num)        { return MP->setNow(_num > getMaxMP() ? getMaxMP() : _num ); }
int Attributes::setAttack(int _num)    { return Attack = _num; }
int Attributes::setLV(int _num)        { return LV = _num > AttributesMaxLV ? AttributesMaxLV : _num; }
int Attributes::setSP(int _num)        { return SP = _num; }
int Attributes::setMaxHP(int _num)     { return HP->setMax(_num); }
int Attributes::setMaxMP(int _num)     { return MP->setMax(_num); }

/*
                            Add
*/
int Attributes::addHP(int _num, bool percent, bool zero)        { return setHP(        ADD_FUN(getHP(), _num, percent, zero)); }
int Attributes::addMP(int _num, bool percent, bool zero)        { return setMP(        ADD_FUN(getMP(), _num, percent, zero)); }
int Attributes::addAttack(int _num, bool percent, bool zero)    { return setAttack(    ADD_FUN(getAttack(), _num, percent, zero)); }
int Attributes::addMaxHP(int _num, bool percent, bool zero)     { return setMaxHP(     ADD_FUN(getMaxHP(), _num, percent, zero)); }
int Attributes::addMaxMP(int _num, bool percent, bool zero)     { return setMaxMP(ADD_FUN(getMaxHP(), _num, percent, zero)); }
int Attributes::addLV(int _num, bool percent, bool zero)        { return setLV(ADD_FUN(getLV(), _num, percent, zero)); }
int Attributes::addSP(int _num, bool percent, bool zero)        { return setSP(     ADD_FUN(getSP(), _num, percent, zero)); }

/*
*                                 Tool
*/
int Attributes::ADD_FUN(int _now, int _add, bool percent, bool setZero) {
    _now += percent ? (int)(_now * _add * 0.01) : _now;
    if (setZero) if (_now < 0) _now = 0;
    return _now;
}