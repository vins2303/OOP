#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
#define debug 1
//char **arg;

void help(char *arg) {
	cout << arg << " -encode a.txt b.txt n (a.txt �첾 n �s�X�� b.txt )" << endl;
	cout << arg << " -decode a.txt b.txt n (a.txt �첾 n �s�X�� b.txt )" << endl;
	//cout << arg << " -encode "
}

void encode(char *r, char *w, int move) {
	ifstream finp(r);
	ofstream fout(w);
	char data;
	while (finp.get(data)) {

		fout << (char)(data + move) % 256;
	}
	finp.close();
	fout.close();
}

void decode(char *r, char *w, int move){
	ifstream finp (r);
	ofstream fout (w);
	char data;
	while (finp.get(data)) {
		data -= move;
		if (data < 0) data += 256;
		fout << data;
	}
	finp.close();
	fout.close();
}

int main(int argc, char **argv) {

#if debug
	for (int i = 0; i < argc; i++)
		cout << argv[i] << endl;

#endif

	if (strcmp(argv[1], "/?") == 0) {
		help(argv[0]);
	}
	else if (strcmp(argv[1],"-encode")==0 || strcmp(argv[1], "-decode") == 0) {
		if (argc != 5) {
			cout << "�R�O�y�k�����T�C" << endl;
		}else if (strcmp(argv[1], "-encode") == 0) {
			encode(argv[2], argv[3], atoi(argv[4]));

		}else if (strcmp(argv[1], "-decode") == 0) {
			decode(argv[2], argv[3], atoi(argv[4]));

		}
	}
	else {
		cout << "�R�O�y�k�����T�C" << endl;
	}




	//system("pause");
	return 0;
}