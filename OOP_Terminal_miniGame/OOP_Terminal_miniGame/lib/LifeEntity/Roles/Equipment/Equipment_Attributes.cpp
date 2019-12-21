#include "../../../../include/LifeEntity/Roles/Equipment/Equipment_Attributes.h"
#include "../../../../include/Tool/Tool.h"
#include <iomanip>

Equipment_Attributes::Equipment_Attributes(Account& user_account, string _name, int _lv) :
    Goods(user_account, _name, _lv)

{}

Equipment_Attributes::~Equipment_Attributes() {}

void Equipment_Attributes::show_info() {
    cout << left << setw(8) << getType_S() << getName() << "\t等級：" << left << setw(4) << getLV() << "\t";
    if (getHP() != 0) cout << "生命：" << left << setw(5) << getHP() << "\t";
    if (getMP() != 0) cout << "魔力：" << left << setw(5) << getMP() << "\t";
    if (getAttack() != 0) cout << "攻擊力：" << left << setw(5) << getAttack() << "\t";
    if (getSP() != 0) cout << "速度：" << left << setw(5) << getSP() << "\t";
    if (getDef() != 0) cout << "減傷：" << left << setw(5) << getDef() << "%\t";
    if (getCRT() != 0) cout << "暴擊：" << left << setw(5) << getCRT() << "%\t";
    if (getDrop() != 0) cout << "調寶率：" << left << setw(5) << getDrop() << "\t";
    if (getRestricted_Role()[0] != RoleType::null) {
        cout << "限定職業：";
        for (vector<RoleType>::iterator it = getRestricted_Role().begin(); it != getRestricted_Role().end(); it++)
            cout << toString(*it) << " ";
    }
    if (getRestricted_Race()[0] != RaceType::null) {
        cout << "限定種族：";
        for (vector<RaceType>::iterator it = getRestricted_Race().begin(); it != getRestricted_Race().end(); it++)
            cout << toString(*it) << " ";
    }
    cout << endl << endl;
}

bool Equipment_Attributes::isUse() {
    static int key;
    system("cls");
    cout << "是否要裝備： "; show_info();
    cout << endl << "(y)是 (n)否" << endl;
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