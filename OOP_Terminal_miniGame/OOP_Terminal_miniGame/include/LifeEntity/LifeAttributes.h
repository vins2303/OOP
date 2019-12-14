#ifndef _LIFEENTITY_H_
#define _LIFEENTITY_H_

#include "Attributes.h"
#include "../Map/Draw.h"

//#define LVMagnification( num )  (num)
#define SHOW_MAX_HP 20
#define SHOW_HP_FIGURE(_num) ((_num) ? "=" : " ")
#define SHOW_HP_FRAME_BEGIN "[";
#define SHOW_HP_FRAME_END   "]";

#define SHOW_MAX_MP 20
#define SHOW_MP_FIGURE(_num) ((_num) ? "=": " ")
#define SHOW_MP_FRAME_BEGIN "[";
#define SHOW_MP_FRAME_END "]";

#define SHOW_MAX_EXP 20
#define SHOW_EXP_FIGURE(_num) ((_num) ? "=": " ")
#define SHOW_EXP_FRAME_BEGIN "[";
#define SHOW_EXP_FRAME_END   "]";

class LifeAttributes : public Attributes {
private:
    int LV;
    int maxHP;
    int maxMP;

public:
    LifeAttributes(int _LV, int _HP, int _MP, int _attack, int _sp, int _def, int _drop, int _CRT, int _maxHP = -1, int _maxMP = -1);
    virtual ~LifeAttributes();
    inline int getLV();
    int getMaxHP();
    int getMaxMP();
    int getAttack();
    int getSP();
    int getDef();
    int getCRT();
    int getDrop();

    int setHP(int _num);
    int setMP(int _num);
    int setMaxHP(int _num);
    int setMaxMP(int _num);
    int setLV(int _num);

    int addHP(int _hp, bool percent = false);
    int addMP(int _mp, bool percent = false);
    int addMaxHP(int _maxhp, bool percent = false);
    int addMaxMP(int _maxmp, bool percent = false);
    int addLV(int _lv = 1);
    void addAttributes(Attributes& _att);
    LifeAttributes* showHP(bool a_LV = true, bool show = true, bool LF = true);
    LifeAttributes* showMP(bool a_LV = true, bool show = true, bool LF = true);
};

#endif
