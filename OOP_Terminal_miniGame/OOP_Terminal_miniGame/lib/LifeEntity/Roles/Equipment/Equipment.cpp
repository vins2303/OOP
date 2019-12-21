#include"../../../../include/LifeEntity/Roles/Equipment/Equipment.h"

Equipment::Equipment(Account& _acc, string _name) :
    user_account(_acc),
    name(_name),
    Weapon(Read_Equipment_Attributes(Back_Pack_Type::Weapon)),
    Deputy(Read_Equipment_Attributes(Back_Pack_Type::Deputy)),
    Helmet(Read_Equipment_Attributes(Back_Pack_Type::Helmet)),
    Breastplate(Read_Equipment_Attributes(Back_Pack_Type::Breastplate)),
    Pants(Read_Equipment_Attributes(Back_Pack_Type::Pants)),
    Shoes(Read_Equipment_Attributes(Back_Pack_Type::Shoes))
{
}

Equipment::~Equipment() {
    if (Weapon != NULL)      delete Weapon;
    if (Deputy != NULL)      delete Deputy;
    if (Helmet != NULL)      delete Helmet;
    if (Breastplate != NULL) delete Breastplate;
    if (Pants != NULL)       delete Pants;
    if (Shoes != NULL)       delete Shoes;
}

Equipment_Attributes* Equipment::Put_on(Equipment_Attributes* _E) {
    static Equipment_Attributes* retE;
    switch (_E->getType())
    {
    case Back_Pack_Type::Weapon:
        retE = Weapon;
        Weapon = _E;
        break;
    case Back_Pack_Type::Deputy:
        retE = Deputy;
        Deputy = _E;
        break;

    case Back_Pack_Type::Helmet:
        retE = Helmet;
        Helmet = _E;
        break;
    case Back_Pack_Type::Breastplate:
        retE = Breastplate;
        Breastplate = _E;
        break;
    case Back_Pack_Type::Pants:
        retE = Pants;
        Pants = _E;
        break;
    case Back_Pack_Type::Shoes:
        retE = Shoes;
        Shoes = _E;
        break;
    default:
        break;
    }
    return retE;
}

void Equipment::Remove_Equipment(vector<Sub_Goods*>& goods) {
    static int key;
    while (1) {
        system("cls");
        show_Equipment();
        cout << "Esc 返回" << endl;
        if (Weapon != NULL) cout << "1. 卸下武器" << endl;
        if (Deputy != NULL)      cout << "2. 卸下副武器" << endl;
        if (Helmet != NULL)      cout << "3. 卸下頭盔" << endl;
        if (Breastplate != NULL) cout << "4. 卸下胸甲" << endl;
        if (Pants != NULL)       cout << "5. 卸下褲子" << endl;
        if (Shoes != NULL)       cout << "6. 卸下鞋子" << endl;

        switch (_getch())
        {
        case '1':
            if (Weapon != NULL) {
                goods.push_back(Weapon);
                Weapon = NULL;
            }
            break;
        case '2':
            if (Deputy != NULL) {
                goods.push_back(Deputy);
                Deputy = NULL;
            }
            break;
        case '3':
            if (Helmet != NULL) {
                goods.push_back(Helmet);
                Helmet = NULL;
            }
            break;
        case '4':
            if (Breastplate != NULL) {
                goods.push_back(Breastplate);
                Breastplate = NULL;
            }
            break;
        case '5':
            if (Pants != NULL) {
                goods.push_back(Pants);
                Pants = NULL;
            }
            break;
        case '6':
            if (Shoes != NULL) {
                goods.push_back(Shoes);
                Shoes = NULL;
            }
            break;
        case 27:
            return;
        }
    }
}

//void Equipment::Remove_Equipment(Back_Pack& back_pack)
//{
//}

Equipment_Attributes* Equipment::getWeapon() { return Weapon; }
Equipment_Attributes* Equipment::getDeputy() { return Deputy; }
Equipment_Attributes* Equipment::getHelmet() { return Helmet; }
Equipment_Attributes* Equipment::getBreastplate() { return Breastplate; }
Equipment_Attributes* Equipment::getPants() { return Pants; }
Equipment_Attributes* Equipment::getShoes() { return Shoes; }

Equipment_Attributes* Equipment::setWeapon(Equipment_Attributes* _data) { return Weapon = _data; }
Equipment_Attributes* Equipment::setDeputy(Equipment_Attributes* _data) { return Deputy = _data; }
Equipment_Attributes* Equipment::setHelmet(Equipment_Attributes* _data) { return Helmet = _data; }
Equipment_Attributes* Equipment::setBreastplate(Equipment_Attributes* _data) { return Breastplate = _data; }
Equipment_Attributes* Equipment::setPants(Equipment_Attributes* _data) { return Pants = _data; }
Equipment_Attributes* Equipment::setShoes(Equipment_Attributes* _data) { return Shoes = _data; }

