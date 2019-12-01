#ifndef _RACE_H_
#define _RACE_H_

#include <algorithm>
#include <string>
using std::string;

class Race {
public:
    enum class RaceType : int {
        �H��,//�H��
        �~�H,  //�~�H
        ���F,//���F
        �G�H //�G�H
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
