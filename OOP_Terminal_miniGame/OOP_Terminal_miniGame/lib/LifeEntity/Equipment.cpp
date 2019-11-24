#include "../../include/LifeEntity/Equipment.h"


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
Attributes* Equipment::setDeputy(Attributes *_data) { return deputy = _data; }
Attributes* Equipment::setHelmet(Attributes *_data) { return helmet = _data; }
Attributes* Equipment::setBreastplate(Attributes *_data) { return breastplate= _data; }
Attributes* Equipment::setPants(Attributes *_data) { return pants = _data; }
Attributes* Equipment::setShoes(Attributes *_data) { return shoes = _data; }

int Equipment::sumHP() { return getWeapon()->getHP() + getDeputy()->getHP() + getHelmet()->getHP() + getBreastplate()->getHP() + getPants()->getHP() + getShoes()->getHP(); }
int Equipment::sumMP() { return getWeapon()->getMP() + getDeputy()->getMP() + getHelmet()->getMP() + getBreastplate()->getMP() + getPants()->getMP() + getShoes()->getMP(); }
int Equipment::sumAttack() { return getWeapon()->getAttack() + getDeputy()->getAttack() + getHelmet()->getAttack() + getBreastplate()->getAttack() + getPants()->getAttack() + getShoes()->getAttack(); }
int Equipment::sumDef() { return  getWeapon()->getDef() + getDeputy()->getDef() + getHelmet()->getDef() + getBreastplate()->getDef() + getPants()->getDef() + getShoes()->getDef(); }
int Equipment::sumSP() { return getWeapon()->getSP() + getDeputy()->getSP() + getHelmet()->getSP() + getBreastplate()->getSP() + getPants()->getSP() + getShoes()->getSP(); }

Attributes* Equipment::getBuff() {
    return new Attributes(
        0,
        sumHP(),
        sumMP(),
        sumAttack(),
        sumSP(),
        sumDef()
    );
}