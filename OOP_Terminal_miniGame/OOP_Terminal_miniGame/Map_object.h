#ifndef MAP_OBHECT_H
#define MAP_OBHECT_H

enum M_object {
	null,    //無
	Warrior, //人
	Houst,   //房子
	Wall,    //牆壁
	Portal   //傳送門
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