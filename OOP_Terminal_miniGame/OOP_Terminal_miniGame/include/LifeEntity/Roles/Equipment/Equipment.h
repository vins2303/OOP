#ifndef _EQUIPMENT_H_
#define _EQUIPMENT_H_

#include "../../Attributes.h"

#include <string>
#include<map>
#include "Equipment_Attributes.h"
using namespace std;

class Equipment {
private:
    Equipment_Attributes* Weapon;//�Z��
    Equipment_Attributes* Deputy;//�Ƥ�
    Equipment_Attributes* Helmet;//�Y��
    Equipment_Attributes* Breastplate;//�ݥ�
    Equipment_Attributes* Pants;//�Ǥl
    Equipment_Attributes* Shoes;//�c�l

public:

    Equipment(
        Equipment_Attributes* _weapon = NULL,
        Equipment_Attributes* _deputy = NULL,
        Equipment_Attributes* _helmet = NULL,
        Equipment_Attributes* _breastplate = NULL,
        Equipment_Attributes* _pants = NULL,
        Equipment_Attributes* _shoes = NULL);

    ~Equipment();

    Equipment_Attributes* getWeapon();
    Equipment_Attributes* getDeputy();
    Equipment_Attributes* getHelmet();
    Equipment_Attributes* getBreastplate();
    Equipment_Attributes* getPants();
    Equipment_Attributes* getShoes();

    Equipment_Attributes* setWeapon(Equipment_Attributes* _data);
    Equipment_Attributes* setDeputy(Equipment_Attributes* _data);
    Equipment_Attributes* setHelmet(Equipment_Attributes* _data);
    Equipment_Attributes* setBreastplate(Equipment_Attributes* _data);
    Equipment_Attributes* setPants(Equipment_Attributes* _data);
    Equipment_Attributes* setShoes(Equipment_Attributes* _data);

    //Attributes* getBuff();

    int sumHP();
    int sumMP();
    int sumAttack();
    int sumSP();
    int sumDef();
    int sumCrt();

    static Equipment_Attributes* Read_Equipment_Attributes(string _account, string _name, Back_Pack_Type _type);
};

#endif