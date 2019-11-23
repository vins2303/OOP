#ifndef _EQUIPMENT_H_
#define _EQUIPMENT_H_

class Equipment {
    Attributes* weapon;//武器
    Attributes* deputy;//副手
    Attributes* helmet;//頭盔
    Attributes* breastplate;//胸甲
    Attributes* pants;//褲子
    Attributes* shoes;//鞋子

    Equipment(Attributes* _weapon = NULL,
              Attributes* _deputy = NULL,
              Attributes* _helmet = NULL,
              Attributes* _breastplate = NULL,
              Attributes* _pants = NULL,
              Attributes* _shoes = NULL):
                
              weapon(_weapon),
              deputy(_deputy),
              helmet(_helmet),
              breastplate(_breastplate),
              pants(_pants),
              shoes(_shoes);
    {}


};

#endif