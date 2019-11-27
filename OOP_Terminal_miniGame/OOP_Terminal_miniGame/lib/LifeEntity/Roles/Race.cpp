#include "../../../include/LifeEntity/Roles/Race.h"

Race::Race(RaceType _type):raceType(_type)

{}

Race::RaceType Race::StringToRaceType(string _race) {
    transform(_race.begin(), _race.end(), _race.begin(), tolower);
    if (_race == "human")
        return RaceType::Human;
    if (_race == "orc")
        return RaceType::Orc;
    if (_race == "elves")
        return RaceType::Elves;
    if (_race == "dwart")
        return RaceType::Dwarf;

    return RaceType::Human;
}

string Race::RaceTypeToString(Race::RaceType _type) {
    string outType = "";
    switch (_type) {
    case RaceType::Dwarf:
        outType = "Dwarf";
        break;
    case RaceType::Elves:
        outType = "Elves";
        break;
    case RaceType::Human:
        outType = "Human";
        break;
    case RaceType::Orc:
        outType = "Orc";
        break;
    }
    return outType;
}

Race::RaceType Race::getRace() { return raceType; }

void Race::setRace(RaceType _race) { raceType = _race; }
void Race::setRace(string _race) { setRace(StringToRaceType(_race)); }