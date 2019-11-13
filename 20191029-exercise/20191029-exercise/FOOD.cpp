#include "FOOD.h"
FOOD::FOOD(string _name, int MAXLESSFOOD) 
:Remaining(1000), maxlessfood(rand() % MAXLESSFOOD + 1), name(_name) {};

string FOOD::getName() { return name; }

bool FOOD::ear() {
	Remaining -= rand() % maxlessfood + 1;
	Remaining = Remaining < 0 ? 0 : Remaining;
	return Remaining == 0 ? true : false;
}

void FOOD::show_info() {
	cout << "Player Info: (" << name << ", " << maxlessfood << ")" << endl;
}

void FOOD::show_static() {
	cout << Remaining << ":\t|";
	for (int i = 0; i < 20; i++) 
		cout << (i < Remaining * 0.02 ? "#" : " ");
	cout << "|" << endl;

}