#ifndef FOOT_COLOR
#define FOOT_COLOR

#include "Attributes.h"
#include <string>
#include <math.h>
#include <Windows.h>
#include "../Map/Map_object.h"
#include "Equipment.h"
using std::string;
class FoorColor : public  Attributes , public Equipment{
private:
    int id;
    string name;
    int exp; // (LV-1)^3 + 60
    Map_object *object;//¸}¦âª«¥ó
    int maxHP;
    int maxMP;
public:
    FoorColor(int _id, string _name, int _exp, int _maxHP, int _maxMP, Attributes& _attributes, Equipment& _Equipment);

    ~FoorColor();

    int getID();
    string getName();
    int getExp();
    int getUpExp();
    int getMaxHP();
    int getMaxMP();


    int setID(int _id);
    string setName(string _name);
    int setExp(int _exp);
    int setHP(int _num);
    int setMP(int _num);
    int setMaxHP(int _num);
    int setMaxMP(int _num);

    int addExp(int _exp, bool percent = false);
    int addHP(int _hp, bool percent = false);
    int addMP(int _mp, bool percent = false);
    int addMaxHP(int _maxhp, bool percent = false);
    int addMaxMP(int _maxmp, bool percent = false);

    bool isUpLv();
};

#endif