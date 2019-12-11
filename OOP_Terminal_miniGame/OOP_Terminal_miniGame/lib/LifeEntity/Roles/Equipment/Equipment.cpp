#include"../../../../include/LifeEntity/Roles/Equipment/Equipment.h"
#include "../../../../include/Tool/Tool.h"

Equipment::Equipment(
    Equipment_Attributes* _weapon,
    Equipment_Attributes* _deputy,
    Equipment_Attributes* _helmet,
    Equipment_Attributes* _breastplate,
    Equipment_Attributes* _pants,
    Equipment_Attributes* _shoes) :

    Weapon(_weapon),
    Deputy(_deputy),
    Helmet(_helmet),
    Breastplate(_breastplate),
    Pants(_pants),
    Shoes(_shoes)
{}

Equipment::~Equipment() {
    /*if (Weapon != NULL)      delete Weapon;
    if (Deputy != NULL)      delete Deputy;
    if (Helmet != NULL)      delete Helmet;
    if (Breastplate != NULL) delete Breastplate;
    if (Pants != NULL)       delete Pants;
    if (Shoes != NULL)       delete Shoes;*/
}

Equipment_Attributes* Equipment::getWeapon() { return Weapon; }
Equipment_Attributes* Equipment::getDeputy() { return Deputy; }
Equipment_Attributes* Equipment::getHelmet() { return Helmet; }
Equipment_Attributes* Equipment::getBreastplate() { return Breastplate; }
Equipment_Attributes* Equipment::getPants() { return Pants; }
Equipment_Attributes* Equipment::getShoes() { return Shoes; }

Equipment_Attributes* Equipment::setWeapon(Equipment_Attributes* _data) { return Weapon = _data; }
Equipment_Attributes* Equipment::setDeputy(Equipment_Attributes* _data) { return Deputy = _data; }
Equipment_Attributes* Equipment::setHelmet(Equipment_Attributes* _data) { return Helmet = _data; }
Equipment_Attributes* Equipment::setBreastplate(Equipment_Attributes* _data) { return Breastplate = _data; }
Equipment_Attributes* Equipment::setPants(Equipment_Attributes* _data) { return Pants = _data; }
Equipment_Attributes* Equipment::setShoes(Equipment_Attributes* _data) { return Shoes = _data; }

int Equipment::sumHP() {
    int sum = 0;
    if (Weapon != NULL)      sum += Weapon->getHP();
    if (Deputy != NULL)      sum += Deputy->getHP();
    if (Helmet != NULL)      sum += Helmet->getHP();
    if (Breastplate != NULL) sum += Breastplate->getHP();
    if (Pants != NULL)       sum += Pants->getHP();
    if (Shoes != NULL)       sum += Shoes->getHP();
    return sum;
}
int Equipment::sumMP() {
    int sum = 0;
    if (Weapon != NULL)      sum += Weapon->getMP();
    if (Deputy != NULL)      sum += Deputy->getMP();
    if (Helmet != NULL)      sum += Helmet->getMP();
    if (Breastplate != NULL) sum += Breastplate->getMP();
    if (Pants != NULL)       sum += Pants->getMP();
    if (Shoes != NULL)       sum += Shoes->getMP();
    return sum;
}
int Equipment::sumAttack() {
    int sum = 0;
    if (Weapon != NULL)      sum += Weapon->getAttack();
    if (Deputy != NULL)      sum += Deputy->getAttack();
    if (Helmet != NULL)      sum += Helmet->getAttack();
    if (Breastplate != NULL) sum += Breastplate->getAttack();
    if (Pants != NULL)       sum += Pants->getAttack();
    if (Shoes != NULL)       sum += Shoes->getAttack();
    return sum;
}
int Equipment::sumDef() {
    int sum = 0;
    if (Weapon != NULL)      sum += Weapon->getDef();
    if (Deputy != NULL)      sum += Deputy->getDef();
    if (Helmet != NULL)      sum += Helmet->getDef();
    if (Breastplate != NULL) sum += Breastplate->getDef();
    if (Pants != NULL)       sum += Pants->getDef();
    if (Shoes != NULL)       sum += Shoes->getDef();
    return sum;
}
int Equipment::sumSP() {
    int sum = 0;
    if (Weapon != NULL)      sum += Weapon->getSP();
    if (Deputy != NULL)      sum += Deputy->getSP();
    if (Helmet != NULL)      sum += Helmet->getSP();
    if (Breastplate != NULL) sum += Breastplate->getSP();
    if (Pants != NULL)       sum += Pants->getSP();
    if (Shoes != NULL)       sum += Shoes->getDef();
    return sum;
}
int Equipment::sumCrt() {
    int sum = 0;
    if (Weapon != NULL)      sum += Weapon->getCRT();
    if (Deputy != NULL)      sum += Deputy->getCRT();
    if (Helmet != NULL)      sum += Helmet->getCRT();
    if (Breastplate != NULL) sum += Breastplate->getCRT();
    if (Pants != NULL)       sum += Pants->getCRT();
    if (Shoes != NULL)       sum += Shoes->getCRT();
    if (sum > 100) sum = 100;
    return sum;
}

Equipment_Attributes* Equipment::Read_Equipment_Attributes(string _account, string _name, Back_Pack_Type _type) {
    string path = "Data/Account/" + _account + "/Equipment/" + _name + ".ini";
    if (GetPrivateProfileInt(toString(_type).c_str(), "Have", 0, path.c_str())) {
        return new Equipment_Attributes(
            Tool::ReadStringIni(toString(_type), "Name", "NULL", path),
            GetPrivateProfileInt(toString(_type).c_str(), "LV", INT_MAX, path.c_str()),
            _type
        );
    }
    return NULL;
}

//Attributes* Equipment::getBuff() {
//    return new Attributes(
//        sumHP(),
//        sumMP(),
//        sumAttack(),
//        sumSP(),
//        sumDef(),
//        sumCrt()
//    );
//}