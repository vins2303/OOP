#ifndef ATTRIBUTES_RANGE_H
#define ATTRIBUTES_RANGE_H

#include<vector>

class Attributes_range {
private:
	int Max;
	int Now;
public:
    Attributes_range(int _now, int _max);
	~Attributes_range();

	int setMax(int _num);
	int setNow(int _num);

	int getMax();
	int getNow();
};

#endif


