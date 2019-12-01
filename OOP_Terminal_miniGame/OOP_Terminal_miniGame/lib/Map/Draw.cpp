#include "../../include/Map/Draw.h"



inline void Draw::setXY(int _x, int _y) {
	COORD XY;
	XY.X = _x;
	XY.Y = _y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), XY);
}

void Draw::show(int _x, int _y, string _image) {
	vector<string> list;
	Tool::SplitString(_image, list, "\n");
	for (vector<string>::iterator it = list.begin(); it != list.end(); it++) {
		setXY(_x, _y++);
		cout << *it;
	}
	list.clear();
}

void Draw::clearMap(int _x, int _y, int _width, int _heigh) {
	for (int i = _x; i < _x + _width; i++)
		for (int j = _y; j < _y + _heigh; j++) {
			setXY(i, j);
			cout << " ";
		}
}

string Draw::getImage(string path, string _image, string end) {
	string buff;
	string out = "";
	ifstream ReadFile(path);

    if (!ReadFile.is_open()) {
        assert(ReadFile);
        return "NULL";
    }
    
	bool isfind = false;
	while (!ReadFile.eof() && !isfind) {
		getline(ReadFile, buff);
		if (buff == "[" + _image + "]") {
			getline(ReadFile, buff);
			while (buff != "[" + end + "]") {
				out += buff + "\n";
				getline(ReadFile, buff);
			}
			out = out.substr(0, out.rfind("\n"));
            isfind = true;
		}
	}
	ReadFile.close();
	return isfind ? out :"NULL";
}

void Draw::showObject(int _x, int _y, string path, string _image) {
	show(_x, _y, getImage(path, _image));
}