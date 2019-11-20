#include "../../include/LifeEntity/Attributes.h"
#define SHOW_MAX_HP 20
#define SHOW_HP_FIGURE(_num) ((_num) ? "#" : " ")
#define SHOW_HP_FRAME ("|| ");

#define SHOW_MAX_MP 20
#define SHOW_MP_FIGURE(_num) ((_num) ? "#": " ")
#define SHOW_MP_FRAME ("|| ");

Attributes::Attributes(int _MAX_HP, int _MAX_MP, int _attack):
	HP(new Attributes_range(_MAX_HP)),
	MP(new Attributes_range(_MAX_MP)),
	Attack(new Attributes_range(_attack)){
}

Attributes::~Attributes() {
	delete HP;
	delete MP;
	delete Attack;
}

/*
*                               HP
*/
int Attributes::getHP() { return HP->getNow(); }

Attributes  Attributes::setHP(int _HP) { this->HP->setNow(_HP); return *this; }

Attributes Attributes::AddHP(int _AddHP, bool percent, bool setZero) {
	this ->setHP(ADD_FUN(this->getHP(), _AddHP, percent, setZero));
	return *this;
}

Attributes Attributes::setMaxHP(int _HP) {
	this -> HP->setTop(_HP);
	return *this;
}

Attributes  Attributes::AddMaxHP(int _AddMaxHP, bool percent, bool setZero) {
	this->setMaxHP(ADD_FUN(this->HP->getNow() , _AddMaxHP, percent, setZero));
	return *this;
}

Attributes Attributes::showHP(bool show, bool LF){
	cout << SHOW_HP_FRAME;
	for (int i = 0; i < SHOW_MAX_HP; i++)
		cout << SHOW_HP_FIGURE(i < (HP->getNow() * (SHOW_MAX_HP / (double)HP->getTop())));
	cout << SHOW_HP_FRAME;
	if (show) cout << this->getHP();
	if (LF) cout << endl;
	return *this;
}

/*
*                               MP
*/
int Attributes::getMP() { return this->MP->getNow(); }

Attributes Attributes::setMP(int _MP) {
	this->MP->setNow(_MP); 
	return *this;
}

Attributes Attributes::AddMP(int _AddMP, bool percent, bool setZero) {
	this->setMP(ADD_FUN(this->getMP(), _AddMP, percent, setZero));
	return *this;
}
Attributes Attributes::setMaxMP(int _MP) {
	this->MP->setTop(_MP);
	return *this;
}
Attributes Attributes::AddMaxMP(int _AddMaxMP, bool percent, bool setZero) {
	this->setMaxMP(ADD_FUN(this->MP->getTop(), _AddMaxMP, percent, setZero));
	return *this;
}
Attributes Attributes::showMP(bool show, bool LF) {
	cout << SHOW_MP_FRAME;
	for (int i = 0; i < SHOW_MAX_MP; i++)
		cout << SHOW_MP_FIGURE(i < (this->getMP() * (SHOW_MAX_MP / MP->getTop())));
	cout << SHOW_MP_FRAME;
	if (show) cout << this->getHP();
	if (LF) cout << endl;
	return *this;
}

/*
*                              Attributes
*/
int Attributes::getAttack() { return Attack->getNow(); }

Attributes Attributes::setAttack(int _Attack) { Attack->setNow(_Attack); return *this; }

Attributes Attributes::AddAttack(int _AddAttack, bool percent, bool setZero) {
	this->setAttack(ADD_FUN(this->getAttack(), _AddAttack, percent, setZero));
	return *this;
}

Attributes Attributes::setMaxAttack(int _Attack) { Attack->setTop(_Attack); return *this; }

Attributes Attributes::AddMaxAttack(int _AddMaxAttack, bool percent, bool setZero) {
	this->setMaxAttack(ADD_FUN(this->Attack->getTop(), _AddMaxAttack, percent, setZero));
	return *this;
}

/*
*                                 Tool
*/
int Attributes::ADD_FUN(int _now, int _num, bool percent, bool setZero) {
	_now += percent ? (int)( _now * _num * 0.01) : _num;
	if (setZero) if (_now < 0) _num= 0;
	return _now;
}