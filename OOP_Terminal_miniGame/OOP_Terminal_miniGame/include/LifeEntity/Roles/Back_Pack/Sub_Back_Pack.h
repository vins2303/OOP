#ifndef _SUB_BACK_PACK_H
#define _SUB_BACK_PACK_H

#include "Sub_Goods.h"
#include <fstream>
#include "../Equipment/Equipment_Attributes.h"
#include "Consumables.h"
#include "../Restricted.h"
#include "../Equipment/Equipment.h"

#define SHOW_MAX_WEITH 20
#define SHOW_WEITH_FIGURE(_num) ((_num) ? "▉": "　")
#define SHOW_WEITH_FRAME_BEGIN "|";
#define SHOW_WEITH_FRAME_END   "|";

class Sub_Back_Pack :public Sub_Goods {
private:
    string user_Account;
    string user_Name;
    int Back_ID;
    vector<Sub_Goods*> goods;
    Back_Pack_Szie type;
public:
    Sub_Back_Pack(string _account, string _user_name, int ID, Back_Pack_Szie _size_type = Back_Pack_Szie::Back_Pack_Min);
    virtual ~Sub_Back_Pack();
    virtual void show_info();
    virtual bool isUse();
    int getNowWeith();
    int getMaxWeith();
    void Read_BackPack();
    void Save_BackPack();
    void Open_Sub_Back_Pack(Sub_Back_Pack& _bgds);
    int getID();
    void addGoods(Sub_Goods* _g);
    void RmGoods(int n);
    void ShowWeith(int _max = 0, bool show = true, bool LF = true);
    Back_Pack_Szie getBack_Pack_Szie_Type();
    void setBack_Pack_Szie_Type(Back_Pack_Szie _type);
    Sub_Goods* findGoods(string _name);
    vector<Sub_Goods*>& getBackPack_Goods();

    /*          將物品丟到子背包           */
    bool Put_To_Sub_Back_Pack(Sub_Goods*& _gds);
private:
    //void Sub_Back_Pack_User_Item(Sub_Goods*& _gds);
};

#endif // !_SUB_BACK_PACK_H
