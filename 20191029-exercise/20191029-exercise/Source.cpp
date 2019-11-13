#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<fstream>
#include <time.h>
#include<windows.h>
#include "CNameGenerator.h"
#include "FOOD.h"
using namespace std;



int main() {
	srand(time(NULL));
	CNameGenerator namegenerator("..\\fanily.txt", "..\\firstname.txt");
	vector<FOOD*> fd;
	FOOD *save_fd;
	bool game_exit;
	//CNameGenerator *n = new 
	int input;
	while (true){
		namegenerator.resetName();
		game_exit = false;

		cin >> input;

		while (input > namegenerator.getMaxSize()) {
			cout << "Error overange! number > "<< namegenerator.getMaxSize() << endl;
			cin >> input;
		}
		
		if (input < 1) return 0;
		for (int i = 0; i < input; i++) {
			save_fd = new FOOD(namegenerator.getName(), 100);
			fd.push_back(save_fd);
		}
		save_fd = NULL;
		while (!game_exit) {
			system("cls");
			for (vector<FOOD*>::iterator it = fd.begin(); it != fd.end(); it++) {
				if ((*it)->ear()) {
					game_exit = true;
					save_fd = *it;
				}
				(*it)->show_info();
				(*it)->show_static();
			}
			Sleep(500);
		}
		
		if(save_fd!=NULL) cout << endl << (save_fd->getName()) << "   ³Ó§Q!\n";
		for (vector<FOOD*>::iterator it = fd.begin(); it != fd.end(); it++) {
			delete *it;
		}
		fd.clear();
		system("pause");
		system("cls");

		
	}
	system("pause");
	return 0;
}