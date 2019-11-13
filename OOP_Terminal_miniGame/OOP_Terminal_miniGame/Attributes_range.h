#ifndef ATTRIBUTES_RANGE_H
#define ATTRIBUTES_RANGE_H

#include<vector>

class Attributes_range {
private :
	int top;
	int now;
public:
	Attributes_range(int _top, int _buff = 0);
	int getTop();
	int getNow();
	//int getbuff();
	void setTop(int set = 0);
	void setNow(int set = 0);
};

#endif


