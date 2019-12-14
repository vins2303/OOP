#include "../../../include/LifeEntity/Roles/Roles.h"

Roles::Roles(string _name, int _LV, int nowHP, int nowMP, int Exp, string _Map_Now, string _account, RaceType _race, RoleType _role, Map_object _object) :
    account(_account),
    name(_name),
    exp(Exp),
    Map_Now(_Map_Now),
    Role(_role),
    Map_object(_object),
    Race(_race),
    /*裝備*/
    Equipment(
        _account,
        _name
    ),
    /*背包*/
    Back_Pack(
        _account,
        _name,
        GetPrivateProfileInt(_name.c_str(), "Money", INT_MAX, ("Data/Account/" + _account + "/Roles.ini").c_str())

    ),

    /*屬性*/
    LifeAttributes(
        _LV,
        nowHP == -1 ? sum_Attributes(_race, _role, "HP") * _LV : nowHP,
        nowMP == -1 ? sum_Attributes(_race, _role, "MP") * _LV : nowMP,
        sum_Attributes(_race, _role, "Attack"),
        sum_Attributes(_race, _role, "SP"),
        sum_Attributes(_race, _role, "DEF"),
        sum_Attributes(_race, _role, "CRT"),
        sum_Attributes(_race, _role, "Drop"),
        sum_Attributes(_race, _role, "HP"),
        sum_Attributes(_race, _role, "MP")
    )
{}

Roles::~Roles() {
}

string Roles::getName() { return name; }
int Roles::getExp() { return exp; }
int Roles::getUpExp() { return (int)(pow(getLV() - 1, 3) + 60); }
//int Roles::getDrop() { return drop; }

string Roles::setName(string _name) { return name = _name; }
int Roles::setExp(int _exp) { return exp = (_exp > getUpExp() ? getUpExp() : _exp); }
//int Roles::setDrop(int _drop) { return drop = drop > 100 ? 100 : drop; }
void Roles::setMap_Now(const string _map) { Map_Now = _map; }

int Roles::addExp(int _exp, bool percent) {
    int exp = ADD_FUN(getExp(), _exp, percent);
    //if (exp > getUpExp()) exp = getUpExp();
    return setExp(exp);
}

//int Roles::addDrop(int _drop) { return setDrop(getDrop() + _drop); }

bool Roles::isUpLv() { return getExp() >= getUpExp() ? true : false; }

bool Roles::UP_LV() {
    if (isUpLv()) {
        addLV();
        setHP(getMaxHP());
        setMP(getMaxMP());
        setExp(0);
        return true;
    }
    return false;
}

