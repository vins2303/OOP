#include "../../../../include/LifeEntity/Roles/Back_Pack/Back_Pack.h"

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
    Read_BackPack_Equipment();
}

void Back_Pack::Save_BackPack() {
    Tool::mkdir(BACK_PACK_PAHT);
    Save_BackPack_Equipment();
}

void Back_Pack::Read_BackPack_Equipment() {
    ifstream Read_back(BACK_PACK_EQUIPMENT_PAHT);
    string name, type;
    int lv;
    while (Read_back >> name >> lv >> type) {
        goods.push_back(new Equipment_Attributes(name, lv, toBack_Pack_Type(type)));
    }
    Read_back.close();
}

void Back_Pack::Read_BackPack_Consumables() {
}

void Back_Pack::Save_BackPack_Equipment() {
    static Equipment_Attributes* _equ;
    ofstream wire_back(BACK_PACK_EQUIPMENT_PAHT);
    for (vector<Goods*>::iterator it = goods.begin(); it != goods.end(); it++) {
        if ((*it)->isEquipment()) {
            _equ = (Equipment_Attributes*)(*it);
            wire_back << _equ->getName() << " " << _equ->getLV() << " " << _equ->get_Back_Pack_Type_S() << endl;
        }
    }
    wire_back.close();
}

void Back_Pack::Save_BackPack_Consumables() {
    ofstream wire_back(BACK_PACK_CONSUMABLES_PAHT);

    wire_back.close();
}