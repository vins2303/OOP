#include "../../include/Account/RolesList.h"
//#include "../../include/LifeEntity/Roles/Race.h"

RolesList::RolesList() :Account(), roles(NULL) {}

RolesList::~RolesList() { if (roles != NULL) delete roles; }

void RolesList::RolesListMenu() {
    bool isEnd = false;
    if (Account::IsSignIn() == false) Account::AccountMenu();
    while (!isEnd) {
        system("cls");
        cout << "1. ��ܨ���" << endl;
        cout << "2. �s�W����" << endl;
        cout << "3. �R������" << endl;
        cout << "4. ��^�n�J�e��" << endl << endl;
        cout << "5. �R�����b��" << endl;
        switch (_getch())
        {
        case '1':
            isEnd = Selete_Roles();
            break;
        case '2':
            addRoles();
            break;
        case '3':
            DeleteRoles();
            break;
        case '4':
            if (roles != NULL) {
                delete roles;
                roles = NULL;
            }
            Account::clear();

            isEnd = true;
            break;
        case '5':
            isEnd = rmAccount();
            if (isEnd) {
                if (roles != NULL) {
                    delete roles;
                    roles = NULL;
                }
                Account::clear();
            }
            break;
        default:
            break;
        }
    }
}

void RolesList::DeleteRoles() {
    bool isExit = false;
    vector<Roles*> roleslist;
    int getKey;
    while (!isExit) {
        system("cls");
        FindRoles(roleslist);
        if (roleslist.size() == 0) {
            cout << "���b���S�����󨤦�Х��s�W����!" << endl;
            system("pause");
            isExit = true;
        }
        else {
            cout << "�R������!(�� Ese ���})" << endl;

            showRolesList(roleslist, 2);
            //for (unsigned int i = 0; i < roleslist.size(); i++) {
            //    cout << i+1 <<". " << roleslist[i]->getName() << endl;
            //}

            getKey = _getch();
            if (getKey == 27)
                isExit = true;
            else if ((unsigned int)(getKey = getKey - 1 - '0') < roleslist.size()) {
                WritePrivateProfileString(roleslist[getKey]->getName().c_str(), NULL, NULL, ("Data/Account/" + getAccount() + "/Roles.ini").c_str());
                cout << "�R�����\!" << endl;
                system("pause");
            }
        }
        clearRolesList(roleslist);
    }
}

bool RolesList::addRoles() {
    string name;
    Race::RaceType race_type = Race::RaceType::�H��;
    Roles::RoleType role_type = Roles::RoleType::�k�v;
    vector<string> namelist;
    bool isEnd = false;
    int getKey;

    while (1) {
        system("cls");
        Tool::getIpAppName("Data/Account/" + getAccount() + "/Roles.ini", namelist);
        if (namelist.size() > 2) {
            isEnd = true;
            cout << "����H��F�W��!" << endl;
            system("pause");
            break;
        }
        cout << "�п�J����W��(exit ���}):";
        cin >> name;
        if (name == "exit" || name == "Exit") return false;

        if (find(namelist.begin(), namelist.end(), name) == namelist.end())
            break;
        cout << name << " �w�Q�ϥιL!" << endl;
        namelist.clear();
        system("pause");
    }
    namelist.clear();
    system("cls");

    if (!isEnd) {
        isEnd = false;
        vector<string> TypeList;
        Tool::getIpAppName("Data/Attributes/Race.ini", TypeList);
        showRaceInfo(TypeList, "Data/Attributes/Race.ini", 0);

        while (!isEnd) {
            getKey = _getch();
            if (getKey == 27) {
                break;
            }if ((unsigned int)(getKey = getKey - '0' - 1) < TypeList.size()) {
                race_type = Race::StringToRaceType(TypeList[getKey]);
                isEnd = true;
            }
        }
        TypeList.clear();

        if (isEnd) {
            isEnd = false;
            system("cls");
            Tool::getIpAppName("Data/Attributes/Role.ini", TypeList);
            showRaceInfo(TypeList, "Data/Attributes/Role.ini", 0);
            while (!isEnd) {
                getKey = _getch();
                if (getKey == 27) {
                    break;
                }if ((unsigned int)(getKey = getKey - '0' - 1) < TypeList.size()) {
                    role_type = Roles::StringToRolesType(TypeList[getKey]);
                    isEnd = true;
                }
            }
            TypeList.clear();

            if (isEnd) {
                system("cls");
                cout << setw(10) << "����W�١G" << name << endl;
                cout << setw(10) << "�رڡG" << Race::RaceTypeToString(race_type) << endl;
                cout << setw(10) << "¾�~�G" << Roles::RolesTypeToString(role_type) << endl;
                cout << "�T�w�s�W(y) ����(N)" << endl;
                while (1) {
                    if ((getKey = _getch()) == 'y' || getKey == 'Y' || getKey == 'n' || getKey == 'N')
                        break;
                }
                if (getKey == 'y' || getKey == 'Y') {
                    Tool::mkdir("Data/Account/" + getAccount());
                    string outfile = "Data/Account/" + getAccount() + "/Roles.ini";
                    WritePrivateProfileString(name.c_str(), "LV", "1", outfile.c_str());
                    WritePrivateProfileString(name.c_str(), "Race", Race::RaceTypeToString(race_type).c_str(), outfile.c_str());
                    WritePrivateProfileString(name.c_str(), "Role", Roles::RolesTypeToString(role_type).c_str(), outfile.c_str());
                    WritePrivateProfileString(name.c_str(), "HP", to_string(Roles::sum_Attributes(race_type, role_type, "HP")).c_str(), outfile.c_str());
                    WritePrivateProfileString(name.c_str(), "MP", to_string(Roles::sum_Attributes(race_type, role_type, "MP")).c_str(), outfile.c_str());
                    WritePrivateProfileString(name.c_str(), "EXP", "0", outfile.c_str());
                    WritePrivateProfileString(name.c_str(), "MapNow", "����", outfile.c_str());
                    WritePrivateProfileString(name.c_str(), "ObjectX", "50", outfile.c_str());
                    WritePrivateProfileString(name.c_str(), "ObjectY", "22", outfile.c_str());
                    WritePrivateProfileString(name.c_str(), "ObjectWidth", ROLES_OBJECT_WIDTH, outfile.c_str());
                    WritePrivateProfileString(name.c_str(), "ObjectHeigh", ROLES_OBJECT_HEIGHT, outfile.c_str());

                    cout << "�s�W���⦨�\!" << endl;
                    system("pause");
                    return true;
                }
            }
        }
    }
    return false;
}

