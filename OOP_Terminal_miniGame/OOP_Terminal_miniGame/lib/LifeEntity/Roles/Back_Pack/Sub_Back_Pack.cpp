#include "../../../../include/LifeEntity/Roles/Back_Pack/Sub_Back_Pack.h"
#include <iomanip>

Sub_Back_Pack::Sub_Back_Pack(string _account, string _user_name, int ID, Back_Pack_Szie _size_type) :
    Back_ID(ID),
    user_Account(_account),
    user_Name(_user_name),
    type(_size_type == Back_Pack_Szie::Back_Pack_Min ? toBack_Pack_Size(Tool::ReadStringIni(to_string(ID), "BackPackSize", "小型背包", BACK_PACK_INI_PAHT(_account, _user_name))) : _size_type),
    Sub_Goods(toString(_size_type == Back_Pack_Szie::Back_Pack_Min ? toBack_Pack_Size(Tool::ReadStringIni(to_string(ID), "BackPackSize", "小型背包", BACK_PACK_INI_PAHT(_account, _user_name))) : _size_type))

{
    Read_BackPack();
}

Sub_Back_Pack::~Sub_Back_Pack() {
    for (vector<Sub_Goods*>::iterator it = goods.begin(); it != goods.end(); it++) {
        delete* it;
    }
}

void Sub_Back_Pack::Read_BackPack() {
    static string name, type;
    static int lv;

    ifstream Read_back(BACK_PACK_INFO_PAHT(user_Account, user_Name, to_string(Back_ID)));
    while (Read_back >> name >> lv) {
        switch (toBack_Pack_Type_Category(toBack_Pack_Type(Tool::ReadStringIni(name, "TYPE", "NULL", Read_Back_Pack_PATH))))
        {
        case  Back_Pack_Type_Category::Equipment:
            goods.push_back(new Equipment_Attributes(name, lv));
            break;

        case Back_Pack_Type_Category::Consumables:
            goods.push_back(new Consumables(name, lv));
            break;
        case Back_Pack_Type_Category::SubBackPack:
            goods.push_back(new Sub_Back_Pack(user_Account, user_Name, lv)); // lv = back_pack id
            break;
        default:
            break;
        }
    }
    Read_back.close();
}

void Sub_Back_Pack::Save_BackPack() {
    static string name;
    static int lv;
    Tool::mkdir(BACK_PACK_PAHT(user_Account, user_Name));
    WritePrivateProfileString(to_string(Back_ID).c_str(), "BackPackSize", toString(type).c_str(), BACK_PACK_INI_PAHT(user_Account, user_Name).c_str());

    ofstream wire_back(BACK_PACK_INFO_PAHT(user_Account, user_Name, to_string(Back_ID)));
    for (vector<Sub_Goods*>::iterator it = goods.begin(); it != goods.end(); it++) {
        if (typeid(**it) == typeid(Equipment_Attributes)) {
            static Equipment_Attributes* _equ;
            _equ = (Equipment_Attributes*)(*it);
            wire_back << _equ->getName() << " " << _equ->getLV() << endl;
        }
        else if (typeid(**it) == typeid(Consumables)) {
            static Consumables* _equ;

            _equ = (Consumables*)(*it);
            wire_back << _equ->getName() << " " << _equ->getQuantity() << endl;
        }
        else if (typeid(**it) == typeid(Sub_Back_Pack)) {
            static Sub_Back_Pack* _sub;
            _sub = (Sub_Back_Pack*)(*it);
            wire_back << _sub->getName() << " " << _sub->getID() << endl;
            _sub->Save_BackPack();
        }
    }
    wire_back.close();
}

void Sub_Back_Pack::Open_Sub_Back_Pack(Sub_Back_Pack& Previous_Back) {
    static int key, _row, i;
    _row = 0;
    while (true) {
        system("cls");
        cout << "==================================== " << Back_ID << " ====================================" << endl;
        cout << "\t背包負重："; ShowWeith(); cout << endl;

        for (i = _row * 10; i < goods.size() && i < (_row + 1) * 10; i++) {
            cout << left << setw(3) << to_string(i % 10) + "." << " ";
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
                int sel = 0;
                system("cls");
                if (typeid(*goods[(__int64)key + (__int64)_row * 10]) == typeid(Sub_Back_Pack))
                    cout << "1. 進入子背包 or 丟回上一個背包" << endl;
                else cout << "1. 丟回上一個背包" << endl;
                cout << "2. 丟到子背包\n3. 丟棄物品";
                while (sel == 0) {
                    switch ((sel = _getch()))
                    {
                    case '1':
                        static bool ismove;
                        ismove = true;
                        if (typeid(*goods[(__int64)key + (__int64)_row * 10]) == typeid(Sub_Back_Pack)) {
                            int kk;

                            while (true) {
                                system("cls");
                                cout << "1. 進入子背包\n2.丟回上一個背包" << endl;
                                kk = _getch();
                                if (kk == '1') {
                                    ((Sub_Back_Pack*)goods[(__int64)key + (__int64)_row * 10])->Open_Sub_Back_Pack(*this);
                                    ismove = false;
                                    break;
                                }
                                else if (kk == '2') {
                                    ismove = true;
                                    break;
                                }
                            }
                        }
                        if (ismove) {
                            if (Previous_Back.getNowWeith() + goods[(__int64)key + (__int64)_row * 10]->getWight() > Previous_Back.getMaxWeith()) {
                                cout << "前一個背包過重無法丟回!" << endl;
                                system("pause");
                            }
                            else {
                                Previous_Back.addGoods(goods[(__int64)key + (__int64)_row * 10]);
                                RmGoods((__int64)key + (__int64)_row * 10);
                            }
                        }

                        break;
                    case '2':
                        if (Put_To_Sub_Back_Pack(goods[(__int64)key + (__int64)_row * 10])) {
                            RmGoods((__int64)key + (__int64)_row * 10);
                        }
                        break;
                    case '3':
                        static Sub_Goods * _good; _good = goods[(__int64)key + (__int64)_row * 10];
                        if (typeid(*_good) == typeid(Sub_Back_Pack)) {
                            WritePrivateProfileString(to_string((((Sub_Back_Pack*)_good)->getID())).c_str(), NULL, NULL, BACK_PACK_INI_PAHT(user_Account, user_Name).c_str());
                            remove(BACK_PACK_INFO_PAHT(user_Account, user_Name, to_string(((Sub_Back_Pack*)_good)->getID())).c_str());
                        }
                        delete goods[(__int64)key + (__int64)_row * 10];
                        goods[(__int64)key + (__int64)_row * 10] = NULL;
                        break;
                    default:
                        //sel = 0;
                        break;
                    }
                }

                for (vector<Sub_Goods*>::iterator it = goods.begin(); it != goods.end(); it++) {
                    if (*it == NULL) {
                        goods.erase(it);
                        if (goods.size() > 0)
                            it = goods.begin();
                        else break;
                    }
                }
            }
            break;
        }
    }
    Save_BackPack();
}

