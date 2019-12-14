#include "../../../../include/LifeEntity/Roles/Back_Pack/Consumables.h"

Consumables::Consumables(string _name, Back_Pack_Type _type, int _Quantity, int _Duration) :
    Goods(_name, Read_Equipment_Attributes_int_ini(_name, "LV"), _type, _Quantity),
    Duration(_Duration)
{}

Consumables::~Consumables() { }

void Consumables::show_info() {
    cout << getType_S() << "\t" << getName() << " 等級：" << getLV() << "\t" << "數量：" << getQuantity() << "\t";
    if (getHP() != 0) cout << "生命：" << getHP() << "\t";
    if (getMP() != 0) cout << "魔力：" << getMP() << "\t";
    if (getAttack() != 0) cout << "攻擊力：" << getAttack() << "\t";
    if (getSP() != 0) cout << "速度：" << getSP() << "	";
    if (getDef() != 0) cout << "減傷：" << getDef() << "%\t";
    if (getCRT() != 0) cout << "暴擊：" << getCRT() << "%\t";
    if (getDrop() != 0) cout << "調寶率：" << getDrop() << "\t";
    if (Duration != 0) cout << "持續時間:" << Duration << "回合\t";
    cout << endl << endl;
}

bool Consumables::isUse() {
    static int key;
    system("cls");
    cout << "是否要使用： "; show_info();
    cout << endl << "(y)是 (n)否" << endl;
    while (true) {
        if ((key = _getch()) == 'y' || key == 'Y')
            return true;
        else if (key == 'n' || key == 'N')
            return false;
    }
    return false;
}

void Consumables::Use(LifeAttributes& _life) {
    _life.addAttributes(*this);
    _life.showHP();
    _life.showMP();
    setQuantity(getQuantity() - 1);
    system("pause");
}