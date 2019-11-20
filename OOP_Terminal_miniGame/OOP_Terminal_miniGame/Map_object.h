#ifndef MAP_OBHECT_H
#define MAP_OBHECT_H

enum objectType {
	null,    //�L
	Warrior, //�H
	Houst,   //�Фl
	Wall,    //���
	Portal,  //�ǰe��
	Monster  //�Ǫ�
};

class Map_object {
private:
	objectType object;
	int X, Y, width, heigh;

public:
	Map_object(objectType _object = objectType::null);

	objectType getObject();

	Map_object setObject(objectType _M);
};

#endif