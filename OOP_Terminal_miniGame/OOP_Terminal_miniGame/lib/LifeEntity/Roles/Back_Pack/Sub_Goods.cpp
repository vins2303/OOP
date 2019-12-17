#include "../../../../include/LifeEntity/Roles/Back_Pack/Sub_Goods.h"

Sub_Goods::Sub_Goods(string _name, int _Quantity) :
    Weight(Read_Equipment_Attributes_int_ini(_name, "Weight")),
    name(_name),
    type(toBack_Pack_Type(Tool::ReadStringIni(_name, "TYPE", "NULL", Read_Back_Pack_PATH))),
    Quantity(_Quantity),
    Money(Read_Equipment_Attributes_int_ini(_name, "Money"))

{
}

Sub_Goods::~Sub_Goods()
{
}

bool Sub_Goods::operator==(const Sub_Goods& _god) const
{
    return name == _god.name;
}

void Sub_Goods::show_info() { assert(false); }

bool Sub_Goods::isUse() { assert(false);  return false; }

int Sub_Goods::getWight() { return Quantity * Weight; }
int Sub_Goods::getWight_one() { return Weight; }

string Sub_Goods::getType_S() { return toString(type); }

Back_Pack_Type& Sub_Goods::getType() { return type; }

string Sub_Goods::getName() { return name; }

int Sub_Goods::getMoney() { return Money; }

int Sub_Goods::getQuantity() { return Quantity; }

void Sub_Goods::setQuantity(int _num) {
    if (_num >= 0) Quantity = _num;
    else {
        assert(false);
    }
}

void Sub_Goods::addQuantity(int _num) { Quantity += _num; }