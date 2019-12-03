#ifndef FOOD_H
#define FOOD_H
#include<iostream>
#include<string>
using namespace std;

class FOOD {
public:
    int maxlessfood;
    int Remaining;
    string name;
    int Cskill;
    int buff=0;
public:
    FOOD(string _name, int MAXLESSFOOD);
    string getName();
    virtual bool ear();
    virtual void skill();
    void show_info();
    void show_static();
    int getCskill();
    void setCskill(int _num);
};
#endif
