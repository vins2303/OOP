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
        cout << "怪物:"; monster->showHP(false);
        cout << "勇者:"; roles->showHP()->showMP();
        cout << endl;
    }

    if (roles->getHP() > 0) {
        cout << roles->getName() << "勝利! 獲得經驗:";
    }
    else {
        cout << roles->getName() << "已經死亡";
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
    cout << roles->getName() << " 受到了" << (_CRT ? "暴擊傷害" : "") << "損失了" << _attack << "生命" << endl;
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
    cout << monster->getName() << " 受到了" << (_CRT ? "暴擊傷害" : "") << "損失了" << _attack << "生命" << endl;
}