#include "Draw.h"

void Draw::setXY(int _x, int _y) {
	COORD XY;
	XY.X = _x;
	XY.Y = _y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), XY);
}

void Draw::clearMap(int _x, int _y, int _width, int _heigh) {
	for(int i=_x;i<_x+_width;i++)
		for (int j = _y; j < _y + _heigh; j++) {
			setXY(i,j);
			cout << " ";
		}

}


void Draw::showHoust(int _x, int _y) {
	setXY(_x,_y);
	cout << " /‵‵‵‵/\\";
	setXY(_x, _y + 1);
	cout << "/......../..\\";
	setXY(_x, _y + 2);
	cout << "▎_____  ▎  ▎";
	setXY(_x, _y + 3);
	cout << "▎▎ | ▎▎  ▎";
	setXY(_x, _y + 4);
	cout << "▎▎'|'▎▎  ▎";
	setXY(_x, _y + 5);
	cout << "▔▔▔▔▔▔▔";
	//cout << "|  |  | ||"<<endl;
	
}

void Draw::showWarrior(int _x, int _y) {
	setXY(_x, _y);
	cout << " X";
	setXY(_x, _y+1);
	cout << "\\|/";
	setXY(_x, _y + 2);
	cout << " |";
	setXY(_x, _y + 3);
	cout << "/ \\";

}

void Draw::showMap_wall(Map& _map) {
	setXY(0, 0);
	//cout << "『";
	for (int i = 0; i < _map.getWidth()/2 + 1; i++)
		cout << "＝";
	//cout << "﹃";
	setXY(0, 42);
	for (int i = 0; i < _map.getWidth() / 2 + 1; i++)
		cout << "＝";

	for (int i = 1; i < _map.getHigh(); i++) {
		setXY(0, i);
		cout << "∥";
		setXY(102, i);
		cout << "∥";
	}
}