#include "../../../../include/LifeEntity/Roles/Back_Pack/Back_Pack.h"
#include "../../../../include/LifeEntity/Roles/Back_Pack/Consumables.h"

//#define Read_Back_Pack_int_ini( lpAppName,lpKeyName) GetPrivateProfileInt((lpAppName).c_str(), lpKeyName, INT_MAX, "Data/Account/"+ user_Account +"/Back_Pack/Back_Pack.ini")

#define BACK_PACK_PAHT "Data/Account/" + user_Account + "/" + user_Name
//#define BACK_PACK_EQUIPMENT_PAHT "Data/Account/" + user_Account + "/" + user_Name + "/BackPack_Equipment.txt"
//#define BACK_PACK_CONSUMABLES_PAHT "Data/Account/" + user_Account + "/" + user_Name + "/BackPack_Consumables.txt"
#define BACK_PACK_XXXX_PAHT "Data/Account/" + user_Account + "/" + user_Name + "/BackPack.txt"

Back_Pack::Back_Pack(string _account, string _user_name, int _Money) :
    user_Account(_account),
    user_Name(_user_name),
    Money(_Money)
{
    Read_BackPack();
}

Back_Pack::~Back_Pack() { }

int Back_Pack::getMoney() { return Money; }

void Back_Pack::setMoney(int _money) { Money = _money; }

int Back_Pack::AddMoney(int _money) { return Money += _money; }

void Back_Pack::Read_BackPack() {
    static string name, type;
    static int lv;

    ifstream Read_back(BACK_PACK_XXXX_PAHT);
    while (Read_back >> name >> lv) {
        switch (toBack_Pack_Type_Category(toBack_Pack_Type(Tool::ReadStringIni(name, "TYPE", "NULL", Read_Back_Pack_PATH))))
        {
        case  Back_Pack_Type_Category::Equipment:
            goods.push_back(new Equipment_Attributes(name, lv));
            break;

        case Back_Pack_Type_Category::Consumables:
            goods.push_back(new Consumables(name, lv));

        default:
            break;
        }
    }
    Read_back.close();
    //Read_BackPack_Consumables();
    //Read_BackPack_Equipment();
}

void Back_Pack::Save_BackPack() {
    Tool::mkdir(BACK_PACK_PAHT);

    ofstream wire_back(BACK_PACK_XXXX_PAHT);
    for (vector<Goods*>::iterator it = goods.begin(); it != goods.end(); it++) {
        if (typeid(**it) == typeid(Equipment_Attributes)) {
            static Equipment_Attributes* _equ;
            _equ = (Equipment_Attributes*)(*it);
            wire_back << _equ->getName() << " " << _equ->getLV() << " " << endl;
        }
        else if (typeid(**it) == typeid(Consumables)) {
            static Consumables* _equ;

            _equ = (Consumables*)(*it);
            wire_back << _equ->getName() << " " << _equ->getQuantity() << " " << endl;
        }
    }
    wire_back.close();

    /* Save_BackPack_Equipment();
     Save_BackPack_Consumables();*/
}

void Back_Pack::addGoods(Goods* _g) { goods.push_back(_g); }

Goods* Back_Pack::findGoods(string _name)
{
    for (vector<Goods*>::iterator it = goods.begin(); it != goods.end(); it++)
        if ((*it)->getName() == _name)
            return *it;
    return NULL;
}

vector<Goods*>& Back_Pack::getBackPack_Goods() { return goods; }

//void Back_Pack::Read_BackPack_Equipment() {
//    static string name, type;
//    static int lv;
//
//    ifstream Read_back(BACK_PACK_EQUIPMENT_PAHT);
//    while (Read_back >> name >> lv) {
//        goods.push_back(new Equipment_Attributes(name, lv));
//    }
//    Read_back.close();
//}

//void Back_Pack::Read_BackPack_Consumables() {
//    static string name;
//    static int lv;
//
//    ifstream Read_back(BACK_PACK_CONSUMABLES_PAHT);
//    while (Read_back >> name >> lv) {
//        goods.push_back(new Consumables(name, lv));
//    }
//    Read_back.close();
//}

//void Back_Pack::Save_BackPack_Equipment() {
//    static Equipment_Attributes* _equ;
//    ofstream wire_back(BACK_PACK_EQUIPMENT_PAHT);
//    for (vector<Goods*>::iterator it = goods.begin(); it != goods.end(); it++) {
//        if (typeid(**it) == typeid(Equipment_Attributes)) {
//            _equ = (Equipment_Attributes*)(*it);
//            wire_back << _equ->getName() << " " << _equ->getLV() << " " << endl;
//        }
//    }
//    _equ = NULL;
//    wire_back.close();
//}
//
//void Back_Pack::Save_BackPack_Consumables() {
//    static Consumables* _equ;
//    ofstream wire_back(BACK_PACK_CONSUMABLES_PAHT);
//    for (vector<Goods*>::iterator it = goods.begin(); it != goods.end(); it++) {
//        if (typeid(**it) == typeid(Consumables)) {
//            _equ = (Consumables*)(*it);
//            wire_back << _equ->getName() << " " << _equ->getQuantity() << " " << endl;
//        }
//    }
//    _equ = NULL;
//    wire_back.close();
//}