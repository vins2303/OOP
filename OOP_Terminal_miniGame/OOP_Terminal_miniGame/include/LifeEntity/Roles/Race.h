#ifndef _RACE_H_
#define _RACE_H_

#include <algorithm>
#include <string>
using std::string;

class Race {
public:
    enum class RaceType : int {
        人族,//人族
        獸人,  //獸人
        精靈,//精靈
        矮人 //矮人
    };

private:
    RaceType raceType;

public:
    Race(RaceType _type);
    
    RaceType getRace();
    string getRaceType();
    
    static RaceType StringToRaceType(string _race);
    static string RaceTypeToString(RaceType _race);


    void setRace(RaceType _race);
    void setRace(string _race);
};

#endif // !_RACE_H_
