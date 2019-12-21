#ifndef _EQUIPMENT_ATTRIBUTES_H_
#define _EQUIPMENT_ATTRIBUTES_H_

#include "../../Attributes.h"
#include "../../../Type.h"
#include "../Back_Pack/Goods.h"
//#include "../Roles.h"
#include <vector>
#include <Windows.h>
#include <algorithm>

using namespace std;

class Equipment_Attributes : public Goods {
private:

public:

    Equipment_Attributes(Account& user_account, string _name, int _lv = 1);
    virtual ~Equipment_Attributes();

    virtual void show_info();
    virtual bool isUse();

    int getHP();
    int getMP();
    int getAttack();
    int getSP();
    int getDef();
    int getCRT();
    int getDrop();
};

#endif // !_EQUIPMENT_ATTRIBUTES_H_
