#ifndef MAP_OBHECT_H
#define MAP_OBHECT_H

enum M_object {
	null,    //�L
	Warrior, //�H
	Houst,   //�Фl
	Wall,    //���
	Portal   //�ǰe��
};

class Map_object {
private:
	M_object object;

public:
	Map_object(M_object _object = M_object::null);

	M_object getObject();

	Map_object setObject(M_object _M);
};

#endif