int Sub_Back_Pack::getID() { return Back_ID; }

void Sub_Back_Pack::addGoods(Sub_Goods* _g) { goods.push_back(_g); }

void Sub_Back_Pack::RmGoods(int n) {
    goods.erase(goods.begin() + n);
}

void Sub_Back_Pack::ShowWeith(int _max, bool show, bool LF) {
    Draw::SetColor(3);
    cout << SHOW_WEITH_FRAME_BEGIN;
    for (int i = 0; i < SHOW_MAX_WEITH; i++)
        cout << SHOW_WEITH_FIGURE(i < (getNowWeith() * (SHOW_MAX_EXP / (double)(getMaxWeith()))));
    cout << SHOW_MP_FRAME_END;
    Draw::SetColor();
    if (show) cout << " " << left << setw(4) << getNowWeith() << "/" << left << setw(4) << getMaxWeith();
    if (LF) cout << endl;
}

Back_Pack_Szie Sub_Back_Pack::getBack_Pack_Szie_Type() { return type; }

void Sub_Back_Pack::setBack_Pack_Szie_Type(Back_Pack_Szie _type) { type = _type; }

Sub_Goods* Sub_Back_Pack::findGoods(string _name) {
    for (vector<Sub_Goods*>::iterator it = goods.begin(); it != goods.end(); it++)
        if ((*it)->getName() == _name)
            return *it;
    return NULL;
}

vector<Sub_Goods*>& Sub_Back_Pack::getBackPack_Goods() { return goods; }

bool Sub_Back_Pack::Put_To_Sub_Back_Pack(Sub_Goods*& _gds)
{
    vector<Sub_Back_Pack*> goods_copy;

    for (vector<Sub_Goods*>::iterator it = goods.begin(); it != goods.end(); it++) {
        if (typeid(**it) == typeid(Sub_Back_Pack))
            goods_copy.push_back((Sub_Back_Pack*)*it);
    }
    if (goods_copy.size() == 0) {
        cout << "沒有子背包!" << endl;
        system("pause");
        return false;
    }
    static int key, _row, i;
    _row = 0;

    while (true) {
        system("cls");
        cout << "==================================== 子背包 ====================================" << endl;
        for (i = _row * 10; i < goods_copy.size() && i < (_row + 1) * 10; i++) {
            cout << left << setw(3) << to_string(i % 10) + "." << " ";
            goods_copy[i]->show_info();
        }
        cout << endl;
        if (_row != 0) cout << "(Q) 返回上一頁 ";
        if (i < goods_copy.size()) cout << "(W) 前往下一頁 ";
        cout << endl;
        key = _getch();

        switch (key)
        {
        case 27: case 'b': case 'B':
            return false;
        case 'Q': case 'q':
            if (_row != 0) _row--;
            break;

        case 'w': case 'W':
            if (i < goods.size()) _row++;
            break;

        default:
            if ((key = key - '0') >= 0 && key < 10 && key + _row * 10 < (int)goods_copy.size()) {
                if (goods_copy[key]->getNowWeith() + _gds->getWight() > goods_copy[key]->getMaxWeith()) {
                    cout << "子背包過重無法存放!" << endl;
                    system("pause");
                    return false;
                }
                else {
                    goods_copy[key]->addGoods(_gds);
                    return true;
                }
            }
            break;
        }
    }
    return false;
}

void Sub_Back_Pack::show_info() {
    cout << getType_S() << "\t" << getName() << "\tID：" << getID() << "\t負重：" << getNowWeith() << "/" << getMaxWeith() << endl << endl;
}

bool Sub_Back_Pack::isUse() {
    if (getNowWeith() == 0) {
        system("cls");
        cout << "是否要更換背包? (y)是 (n)否" << endl;
        while (1) {
            switch (_getch())
            {
            case 'y':
            case 'Y':
                return true;
            case 'n':
            case 'N':
            case 27:
                return false;
            }
        }
    }
    return true;
}

int Sub_Back_Pack::getNowWeith() {
    static int out; out = 0;
    for (vector<Sub_Goods*>::iterator it = goods.begin(); it != goods.end(); it++)
        out += (*it)->getWight();
    return out;
}

int Sub_Back_Pack::getMaxWeith() { return GetPrivateProfileInt(toString(type).c_str(), "Weight_Max", INT_MAX, Read_Back_Pack_PATH); }