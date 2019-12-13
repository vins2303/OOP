#include "../../../../include/LifeEntity/Roles/Equipment/Equipment_Attributes.h"
#include "../../../../include/Tool/Tool.h"
#include <conio.h>

Equipment_Attributes::Equipment_Attributes(string _name, int _lv, Back_Pack_Type _type) :
    Goods(_name, _lv, _type)

{}

Equipment_Attributes::~Equipment_Attributes() {}

void Equipment_Attributes::show_info() {
    cout << getType_S() << "\t" << getName() << " ���šG" << getLV() << "\t";
    if (getHP() != 0) cout << "�ͩR�G" << getHP() << "\t";
    if (getMP() != 0) cout << "�]�O�G" << getMP() << "\t";
    if (getAttack() != 0) cout << "�����O�G" << getAttack() << "\t";
    if (getSP() != 0) cout << "�t�סG" << getSP() << "	";
    if (getDef() != 0) cout << "��ˡG" << getDef() << "%\t";
    if (getCRT() != 0) cout << "�����G" << getCRT() << "%\t";
    if (getDrop() != 0) cout << "���_�v�G" << getDrop() << "\t";
    cout << endl<<endl;
}

bool Equipment_Attributes::User_Items() {
    static int key;
    system("cls");
    cout << "�O�_�n�˳ơG "; show_info();
    cout << endl << "(y)�O (n)�_" << endl;
    while (true) {
        if ((key = _getch()) == 'y' || key == 'Y')
            return true;
        else if (key == 'n' || key == 'N')
            return false;
    }
    return false;
}

//bool Equipment_Attributes::Usable(Roles& _roles) {
//    return Usable(_roles.getRoleType(), _roles.getRaceType());
//}

int Equipment_Attributes::getHP() { return LV_Magnification(Attributes::getHP()); }

int Equipment_Attributes::getMP() { return LV_Magnification(Attributes::getMP()); }

int Equipment_Attributes::getAttack() { return LV_Magnification(Attributes::getAttack()); }

int Equipment_Attributes::getSP() { return LV_Magnification(Attributes::getSP()); }

int Equipment_Attributes::getDef() { return LV_Magnification(Attributes::getDef()); }

int Equipment_Attributes::getCRT() { return LV_Magnification(Attributes::getCRT()); }

int Equipment_Attributes::getDrop() { return LV_Magnification(Attributes::getDrop()); }