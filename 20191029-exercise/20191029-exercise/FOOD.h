#ifndef FOOD_H
#define FOOD_H
#include<iostream>
#include<string>
using namespace std;

class FOOD {
private:
	int maxlessfood;
	int Remaining;
	string name;
public:
	FOOD(string _name, int MAXLESSFOOD);
	string getName();
	bool ear();
	void show_info();
	void show_static();
};
#endif
