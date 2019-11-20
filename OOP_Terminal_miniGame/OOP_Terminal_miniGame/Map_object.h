#ifndef MAP_OBHECT_H
#define MAP_OBHECT_H

enum objectType {
	null,    //無
	Warrior, //人
	Houst,   //房子
	Wall,    //牆壁
	Portal,  //傳送門
	Monster  //怪物
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