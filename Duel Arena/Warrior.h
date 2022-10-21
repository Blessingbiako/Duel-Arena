#ifndef __WARRIOR_H_
#define __WARRIOR_H_
#include <string>
#include "RollingDie.h"

using namespace std;

class Warrior
{
private:
	float health;
	float max_health;
	float damage;
	float defense;
	RollingDie& die;
public:
	Warrior(float health, float damage, float defense, RollingDie& die);
	bool alive();
	float attack(Warrior& second);
	float getHealth();      // getter
	float getMaxHealth();
	float getAttack();
	float getDefense();
};
#endif