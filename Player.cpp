#include "Player.h"
#include<random>
#include<ctime>
using namespace std;

// Constructor, initializes position to zero
Player::Player() {
	
}

void Player::init(int health, int attack,int defense) {
	_health = health;
	_attack = attack;
	_defense = defense;
}

void Player::setName(string n) { _name = n; }

void Player::displayStats() {
	cout << "Player : " << _name << "  " << "Health : " << _health << "  " << "Attack : " << _attack <<"  " <<"Defense : "<<_defense<<"  " <<"Score : "<<_score<< endl;
	cout << " Use WASD to move around and Q to Quit " << endl;
}


int Player::takeDamage(int attack) {

	if (attack > 0) {
		_health -= attack;
		if (_health <= 0) {
			return 1;
		}
	}


}



