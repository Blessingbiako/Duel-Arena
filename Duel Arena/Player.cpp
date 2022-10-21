#include "Player.h"
Player::Player(string name, RollingDie& die) : warrior(100, 8, 5, die)
{
	this->name = name;
}
string Player::getName()
{
	return this->name;
}
Warrior& Player::getWarrior()
{
	return this->warrior;
}