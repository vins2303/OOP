#ifndef  ATTRIBUTES_CPP
#define  ATTRIBUTES_CPP
#include<iostream>
#include "Attributes.h"
using namespace std;

#define AttributesMaxLV 100

class Attributes {
private:
    int HP;
    int MP;
    int Attack;

    int SP;
    int Def;
    int CRT;//√z¿ª≤v

public:
    Attributes(int _HP, int _MP, int _attack, int _sp, int _def, int _CRT);
    ~Attributes();

    int getHP();
    int getMP();
    int getAttack();
    int getSP();
    int getDef();
    int getCRT();

    int setHP(int);
    int setMP(int);
    int setAttack(int);
    int setSP(int);
    int setDef(int);
    int setCrt(int);

    int addHP(int, bool = false, bool = true);
    int addMP(int, bool = false, bool = true);
    int addAttack(int, bool = false, bool = true);
    int addSP(int, bool = false, bool = true);
    int addDef(int, bool = false, bool = true);
    int addCrt(int);

    int ADD_FUN(int _now, int _add, bool percent = false, bool setZero = true);
};
#endif