#ifndef  ATTRIBUTES_CPP
#define  ATTRIBUTES_CPP
#include<iostream>
#include "Attributes_range.h"
using namespace std;

#define AttributesMaxLV 100

class Attributes {
private:
    int HP;
    int MP;
    int Attack;
    int LV;
    int SP;
    int Def;

public:
    Attributes(int _LV, int _HP, int _MP, int _attack, int _sp, int _def);
    ~Attributes();

    int getHP();
    int getMP();
    int getAttack();
    int getLV();
    int getSP();
    int getDef();

    int setHP(int);
    int setMP(int);
    int setAttack(int);
    int setLV(int);
    int setSP(int);
    int setDef(int);

    int addHP(int, bool = false, bool = true);
    int addMP(int, bool = false, bool = true);
    int addAttack(int, bool = false, bool = true);
    int addLV(int, bool = false, bool = true);
    int addSP(int, bool = false, bool = true);
    int addDef(int, bool = false, bool = true);

    int ADD_FUN(int _now, int _add, bool percent = false, bool setZero = true);

};
#endif