void RolesList::FindRoles(vector<Roles*>& out) {
    Roles* roles;
    string inifile = "Data/Account/" + getAccount() + "/Roles.ini";
    vector<string> roleslist;
    Tool::getIpAppName(inifile, roleslist);
    CString read_ini;
    Race::RaceType race;
    Roles::RoleType role;
    for (vector<string>::iterator it = roleslist.begin(); it != roleslist.end(); it++) {
        GetPrivateProfileString(it->c_str(), "Race", "NULL", read_ini.GetBuffer(255), 255, inifile.c_str());
        read_ini.ReleaseBuffer();
        race = Race::StringToRaceType(string(read_ini));
        GetPrivateProfileString(it->c_str(), "Role", "NULL", read_ini.GetBuffer(255), 255, inifile.c_str());
        read_ini.ReleaseBuffer();
        role = Roles::StringToRolesType(string(read_ini));

        roles = new Roles(
            *it,
            GetPrivateProfileInt((*it).c_str(), "LV", INT_MAX, inifile.c_str()),
            GetPrivateProfileInt((*it).c_str(), "HP", INT_MAX, inifile.c_str()),
            GetPrivateProfileInt((*it).c_str(), "MP", INT_MAX, inifile.c_str()),
            GetPrivateProfileInt((*it).c_str(), "EXP", INT_MAX, inifile.c_str()),
            Tool::readStringIni(*it, "MapNow", "NULL", inifile),
            this->getAccount(),
            race,
            role,
            Map_object("data/Image/object.txt",
                "Warrior",
                Map_object::objectType::Warrior,
                GetPrivateProfileInt((*it).c_str(), "ObjectX", INT_MAX, inifile.c_str()),
                GetPrivateProfileInt((*it).c_str(), "ObjectY", INT_MAX, inifile.c_str()),
                GetPrivateProfileInt((*it).c_str(), "ObjectWidth", INT_MAX, inifile.c_str()),
                GetPrivateProfileInt((*it).c_str(), "ObjectHeigh", INT_MAX, inifile.c_str())
            )
        );
        out.push_back(roles);
    }
}

bool RolesList::Selete_Roles() {
    vector<Roles*> roleslist;
    bool isExit = false;
    unsigned int getKey;
    while (roles == NULL && !isExit) {
        FindRoles(roleslist);
        system("cls");
        cout << "�@�� " << roleslist.size() << "/3 ������!" << endl;
        if (roleslist.size() == 0) {
            cout << "���b���S�����󨤦�e���s�W����!" << endl;
            system("pause");

            return addRoles();
        }

        cout << "�п�ܨ���:(Esc���})" << endl;
        showRolesList(roleslist, 3);

        while (!isExit) {
            getKey = _getch();
            if (getKey == 27)
                isExit = true;
            else if ((getKey = getKey - '0' - 1) < roleslist.size()) {
                roles = roleslist[getKey];
                isExit = true;
            }
        }

        clearRolesList(roleslist);
    }
    return roles == NULL ? false : true;
}

