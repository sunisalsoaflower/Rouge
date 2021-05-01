#include "Character.h"

Character::Character() {
	_x = 0;
	_y = 0;
	_health = 0;
	_attack = 0;
	_name = " ";
	_defense = 0;
	_score = 0;

}

//Setters
void Character::setPosition(int x, int y) {
	_x = x;
	_y = y;
}

void Character::sethealth() {
	cout << "Your Health was restored\n";
	this->_health = 100;
}

//Getters
void Character::getPosition(int& x, int& y) {
	x = _x;
	y = _y;
}

int Character::getx() {
	return this->_x;
}
int Character::gety() {
	return this->_y;
}

int Character::gethealth() {
	return _health;
}

string Character::get_name() {
	return _name;
}

int Character::takeDamage(int attack) {
	return 0;
}