#ifndef __PLAYER__H_
#define __PLAYER__H_
#include <string>
#include "RollingDie.h"
#include "Warrior.h"
using namespace std;

class Player
{
private:
	Warrior warrior;
	string name;
public:
	Player(string name, RollingDie& die);
	string getName();
	Warrior& getWarrior();
};
#endif