#ifndef  ATTRIBUTES_CPP
#define  ATTRIBUTES_CPP
#include<iostream>
#include "Attributes_range.h"
using namespace std;

class Attributes {
private:
	Attributes_range *HP;
	Attributes_range *MP;
	Attributes_range *Attack;

public:

	Attributes(int _MAX_HP, int _MAX_MP, int _attack);
	~Attributes();

	int getHP();
	Attributes setHP(int _HP);
	Attributes AddHP(int _AddHP, bool percent = false, bool setZero = true);
	Attributes setMaxHP(int _HP);
	Attributes AddMaxHP(int _AddMaxHP, bool percent = false, bool setZero = true);
	Attributes showHP(bool show = false, bool LF = true);

	int getMP();
	Attributes setMP(int _MP);
	Attributes AddMP(int _AddMP, bool percent = false, bool setZero = true);
	Attributes setMaxMP(int _MP);
	Attributes AddMaxMP(int _AddMaxMP, bool percent = false, bool setZero = true);
	Attributes showMP(bool show = false, bool LF = true);

	int getAttack();
	Attributes setAttack(int _Attack);
	Attributes AddAttack(int _AddAttack, bool percent = false, bool setZero = true);
	Attributes setMaxAttack(int _Attack);
	Attributes AddMaxAttack(int _AddMaxAttack, bool percent = false, bool setZero = true);
	//void showAttack();

	int getLeve();
	Attributes setLeve(int _leve);
	Attributes AddLeve(int _leve);
	
	
private:
	//int ADD_FUN(int _now, int _add, bool percent = false);
	int ADD_FUN(int _now, int _less, bool percent = false, bool setZero = true);

};
#endif