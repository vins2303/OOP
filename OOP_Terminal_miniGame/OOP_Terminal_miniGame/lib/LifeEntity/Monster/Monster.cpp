#include "../../../include/LifeEntity/Monster/Monster.h"
#include <conio.h>
#include <iomanip>

Monster::Monster(Map_object _object) :
    Map_object(_object),
    LifeAttributes(
        Read_Moater_Attributes_ini(_object.getName().c_str(), "LV"),
        Read_Moater_Attributes_ini(_object.getName().c_str(), "HP"),
        Read_Moater_Attributes_ini(_object.getName().c_str(), "MP"),
        Read_Moater_Attributes_ini(_object.getName().c_str(), "Attack"),
        Read_Moater_Attributes_ini(_object.getName().c_str(), "SP"),
        Read_Moater_Attributes_ini(_object.getName().c_str(), "DEF"),
        Read_Moater_Attributes_ini(_object.getName().c_str(), "CRT"),
        Read_Moater_Attributes_ini(_object.getName().c_str(), "Drop")
    ),
    exp(Read_Moater_Attributes_ini(_object.getName().c_str(), "EXP"))

{}

Monster::~Monster() {}

void Monster::show_info(int _x, int _y) {
    showObject(_x, _y);
    _y = getHeigh() + _y;
    int n = this->getAttack();
    Draw::setXY(_x, (++_y)++); cout << right << setw(8) << "���šG" << this->getLV();
    Draw::setXY(_x, _y++);     cout << right << setw(8) << "�ͩR�G" << this->Attributes::getHP();
    Draw::setXY(_x, _y++);     cout << right << setw(8) << "�����O�G" << this->Attributes::getAttack();
    Draw::setXY(_x, _y++);     cout << right << setw(8) << "�t�סG" << this->Attributes::getSP();
    Draw::setXY(_x, _y++);     cout << right << setw(8) << "��ˡG" << this->Attributes::getDef() << "%";
    Draw::setXY(_x, _y++);     cout << right << setw(8) << "�z���v�G" << this->Attributes::getCRT() << "%";
    Draw::setXY(_x, _y++);     cout << right << setw(8) << "�g��ȡG" << this->exp;
    Draw::setXY(_x, _y++);     cout << right << setw(8) << "���_�v�G" << this->Attributes::getDrop()<<"%";
    Draw::setXY(_x, ++_y);     cout << "�� Q �i�J�԰�";
    Draw::setXY(_x, _y++);
}

int Monster::getExp() { return exp; }
//void Monster::setExp(int _n) { exp = _n; }