#include "../../../../include/LifeEntity/Roles/Skill/Skill_LIst.h"

Skill_List::Skill_List(Account& _user_account, RaceType _race, RoleType _role) :
    user_account(_user_account),
    Skill_Point(GetPrivateProfileInt((_user_account.getRolesName()).c_str(), "Skill_Point", INT_MAX, Roles_PATH__(_user_account.getAccount()).c_str())),
    skill_using(),
    skill(Read_skill()),
    racet(_race),
    rolet(_role)
{ }

Skill_List::~Skill_List()
{
    for (vector<Skill*>::iterator it = skill_using.begin(); it != skill_using.end(); it++)
        delete* it;

    for (vector<Skill*>::iterator it = skill.begin(); it != skill.end(); it++)
        delete* it;

    skill_using.clear();
    skill.clear();
}

void Skill_List::Skill_Menu() {
    while (1)
    {
        system("cls");
        cout << "======================= ��e�ޯ� =======================" << endl;
        for (vector<Skill*>::iterator it = skill.begin(); it != skill.end(); it++) {
            (*it)->show_info(true);
        }
        cout << "\n�Ѿl�ޯ��I�ơG" << Skill_Point << endl << endl;
        cout << "1. �ǲߧޯ�" << endl;
        cout << "2. �ɯŧޯ�" << endl;
        switch (_getch()) {
        case '1':
            New_Skill();
            break;
        case '2':
            UP_Skill();
            break;
        case 27:
        case 'k':
        case 'K':
            return;
            break;
        }
    }
}

void Skill_List::Save_Skill() {
    ofstream wire(SKILL_PAHT__(user_account.getAccount(), user_account.getRolesName()));
    WritePrivateProfileString(user_account.getRolesName().c_str(), "Skill_Point", to_string(Skill_Point).c_str(), Roles_PATH__(user_account.getAccount()).c_str());
    for (vector<Skill*>::iterator it = skill.begin(); it != skill.end(); it++) {
        wire << (*it)->getName() << " " << (*it)->getLV() << endl;
    }
    wire.close();
}

bool Skill_List::Us_Skill(LifeAttributes& att) {
    int key;
    vector<Skill*> skill_copy;
    for (vector<Skill*>::iterator it = skill.begin(); it != skill.end(); it++) {
        if ((*it)->get_Now_Cooling_Time() == 0) {
            skill_copy.push_back(*it);
        }
        else {
            cout << (*it)->getName() << " �Ѿl�N�o�ɶ��G" << (*it)->get_Now_Cooling_Time() << endl;
        }
    }
    cout << endl;
    if (skill_copy.size() == 0) {
        cout << "�ثe�S���ޯ�i�H�ϥ�!" << endl;
        system("pause");
        return false;
    }
    else {
        for (int i = 0; i < skill_copy.size(); i++) {
            cout << i << ". "; skill[i]->show_info(true);
        }
        while (1) {
            key = _getch();
            if (key == 27) return false;
            key -= '0';
            if (key >= 0 && key < 10 && key < skill_copy.size()) {
                if (att.getMP() < skill[key]->get_Consume_MP()) {
                    cout << "�]�O���� �L�k�ϥ�!" << endl;
                    return false;
                    system("pause");
                }
                else {
                    skill[key]->Casting_Skills();
                    skill_using.push_back(new Skill(*skill[key]));
                    att.setMP(att.getMP() - skill[key]->get_Consume_MP());
                    return true;
                }
            }
        }
    }
    return false;
}

void Skill_List::New_Skill() {
    system("cls");
    cout << "======================= �ǲߧޯ� =======================" << endl;
    if (Skill_Point <= 0) {
        cout << "�ޯ��I�� <1 �L�k�ǲ߷s���ޯ�" << endl;
        system("pause");
        return;
    }
    vector<string> findskill;
    vector<Skill*> ls_skill;
    int key;
    Tool::ReadIpAppName(Read_SKILL_INI_PATH, findskill);
    Skill* N_skill = NULL;

    for (vector<string>::iterator skill_name = findskill.begin(); skill_name != findskill.end(); skill_name++) {
        N_skill = new Skill(*skill_name, 1);
        if (findSkill(N_skill) == NULL && N_skill->Usable(rolet, racet)) {
            ls_skill.push_back(N_skill);
        }
        else {
            delete N_skill;
        }
    }

    for (int i = 0; i < ls_skill.size(); i++) {
        cout << i << ". "; ls_skill[i]->show_info();
    }
    N_skill = NULL;
    while (1) {
        key = _getch();
        if (key == 27) { break; }
        key -= '0';
        if (key >= 0 && key < 10 && key < ls_skill.size()) {
            N_skill = ls_skill[key];
            break;
        }
    }
    for (vector<Skill*>::iterator it = ls_skill.begin(); it != ls_skill.end(); it++) {
        if (*it != N_skill) {
            delete* it;
        }
    }
    if (N_skill != NULL) {
        cout << "�O�_���� 1 �ޯ��I�ǲ� " << N_skill->getName() << endl;
        cout << "(y)�O (n)�_";
        while (true)
        {
            key = _getch();
            if (key == 'y' || key == 'Y') {
                skill.push_back(N_skill);
                Skill_Point--;
                break;
            }
            else if (key == 'n' || key == 'N') {
                delete N_skill;
                break;
            }
        }
    }
}

