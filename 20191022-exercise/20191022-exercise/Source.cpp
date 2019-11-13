#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<fstream>
#include <time.h>
#include "CNameGenerator.h"
using namespace std;

int main() {
	srand(time(NULL));
	CNameGenerator namegenerator("..\\fanily.txt", "..\\firstname.txt");
	//CNameGenerator *n = new 
	int input;
	while (true){
		
		cin >> input;

		while (input > namegenerator.getMaxSize()) {
			cout << "Error overange! number > "<< namegenerator.getMaxSize() << endl;
			cin >> input;
		}
		
		if (input < 1) return 0;
		for (int i = 0; i < input; i++) 
			cout << namegenerator.getName() << endl;
		
		namegenerator.resetName();

		cout << endl;
	}
	system("pause");
	return 0;
}