#ifndef _LIFEENTITY_H_
#define _LIFEENTITY_H_

#include "Attributes.h"

class LifeAttributes : public Attributes {
private:
    int LV;
    int maxHP;
    int maxMP;

public:
    LifeAttributes(int _LV, int _HP, int _MP, int _attack, int _sp, int _def, int _CRT, int _maxHP = -1, int _maxMP = -1);


    int getMaxHP();
    int getMaxMP();
    int getLV();

    int setHP(int _num);
    int setMP(int _num);
    int setMaxHP(int _num);
    int setMaxMP(int _num);
    int setLV(int _num);

    int addHP(int _hp, bool percent = false);
    int addMP(int _mp, bool percent = false);
    int addMaxHP(int _maxhp, bool percent = false);
    int addMaxMP(int _maxmp, bool percent = false);
    int addLV(int _lv);
};


#endif
