#include "Attributes_range.h"

int Attributes_range::getTop() { return top; }
int Attributes_range::getNow() { return now; }
void Attributes_range::setTop(int _set) { this->top = _set; }
void Attributes_range::setNow(int _set) { this->now = _set; }

Attributes_range::Attributes_range(int _top, int _buff):
top(_top), now(_top)
{}