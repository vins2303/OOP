#ifndef _CONSUMABLES_H_
#define _CONSUMABLES_H_

#include "Goods.h"
#include "../../LifeAttributes.h"

class Consumables :public Goods {
private:
    int Duration;
public:
    Consumables(string _name, Back_Pack_Type _type, int _Quantity = 1, int _Duration = 0);
    virtual ~Consumables();
    virtual void show_info();
    virtual bool isUse();

    void Use(LifeAttributes& _life);
};
#endif