void RolesList::clearRolesList(vector<Roles*>& _list) {
    for (vector<Roles*>::iterator it = _list.begin(); it != _list.end(); it++)
        if (*it != roles)
            delete* it;
    _list.clear();
}

Roles* RolesList::getRoles() { return roles; }

void RolesList::showRolesList(vector<Roles*>& roleslist, unsigned int _row) {
    static unsigned int row;
    for (unsigned int i = 0; i < roleslist.size(); i++) {
        row = _row;
        Draw::setXY(SELROLESP_COL(i), row++); cout << "�U" << "�áááááá�";
        Draw::setXY(SELROLESP_COL(i), row++); cout << "�U" << (i + 1);
        Draw::setXY(SELROLESP_COL(i), row++); cout << "�U" << "��������";
        Draw::setXY(SELROLESP_COL(i), row++); cout << "�U" << roleslist[i]->getName();
        Draw::setXY(SELROLESP_COL(i), row++); cout << "�U" << setw(8) << "���šG" << roleslist[i]->getLV();
        Draw::setXY(SELROLESP_COL(i), row++); cout << "�U" << setw(8) << "�رڡG" << roleslist[i]->getRaceType();
        Draw::setXY(SELROLESP_COL(i), row++); cout << "�U" << setw(8) << "¾�~�G" << roleslist[i]->getRoleType();
        Draw::setXY(SELROLESP_COL(i), row++); cout << "�U" << setw(8) << "�����O�G" << roleslist[i]->getAttack();
        Draw::setXY(SELROLESP_COL(i), row++); cout << "�U" << setw(8) << "HP�G" << roleslist[i]->getMaxHP();
        Draw::setXY(SELROLESP_COL(i), row++); cout << "�U" << setw(8) << "MP�G" << roleslist[i]->getMaxMP();
        Draw::setXY(SELROLESP_COL(i), row++); cout << "�U" << "�šššššš�";
    }
    for (int i = 0; i < 11; i++) { Draw::setXY(SELROLESP_COL(roleslist.size()), _row + i); cout << "�U"; }
    Draw::setXY(0, row++);
}

void RolesList::showRoleInfo(const vector<string>& rolesList, const string _file, const unsigned int _row) {
    static unsigned int row;
    for (unsigned int i = 0; i < rolesList.size(); i++) {
        row = _row;
        Draw::setXY(SHOWRACEINFO_COL(i), row++); for (int count = 0; count < SHOWRACEINFO_COUNT; count++) cout << "��";
        //Draw::setXY(SHOWRACEINFO_COL(i), row++); cout << "�U";
        row++;
        Draw::setXY(SHOWRACEINFO_COL(i), row++); for (int count = 0; count < SHOWRACEINFO_COUNT; count++) cout << "��";
        Draw::setXY(SHOWRACEINFO_COL(i), row++); cout << "�U" << right << setw(4) << (i + 1) << ". " << left << setw(10) << rolesList.at(i);
        Draw::setXY(SHOWRACEINFO_COL(i), row++); cout << "�U"; for (int count = 0; count < SHOWRACEINFO_COUNT - 1; count++) cout << "��";
        Draw::setXY(SHOWRACEINFO_COL(i), row++); cout << "�U" << right << setw(8) << "�����O�G" << left << setw(6) << GetPrivateProfileInt(rolesList[i].c_str(), "Attack", INT_MAX, _file.c_str());
        Draw::setXY(SHOWRACEINFO_COL(i), row++); cout << "�U" << right << setw(8) << "HP�G" << left << setw(6) << GetPrivateProfileInt(rolesList[i].c_str(), "HP", INT_MAX, _file.c_str());
        Draw::setXY(SHOWRACEINFO_COL(i), row++); cout << "�U" << right << setw(8) << "MP�G" << left << setw(6) << GetPrivateProfileInt(rolesList[i].c_str(), "MP", INT_MAX, _file.c_str());
        Draw::setXY(SHOWRACEINFO_COL(i), row++); cout << "�U" << right << setw(8) << "�t�סG" << left << setw(6) << GetPrivateProfileInt(rolesList[i].c_str(), "SP", INT_MAX, _file.c_str());
        Draw::setXY(SHOWRACEINFO_COL(i), row++); cout << "�U" << right << setw(8) << "�z���G" << left << setw(6) << GetPrivateProfileInt(rolesList[i].c_str(), "CRT", INT_MAX, _file.c_str());
        Draw::setXY(SHOWRACEINFO_COL(i), row++); cout << "�U" << right << setw(8) << "���m�G" << left << setw(6) << GetPrivateProfileInt(rolesList[i].c_str(), "DEF", INT_MAX, _file.c_str());
        Draw::setXY(SHOWRACEINFO_COL(i), row++); cout << "�U" << right << setw(8) << "���_�v�G" << left << setw(6) << GetPrivateProfileInt(rolesList[i].c_str(), "Drop", INT_MAX, _file.c_str());
        Draw::setXY(SHOWRACEINFO_COL(i), row++); for (int count = 0; count < SHOWRACEINFO_COUNT; count++) cout << "��";
    }
    for (int i = 0; i < 13; i++) {
        Draw::setXY(0, _row + i); cout << "�U";
        Draw::setXY(SHOWRACEINFO_COL(rolesList.size()), _row + i); cout << "�U";
    }

    Draw::setXY(SHOWRACEINFO_COUNT * 2 * rolesList.size() / 2 - 2, _row + 1); cout << "¾�~";
    Draw::setXY(0, row);
}

