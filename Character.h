
#ifndef CHARACTER_H
#define CHARACTER_H

#include <random>
#include <ctime>
#include <string>
#include<iostream>
using namespace std;

class Character
{
public:

	int _score;
	int _attack;

	Character();
	//Setters
	void setPosition(int x, int y);
	void sethealth();

	//Getters
	void getPosition(int& x, int& y);
	int getx();
	int gety();
	int gethealth();
	string get_name();
	
	virtual int takeDamage(int attack);

protected:
	// Properties
	string _name;
	int _health;

	int _defense;

	// Position
	int _x;
	int _y;
};
#endif