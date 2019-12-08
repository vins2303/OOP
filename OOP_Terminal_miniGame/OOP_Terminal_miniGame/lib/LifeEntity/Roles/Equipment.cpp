#include"../../../include/LifeEntity/Roles/Equipment.h"

Equipment::Equipment(
    Attributes* _weapon,
    Attributes* _deputy,
    Attributes* _helmet,
    Attributes* _breastplate,
    Attributes* _pants,
    Attributes* _shoes) :

    weapon(_weapon),
    deputy(_deputy),
    helmet(_helmet),
    breastplate(_breastplate),
    pants(_pants),
    shoes(_shoes)
{}

Equipment::~Equipment() {
    if (weapon != NULL)      delete weapon;
    if (deputy != NULL)      delete deputy;
    if (helmet != NULL)      delete helmet;
    if (breastplate != NULL) delete breastplate;
    if (pants != NULL)       delete pants;
    if (shoes != NULL)       delete shoes;
}

Attributes* Equipment::getWeapon() { return weapon; }
Attributes* Equipment::getDeputy() { return deputy; }
Attributes* Equipment::getHelmet() { return helmet; }
Attributes* Equipment::getBreastplate() { return breastplate; }
Attributes* Equipment::getPants() { return pants; }
Attributes* Equipment::getShoes() { return shoes; }

Attributes* Equipment::setWeapon(Attributes* _data) { return weapon = _data; }
Attributes* Equipment::setDeputy(Attributes* _data) { return deputy = _data; }
Attributes* Equipment::setHelmet(Attributes* _data) { return helmet = _data; }
Attributes* Equipment::setBreastplate(Attributes* _data) { return breastplate = _data; }
Attributes* Equipment::setPants(Attributes* _data) { return pants = _data; }
Attributes* Equipment::setShoes(Attributes* _data) { return shoes = _data; }

int Equipment::sumHP() {
    int sum = 0;
    if (weapon != NULL)      sum += weapon->getHP();
    if (deputy != NULL)      sum += deputy->getHP();
    if (helmet != NULL)      sum += helmet->getHP();
    if (breastplate != NULL) sum += breastplate->getHP();
    if (pants != NULL)       sum += pants->getHP();
    if (shoes != NULL)       sum += shoes->getHP();
    return sum;
}
int Equipment::sumMP() {
    int sum = 0;
    if (weapon != NULL)      sum += weapon->getMP();
    if (deputy != NULL)      sum += deputy->getMP();
    if (helmet != NULL)      sum += helmet->getMP();
    if (breastplate != NULL) sum += breastplate->getMP();
    if (pants != NULL)       sum += pants->getMP();
    if (shoes != NULL)       sum += shoes->getMP();
    return sum;
}
int Equipment::sumAttack() {
    int sum = 0;
    if (weapon != NULL)      sum += weapon->getAttack();
    if (deputy != NULL)      sum += deputy->getAttack();
    if (helmet != NULL)      sum += helmet->getAttack();
    if (breastplate != NULL) sum += breastplate->getAttack();
    if (pants != NULL)       sum += pants->getAttack();
    if (shoes != NULL)       sum += shoes->getAttack();
    return sum;
}
int Equipment::sumDef() {
    int sum = 0;
    if (weapon != NULL)      sum += weapon->getDef();
    if (deputy != NULL)      sum += deputy->getDef();
    if (helmet != NULL)      sum += helmet->getDef();
    if (breastplate != NULL) sum += breastplate->getDef();
    if (pants != NULL)       sum += pants->getDef();
    if (shoes != NULL)       sum += shoes->getDef();
    return sum;
}
int Equipment::sumSP() {
    int sum = 0;
    if (weapon != NULL)      sum += weapon->getSP();
    if (deputy != NULL)      sum += deputy->getSP();
    if (helmet != NULL)      sum += helmet->getSP();
    if (breastplate != NULL) sum += breastplate->getSP();
    if (pants != NULL)       sum += pants->getSP();
    if (shoes != NULL)       sum += shoes->getDef();
    return sum;
}
int Equipment::sumCrt() {
    int sum = 0;
    if (weapon != NULL)      sum += weapon->getCRT();
    if (deputy != NULL)      sum += deputy->getCRT();
    if (helmet != NULL)      sum += helmet->getCRT();
    if (breastplate != NULL) sum += breastplate->getCRT();
    if (pants != NULL)       sum += pants->getCRT();
    if (shoes != NULL)       sum += shoes->getCRT();
    if (sum > 100) sum = 100;
    return sum;
}

Attributes* Equipment::getBuff() {
    return new Attributes(
        sumHP(),
        sumMP(),
        sumAttack(),
        sumSP(),
        sumDef(),
        sumCrt()
    );
}