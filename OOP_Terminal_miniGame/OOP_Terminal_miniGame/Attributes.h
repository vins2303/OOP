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
	void setHP(int _HP);
	void AddHP(int _AddHP, bool percent = false, bool setZero = true);
	void setMaxHP(int _HP);
	void AddMaxHP(int _AddMaxHP, bool percent = false, bool setZero = true);
	void showHP(bool show = false, bool LF = true);

	int getMP();
	void setMP(int _MP);
	void AddMP(int _AddMP, bool percent = false, bool setZero = true);
	void setMaxMP(int _MP);
	void AddMaxMP(int _AddMaxMP, bool percent = false, bool setZero = true);
	void showMP(bool show = false, bool LF = true);

	int getAttack();
	void setAttack(int _Attack);
	void AddAttack(int _AddAttack, bool percent = false, bool setZero = true);
	void setMaxAttack(int _Attack);
	void AddMaxAttack(int _AddMaxAttack, bool percent = false, bool setZero = true);
	//void showAttack();
	
private:
	//int ADD_FUN(int _now, int _add, bool percent = false);
	int ADD_FUN(int _now, int _less, bool percent = false, bool setZero = true);

};
#endif