void Roles::Open_BackPack() {
    vector<Goods*>& goods = getBackPack_Goods();
    static int key, _row, i;
    _row = 0;
    while (true) {
        system("cls");
        for (i = _row * 10; i < goods.size() && i < (_row + 1) * 10; i++) {
            cout << left << setw(3) << to_string(i % 10) + "." << " ";
            goods[i]->show_info();
        }
        cout << endl;
        if (_row != 0) cout << "(Q) 返回上一頁 ";
        if (i < goods.size()) cout << "(W) 前往下一頁";
        cout << endl;
        key = _getch();
        if (key == 27 || key == 'b' || key == 'B')
            break;

        switch (key)
        {
        case 27:
        case 'b':
        case 'B':
            return;
        case 'Q':
        case 'q':
            if (_row != 0) _row--;
            break;

        case 'w':
        case 'W':
            if (i < goods.size()) _row++;
            break;

        default:
            if ((key = key - '0') >= 0 && key < 10 && key + _row * 10 < (int)goods.size()) {
                Back_Pack_User_Item(goods[(__int64)key + (__int64)_row * 10]);

                for (vector<Goods*>::iterator it = goods.begin(); it != goods.end(); it++) {
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
    Save_Roles();
}

void Roles::Back_Pack_User_Item(Goods*& _gds) {
    if (_gds->isUse()) {
        if (_gds->Usable(get_RoleType(), getRaceType())) {
            if (getLV() >= _gds->getLV()) {
                if (typeid(*_gds) == typeid(Equipment_Attributes)) {
                    _gds = Put_on((Equipment_Attributes*)_gds);
                }
                else if (typeid(*_gds) == typeid(Consumables)) {
                    ((Consumables*)_gds)->Use(*this);
                    if (_gds->getQuantity() == 0) {
                        delete _gds;
                        _gds = NULL;
                    }
                }
            }
            else {
                cout << "你的等級未到達 無法使用!" << endl;
                system("pause");
            }
        }
        else {
            if (_gds->Usable_Role(get_RoleType()) == false) cout << "你的職業無法使用!" << endl;
            if (!_gds->Usable_Race(getRaceType()) == false) cout << "你的種族無法使用!" << endl;
            cout << endl;
            system("pause");
        }
    }
}

int Roles::sum_Attributes(RaceType _race, RoleType _role, string _att) {
    return GetPrivateProfileInt(toString(_race).c_str(), _att.c_str(), INT_MAX, "Data/Attributes/Race.ini") + GetPrivateProfileInt(toString(_role).c_str(), _att.c_str(), INT_MAX, "Data/Attributes/Role.ini");
}

//string Roles::getRoleType_S() { return toString(role); }
//RoleType Roles::getRoleType() { return (role); }

string Roles::getMap_Now() { return Map_Now; }

void Roles::Save_Roles_info() {
    string outfile = "Data/Account/" + account + "/Roles.ini";
    WritePrivateProfileString(name.c_str(), "LV", to_string(getLV()).c_str(), outfile.c_str());
    WritePrivateProfileString(name.c_str(), "Race", (getRaceType_S()).c_str(), outfile.c_str());
    WritePrivateProfileString(name.c_str(), "Role", getRoleType_S().c_str(), outfile.c_str());
    WritePrivateProfileString(name.c_str(), "HP", to_string(getHP()).c_str(), outfile.c_str());
    WritePrivateProfileString(name.c_str(), "MP", to_string(getMP()).c_str(), outfile.c_str());
    WritePrivateProfileString(name.c_str(), "EXP", to_string(getExp()).c_str(), outfile.c_str());
    WritePrivateProfileString(name.c_str(), "MapNow", getMap_Now().c_str(), outfile.c_str());
    WritePrivateProfileString(name.c_str(), "ObjectX", to_string(get_seat_X()).c_str(), outfile.c_str());
    WritePrivateProfileString(name.c_str(), "ObjectY", to_string(get_seat_Y()).c_str(), outfile.c_str());
    WritePrivateProfileString(name.c_str(), "ObjectWidth", to_string(get_Map_Width()).c_str(), outfile.c_str());
    WritePrivateProfileString(name.c_str(), "ObjectHeigh", to_string(getHeigh()).c_str(), outfile.c_str());
    WritePrivateProfileString(name.c_str(), "Money", to_string(getMoney()).c_str(), outfile.c_str());
}

//*********************************** 角色移動 ***********************************
/*物件移動 X*/
Map_object* Roles::set_Roles_Move_X(int _x, vector<Map_object*>& _object) {
    static Map_object* over;
    static int posX;
    over = NULL;
    posX = get_seat_X();
    Map_object::set_Point_X(_x);
    if ((over = Object_Overlapping(_object)) != NULL || get_seat_X() < 1 || get_seat_X() > MAP_WIDTH_DEF - get_Map_Width()) {
        Map_object::set_Point_X(posX);
    }
    else {
        Map_object::set_Point_X(posX);
        clear_Draw_Object();
        Map_object::set_Point_X(_x);
    }
    return over;
}

/*物件移動 Y*/
Map_object* Roles::set_Roles_Move_Y(int _y, vector<Map_object*>& _object) {
    static Map_object* over;
    static int posY;
    over = NULL;
    posY = get_seat_Y();
    Map_object::set_Point_Y(_y);
    if ((over = Object_Overlapping(_object)) != NULL || get_seat_Y() < 1 || get_seat_Y() > MAP_HIGH_DEF - getHeigh()) {
        Map_object::set_Point_Y(posY);
        //Y = posY;
    }
    else {
        Map_object::set_Point_Y(posY);
        clear_Draw_Object();
        Map_object::set_Point_Y(_y);
    }
    return over;
}

void Roles::Save_Roles() {
    Save_Roles_info();
    Save_BackPack();
    Save_Equipment();
}

void Roles::show_State() {
    system("cls");
    cout << "\n\n\t\t\t角色狀態" << endl << endl;
    cout << setw(20) << "角色名稱：" << " " << getName() << endl;
    cout << setw(20) << "種族：" << " " << getRaceType_S() << endl;
    cout << setw(20) << "職業：" << " " << getRoleType_S() << endl;
    cout << setw(20) << "等級：" << " " << getLV() << endl;
    cout << setw(20) << "生命：" << " "; showHP();
    cout << setw(20) << "魔力：" << " "; showMP();
    cout << setw(20) << "經驗值：" << " "; show_EXP();
    cout << setw(20) << "攻擊力：" << " " << getAttack() << endl;
    cout << setw(20) << "速度：" << " " << getSP() << endl;
    cout << setw(20) << "暴擊：" << " " << getCRT() << "%" << endl;
    cout << setw(20) << "減傷：" << " " << getDef() << "%" << endl;
    cout << setw(20) << "掉寶率：" << " " << getDrop() << "%" << endl;
    show_Equipment();
}

void Roles::show_EXP(bool show, bool LF) {
    Draw::SetColor(2);
    cout << SHOW_EXP_FRAME_BEGIN;
    for (int i = 0; i < SHOW_MAX_EXP; i++)
        cout << SHOW_EXP_FIGURE(i < (getExp() * (SHOW_MAX_EXP / (double)(getUpExp()))));
    cout << SHOW_MP_FRAME_END;
    Draw::SetColor();
    if (show) cout << " " << getExp() << "/" << getUpExp();
    if (LF) cout << endl;
    //return this;
}

////判斷是否重疊
//Map_object* Roles::Object_overlapping(Map_object& obj, vector<Map_object*>& _object) {
//    for (vector<Map_object*>::iterator it = _object.begin(); it != _object.end(); it++)
//        if (obj == (**it))
//            return *it;
//    return NULL;
//}
//**********************************************************************************************