#include "../../../../include/LifeEntity/Roles/Skill/Skill.h"

Skill::Skill(string _name, int _lv) :
    Name(_name),
    LV(_lv),
    Help(Tool::ReadStringIni(_name, "Help", "NULL", Read_SKILL_INI_PATH)),
    Cooling_Time(Read_SKILL_int_ini(_name, "Cooling_Time")),
    Duration(Read_SKILL_int_ini(_name, "Duration")),
    Consume_MP(Read_SKILL_int_ini(_name, "Consume_MP")),
    Now_Cooling_Time(0),
    Attributes(
        Read_SKILL_int_ini(_name, "HP"),
        Read_SKILL_int_ini(_name, "MP"),
        Read_SKILL_int_ini(_name, "Attack"),
        Read_SKILL_int_ini(_name, "SP"),
        Read_SKILL_int_ini(_name, "DEF"),
        Read_SKILL_int_ini(_name, "CRT"),
        Read_SKILL_int_ini(_name, "Drop")
    ),
    Restricted(
        toRoleType_List(Tool::SplitString(Tool::ReadStringIni(_name, "Role", "NULL", Read_SKILL_INI_PATH), " ")),
        toRaceType_List(Tool::SplitString(Tool::ReadStringIni(_name, "Race", "NULL", Read_SKILL_INI_PATH), " "))
    )
{
}

Skill::~Skill()
{
}

bool Skill::operator==(const Skill& skill) { return Name == skill.Name; }

int Skill::getLV()
{
    return LV;
}

int Skill::Up_LV(int num) { return LV += num; }

string Skill::getName() { return Name; }

int Skill::getCooling_Time() { return Cooling_Time; }

int Skill::get_Now_Cooling_Time() { return Now_Cooling_Time; }

int Skill::get_Consume_MP() { return Consume_MP; }

int Skill::get_Duration() { return Duration; }

void Skill::setDuration(int num) { Duration = num; }

void Skill::show_info(int _now) {
    cout << "技能：" << Name << "\t等級" << LV << (_now ? "" : "\t冷卻時間：" + (_now ? Now_Cooling_Time : Duration)) << " ";
    if (Duration != 1) cout << "\t持續時間：" << Cooling_Time << " ";
    if (getHP() != 0) cout << "\t增加生命：" << getHP() << " ";
    if (getMP() != 0) cout << "\t增加魔力：" << getMP() << " ";
    if (getAttack() != 0) cout << "\t增加攻擊力：" << getAttack() << " ";

    if (getSP() != 0) cout << "\t增加速度：" << getSP() << " ";
    if (getDef() != 0) cout << "\t增加減商：" << getDef() << "% ";
    if (getCRT() != 0) cout << "\t增加暴擊：" << getCRT() << "% ";
    cout << "\t技能說明：" << Help;
    cout << endl;
}

void Skill::Casting_Skills()
{
    Now_Cooling_Time = Cooling_Time;
}

int Skill::Round_End_US_Skill() {
    return --Duration;
}

int Skill::Round_End_Restore()
{
    if (Now_Cooling_Time > 0) Now_Cooling_Time--;
    return Now_Cooling_Time;
}

int Skill::getHP() { return LV_Magnification(Attributes::getHP()); }

int Skill::getMP() { return LV_Magnification(Attributes::getMP()); }

int Skill::getAttack() { return LV_Magnification(Attributes::getAttack()); }

int Skill::getSP() { return LV_Magnification(Attributes::getSP()); }

int Skill::getDef() { return LV_Magnification(Attributes::getDef()); }

int Skill::getCRT() { return LV_Magnification(Attributes::getCRT()); }

int Skill::getDrop() { return LV_Magnification(Attributes::getDrop()); }