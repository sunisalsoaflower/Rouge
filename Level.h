
#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <string>
#include <random>
#include <ctime>

#include "Character.h"
#include "Player.h"
#include"Enemy.h"

using namespace std;

class Level
{
public:
	Level();

	void load(string fileName, Player& player);
	void print();
	void movePlayer(char input, Player& player);

	//Getters
	char getTile(int x, int y);
	//Settters
	void setTile(int x, int y, char tile);

	int randGenerator(int max);



private:
	vector <string> _levelData;
	vector<Enemy> _enemies;
	void processPlayerMove(Player& player, int targetX, int targetY);
	bool isFloor(int x, int y);
	void randTile();
	void battleMonster(Player& player, int targetX, int targetY);
	int X, Y;
	bool check;
};





#endif