void RolesList::showRaceInfo(const vector<string>& raceList, const string _file, const unsigned int _row) {
    static unsigned int row;
    for (unsigned int i = 0; i < raceList.size(); i++) {
        row = _row;
        Draw::setXY(SHOWRACEINFO_COL(i), row++); for (int count = 0; count < SHOWRACEINFO_COUNT; count++) cout << "��";
        //Draw::setXY(SHOWRACEINFO_COL(i), row++); cout << "�U";
        row++;
        Draw::setXY(SHOWRACEINFO_COL(i), row++); for (int count = 0; count < SHOWRACEINFO_COUNT; count++) cout << "��";
        Draw::setXY(SHOWRACEINFO_COL(i), row++); cout << "�U" << right << setw(4) << (i + 1) << ". " << left << setw(10) << raceList.at(i);
        Draw::setXY(SHOWRACEINFO_COL(i), row++); cout << "�U"; for (int count = 0; count < SHOWRACEINFO_COUNT - 1; count++) cout << "��";
        Draw::setXY(SHOWRACEINFO_COL(i), row++); cout << "�U" << right << setw(8) << "�����O�G" << left << setw(6) << GetPrivateProfileInt(raceList[i].c_str(), "Attack", INT_MAX, _file.c_str());
        Draw::setXY(SHOWRACEINFO_COL(i), row++); cout << "�U" << right << setw(8) << "HP�G" << left << setw(6) << GetPrivateProfileInt(raceList[i].c_str(), "HP", INT_MAX, _file.c_str());
        Draw::setXY(SHOWRACEINFO_COL(i), row++); cout << "�U" << right << setw(8) << "MP�G" << left << setw(6) << GetPrivateProfileInt(raceList[i].c_str(), "MP", INT_MAX, _file.c_str());
        Draw::setXY(SHOWRACEINFO_COL(i), row++); cout << "�U" << right << setw(8) << "�t�סG" << left << setw(6) << GetPrivateProfileInt(raceList[i].c_str(), "SP", INT_MAX, _file.c_str());
        Draw::setXY(SHOWRACEINFO_COL(i), row++); cout << "�U" << right << setw(8) << "�z���G" << left << setw(6) << GetPrivateProfileInt(raceList[i].c_str(), "CRT", INT_MAX, _file.c_str());
        Draw::setXY(SHOWRACEINFO_COL(i), row++); cout << "�U" << right << setw(8) << "���m�G" << left << setw(6) << GetPrivateProfileInt(raceList[i].c_str(), "DEF", INT_MAX, _file.c_str());
        Draw::setXY(SHOWRACEINFO_COL(i), row++); cout << "�U" << right << setw(8) << "���_�v�G" << left << setw(6) << GetPrivateProfileInt(raceList[i].c_str(), "Drop", INT_MAX, _file.c_str());
        Draw::setXY(SHOWRACEINFO_COL(i), row++); for (int count = 0; count < SHOWRACEINFO_COUNT; count++) cout << "��";
    }
    for (int i = 0; i < 13; i++) {
        Draw::setXY(0, _row + i); cout << "�U";
        Draw::setXY(SHOWRACEINFO_COL(raceList.size()), _row + i); cout << "�U";
    }

    Draw::setXY(SHOWRACEINFO_COUNT * 2 * raceList.size() / 2 - 2, _row + 1); cout << "�ر�";
    Draw::setXY(0, row);
}