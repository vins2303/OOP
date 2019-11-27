#include "../../include/LifeEntity/Attributes.h"
#define SHOW_MAX_HP 20
#define SHOW_HP_FIGURE(_num) ((_num) ? "#" : " ")
#define SHOW_HP_FRAME ("|| ");

#define SHOW_MAX_MP 20
#define SHOW_MP_FIGURE(_num) ((_num) ? "#": " ")
#define SHOW_MP_FRAME ("|| ");

Attributes::Attributes(int _HP, int _MP, int _attack, int _sp, int _def,int _CRT) :
    HP(_HP),
    MP(_MP),
    Attack(_attack),
    SP(_sp),
    Def(_def),
    CRT(_CRT)
{}

Attributes::~Attributes() {

}
/*
                            get
*/

int Attributes::getHP()        { return HP; }
int Attributes::getMP()        { return MP; }
int Attributes::getAttack()    { return Attack; }
int Attributes::getSP()        { return SP; }
int Attributes::getDef()       { return Def; }
int Attributes::getCrt()       { return CRT; }


/*
                            set
*/
int Attributes::setHP(int _num) { return HP = _num; }
int Attributes::setMP(int _num) { return MP = _num; }
int Attributes::setAttack(int _num)    { return Attack = _num; }
int Attributes::setSP(int _num)        { return SP = _num; }
int Attributes::setDef(int _num)       { return Def = _num; }
int Attributes::setCrt(int _num) { return CRT = _num > 100 ? 100 : CRT; }

/*
                            Add
*/
int Attributes::addHP(int _num, bool percent, bool zero)        { return setHP(     ADD_FUN(getHP(), _num, percent, zero)); }
int Attributes::addMP(int _num, bool percent, bool zero)        { return setMP(     ADD_FUN(getMP(), _num, percent, zero)); }
int Attributes::addAttack(int _num, bool percent, bool zero)    { return setAttack( ADD_FUN(getAttack(), _num, percent, zero)); }
int Attributes::addSP(int _num, bool percent, bool zero)        { return setSP(     ADD_FUN(getSP(), _num, percent, zero)); }
int Attributes::addDef(int _num, bool percent, bool zero)       { return setDef(    ADD_FUN(getDef(), _num, percent, zero)); }
int Attributes::addCrt(int _num)                                { return setCrt(getCrt() + _num); }
/*
*                                 Tool
*/
int Attributes::ADD_FUN(int _now, int _add, bool percent, bool setZero) {
    _now += percent ? (int)(_now * _add * 0.01) : _now;
    if (setZero) if (_now < 0) _now = 0;
    return _now;
}