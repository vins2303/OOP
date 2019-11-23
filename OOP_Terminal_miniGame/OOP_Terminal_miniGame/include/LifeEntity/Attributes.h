#ifndef  ATTRIBUTES_CPP
#define  ATTRIBUTES_CPP
#include<iostream>
#include "Attributes_range.h"
using namespace std;

#define AttributesMaxLV 100

class Attributes {
private:
    Attributes_range* HP;
    Attributes_range* MP;
    int Attack;
    int LV;
    int SP;

public:
    Attributes(int _LV, Attributes_range* _HP, Attributes_range* _MP, int _attack, int _sp);
    ~Attributes();

    int getHP();
    int getMP();
    int getAttack();
    int getMaxHP();
    int getMaxMP();
    int getLV();
    int getSP();

    int setHP(int);
    int setMP(int);
    int setAttack(int);
    int setMaxHP(int);
    int setMaxMP(int);
    int setLV(int);
    int setSP(int);

    int addHP(int, bool = false, bool = true);
    int addMP(int, bool = false, bool = true);
    int addAttack(int, bool = false, bool = true);
    int addMaxHP(int, bool = false, bool = true);
    int addMaxMP(int, bool = false, bool = true);
    int addLV(int, bool = false, bool = true);
    int addSP(int, bool = false, bool = true);

private:
    int ADD_FUN(int _now, int _add, bool percent = false, bool setZero = true);

};
#endif