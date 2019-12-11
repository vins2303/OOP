#include "../../../include/LifeEntity/Roles/Race.h"

Race::Race(RaceType _type) :raceType(_type)
{}

string Race::getRaceType_S() { return toString(raceType); }

RaceType Race::getRaceType() { return raceType; }
void Race::setRace(RaceType _race) { raceType = _race; }
void Race::setRace(string _race) { setRace(toRace_Type(_race)); }