#include "../Attributes.h"
#ifndef _EQUIPMENT_H_
#define _EQUIPMENT_H_

class Equipment {
private:
    Attributes* weapon;//武器
    Attributes* deputy;//副手
    Attributes* helmet;//頭盔
    Attributes* breastplate;//胸甲
    Attributes* pants;//褲子
    Attributes* shoes;//鞋子

public:
    Equipment(Attributes* _weapon = NULL,
        Attributes* _deputy = NULL,
        Attributes* _helmet = NULL,
        Attributes* _breastplate = NULL,
        Attributes* _pants = NULL,
        Attributes* _shoes = NULL);

    ~Equipment();

    Attributes* getWeapon();
    Attributes* getDeputy();
    Attributes* getHelmet();
    Attributes* getBreastplate();
    Attributes* getPants();
    Attributes* getShoes();

    Attributes* setWeapon(Attributes* _data);
    Attributes* setDeputy(Attributes* _data);
    Attributes* setHelmet(Attributes* _data);
    Attributes* setBreastplate(Attributes* _data);
    Attributes* setPants(Attributes* _data);
    Attributes* setShoes(Attributes* _data);

    Attributes* getBuff();

    int sumHP();
    int sumMP();
    int sumAttack();
    int sumSP();
    int sumDef();
    int sumCrt();
};

#endif