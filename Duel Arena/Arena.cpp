/*
 *       _____ _____ _____                _       _
 *      |_   _/  __ \_   _|              (_)     | |
 *        | | | /  \/ | |  ___  ___   ___ _  __ _| |
 *        | | ||      | | / __|/ _ \ / __| |/ _` | |
 *       _| |_| \__/\ | |_\__ \ (_) | (__| | (_| | |
 *      |_____\_____/ |_(_)___/\___/ \___|_|\__,_|_|
 *                   ___
 *                  |  _|___ ___ ___
 *                  |  _|  _| -_| -_|  LICENSE
 *                  |_| |_| |___|___|
 *
 * IT NEWS  <>  PROGRAMMING  <>  HW & SW  <>  COMMUNITY
 *
 * This source code is a part of online courses at IT social
 * network WWW.ICT.SOCIAL
 *
 * Feel free to use it for whatever you want, modify it and share it but
 * don't forget to keep this link in your code.
 *
 * Visit http://www.ict.social/licenses for more information
 */
#include <iostream>
#include "Arena.h"

Arena::Arena(int _players_count, RollingDie& die) : round(1)
{
	players_count = _players_count; // storing the player count
	players = new Player * [players_count]; // creating an array for the players
	for (int i = 0; i < players_count; i++)
	{
		string name;
		cout << "Enter a player name: ";
		cin >> name;
		players[i] = new Player(name, die); // creating the player
	}
}

Arena::~Arena()
{
	for (int i = 0; i < this->players_count; i++)
		delete players[i]; // deleting the players
	delete[] players; // deleting the array
	players = NULL;
}

void Arena::print()
{
	cout << "-------------- Arena --------------" << endl;
	cout << "Round: " << this->round << endl;
	cout << "Warriors health:" << endl;
	for (int i = 0; i < this->players_count; i++)
	{
		cout << "\t" << this->players[i]->getName() << ": "; // print warrior name
		if (!this->players[i]->getWarrior().alive()) // determine whether the warriors hasn't died yet
		{
			cout << "dead" << endl;  // if he has, we inform about it
			continue; // and continue with another warrior
		}
		cout << "["; // healthbar start
		// compute the remaining percentage of health the warrior still has
		float health_percent = this->players[i]->getWarrior().getHealth() / this->players[i]->getWarrior().getMaxHealth();
		for (double h = 0; h < 1.0; h += 0.1)
			cout << (h < health_percent ? '#' : ' '); // print health percentage
		// ends the healthbar and prints damage and defense info
		cout << "] (damage: " << this->players[i]->getWarrior().getAttack() << ", defense: " << this->players[i]->getWarrior().getDefense() << ")" << endl;
	}
}

bool Arena::winnerExists()
{
	return this->countAlive() == 1;
}

int Arena::countAlive()
{
	int alive = 0;
	// for every alive player
	for (int i = 0; i < this->players_count; i++)
		if (this->players[i]->getWarrior().alive())
			alive++; // increment the number of alive by 1
	return alive;
}

void Arena::fight()
{
	// till the last player standing
	while (!this->winnerExists())
	{
		this->print(); // print player information
		// check all players
		for (int i = 0; i < this->players_count; i++)
		{
			// if the warrior isn't alive, skip him
			if (!this->players[i]->getWarrior().alive())
				continue;
			// it could happen that somebody was killed in the previous round so there may be the last warrior left
			// if this happend, the game is over
			if (this->winnerExists())
				break;
			// computes the index of the closest alive player which we can attack
			int attack_at = (i + 1) % this->players_count;
			while (!this->players[attack_at]->getWarrior().alive())
				attack_at = (attack_at + 1) % this->players_count;
			// attack
			float injury = this->players[i]->getWarrior().attack(this->players[attack_at]->getWarrior());
			// print the fight result
			cout << this->players[i]->getName() << " attacks "
				<< this->players[attack_at]->getName() << " for " << injury << " hp" << endl;
		}
		// proceed to the next round
		this->round++;
	}
}

void Arena::printWinner()
{
	if (!this->winnerExists())
		return;

	for (int i = 0; i < this->players_count; i++)
		if (this->players[i]->getWarrior().alive())
		{
			cout << endl << "-------------- WINNER --------------" << endl;
			cout << "The winner is: " << this->players[i]->getName() << " with " << this->players[i]->getWarrior().getHealth() << " health" << endl;
			return;
		}
}