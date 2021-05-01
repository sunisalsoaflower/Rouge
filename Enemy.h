
#ifndef ENEMY_H
#define ENEMY_H
#include<string.h>
#include<conio.h>
#include"Character.h"
#include"Player.h"


class Enemy : public Character
{
private:
	char _tile;

public:

	Enemy(string name,char tile,int health,int attack,int defense);
	int takeDamage(int attack);

	//Getters
	char getname();
};




#endif