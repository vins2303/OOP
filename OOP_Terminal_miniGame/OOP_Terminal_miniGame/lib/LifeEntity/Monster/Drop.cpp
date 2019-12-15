#include "../../../include/LifeEntity/Monster/Drop.h"

Drop::Drop(string _name, int _chance, int _max) :
    Name(_name),
    Chance(_chance),
    MAX(_max)
{}

Drop::~Drop() { }

string Drop::getName() { return Name; }

int Drop::getChance() { return Chance; }

void Drop::show_info() {
    cout << Name << "\t" << Chance << "%";
}

bool Drop::isDrop(int _addChance) { return (rand() % 100) < (Chance + _addChance); }

int Drop::Drop_Number() { return rand() % MAX + 1; }