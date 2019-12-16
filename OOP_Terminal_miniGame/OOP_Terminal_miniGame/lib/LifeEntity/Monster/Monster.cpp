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
        //Read_Moater_Attributes_ini(_object.getName().c_str(), "Drop"),
        0
    ),
    exp(Read_Moater_Attributes_ini(_object.getName().c_str(), "EXP")),
    Money(Read_Moater_Attributes_ini(_object.getName().c_str(), "Money")),
    drop(Read_Drop())

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
    //Draw::setXY(_x, _y++);     cout << right << setw(8) << "���_�v�G" << this->Attributes::getDrop() << "%";
    Draw::setXY(_x, _y++);     cout << right << setw(8) << "�����B�G" << this->getMoney();
    _y++;
    Draw::setXY(_x, _y++); cout << "������\t���v";
    Draw::setXY(_x, _y++); cout << "------------";

    for (vector<Drop*>::iterator it = drop.begin(); it != drop.end(); it++) {
        Draw::setXY(_x, _y++); (*it)->show_info();
    }
    Draw::setXY(_x, ++_y);     cout << "�� Q �i�J�԰�";
    Draw::setXY(_x, _y++);
}

void Monster::show_info_Fighting() {
    cout << right << setw(8) << "���šG" << this->getLV()<<endl;
    cout << right << setw(8) << "�ͩR�G"; this->showHP(false);
    cout << right << setw(8) << "�����O�G" << this->Attributes::getAttack() << endl;
    cout << right << setw(8) << "�t�סG" << this->Attributes::getSP() << endl;
    cout << right << setw(8) << "��ˡG" << this->Attributes::getDef() << "%" << endl;
    cout << right << setw(8) << "�z���v�G" << this->Attributes::getCRT() << "%" << endl;
}

int Monster::getExp() { return exp; }
int Monster::getMoney() { return Money; }

vector<Drop*>& Monster::getDrop() { return drop; }

vector<Drop*> Monster::Read_Drop() {
    string name;
    int dop, n;
    vector<Drop*> out;

    ifstream Read_d(Read_Moater_DROP_PATH(string("ALL")));
    while (Read_d >> name >> dop >> n) {
        out.push_back(new Drop(name, dop, n));
    }
    Read_d.close();
    Read_d.open(Read_Moater_DROP_PATH(getName()));
    //ifstream Read_d(Read_Moater_DROP_PATH(getName()));
    while (Read_d >> name >> dop >> n) {
        out.push_back(new Drop(name, dop, n));
    }
    Read_d.close();
    return out;
}