#ifndef _EQUIPMENT_H_
#define _EQUIPMENT_H_

class Equipment {
    Attributes* weapon;//�Z��
    Attributes* deputy;//�Ƥ�
    Attributes* helmet;//�Y��
    Attributes* breastplate;//�ݥ�
    Attributes* pants;//�Ǥl
    Attributes* shoes;//�c�l

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