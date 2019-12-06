#include "../../../include/LifeEntity/Roles/Race.h"

Race::Race(RaceType _type) :raceType(_type)
{}

RaceType StringToRaceType(string _race) {
    //transform(_race.begin(), _race.end(), _race.begin(), tolower);
    if (_race == "�H��")
        return RaceType::�H��;
    if (_race == "�G�H")
        return RaceType::�G�H;
    if (_race == "���F")
        return RaceType::���F;
    if (_race == "�~�H")
        return RaceType::�~�H;
    return RaceType::�H��;
}

string RaceTypeToString(RaceType _type) {
    string outType = "";
    switch (_type) {
    case RaceType::�H��:
        outType = "�H��";
        break;
    case RaceType::�G�H:
        outType = "�G�H";
        break;
    case RaceType::���F:
        outType = "���F";
        break;
    case RaceType::�~�H:
        outType = "�~�H";
        break;
    }
    return outType;
}
string Race::getRaceType() { return RaceTypeToString(raceType); }

RaceType Race::getRace() { return raceType; }
void Race::setRace(RaceType _race) { raceType = _race; }
void Race::setRace(string _race) { setRace(StringToRaceType(_race)); }