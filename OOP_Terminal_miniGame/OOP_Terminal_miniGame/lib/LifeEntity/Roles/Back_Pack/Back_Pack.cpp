#include "../../../../include/LifeEntity/Roles/Back_Pack/Back_Pack.h"
#include "../../../../include/LifeEntity/Roles/Back_Pack/Consumables.h"

//#define Read_Back_Pack_int_ini( lpAppName,lpKeyName) GetPrivateProfileInt((lpAppName).c_str(), lpKeyName, INT_MAX, "Data/Account/"+ user_Account +"/Back_Pack/Back_Pack.ini")

#define BACK_PACK_PAHT "Data/Account/" + user_Account + "/" + user_Name
#define BACK_PACK_EQUIPMENT_PAHT "Data/Account/" + user_Account + "/" + user_Name + "/BackPack_Equipment.txt"
#define BACK_PACK_CONSUMABLES_PAHT "Data/Account/" + user_Account + "/" + user_Name + "/BackPack_Consumables.txt"

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

void Back_Pack::Read_BackPack() {
    Read_BackPack_Consumables();
    Read_BackPack_Equipment();
}

void Back_Pack::Save_BackPack() {
    Tool::mkdir(BACK_PACK_PAHT);
    Save_BackPack_Equipment();
    Save_BackPack_Consumables();
}

vector<Goods*>& Back_Pack::getBackPack_Goods() { return goods; }

void Back_Pack::Read_BackPack_Equipment() {
    static string name, type;
    static int lv;

    ifstream Read_back(BACK_PACK_EQUIPMENT_PAHT);
    while (Read_back >> name >> lv >> type) {
        goods.push_back(new Equipment_Attributes(name, lv, toBack_Pack_Type(type)));
    }
    Read_back.close();
}

void Back_Pack::Read_BackPack_Consumables() {
    static string name, type;
    static int lv;

    ifstream Read_back(BACK_PACK_CONSUMABLES_PAHT);
    while (Read_back >> name >> lv >> type) {
        goods.push_back(new Consumables(name, toBack_Pack_Type(type), lv));
    }
    Read_back.close();
}

void Back_Pack::Save_BackPack_Equipment() {
    static Equipment_Attributes* _equ;
    ofstream wire_back(BACK_PACK_EQUIPMENT_PAHT);
    for (vector<Goods*>::iterator it = goods.begin(); it != goods.end(); it++) {
        if (typeid(**it) == typeid(Equipment_Attributes)) {
            _equ = (Equipment_Attributes*)(*it);
            wire_back << _equ->getName() << " " << _equ->getLV() << " " << _equ->getType_S() << endl;
        }
    }
    _equ = NULL;
    wire_back.close();
}

void Back_Pack::Save_BackPack_Consumables() {
    static Consumables* _equ;
    ofstream wire_back(BACK_PACK_CONSUMABLES_PAHT);
    for (vector<Goods*>::iterator it = goods.begin(); it != goods.end(); it++) {
        if (typeid(**it) == typeid(Consumables)) {
            _equ = (Consumables*)(*it);
            wire_back << _equ->getName() << " " << _equ->getQuantity() << " " << _equ->getType_S() << endl;
        }
    }
    _equ = NULL;
    wire_back.close();
}