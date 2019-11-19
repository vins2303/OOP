#include "Map_object.h"

Map_object::Map_object(M_object _object):object(_object) {

}

M_object Map_object::getObject() {
	return object;
}

Map_object Map_object::setObject(M_object _M) {
	object = _M;
	return *this;
}