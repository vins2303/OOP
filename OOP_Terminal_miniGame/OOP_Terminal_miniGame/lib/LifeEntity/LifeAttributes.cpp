#include "../../include/LifeEntity/LifeAttributes.h"

LifeAttributes::LifeAttributes(int _LV, int _HP, int _MP, int _attack, int _sp, int _def, int _CRT, int _drop, int _maxHP, int _maxMP) :
    Attributes(_HP, _MP, _attack, _sp, _def, _CRT, _drop),
    LV(_LV),
    maxHP(_maxHP == -1 ? _HP : _maxHP),
    maxMP(_maxMP == -1 ? _MP : _maxMP)
{}

LifeAttributes::~LifeAttributes() {}

inline int LifeAttributes::getLV() { return LV; }
int LifeAttributes::getMaxHP() { return LV_Magnification(maxHP); }
int LifeAttributes::getMaxMP() { return LV_Magnification(maxMP); }
int LifeAttributes::getAttack() { return LV_Magnification(Attributes::getAttack()); }
int LifeAttributes::getSP() { return LV_Magnification(Attributes::getSP()); }
int LifeAttributes::getDef() { return LV_Magnification(Attributes::getDef()); }
int LifeAttributes::getCRT() { return LV_Magnification(Attributes::getCRT()); }
int LifeAttributes::getDrop() { return LV_Magnification(Attributes::getDrop()); }

int LifeAttributes::setHP(int _num) { return Attributes::setHP(_num > getMaxHP() ? getMaxHP() : _num); }
int LifeAttributes::setMP(int _num) { return Attributes::setMP(_num > getMaxMP() ? getMaxMP() : _num); }
int LifeAttributes::setMaxHP(int _num) { return maxHP = _num; }
int LifeAttributes::setMaxMP(int _num) { return maxMP = _num; }
int LifeAttributes::setLV(int _lv) { return LV = _lv; }

int LifeAttributes::addHP(int _hp, bool percent) { return setHP(ADD_FUN(getHP(), _hp, percent)); }
int LifeAttributes::addMP(int _mp, bool percent) { return setMP(ADD_FUN(getMP(), _mp, percent)); }
int LifeAttributes::addMaxHP(int _maxhp, bool percent) {
    addHP(_maxhp);
    return setHP(ADD_FUN(getHP(), _maxhp, percent));
}
int LifeAttributes::addMaxMP(int _maxmp, bool percent) {
    addMP(_maxmp);
    return setHP(ADD_FUN(getHP(), _maxmp, percent));
}

int LifeAttributes::addLV(int _add) { return setLV(getLV() + _add); }

void LifeAttributes::addAttributes(Attributes& _att) {
    addHP(_att.getHP());
    addMP(_att.getMP());
}

LifeAttributes* LifeAttributes::showHP(bool a_LV, int _max, bool show, bool LF) {
    static int hp, maxhp;
    Draw::SetColor(4);
    hp = a_LV ? getHP() : Attributes::getHP();
    maxhp = _max == 0 ? (a_LV ? getMaxHP() : maxHP) : _max;
    cout << SHOW_HP_FRAME_BEGIN;
    for (int i = 0; i < SHOW_MAX_HP; i++)
        cout << SHOW_HP_FIGURE(i < (hp * (SHOW_MAX_HP / (double)(maxhp))));
    cout << SHOW_HP_FRAME_END;
    Draw::SetColor();
    if (show) cout << " " << hp << "/" << maxhp;
    if (LF) cout << endl;
    return this;
}

LifeAttributes* LifeAttributes::showMP(bool a_LV, int _max, bool show, bool LF) {
    static int mp, maxmp;
    Draw::SetColor(1);
    mp = a_LV ? getMP() : Attributes::getMP();
    maxmp = _max == 0 ? (a_LV ? getMaxMP() : maxMP) : _max;
    cout << SHOW_MP_FRAME_BEGIN;
    for (int i = 0; i < SHOW_MAX_MP; i++)
        cout << SHOW_MP_FIGURE(i < (mp * (SHOW_MAX_MP / (double)(maxmp))));
    cout << SHOW_MP_FRAME_END;
    Draw::SetColor();
    if (show) cout << " " << mp << "/" << maxmp;
    if (LF) cout << endl;
    return this;
}