#ifndef _DROP_H_
#define _DROP_H_

#include "../Roles/Back_Pack/Goods.h"

class Drop {
private:
    string Name;
    int Chance;
    int MAX;
public:
    Drop(string _name, int _chance, int _max);
    ~Drop();

    string getName();
    int getChance();
    void show_info();
    bool isDrop(int _addChance = 0);
    int Drop_Number();
};

#endif // !
