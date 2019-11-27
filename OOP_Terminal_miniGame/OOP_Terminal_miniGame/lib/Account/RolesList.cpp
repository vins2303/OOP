#include "../../include/Account/RolesList.h"
#include "../../include/LifeEntity/Roles/Race.h"


RolesList::RolesList(Account& _account) :Account(_account), roles(NULL){
    vector<string> file;
    string path = "Data/Account/"+ Account::getAccount();
    /*Tool::findFile(path, file);
    for (vector<string>::iterator it = file.begin(); it != file.end(); it++) {
        cout << *it << endl;
    }
    system("pause");*/
}

void RolesList::Menu() {
    bool isEnd = false;
    vector<string> dir;
    //Tool::findDir("Data/Account/" + getAccount(), dir);
    //FindRoles();
    vector<Roles*> test;
    FindRoles(test);
    while (!isEnd) {
        system("cls");
        cout << "1. 選擇角色" << endl;
        cout << "2. 新增角色" << endl;
        cout << "3. 刪除角色" << endl;
        switch (_getch())
        {
        case '2':
            addRoles();
            break;
        default:
            break;
        }
    }
}

bool RolesList::addRoles() {
    string name;
    Race::RaceType *race = NULL;
    Roles::RoleType *role = NULL;
    vector<string> namelist;
    
    while (1) {
        system("cls");
        cout << "請輸入角色名稱(Exit 離開):";
        cin >> name;
        if (name == "Exit") return false;
        if (find(namelist.begin(), namelist.end(), name) == namelist.end())
            break;
        cout << name <<" 已被使用過!" << endl;
        system("pause");
    }
    system("cls");
    cout << " ﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍" << endl;
    cout << "｜                   種族                           ｜" << endl;
    cout << "｜—————————————————————————｜" << endl;
    cout << "｜" << left << setw(11) << "1. 人族" << "｜" << left << setw(11) << "2. 獸人" << "｜" << left << setw(11) << "3. 精靈" << "｜" << left << setw(11) << "4.矮人"<<"｜" << endl;
    do {
        switch (_getch()){
        case '1':
            race = new  Race::RaceType(Race::RaceType::Human);
            break;
        case '2':
            race = new  Race::RaceType(Race::RaceType::Orc);
            break;
        case '3':
            race = new  Race::RaceType(Race::RaceType::Elves);
            break;
        case '4':
            race = new  Race::RaceType(Race::RaceType::Dwarf);
            break;
        }
    } while (race == NULL);

    system("cls");

    cout << " ﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍"  << endl;
    cout << "｜                職業              ｜" << endl;
    cout << "｜—————————————————｜" << endl;
    cout << "｜" << left << setw(10) << "1. 劍士" << "｜" << left << setw(10) << "2. 法師" << "｜" << left << setw(10) << "3. 盜賊"<<"｜" << endl;

    do {
        switch (_getch())
        {
        case '1':
            role = new  Roles::RoleType(Roles::RoleType::Warrior);
            break;
        case '2':
            role = new  Roles::RoleType(Roles::RoleType::Magician);
            break;
        case '3':
            role = new  Roles::RoleType(Roles::RoleType::Thief);
            break;
        }
    } while (role == NULL);
    Tool::mkdir("Data/Account/" + getAccount());
    string outfile = "Data/Account/" + getAccount() + "/Roles.ini";
    WritePrivateProfileString(name.c_str(), "LV", "1", outfile.c_str());
    WritePrivateProfileString(name.c_str(), "Race", Race::RaceTypeToString(*race).c_str(), outfile.c_str());
    WritePrivateProfileString(name.c_str(), "Role", Roles::RolesTypeToString(*role).c_str(), outfile.c_str());
    WritePrivateProfileString(name.c_str(), "HP", "0", outfile.c_str());
    WritePrivateProfileString(name.c_str(), "MP", "0", outfile.c_str());
    WritePrivateProfileString(name.c_str(), "EXP", "0", outfile.c_str());
    //cout << "角色名稱：" << name<<endl;
    cout << "新增角色成功!" << endl;
    system("pause");
    delete race;
    delete role;
    return true;
}

void RolesList::FindRoles(vector<Roles*> &out) {
    int LV;
    string inifile = "Data/Account/" + getAccount() + "/Roles.ini";
    vector<string> roleslist;
    Tool::getIpAppName(inifile,roleslist);
    for (vector<string>::iterator it = roleslist.begin(); it != roleslist.end(); it++) {
        LV = GetPrivateProfileInt((*it).c_str(), "LV", 0, inifile.c_str());
        cout << LV << endl;
    }
}

   