int Equipment::sumHP() {
    int sum = 0;
    if (Weapon != NULL)      sum += Weapon->getHP();
    if (Deputy != NULL)      sum += Deputy->getHP();
    if (Helmet != NULL)      sum += Helmet->getHP();
    if (Breastplate != NULL) sum += Breastplate->getHP();
    if (Pants != NULL)       sum += Pants->getHP();
    if (Shoes != NULL)       sum += Shoes->getHP();
    return sum;
}
int Equipment::sumMP() {
    int sum = 0;
    if (Weapon != NULL)      sum += Weapon->getMP();
    if (Deputy != NULL)      sum += Deputy->getMP();
    if (Helmet != NULL)      sum += Helmet->getMP();
    if (Breastplate != NULL) sum += Breastplate->getMP();
    if (Pants != NULL)       sum += Pants->getMP();
    if (Shoes != NULL)       sum += Shoes->getMP();
    return sum;
}
int Equipment::sumAttack() {
    int sum = 0;
    if (Weapon != NULL)      sum += Weapon->getAttack();
    if (Deputy != NULL)      sum += Deputy->getAttack();
    if (Helmet != NULL)      sum += Helmet->getAttack();
    if (Breastplate != NULL) sum += Breastplate->getAttack();
    if (Pants != NULL)       sum += Pants->getAttack();
    if (Shoes != NULL)       sum += Shoes->getAttack();
    return sum;
}
int Equipment::sumDef() {
    int sum = 0;
    if (Weapon != NULL)      sum += Weapon->getDef();
    if (Deputy != NULL)      sum += Deputy->getDef();
    if (Helmet != NULL)      sum += Helmet->getDef();
    if (Breastplate != NULL) sum += Breastplate->getDef();
    if (Pants != NULL)       sum += Pants->getDef();
    if (Shoes != NULL)       sum += Shoes->getDef();
    return sum;
}
int Equipment::sumSP() {
    int sum = 0;
    if (Weapon != NULL)      sum += Weapon->getSP();
    if (Deputy != NULL)      sum += Deputy->getSP();
    if (Helmet != NULL)      sum += Helmet->getSP();
    if (Breastplate != NULL) sum += Breastplate->getSP();
    if (Pants != NULL)       sum += Pants->getSP();
    if (Shoes != NULL)       sum += Shoes->getDef();
    return sum;
}
int Equipment::sumCrt() {
    int sum = 0;
    if (Weapon != NULL)      sum += Weapon->getCRT();
    if (Deputy != NULL)      sum += Deputy->getCRT();
    if (Helmet != NULL)      sum += Helmet->getCRT();
    if (Breastplate != NULL) sum += Breastplate->getCRT();
    if (Pants != NULL)       sum += Pants->getCRT();
    if (Shoes != NULL)       sum += Shoes->getCRT();
    if (sum > 100) sum = 100;
    return sum;
}

int Equipment::sumDrop() {
    int sum = 0;
    if (Weapon != NULL)      sum += Weapon->getDrop();
    if (Deputy != NULL)      sum += Deputy->getDrop();
    if (Helmet != NULL)      sum += Helmet->getDrop();
    if (Breastplate != NULL) sum += Breastplate->getDrop();
    if (Pants != NULL)       sum += Pants->getDrop();
    if (Shoes != NULL)       sum += Shoes->getDrop();
    if (sum > 100) sum = 100;
    return sum;
}

void Equipment::show_Equipment()
{
    cout << endl << "==================================== 裝備 ====================================" << endl;
    if (Weapon != NULL)      Weapon->show_info();
    if (Deputy != NULL)      Deputy->show_info();
    if (Helmet != NULL)      Helmet->show_info();
    if (Breastplate != NULL) Breastplate->show_info();
    if (Pants != NULL)       Pants->show_info();
    if (Shoes != NULL)       Shoes->show_info();
}

