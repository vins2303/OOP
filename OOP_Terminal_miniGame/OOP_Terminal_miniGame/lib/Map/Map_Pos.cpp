#include "../../include/Map/Map_Pos.h"

Map_Pos::Map_Pos(string _Map_Name) :
    Map_Name(_Map_Name),
    X(Get_Map_Pos_ini(_Map_Name, "X")),
    Y(Get_Map_Pos_ini(_Map_Name, "Y")),
    LV(Get_Map_Pos_ini(_Map_Name, "LV")),
    ShowLV(Get_Map_Pos_ini(_Map_Name, "ShowLV")),
    E(Get_Map_Pos_ini(_Map_Name, "E")),
    W(Get_Map_Pos_ini(_Map_Name, "W")),
    S(Get_Map_Pos_ini(_Map_Name, "S")),
    N(Get_Map_Pos_ini(_Map_Name, "N"))
{}

void Map_Pos::Show_Map_Pos(int f) {
    static string out_str;
    Draw::SetColor(f);
    {
        Draw::setXY(MAP_POS_WIDTH_ADD(X), MAP_POS_HEIGH_ADD(Y));
        cout << "¢z";
        for (int i = 0; i < MAP_POS_WIDTH - 1; i++)
            cout << "¢w";
        cout << "¢{";

        Draw::setXY(MAP_POS_WIDTH_ADD(X), MAP_POS_HEIGH_ADD(Y) - 1 + MAP_POS_HEIGH);
        cout << "¢|";
        for (int i = 0; i < MAP_POS_WIDTH - 1; i++)
            cout << "¢w";
        cout << "¢}";

        for (int i = 1; i < MAP_POS_HEIGH - 1; i++) {
            Draw::setXY(MAP_POS_WIDTH_ADD(X), MAP_POS_HEIGH_ADD(Y) + i);
            cout << "¢x";
            Draw::setXY(MAP_POS_WIDTH_ADD(X) + MAP_POS_WIDTH, MAP_POS_HEIGH_ADD(Y) + i);
            cout << "¢x";
        }
    }

    {
        if (ShowLV) {
            out_str = "©Çª«µ¥¯Å:" + to_string(LV);
            Draw::setXY(MAP_POS_WIDTH_ADD(X) + (MAP_POS_WIDTH - (int)out_str.length()) / 2 + 1, MAP_POS_HEIGH_ADD(Y) + 1);
            cout << out_str;
        }

        Draw::setXY(MAP_POS_WIDTH_ADD(X) + (MAP_POS_WIDTH - (int)Map_Name.length()) / 2 + 1, MAP_POS_HEIGH_ADD(Y) + 2);
        cout << Map_Name;
    }

    Draw::SetColor();

    {
        if (E) {
            Draw::setXY(MAP_POS_WIDTH_ADD(X) + MAP_POS_WIDTH + 1, MAP_POS_HEIGH_ADD(Y) + MAP_POS_HEIGH / 2);
            for (int i = 0; i < MAP_POS_WIDTH_SPACE / 2; i++)cout << "¢w";
        }
        if (W) {
            Draw::setXY(MAP_POS_WIDTH_ADD(X) - MAP_POS_WIDTH / 2, MAP_POS_HEIGH_ADD(Y) + MAP_POS_HEIGH / 2);
            for (int i = 0; i < MAP_POS_WIDTH_SPACE / 2; i++)cout << "¢w";
        }

        if (S) {
            for (int i = 0; i < MAP_POS_HEIGH / 2; i++) {
                Draw::setXY(MAP_POS_WIDTH_ADD(X) + MAP_POS_WIDTH / 2, MAP_POS_HEIGH_ADD(Y) + MAP_POS_HEIGH + i);
                cout << "¢x";
            }
        }

        if (N) {
            for (int i = 0; i < MAP_POS_HEIGH / 2; i++) {
                Draw::setXY(MAP_POS_WIDTH_ADD(X) + MAP_POS_WIDTH / 2, MAP_POS_HEIGH_ADD(Y) - i - 1);
                cout << "¢x";
            }
        }
    }
    Draw::setXY(0, 40);
}