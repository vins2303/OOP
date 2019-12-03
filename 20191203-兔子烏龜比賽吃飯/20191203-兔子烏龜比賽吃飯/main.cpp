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
    rabbit(string _name, int MAXLESSFOOD):FOOD(_name, MAXLESSFOOD)
    
    {}
    void skill() {
        if (getCskill() == 0) {
            if (rand() % 10 < 3) {
                setCskill(rand()%5+1);
            }
        }
    }

    bool ear() {
        if (getCskill() != 0) {
            setCskill(getCskill()-1);
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
    tortoise(string _name, int MAXLESSFOOD):FOOD(_name, MAXLESSFOOD) {}

    void skill() {
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


int main() {
    srand(time(NULL));
    while (1) {
        //CNameGenerator namegenerator("..\\fanily.txt", "..\\firstname.txt");
        vector<FOOD*> fd;
        FOOD* save_fd;
        bool game_exit;
        //CNameGenerator *n = new 
        int input;
        while (true) {
            game_exit = false;


            cout << "兔子數量:"; cin >> input;
            if (input < 1) return 0;
            for (int i = 0; i < input; i++) {
                //save_fd = 
                fd.push_back(new rabbit("兔子"+to_string(i), 100));
            }

            cout << "烏龜數量:"; cin >> input;
            if (input < 1) return 0;
            for (int i = 0; i < input; i++) {

                fd.push_back(new tortoise("烏龜"+to_string(i), 80));
            }


            save_fd = NULL;
            while (!game_exit) {
                system("cls");
                for (vector<FOOD*>::iterator it = fd.begin(); it != fd.end(); it++) {
                    if ((*it)->ear()) {
                        game_exit = true;
                        save_fd = *it;
                    }
                    (*it)->skill();
                    (*it)->show_info();
                    (*it)->show_static();
                }
                Sleep(500);
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