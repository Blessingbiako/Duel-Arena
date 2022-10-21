#ifndef __ARENA_H_
#define __ARENA_H_
#include "Player.h"

class Arena
{
public:
	Player** players;
	int players_count;
	int round;
	Arena(int _players_count, RollingDie& die);
	~Arena();
	void print();
	bool winnerExists();
	int countAlive();
	void fight();
	void printWinner();
};
#endif