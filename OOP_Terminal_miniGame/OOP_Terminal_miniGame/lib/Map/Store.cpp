#include "../../include/Map/Store.h"

Store::Store(Account& _user_account, string _Store_Name) :
    user_account(_user_account),
    Store_Name(_Store_Name)
{
    Read_Store();
}

Store::~Store() {
    for (vector<Sub_Goods*>::iterator it = Stroe_Goods.begin(); it != Stroe_Goods.end(); it++)
        delete* it;
}

void Store::Store_Menu(Roles& roles) {
    system("cls");
    int key;
    cout << "1. 購賣物品" << endl;
    cout << "2. 販售物品" << endl;

    while (true) {
        switch ((key = _getch())) {
        case '1':
            Shopping(roles);
            return;
        case '2':
            Sell(roles);
            return;
        case 27:
            return;
        }
    }

    system("pause");
}

void Store::Shopping(Roles& roles) {
    int key, number;
    while (1) {
        system("cls");
        cout << "剩餘金幣：" << roles.getMoney()<<endl;
        for (int i = 0; i < Stroe_Goods.size(); i++) {
            cout << i << ". 售價：" << Stroe_Goods[i]->getMoney() * 2 << " "; Stroe_Goods[i]->show_info();
        }
        switch ((key = _getch())) {
        case 27:
            return;
        default:
            key -= '0';
            if (key >= 0 && key < Stroe_Goods.size()) {
                cout << "請輸入購買數量："; cin >> number;
                if (number * Stroe_Goods[key]->getMoney() * 2 > roles.getMoney()) {
                    cout << "您只有 " << roles.getMoney() << "金幣不足無法購買!" << endl;
                }
                else if (Stroe_Goods[key]->getWight_one() * number + roles.getWight() > roles.getMaxWeith()) {
                    cout << "已超過背包最大負重!" << endl;
                }
                else {
                    for (int i = 0; i < number; i++) {
                        if (typeid(*Stroe_Goods[key]) == typeid(Equipment_Attributes)) {
                            roles.addGoods(new Equipment_Attributes(*((Equipment_Attributes*)Stroe_Goods[key])));
                        }
                        else if (typeid(*Stroe_Goods[key]) == typeid(Consumables)) {
                            roles.addGoods(new Consumables(*((Consumables*)Stroe_Goods[key])));
                        }
                    }
                    roles.AddMoney(-1 * ((2 * number * Stroe_Goods[key]->getMoney())));
                    cout << "購買成功!" << endl;
                }
                system("pause");
            }
            break;
        }
    }
}

void Store::Sell(Roles& roles) {
    system("cls");
    static int key, _row, i, count;
    _row = 0;

    while (true) {
        system("cls");
        vector<Sub_Goods*>& goods = roles.getBackPack_Goods();
        cout << "==================================== " << "背包" << " ====================================" << endl;
        cout << "\t背包負重："; roles.ShowWeith(); cout << endl;

        for (i = _row * 10; i < goods.size() && i < (_row + 1) * 10; i++) {
            cout << left << setw(3) << to_string(i % 10) + "." << " 販售價格：" << goods[i]->getMoney() << " ";
            goods[i]->show_info();
        }
        cout << endl;
        if (_row != 0) cout << "(Q) 返回上一頁 ";
        if (i < goods.size()) cout << "(W) 前往下一頁 ";
        cout << endl;

        key = _getch();

        switch (key)
        {
        case 27: case 'b': case 'B':
            return;
        case 'Q': case 'q':
            if (_row != 0) _row--;
            break;

        case 'w': case 'W':
            if (i < goods.size()) _row++;
            break;
        default:
            if ((key = key - '0') >= 0 && key < 10 && key + _row * 10 < (int)goods.size()) {
                count = goods[key]->getQuantity();
                if (count != 1) {
                    static int sell_count;
                    cout << "請輸入販售數量："; cin >> sell_count;
                    if (sell_count > count) {}
                    else if (sell_count < 0) count = 0;
                    else count = sell_count;
                }
                goods[key]->addQuantity(count * -1);
                cout << "獲得 " << goods[key]->getMoney() * count << "金幣" << endl;
                roles.AddMoney(goods[key]->getMoney() * count);
                {
                    if (typeid(*goods[key]) == typeid(Sub_Back_Pack)) {
                        ((Sub_Back_Pack*)goods[key])->Away_Sub_Back_Pack();
                    }
                }
                system("pause");
                for (vector<Sub_Goods*>::iterator it = goods.begin(); it != goods.end(); it++) {
                    if ((*it)->getQuantity() <= 0) {
                        delete* it;
                        goods.erase(it);
                        break;
                    }
                }
            }
        }
    }
}

void Store::Read_Store() {
    static string name, type;
    static int lv;
    ifstream Read_back(MAP_STORE_PATH(Store_Name));
    while (Read_back >> name) {
        switch (toBack_Pack_Type_Category(toBack_Pack_Type(Tool::ReadStringIni(name, "TYPE", "NULL", Read_Back_Pack_PATH))))
        {
        case  Back_Pack_Type_Category::Equipment:
            Stroe_Goods.push_back(new Equipment_Attributes(user_account, name));
            break;

        case Back_Pack_Type_Category::Consumables:
            Stroe_Goods.push_back(new Consumables(user_account, name));
            break;
            //case Back_Pack_Type_Category::SubBackPack:
            //    Stroe_Goods.push_back(new Sub_Back_Pack(user_account, lv)); // lv = back_pack id
            //    break;
        default:
            break;
        }
    }
    Read_back.close();
}