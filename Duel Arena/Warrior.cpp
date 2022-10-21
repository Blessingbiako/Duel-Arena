#include "Warrior.h"



Warrior::Warrior(float health, float damage, float defense, RollingDie& die) :
	die(die), health(health), max_health(health), damage(damage), defense(defense)
{}


bool Warrior::alive()
{
	return this->health > 0;
}

float Warrior::attack(Warrior& second)
{
	float defense_second = second.defense + second.die.roll();
	float attack_first = this->damage + this->die.roll();
	float injury = attack_first - defense_second;
	if (injury < 0)
		injury = 0;
	second.health -= injury;
	return injury;
}

float Warrior::getHealth()
{
	return this->health;
}

float Warrior::getMaxHealth()
{
	return this->max_health;
}

float Warrior::getAttack()
{
	return this->damage;
}

float Warrior::getDefense()
{
	return this->defense;
}