
#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player : public Character
{
public:
	Player();
	int takeDamage(int attack);
	void init(int health, int attack,int defense);
	void setName(string n);
	void displayStats();

	
};

#endif