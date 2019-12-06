#include "../../../include/LifeEntity/Roles/Race.h"

Race::Race(RaceType _type) :raceType(_type)
{}

RaceType StringToRaceType(string _race) {
    //transform(_race.begin(), _race.end(), _race.begin(), tolower);
    if (_race == "人族")
        return RaceType::人族;
    if (_race == "矮人")
        return RaceType::矮人;
    if (_race == "精靈")
        return RaceType::精靈;
    if (_race == "獸人")
        return RaceType::獸人;
    return RaceType::人族;
}

string RaceTypeToString(RaceType _type) {
    string outType = "";
    switch (_type) {
    case RaceType::人族:
        outType = "人族";
        break;
    case RaceType::矮人:
        outType = "矮人";
        break;
    case RaceType::精靈:
        outType = "精靈";
        break;
    case RaceType::獸人:
        outType = "獸人";
        break;
    }
    return outType;
}
string Race::getRaceType() { return RaceTypeToString(raceType); }

RaceType Race::getRace() { return raceType; }
void Race::setRace(RaceType _race) { raceType = _race; }
void Race::setRace(string _race) { setRace(StringToRaceType(_race)); }