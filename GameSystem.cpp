
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <iostream>

#include "GameSystem.h"
#include "Level.h"


using namespace std;


// sets up game
GameSystem::GameSystem(string levelFileName) {

	_player.init(100, 10,10);
	_level.load(levelFileName, _player);

	string name;

	cout << "WElLCOME!!! STARTING GAME NOW : " << endl;
	cout << "Player is represented by @" << endl;
	cout << "$ is Gold and sevral other letters are enemies that must be defeated" << endl;
	cout << "# are walls, cannot be crossed, . is the floor and can be walked on" << endl;
	cout << "IF health reaches 0, you lose" << endl;
	cout << "To win reach the staircase to leave the dungeon represented by / " << endl << endl;
	cout << "Name your character : ";
	cin >> name;
	_player.setName(name);
}

void GameSystem::playGame() {

	bool isDone = false;

	while (isDone != true) {
		system("CLS");
		_level.print();
		_player.displayStats();
		playerMove();

	}

}

void GameSystem::playerMove() {
	

		char input;
		cout << "Enter a move command : ";
		input = _getch();
		input = toupper(input);
		_level.movePlayer(input, _player);
	
}
