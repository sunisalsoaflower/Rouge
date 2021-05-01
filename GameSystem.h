#ifndef GAMESYSTEM_H
#define GAMESYSTEM_H

#include "Player.h"
#include "Level.h"

#include <string>

using namespace std;


class GameSystem {
public:
	GameSystem(string levelFileName);
	void playGame();
	void playerMove();

private:
	Player _player;
	Level _level;
	};

#endif