#ifndef FOOT_COLOR
#define FOOT_COLOR

#include "Attributes.h"
#include <string>
#include <math.h>
#include <Windows.h>
#include "../Map/Map_object.h"
using std::string;
class FoorColor : public  Attributes{
private:
    int id;
    string name;
    int exp; // (LV-1)^3 + 60
    Map_object *object;//¸}¦âª«¥ó
public:
    FoorColor(int _id, string _name, int _exp, int _LV, Attributes_range* _HP, Attributes_range* _MP, int _attack, int _sp);


    int getID();
    string getName();
    int getExp();
    int UpExp();

    int setID(int _id);
    string setName(string _name);
    int setExp(int _exp);

    int addExp(int _exp);
};

#endif