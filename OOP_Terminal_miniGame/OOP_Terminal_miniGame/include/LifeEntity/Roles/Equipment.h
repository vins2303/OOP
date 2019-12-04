#include "../Attributes.h"
#ifndef _EQUIPMENT_H_
#define _EQUIPMENT_H_

class Equipment {
private:
    Attributes* weapon;//�Z��
    Attributes* deputy;//�Ƥ�
    Attributes* helmet;//�Y��
    Attributes* breastplate;//�ݥ�
    Attributes* pants;//�Ǥl
    Attributes* shoes;//�c�l

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