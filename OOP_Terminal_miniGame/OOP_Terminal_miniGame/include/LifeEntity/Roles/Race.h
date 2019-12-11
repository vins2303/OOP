#ifndef _RACE_H_
#define _RACE_H_

#include <algorithm>
#include <string>
#include "../../Type.h"
using std::string;

class Race {
private:
    RaceType raceType;

public:
    Race(RaceType _type);

    string getRaceType_S();
    RaceType getRaceType();

    void setRace(RaceType _race);
    void setRace(string _race);
};

#endif // !_RACE_H_
