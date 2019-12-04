#ifndef _MAP_POS_H
#define _MAP_POS_H

#include <Windows.h>
#include<string>
#include "Draw.h"
using namespace std;

#define MAP_POS_WIDTH 20
#define MAP_POS_HEIGH 5
#define MAP_POS_WIDTH_SPACE 20
#define MAP_POS_HEIGH_SPACE 4

#define MAP_POS_WIDTH_ADD(x) ( x * ( MAP_POS_WIDTH + MAP_POS_WIDTH_SPACE ) )
#define MAP_POS_HEIGH_ADD(y) ( y * ( MAP_POS_HEIGH + MAP_POS_HEIGH_SPACE ) )
#define Get_Map_Pos_ini(_Map_Name, num) GetPrivateProfileInt(_Map_Name.c_str(), num, INT_MAX, "Data/Map/Map_Pos.ini")

class Map_Pos {
private:
    string Map_Name;
    unsigned int X, Y, LV;
    bool E, W, S, N, ShowLV;
public:
    Map_Pos(string _Map_Name);

    //¶Â¡@ÂÅ¡@ºñ¡@«C¡@¬õ¡@µµ¡@¶À¡@¥Õ
    //¢¯¡@¢°¡@¢±¡@¢²¡@¢³¡@¢´¡@¢µ¡@¢¶
    void Show_Map_Pos(int f);
};
#endif