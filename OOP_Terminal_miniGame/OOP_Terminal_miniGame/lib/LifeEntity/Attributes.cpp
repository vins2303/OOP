#include "../../include/LifeEntity/Attributes.h"

Attributes::Attributes(int _HP, int _MP, int _attack, int _sp, int _def, int _CRT, int _drop) :
    HP(_HP),
    MP(_MP),
    Attack(_attack),
    SP(_sp),
    Def(_def),
    CRT(_CRT),
    DROP(_drop)
{}

Attributes::~Attributes() {
}
/*
                            get
*/

int Attributes::getHP() { return HP; }
int Attributes::getMP() { return MP; }
int Attributes::getAttack() { return Attack; }
int Attributes::getSP() { return SP; }
int Attributes::getDef() { return Def; }
int Attributes::getCRT() { return CRT; }
int Attributes::getDrop() { return DROP; }

/*
                            set
*/
int Attributes::setHP(int _num) { return HP = _num; }
int Attributes::setMP(int _num) { return MP = _num; }
int Attributes::setAttack(int _num) { return Attack = _num; }
int Attributes::setSP(int _num) { return SP = _num; }
int Attributes::setDef(int _num) { return Def = _num; }
int Attributes::setCrt(int _num) { return CRT = _num > 100 ? 100 : CRT; }

int Attributes::setDrop(int _drop) { return DROP = _drop > 100 ? 100 : _drop; }

/*
                            Add
*/
int Attributes::addHP(int _num, bool percent, bool zero) { return setHP(ADD_FUN(getHP(), _num, percent, zero)); }
int Attributes::addMP(int _num, bool percent, bool zero) { return setMP(ADD_FUN(getMP(), _num, percent, zero)); }
int Attributes::addAttack(int _num, bool percent, bool zero) { return setAttack(ADD_FUN(getAttack(), _num, percent, zero)); }
int Attributes::addSP(int _num, bool percent, bool zero) { return setSP(ADD_FUN(getSP(), _num, percent, zero)); }
int Attributes::addDef(int _num, bool percent, bool zero) { return setDef(ADD_FUN(getDef(), _num, percent, zero)); }
int Attributes::addCrt(int _num) { return setCrt(getCRT() + _num); }

/*
                            show
*/
//void Attributes::showHP(bool show, bool LF) {
//    cout << SHOW_HP_FRAME;
//    for (int i = 0; i < SHOW_MAX_HP; i++)
//        cout << SHOW_HP_FIGURE(i < (HP->getNow() * (SHOW_MAX_HP / (double)HP->getTop())));
//    cout << SHOW_HP_FRAME;
//    if (show) cout << this->getHP();
//    if (LF) cout << endl;
//}

/*
*                                 Tool
*/
int Attributes::ADD_FUN(int _now, int _add, bool percent, bool setZero) {
    _now += percent ? (int)(_now * _add * 0.01) : _add;
    if (setZero) if (_now < 0) _now = 0;
    return _now;
}