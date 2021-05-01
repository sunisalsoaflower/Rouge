
#include <fstream>
#include<stdlib.h>
#include <iostream>

#include "Player.h"
#include "Level.h"
#include"Enemy.h"

using namespace std;

Level::Level() {}

void Level::load(string fileName, Player& player) {

	// load level
	ifstream file;
	file.open(fileName);

	if (file.fail()) {
		perror(fileName.c_str());
		exit(1);
	}

	string line;

	while (getline(file, line)) {
		_levelData.push_back(line);
	}
	file.close();

	randTile();

	_levelData[Y][X] = '@';          //Player
	player.setPosition(X, Y);

	randTile();
	_levelData[Y][X] = '/';          //Staircase

	char tile;
	for (size_t i = 0; i < _levelData.size(); i++){
		for (size_t j = 0; j < _levelData[i].size(); j++) {
			tile = _levelData[i][j];

			if (tile == 'S') {//Snake
				_enemies.push_back(Enemy("Snake", tile, 10, 2, 1));
				_enemies.back().setPosition(j, i);
			}
			else if (tile == 'G') { //Goblin
				_enemies.push_back(Enemy("Goblin", tile, 13, 4, 3));
				_enemies.back().setPosition(j, i);
			}
			else if (tile == 'O') { //Ogre
				_enemies.push_back(Enemy("Ogre", tile, 8, 6, 5));
				_enemies.back().setPosition(j, i);
			}
			else if (tile == 'D') { //Dragon
				_enemies.push_back(Enemy("Dragon", tile, 20, 10, 9));
				_enemies.back().setPosition(j, i);
			}
			else if (tile == 'B') { //Bandit
				_enemies.push_back(Enemy("Bandit", tile, 16, 8, 7));
				_enemies.back().setPosition(j, i);
			}

			
		}
}
}



void Level::print() {
	for (vector<int>::size_type i = 0; i < _levelData.size(); i++) {
		cout << _levelData[i].c_str() << endl;
	}
	cout << endl;

}

void Level::movePlayer(char input, Player& player) {

	int playerX, playerY;
	player.getPosition(playerX, playerY);
	try {
		if (input !='W' && input!='S' && input!= 'A'&& input!= 'D'&& input!= 'Q' && input != 'J')
			throw "Invallid input";
			}
	catch (const char* e) {
		cerr << "Try again." << e << endl;	
	}
	
	switch (input) {
	 case 'W':
		processPlayerMove(player, playerX, playerY -1);
		break;
	 case'A':
		processPlayerMove(player, playerX - 1, playerY);
		break;
	 case 'S':
		processPlayerMove(player, playerX, playerY + 1);
		break;
	case 'D':
		processPlayerMove(player, playerX + 1, playerY);
		break;
	case 'Q':
		system("CLS");
		cout << endl << "Quitting Game" << endl;
		exit(0);
		break;
	case 'J' :
		break;
	}
	
}


char Level::getTile(int x, int y) {
	return _levelData[y][x];
}

void Level::setTile(int x, int y, char tile) {
	_levelData[y][x] = tile;
}

