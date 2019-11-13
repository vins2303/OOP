#ifndef CNNAMEGENERATOR_H
#define CNNAMEGENERATOR_H

#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<algorithm>
using namespace std;
class CNameGenerator {
private:
	vector<string> family;
	vector<string> first;
	vector<string> used;

public:
	CNameGenerator(string, string);
	string getName();
	int getMaxSize();
	void resetName();
};
#endif
