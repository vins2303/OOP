#include "../../include/LifeEntity/Attributes_range.h"

Attributes_range::Attributes_range(int _top, int _buff) :
	Max(_top), Now(_top)
{}

Attributes_range::~Attributes_range() {

}

int Attributes_range::getMax() { return Max; }
int Attributes_range::getNow() { return Now; }
int Attributes_range::setMax(int _set) { return this->Max = _set; }
int Attributes_range::setNow(int _set) { return this->Now = _set; }