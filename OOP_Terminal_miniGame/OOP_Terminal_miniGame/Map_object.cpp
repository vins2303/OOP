#include "Map_object.h"

Map_object::Map_object(objectType _object):object(_object) {

}

objectType Map_object::getObject() {
	return object;
}

Map_object Map_object::setObject(objectType _M) {
	object = _M;
	return *this;
}