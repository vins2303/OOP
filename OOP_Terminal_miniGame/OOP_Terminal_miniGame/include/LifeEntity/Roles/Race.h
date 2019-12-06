#ifndef _RACE_H_
#define _RACE_H_

#include <algorithm>
#include <string>
using std::string;

enum class RaceType : int {
    �H��,//�H��
    �~�H,  //�~�H
    ���F,//���F
    �G�H //�G�H
};

RaceType StringToRaceType(string _race);
string RaceTypeToString(RaceType _race);

class Race {
private:
    RaceType raceType;

public:
    Race(RaceType _type);

    RaceType getRace();
    string getRaceType();

    void setRace(RaceType _race);
    void setRace(string _race);
};

#endif // !_RACE_H_
