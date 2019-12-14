#include "../../../../include/LifeEntity/Roles/Back_Pack/Consumables.h"

Consumables::Consumables(string _name, Back_Pack_Type _type, int _Quantity, int _Duration) :
    Goods(_name, Read_Equipment_Attributes_int_ini(_name, "LV"), _type, _Quantity),
    Duration(_Duration)
{}

Consumables::~Consumables() { }

void Consumables::show_info() {
    cout << getType_S() << "\t" << getName() << " ���šG" << getLV() << "\t" << "�ƶq�G" << getQuantity() << "\t";
    if (getHP() != 0) cout << "�ͩR�G" << getHP() << "\t";
    if (getMP() != 0) cout << "�]�O�G" << getMP() << "\t";
    if (getAttack() != 0) cout << "�����O�G" << getAttack() << "\t";
    if (getSP() != 0) cout << "�t�סG" << getSP() << "	";
    if (getDef() != 0) cout << "��ˡG" << getDef() << "%\t";
    if (getCRT() != 0) cout << "�����G" << getCRT() << "%\t";
    if (getDrop() != 0) cout << "���_�v�G" << getDrop() << "\t";
    if (Duration != 0) cout << "����ɶ�:" << Duration << "�^�X\t";
    cout << endl << endl;
}

bool Consumables::isUse() {
    static int key;
    system("cls");
    cout << "�O�_�n�ϥΡG "; show_info();
    cout << endl << "(y)�O (n)�_" << endl;
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