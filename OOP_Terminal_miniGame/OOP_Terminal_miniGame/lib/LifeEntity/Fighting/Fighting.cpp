#include "../../../include/LifeEntity/Fighting/Fighting.h"

Fighting::Fighting(Roles* _roles, Monster* _moster) :
    roles(_roles),
    monster(_moster)
{
}

bool Fighting::Fighting_Start() {
    system("cls");
    while (roles->getHP() > 0 && monster->getHP() > 0) {
        if (roles->getSP() > monster->getSP()) {
            Roles_Attack();
            if (monster->getHP() > 0) Moster_Attack();
        }
        else {
            Moster_Attack();
            if (roles->getHP() > 0)Roles_Attack();
        }
        cout << "�Ǫ�:"; monster->showHP(false);
        cout << "�i��:"; roles->showHP()->showMP();
        cout << endl;
    }

    if (roles->getHP() > 0) {
        cout << roles->getName() << "�ӧQ! ��o�g��:";
    }
    else {
        cout << roles->getName() << "�w�g���`";
    }
    system("pause");
    return false;
}

void Fighting::Moster_Attack() {
    static int  _attack;
    static bool _CRT;
    //static bool
    _CRT = (rand() % 100) < monster->getCRT();
    _attack = (((rand() % monster->Attributes::getAttack() + 1) * (_CRT ? 2 : 1)) - roles->getDef());
    if (_attack < 1) _attack = 1;
    roles->addHP(_attack * -1);
    cout << roles->getName() << " ����F" << (_CRT ? "�����ˮ`" : "") << "�l���F" << _attack << "�ͩR" << endl;
}

void Fighting::Roles_Attack() {
    static int  _attack;
    static bool _CRT;
    //static bool
    _CRT = (rand() % 100) < roles->getCRT();
    int nn = roles->getAttack();
    int kk = monster->Attributes::getDef();
    _attack = (((rand() % roles->getAttack() + 1) * (_CRT ? 2 : 1)) - monster->Attributes::getDef());
    if (_attack < 1) _attack = 1;
    monster->addHP(_attack * -1);
    cout << monster->getName() << " ����F" << (_CRT ? "�����ˮ`" : "") << "�l���F" << _attack << "�ͩR" << endl;
}