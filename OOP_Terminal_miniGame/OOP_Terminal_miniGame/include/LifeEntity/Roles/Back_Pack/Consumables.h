#ifndef _CONSUMABLES_H_
#define _CONSUMABLES_H_

#include "Goods.h"
#include "../../LifeAttributes.h"

class Consumables :public Goods {
private:
    int Duration;
public:
    Account& user_account;
    Consumables(Account& user_account, string _name, int _Quantity = 1, int _Duration = 0);
    virtual ~Consumables();
    virtual void show_info();
    virtual bool isUse();

    void Use(LifeAttributes& _life);
};
#endif