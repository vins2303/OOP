#ifndef  ATTRIBUTES_CPP
#define  ATTRIBUTES_CPP
#include<iostream>
#include "Attributes.h"
using namespace std;

#define LV_Magnification( num )  (int)((double)(num) + (double)(num)  * (double)((double)getLV() - 1.0) * 0.5  )
#define AttributesMaxLV 100

class Attributes {
private:
    int HP;
    int MP;
    int Attack;

    int SP;
    int Def;
    int CRT;//ÃzÀ»²v
    int DROP;//½ÕÄ_²v
public:
    Attributes(int _HP, int _MP, int _attack, int _sp, int _def, int _CRT, int _drop);
    virtual ~Attributes();

    int getHP();
    int getMP();
    int getAttack();
    int getSP();
    int getDef();
    int getCRT();
    int getDrop();

    int setHP(int);
    int setMP(int);
    int setAttack(int);
    int setSP(int);
    int setDef(int);
    int setCrt(int);
    int setDrop(int _drop);

    int addHP(int, bool = false, bool = true);
    int addMP(int, bool = false, bool = true);
    int addAttack(int, bool = false, bool = true);
    int addSP(int, bool = false, bool = true);
    int addDef(int, bool = false, bool = true);
    int addCrt(int);

    //void showHP(bool show, bool LF);

    int ADD_FUN(int _now, int _add, bool percent = false, bool setZero = true);
};
#endif