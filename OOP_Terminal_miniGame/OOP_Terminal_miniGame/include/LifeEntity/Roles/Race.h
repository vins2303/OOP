#ifndef _RACE_H_
#define _RACE_H_

#include <algorithm>
#include <string>
using std::string;

class Race {
public:
    enum class RaceType : int {
        Human,//人族
        Orc,  //獸人
        Elves,//精靈
        Dwarf //矮人
    };

private:
    RaceType raceType;

public:
    Race(RaceType _type);
    static RaceType StringToRaceType(string _race);
    static string RaceTypeToString(RaceType _race);

    RaceType getRace();

    void setRace(RaceType _race);
    void setRace(string _race);
};

#endif // !_RACE_H_
