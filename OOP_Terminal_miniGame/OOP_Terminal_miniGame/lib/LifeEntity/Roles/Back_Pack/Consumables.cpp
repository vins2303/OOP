#include "../../../../include/LifeEntity/Roles/Back_Pack/Consumables.h"

Consumables::Consumables(Account& _user_account, string _name, int _Quantity, int _Duration) :
    user_account(_user_account),
    Goods(user_account, _name, Read_Equipment_Attributes_int_ini(_name, "LV"), _Quantity),
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
    static int n;
    cout << "使用幾個：";
    cin >> n;
    if (n < 1) n = 1;
    if (n > getQuantity()) {
        cout << "數量不足" << endl;
    }
    else {
        for (int i = 0; i < n; i++) _life += *this;
        _life.showHP();
        _life.showMP();
        setQuantity(getQuantity() - n);
    }
    system("pause");
}