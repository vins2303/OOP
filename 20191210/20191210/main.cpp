#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<fstream>
#include <time.h>
#include<windows.h>
//#include "CNameGenerator.h"
#include "FOOD.h"
using namespace std;

class rabbit :public FOOD {
public:
    rabbit(string _name, int MAXLESSFOOD) :FOOD(_name, MAXLESSFOOD)

    {}
    void skill(vector<FOOD*>& ve) {
        if (getCskill() == 0) {
            if (rand() % 10 < 3) {
                setCskill(rand() % 5 + 1);
            }
        }
    }

    bool ear() {
        if (getCskill() != 0) {
            setCskill(getCskill() - 1);
        }
        else {
            Remaining -= rand() % maxlessfood + 1;
            Remaining = Remaining < 0 ? 0 : Remaining;
            return Remaining == 0 ? true : false;
        }
        return false;
    }
};

class tortoise :public FOOD {
public:
    tortoise(string _name, int MAXLESSFOOD) :FOOD(_name, MAXLESSFOOD) {}

    void skill(vector<FOOD*>& ve) {
        if (getCskill() == 0) {
            if (rand() % 10 < 3) {
                setCskill(rand() % 5 + 1);
            }
        }
    }

    bool ear() {
        buff = (rand() % maxlessfood + 1) * (getCskill() == 0 ? 1 : 2);
        Remaining -= buff;
        Remaining = Remaining < 0 ? 0 : Remaining;
        return Remaining == 0 ? true : false;
    }
};

class Mice :public FOOD {
public:
    vector<FOOD*> ve;
    Mice(string _name, int MAXLESSFOOD) :FOOD(_name, MAXLESSFOOD) {}

    void skill(vector<FOOD*>& _ve) {
        ve = _ve;
    }

    bool ear() {
        buff = (rand() % maxlessfood + 1);
        Remaining -= buff;
        Remaining = Remaining < 0 ? 0 : Remaining;
        return Remaining == 0 ? true : false;
    }

    virtual void show_static() {
        cout << Remaining << ":\t|";
        for (int i = 0; i < 20; i++)
            cout << (i < Remaining * 0.02 ? "#" : " ");
        cout << "| ";
        if (getCskill() == 0) {
            if (rand() % 10 < 3) {
                int lefo = rand() % maxlessfood + 1;
                int n = rand() % ve.size();
                ve[n]->Remaining += lefo;
                Remaining -= lefo;
                cout << name << "盢敖倒 " << ve[n]->name << " 计秖:" << lefo;
            }
        }
        cout << endl;
    }
};

class People :public FOOD {
public:
    vector<FOOD*> ve;
    People(string _name, int MAXLESSFOOD) :FOOD(_name, MAXLESSFOOD) {}

    void skill(vector<FOOD*>& _ve) {
        ve = _ve;
    }

    bool ear() {
        buff = (rand() % maxlessfood + 1);
        Remaining -= buff;
        Remaining = Remaining < 0 ? 0 : Remaining;
        return Remaining == 0 ? true : false;
    }

    virtual void show_static() {
        cout << Remaining << ":\t|";
        for (int i = 0; i < 20; i++)
            cout << (i < Remaining * 0.02 ? "#" : " ");
        cout << "| ";

        if ((rand() % 2) == 1) {
            if (getCskill() == 0) {
                if (rand() % 10 < 3) {
                    int lefo = rand() % maxlessfood + 1;
                    int n = rand() % ve.size();
                    ve[n]->Remaining -= lefo;
                    //Remaining -= lefo;
                    cout << name << "腊 " << ve[n]->name << "硉:" << lefo;
                }
            }
        }
        else if ((rand() % 2) == 1) {
            if (getCskill() == 0) {
                if (rand() % 10 < 3) {
                    int lefo = rand() % maxlessfood + 1;
                    int n = rand() % ve.size();
                    ve[n]->Remaining += lefo;
                    Remaining -= lefo;
                    cout << name << "盢敖倒 " << ve[n]->name << "计秖" << lefo;
                }
            }
        }
        cout << endl;
    }
};

int main() {
    srand(time(NULL));
    while (1) {
        vector<FOOD*> fd;
        FOOD* save_fd;
        bool game_exit;
        int input;
        while (true) {
            game_exit = false;

            cout << "ㄟ计秖:"; cin >> input;
            if (input < 1) return 0;
            for (int i = 0; i < input; i++) {
                //save_fd =
                fd.push_back(new rabbit("ㄟ " + to_string(i), 100));
            }

            cout << "疩纓计秖:"; cin >> input;
            if (input < 1) return 0;
            for (int i = 0; i < input; i++) {
                fd.push_back(new tortoise("疩纓 " + to_string(i), 80));
            }

            cout << "ρ公计秖:"; cin >> input;
            if (input < 1) return 0;
            for (int i = 0; i < input; i++) {
                fd.push_back(new Mice("ρ公 " + to_string(i), 80));
            }

            cout << " 计秖:"; cin >> input;
            if (input < 1) return 0;
            for (int i = 0; i < input; i++) {
                fd.push_back(new People(" " + to_string(i), 80));
            }

            save_fd = NULL;
            while (!game_exit) {
                system("cls");
                for (vector<FOOD*>::iterator it = fd.begin(); it != fd.end(); it++) {
                    if ((*it)->ear()) {
                        game_exit = true;
                        save_fd = *it;
                    }
                    (*it)->skill(fd);
                    (*it)->show_info();
                    (*it)->show_static();
                }
                Sleep(3000);
                //system("pause");
            }

            if (save_fd != NULL) cout << endl << (save_fd->getName()) << "\n";
            for (vector<FOOD*>::iterator it = fd.begin(); it != fd.end(); it++) {
                delete* it;
            }
            fd.clear();
            system("pause");
            system("cls");
        }
    }
    //system("pause");
    return 0;
}