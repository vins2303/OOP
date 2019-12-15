#ifndef _EQUIPMENT_H_
#define _EQUIPMENT_H_

#define Equipment_INI_PATH  ("Data/Account/" + account + "/" + name + "/Equipment.ini")
#define Equipment_DIR_PATH  ("Data/Account/" + account + "/" + name )

#include "../../Attributes.h"
//#include "../Back_Pack/Back_Pack.h"
#include <string>
#include<map>
#include "Equipment_Attributes.h"
using namespace std;

class Equipment {
private:
    string account;
    string name;
    Equipment_Attributes* Weapon;//武器
    Equipment_Attributes* Deputy;//副手
    Equipment_Attributes* Helmet;//頭盔
    Equipment_Attributes* Breastplate;//胸甲
    Equipment_Attributes* Pants;//褲子
    Equipment_Attributes* Shoes;//鞋子

public:

    Equipment(string _acc, string _name);

    ~Equipment();

    Equipment_Attributes* Put_on(Equipment_Attributes* _E);

    void Remove_Equipment(vector<Goods*>& goods);

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

    void show_Equipment();
    void Save_Equipment();
    Equipment_Attributes* Read_Equipment_Attributes(Back_Pack_Type _type);
};

#endif