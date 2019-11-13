#include "CNameGenerator.h"

CNameGenerator::CNameGenerator(string family_path, string first_path) {
	ifstream family_read(family_path);
	ifstream first_read(first_path);
	string str;
	while (!family_read.eof()) {
		family_read >> str;
		family.push_back(str);
	}
	while (!first_read.eof()) {
		first_read >> str;
		first.push_back(str);
	}
	family_read.close();
	first_read.close();
}

string CNameGenerator::getName() {
	string outname;
	int a, b;
	do {
		outname = family[rand() % family.size()];
		if (rand() % 2) {
			do {
				a = rand() % first.size();
				b = rand() % first.size();
			} while (a == b);
			outname = outname + first[a] + first[b];
		}
		else {
			outname = outname + first[rand() % first.size()];
		}
	} while (find(used.begin(), used.end(), outname) != used.end());
	used.push_back(outname);
	return outname;
}

void CNameGenerator::resetName() {
	used.clear();
}

int CNameGenerator::getMaxSize() { return family.size() * first.size() * first.size(); }