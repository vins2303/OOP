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
        roles->addExp(monster->getExp());
        roles->AddMoney(monster->getMoney());

        cout << roles->getName() << "勝利! \n獲得經驗:" << monster->getExp() << endl << "獲得金幣：" << monster->getMoney() << endl;
        if (roles->UP_LV()) {
            cout << "恭喜升級! 等級：" << roles->getLV() << endl;
        }
        Rand_Drop();
    }
    else {
        cout << roles->getName() << "已經死亡";
    }
    system("pause");
    return false;
}

void Fighting::Rand_Drop() {
    static int number;
    static int key;
    key = 0;
    cout << "\n------------------ 掉落物 ------------------" << endl;
    for (vector<Drop*>::iterator it = monster->getDrop().begin(); it != monster->getDrop().end(); it++) {
        if ((*it)->isDrop(roles->getDrop())) {
            cout << "已掉落：" << (*it)->getName() << "數量：" << (number = (*it)->Drop_Number()) << endl;
            if (key != 'a' && key != 'A') { cout << "是否撿起 (y)是 (n)否 (a)撿起所有物品" << endl; key = 0; }
            while (1) {
                if (key != 'a' && key != 'A')
                    key = _getch();
                switch (key)
                {
                case 'y':
                case 'Y':
                case 'A':
                case 'a':
                    switch (toBack_Pack_Type_Category(toBack_Pack_Type(Tool::ReadStringIni((*it)->getName(), "TYPE", "NULL", Read_Back_Pack_PATH)))) {
                    case Back_Pack_Type_Category::Equipment:
                        roles->addGoods(new Equipment_Attributes((*it)->getName(), 1));
                        break;
                    case Back_Pack_Type_Category::Consumables:
                        static Goods* god;
                        god = roles->findGoods((*it)->getName());
                        if (god == NULL) {
                            roles->addGoods(new Consumables((*it)->getName(), number));
                        }
                        else {
                            god->addQuantity(number);
                        }
                        break;
                    }
                    break;
                case 'n':
                case 'N':

                    break;
                }
                if (key != 0 || (key == 'a' || key == 'A')) break;
            }
        }
    }
}

void Fighting::Moster_Attack() {
    static int  _attack;
    static bool _CRT;
    //static bool
    _CRT = (rand() % 100) < monster->getCRT();
    _attack = (((rand() % monster->Attributes::getAttack() + 1) * (_CRT ? 2 : 1)));
    _attack = (int)(_attack - (double)_attack * (double)roles->getDef() * 0.01);
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
    _attack = (((rand() % roles->getAttack() + 1) * (_CRT ? 2 : 1)));
    _attack = (int)(_attack - (double)_attack * (double)monster->Attributes::getDef() * 0.01);

    if (_attack < 1) _attack = 1;
    monster->addHP(_attack * -1);
    cout << monster->getName() << " 受到了" << (_CRT ? "暴擊傷害" : "") << "損失了" << _attack << "生命" << endl;
}