void Equipment::Save_Equipment() {
    Tool::mkdir(Equipment_DIR_PATH(user_account.getAccount(), user_account.getRolesName()));
    if (Weapon != NULL) {
        WritePrivateProfileString(toString(Back_Pack_Type::Weapon).c_str(), "Have", "1", Equipment_INI_PATH(user_account.getAccount(), user_account.getRolesName()).c_str());
        WritePrivateProfileString(toString(Back_Pack_Type::Weapon).c_str(), "Name", Weapon->getName().c_str(), Equipment_INI_PATH(user_account.getAccount(), user_account.getRolesName()).c_str());
        WritePrivateProfileString(toString(Back_Pack_Type::Weapon).c_str(), "LV", to_string(Weapon->getLV()).c_str(), Equipment_INI_PATH(user_account.getAccount(), user_account.getRolesName()).c_str());
    }
    else {
        WritePrivateProfileString(toString(Back_Pack_Type::Weapon).c_str(), "Have", "0", Equipment_INI_PATH(user_account.getAccount(), user_account.getRolesName()).c_str());
    }

    if (Deputy != NULL) {
        WritePrivateProfileString(toString(Back_Pack_Type::Deputy).c_str(), "Have", "1", Equipment_INI_PATH(user_account.getAccount(), user_account.getRolesName()).c_str());
        WritePrivateProfileString(toString(Back_Pack_Type::Deputy).c_str(), "Name", Deputy->getName().c_str(), Equipment_INI_PATH(user_account.getAccount(), user_account.getRolesName()).c_str());
        WritePrivateProfileString(toString(Back_Pack_Type::Deputy).c_str(), "LV", to_string(Deputy->getLV()).c_str(), Equipment_INI_PATH(user_account.getAccount(), user_account.getRolesName()).c_str());
    }
    else {
        WritePrivateProfileString(toString(Back_Pack_Type::Deputy).c_str(), "Have", "0", Equipment_INI_PATH(user_account.getAccount(), user_account.getRolesName()).c_str());
    }

    if (Helmet != NULL) {
        WritePrivateProfileString(toString(Back_Pack_Type::Helmet).c_str(), "Have", "1", Equipment_INI_PATH(user_account.getAccount(), user_account.getRolesName()).c_str());
        WritePrivateProfileString(toString(Back_Pack_Type::Helmet).c_str(), "Name", Helmet->getName().c_str(), Equipment_INI_PATH(user_account.getAccount(), user_account.getRolesName()).c_str());
        WritePrivateProfileString(toString(Back_Pack_Type::Helmet).c_str(), "LV", to_string(Helmet->getLV()).c_str(), Equipment_INI_PATH(user_account.getAccount(), user_account.getRolesName()).c_str());
    }
    else {
        WritePrivateProfileString(toString(Back_Pack_Type::Helmet).c_str(), "Have", "0", Equipment_INI_PATH(user_account.getAccount(), user_account.getRolesName()).c_str());
    }

    if (Breastplate != NULL) {
        WritePrivateProfileString(toString(Back_Pack_Type::Breastplate).c_str(), "Have", "1", Equipment_INI_PATH(user_account.getAccount(), user_account.getRolesName()).c_str());
        WritePrivateProfileString(toString(Back_Pack_Type::Breastplate).c_str(), "Name", Breastplate->getName().c_str(), Equipment_INI_PATH(user_account.getAccount(), user_account.getRolesName()).c_str());
        WritePrivateProfileString(toString(Back_Pack_Type::Breastplate).c_str(), "LV", to_string(Breastplate->getLV()).c_str(), Equipment_INI_PATH(user_account.getAccount(), user_account.getRolesName()).c_str());
    }
    else {
        WritePrivateProfileString(toString(Back_Pack_Type::Breastplate).c_str(), "Have", "0", Equipment_INI_PATH(user_account.getAccount(), user_account.getRolesName()).c_str());
    }

    if (Pants != NULL) {
        WritePrivateProfileString(toString(Back_Pack_Type::Pants).c_str(), "Have", "1", Equipment_INI_PATH(user_account.getAccount(), user_account.getRolesName()).c_str());
        WritePrivateProfileString(toString(Back_Pack_Type::Pants).c_str(), "Name", Pants->getName().c_str(), Equipment_INI_PATH(user_account.getAccount(), user_account.getRolesName()).c_str());
        WritePrivateProfileString(toString(Back_Pack_Type::Pants).c_str(), "LV", to_string(Pants->getLV()).c_str(), Equipment_INI_PATH(user_account.getAccount(), user_account.getRolesName()).c_str());
    }
    else {
        WritePrivateProfileString(toString(Back_Pack_Type::Pants).c_str(), "Have", "0", Equipment_INI_PATH(user_account.getAccount(), user_account.getRolesName()).c_str());
    }

    if (Shoes != NULL) {
        WritePrivateProfileString(toString(Back_Pack_Type::Shoes).c_str(), "Have", "1", Equipment_INI_PATH(user_account.getAccount(), user_account.getRolesName()).c_str());
        WritePrivateProfileString(toString(Back_Pack_Type::Shoes).c_str(), "Name", Shoes->getName().c_str(), Equipment_INI_PATH(user_account.getAccount(), user_account.getRolesName()).c_str());
        WritePrivateProfileString(toString(Back_Pack_Type::Shoes).c_str(), "LV", to_string(Shoes->getLV()).c_str(), Equipment_INI_PATH(user_account.getAccount(), user_account.getRolesName()).c_str());
    }
    else {
        WritePrivateProfileString(toString(Back_Pack_Type::Shoes).c_str(), "Have", "0", Equipment_INI_PATH(user_account.getAccount(), user_account.getRolesName()).c_str());
    }
}

Equipment_Attributes* Equipment::Read_Equipment_Attributes(Back_Pack_Type _type) {
    if (GetPrivateProfileInt(toString(_type).c_str(), "Have", 0, Equipment_INI_PATH(user_account.getAccount(), user_account.getRolesName()).c_str())) {
        return new Equipment_Attributes(
            user_account,
            Tool::ReadStringIni(toString(_type), "Name", "NULL", Equipment_INI_PATH(user_account.getAccount(), user_account.getRolesName())),
            GetPrivateProfileInt(toString(_type).c_str(), "LV", INT_MAX, Equipment_INI_PATH(user_account.getAccount(), user_account.getRolesName()).c_str())
        );
    }
    return NULL;
}

//Attributes* Equipment::getBuff() {
//    return new Attributes(
//        sumHP(),
//        sumMP(),
//        sumAttack(),
//        sumSP(),
//        sumDef(),
//        sumCrt()
//    );
//}