void Level::processPlayerMove(Player& player, int targetX, int targetY) {
	int playerX, playerY;
	player.getPosition(playerX, playerY);

	char moveTile = getTile(targetX, targetY);

	switch (moveTile) {
	case '.':
		player.setPosition(targetX, targetY);
		setTile(playerX, playerY, '.');
		setTile(targetX, targetY, '@');
		
		break;
	case '#':
		cout << endl << "You hit a wall!" << endl;
		break;
	case '/':
		system("CLS");
		cout << "You have found the staircase !" << endl << "YOU WIN!!!!!!!!" << endl;
		exit(0);
	case'$':
		
		player._score += 5;
		
		player.setPosition(targetX, targetY);
		setTile(playerX, playerY, '.');
		setTile(targetX, targetY, '@');
		cout << "You have Collected Gold" << endl;
	default:
		battleMonster(player,targetX,targetY);
		break;

	}

	bool flag = false;
	
	for (size_t i = 0; i < _enemies.size(); i++) {
		
			if (((player.getx() < _enemies[i].getx()-1 )and player.gety() == _enemies[i].gety()) and (_enemies[i].getx() -player.getx()<=5) and (player.getx()!=_enemies[i].getx()+1 and player.getx() != _enemies[i].getx() - 1)) {

				if (flag == false) {
					char x = _enemies[i].getname();
					if (getTile(_enemies[i].getx() - 1, _enemies[i].gety()) == '.') {
					setTile(_enemies[i].getx(), _enemies[i].gety(), '.');
					setTile(_enemies[i].getx() - 1, _enemies[i].gety(), x);
					_enemies[i].setPosition(_enemies[i].getx() - 1, _enemies[i].gety());
					flag = true;
				}
					break;
				}
			}
			else if (((player.getx() > _enemies[i].getx() - 1) and player.gety() == _enemies[i].gety()) and (player.getx()-_enemies[i].getx()  <= 5) and (player.getx() != _enemies[i].getx() + 1 and player.getx() != _enemies[i].getx() - 1)) {
				
				if (flag == false) {
					char x = _enemies[i].getname();
					if (getTile(_enemies[i].getx() + 1, _enemies[i].gety()) == '.') {
					setTile(_enemies[i].getx(), _enemies[i].gety(), '.');
					setTile(_enemies[i].getx() + 1, _enemies[i].gety(), x);
					_enemies[i].setPosition(_enemies[i].getx() + 1, _enemies[i].gety());
					flag = true;
				}
					break;
				
			}
			}
			else if (((player.gety() > _enemies[i].gety() - 1) and player.getx() == _enemies[i].getx()) and (player.gety() - _enemies[i].gety() <= 5) and (player.gety() != _enemies[i].gety() + 1 and player.gety() != _enemies[i].gety() - 1)) {

				if (flag == false) {
					char x = _enemies[i].getname();
					if (getTile(_enemies[i].getx(), _enemies[i].gety() + 1) == '.') {
						setTile(_enemies[i].getx(), _enemies[i].gety(), '.');
						setTile(_enemies[i].getx(), _enemies[i].gety() + 1, x);
						_enemies[i].setPosition(_enemies[i].getx(), _enemies[i].gety() + 1);
						flag = true;
					}
					break;

				}
			}
			else if (((player.gety() < _enemies[i].gety() - 1) and player.getx() == _enemies[i].getx()) and (_enemies[i].gety() - player.gety() <= 5) and (player.gety() != _enemies[i].gety() + 1 and player.gety() != _enemies[i].gety() - 1)) {
				if (flag == false) {
					char x = _enemies[i].getname();
					if (getTile(_enemies[i].getx(), _enemies[i].gety() - 1) == '.') {
						setTile(_enemies[i].getx(), _enemies[i].gety(), '.');
						setTile(_enemies[i].getx(), _enemies[i].gety() - 1, x);
						_enemies[i].setPosition(_enemies[i].getx(), _enemies[i].gety() - 1);
						flag = true;
					}
					break;
				}
			}
		
	}
}
void Level::battleMonster(Player& player, int targetX, int targetY) {
	
	int enemyX;
	int enemyY;
	int attackRoll;
	int attackResult;
	string enemy_name;
	
	for (size_t i = 0; i < _enemies.size(); i++)
	{
		_enemies[i].getPosition(enemyX, enemyY);
		enemy_name = _enemies[i].get_name();
		int gain = _enemies[i].gethealth();
		if (targetX == enemyX && targetY == enemyY) {
			//Battle
			cout << "Battle Starting, Lets see who comes Victorious" << endl;
			cout << "You are facing" << enemy_name << endl;
			
			while (_enemies[i].gethealth()>0 and player.gethealth()>0) {

				attackRoll = randGenerator(player._attack);
				cout << " Player attacked " << enemy_name << " with a roll of  " << attackRoll << endl;
				attackResult = _enemies[i].takeDamage(attackRoll);


				if (_enemies[i].gethealth() <= 0) {
					
					setTile(_enemies[i].getx(), _enemies[i].gety(), '.');
					cout << "You slayed the enemy. Good job!" << endl;
					_enemies[i].setPosition(0, 0);
					player.sethealth();

					int x = rand() % 20;
					int y = rand() % 70;
					while (1) {

						if (_levelData[x][y] == '.' )
							break;
						else {
							x = rand() % 20;
							 y = rand() % 70;
						}
					}
						setTile(y, x, '$');
					
					player._score += gain;
					system("PAUSE");
					return;
				}
				else {
					cout << "the enemy is left with " << _enemies[i].gethealth() << endl;
					system("PAUSE");
				}

				//Monster fights!
				attackRoll = randGenerator(_enemies[i]._attack);
				cout << enemy_name << " attacked player with a roll of  " << attackRoll << endl;
				attackResult = player.takeDamage(attackRoll);
				if (player.gethealth() <= 0) {

					setTile(targetX, targetY, 'x');
					system("CLS");
					cout << "You died. Game over.   Better luck next time";
					exit(0);
					return;
				}
				else {
					cout << "the player is left with " << player.gethealth() << endl;
				}
				system("PAUSE");
			}
		}
	}
}



int Level::randGenerator(int max) {
	static default_random_engine generator(time(NULL));
	uniform_int_distribution<int> distribution(0, max);
	return distribution(generator);
}

bool Level::isFloor(int x, int y) {
	if (_levelData[y][x] == '.')
		return true;
	else return false;
}

void Level::randTile() {
	do {
		Y = randGenerator(24);
		X = randGenerator(79);
		check = isFloor(X, Y);
	} while (!check);
}
