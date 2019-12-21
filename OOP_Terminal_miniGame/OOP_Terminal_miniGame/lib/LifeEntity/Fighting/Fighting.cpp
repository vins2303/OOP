#include "../../../include/LifeEntity/Fighting/Fighting.h"

Fighting::Fighting(Account& _user_account, Roles* _roles, Monster* _moster) :
    user_account(_user_account),
    roles(_roles),
    monster(_moster)
{
}

bool Fighting::Fighting_Start() {
    static int key;
    while (roles->getHP() > 0 && monster->getHP() > 0) {
        while (1) {
            Fighting_Start_Show();
            cout << "\n(1)普通攻擊 (2)使用技能 (3)打開背包" << endl;

            key = _getch();
            if (key == '1') {
                break;
            }
            else if (key == '2') {
                if (roles->Us_Skill(*roles)) {
                    break;
                }
            }
            else if (key == '3') {
                roles->Open_BackPack();
            }
        }
        Fighting_Start_Show();
        //===============================================================================
        cout << endl;
        if (roles->getSP() > monster->getSP()) {
            Roles_Attack();
            if (monster->getHP() > 0) Moster_Attack();
        }
        else {
            Moster_Attack();
            if (roles->getHP() > 0) Roles_Attack();
        }

        roles->Round_End();
        Tool::Delay(2);
    }
    system("cls");
    if (roles->getHP() > 0) {
        roles->addExp(monster->getExp());
        roles->AddMoney(monster->getMoney());

        cout << user_account.getRolesName() << "勝利! \n獲得經驗:" << monster->getExp() << endl << "獲得金幣：" << monster->getMoney() << endl;
        if (roles->UP_LV()) {
            cout << "恭喜升級! 等級：" << roles->getLV() << endl;
        }
        Rand_Drop();
    }
    else {
        cout << user_account.getRolesName() << "已經死亡";
    }
    system("pause");
    return false;
}

void Fighting::Fighting_Start_Show() {
    system("cls");
    cout << "=================== 角色狀態 ===================" << endl;
    roles->show_State();
    cout << "=================== 怪物狀態 ===================" << endl;
    monster->show_info_Fighting();
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
                        roles->addGoods(new Equipment_Attributes(user_account, (*it)->getName(), 1));
                        break;
                    case Back_Pack_Type_Category::Consumables:
                        //static Sub_Goods* god;
                        roles->addGoods(new Consumables(user_account, (*it)->getName(), number));
                        /*god = roles->findGoods((*it)->getName());
                        if (god == NULL) {
                        }
                        else {
                            god->addQuantity(number);
                        }*/
                        break;
                    case Back_Pack_Type_Category::SubBackPack:

                        roles->addGoods(new Sub_Back_Pack(
                            *roles->user_account,
                            Tool::FindMax(Tool::String_To_Int(Tool::ReadIpAppName(BACK_PACK_INI_PAHT(user_account.getAccount(), user_account.getRolesName())))) + 1,
                            toBack_Pack_Size((*it)->getName())
                        ));
                        break;
                    }
                    roles->Save_BackPack();
                    break;
                case 'n':
                case 'N':

                    break;
                }
                if ((key == 'a' || key == 'A') || (key == 'Y' || key == 'y') || (key == 'n' || key == 'N')) break;
            }
        }
    }
}

void Fighting::Moster_Attack() {
    static int  _attack;
    static bool _CRT;
    //static bool
    _CRT = (rand() % 100) < monster->getCRT();
    _attack = rand() % 20 - 10;
    _attack = (((monster->Attributes::getAttack() + (int)((double)_attack * 0.01 * (double)monster->Attributes::getAttack())) * (_CRT ? 2 : 1)));
    _attack = (int)(_attack - (double)_attack * (double)roles->getDef() * 0.01);
    if (_attack < 1) _attack = 1;
    roles->addHP(_attack * -1);
    cout << user_account.getRolesName() << " 受到了" << (_CRT ? "暴擊傷害" : "") << "損失了" << _attack << "生命" << endl;
}

void Fighting::Roles_Attack() {
    static int  _attack;
    static bool _CRT;
    //static bool
    _CRT = (rand() % 100) < roles->getCRT();
    _attack = rand() % 20 - 10;
    _attack = (((roles->getAttack() + (int)((double)roles->getAttack() * (double)_attack * 0.01)) * (_CRT ? 2 : 1)));
    _attack = (int)(_attack - (double)_attack * (double)monster->Attributes::getDef() * 0.01);

    if (_attack < 1) _attack = 1;
    monster->addHP(_attack * -1);
    cout << monster->getName() << " 受到了" << (_CRT ? "暴擊傷害" : "") << "損失了" << _attack << "生命" << endl;
}