void Skill_List::UP_Skill() {
    system("cls");
    int key;
    cout << "======================= �ɯŧޯ� =======================" << endl;
    if (Skill_Point <= 0) {
        cout << "�ޯ��I�� <1 �L�k�ɯŧޯ�" << endl;
        system("pause");
        return;
    }
    for (int i = 0; i < skill.size(); i++) {
        cout << i << ". "; skill[i]->show_info();
    }
    while (1) {
        key = _getch();
        if (key == 27) return;
        key -= '0';
        if (key >= 0 && key < 10 && key < skill.size()) {
            cout << "�O�_���� 1 �ޯ��I�j�� " << skill[key]->getName() << endl;
            cout << "(y)�O (n)�_" << endl;
            while (1) {
                int k2;
                k2 = _getch();
                if (k2 == 'y' || k2 == 'Y') {
                    Skill_Point--;
                    skill[key]->Up_LV();
                    cout << "�ɯŦ��\!" << endl;
                    system("pause");
                    return;
                }
                else {
                    break;
                }
            }
        }
    }
}

vector<Skill*> Skill_List::Read_skill() {
    ifstream Read(SKILL_PAHT__(user_account.getAccount(), user_account.getRolesName()));
    string kill_name;
    int lv;
    vector<Skill*> out;
    while (Read >> kill_name >> lv) {
        out.push_back(new Skill(kill_name, lv));
    }
    Read.close();
    return out;
}

Skill* Skill_List::findSkill(const Skill* _skill) {
    for (vector<Skill*>::iterator it = skill.begin(); it != skill.end(); it++)
        if (**it == *_skill)
            return *it;

    return NULL;
}

/*                                  get                                                  */
int Skill_List::Sum_Skill_HP() {
    static int out; out = 0;
    for (vector<Skill*>::iterator it = skill_using.begin(); it != skill_using.end(); it++)
        out += (*it)->getHP();
    return out;
}

int Skill_List::Sum_Skill_MP() {
    static int out; out = 0;
    for (vector<Skill*>::iterator it = skill_using.begin(); it != skill_using.end(); it++)
        out += (*it)->getMP();
    return out;
}

int Skill_List::Sum_Skill_Attack() {
    static int out; out = 0;
    for (vector<Skill*>::iterator it = skill_using.begin(); it != skill_using.end(); it++)
        out += (*it)->getAttack();
    return out;
}

int Skill_List::Sum_Skill_SP() {
    static int out; out = 0;
    for (vector<Skill*>::iterator it = skill_using.begin(); it != skill_using.end(); it++)
        out += (*it)->getSP();
    return out;
}

int Skill_List::Sum_Skill_Def() {
    static int out; out = 0;
    for (vector<Skill*>::iterator it = skill_using.begin(); it != skill_using.end(); it++)
        out += (*it)->getDef();
    return out;
}

int Skill_List::Sum_Skill_CRT() {
    static int out; out = 0;
    for (vector<Skill*>::iterator it = skill_using.begin(); it != skill_using.end(); it++)
        out += (*it)->getCRT();
    return out;
}

int Skill_List::Sum_Skill_Drop() {
    static int out; out = 0;
    for (vector<Skill*>::iterator it = skill_using.begin(); it != skill_using.end(); it++)
        out += (*it)->getDrop();
    return out;
}

void Skill_List::addSkill_Point(int n) { Skill_Point += n; }

void Skill_List::Round_End() {
    for (vector<Skill*>::iterator it = skill_using.begin(); it != skill_using.end(); it++) {
        (*it)->Round_End_US_Skill();
    }
    for (vector<Skill*>::iterator it = skill_using.begin(); it != skill_using.end(); it++) {
        if ((*it)->get_Duration() == 0) {
            delete* it;
            skill_using.erase(it);
            it = skill_using.begin();
            if (skill_using.size() == 0) break;
        }
    }
    for (vector<Skill*>::iterator it = skill.begin(); it != skill.end(); it++) {
        (*it)->Round_End_Restore();
    }
}