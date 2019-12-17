#pragma once
#ifndef _GOODS_H_
#define _GOODS_H_

#include <iostream>

#include <vector>
#include <Windows.h>
#include <algorithm>
#include "../../../../include/Tool/Tool.h"
#include "../../Attributes.h"
#include <cassert>
#include "../../../Type.h"
#include "../Restricted.h"
#include "Sub_Goods.h"
#include <conio.h>

using namespace std;

class Goods : public Attributes, public Restricted, public Sub_Goods {
private:
    int LV;
public:
    Goods(string _name, int _lv, int _Quantity = 1);
    virtual ~Goods();

    int getLV();

    virtual void show_info();
    virtual bool isUse();
};

#endif // !
